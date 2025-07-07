%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/record.h"
#include "./lib/symbol_table.h"

// Protótipos de funções
int yylex(void);
void yyerror(const char *s);
char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5);
const char* map_type(const char* o);

// Variáveis externas do Flex
extern int yylineno;
extern char *yytext;
extern FILE *yyin, *yyout;

// Contador para gerar labels
static int label_count = 0;
char *new_label() {
    char buf[32];
    sprintf(buf, "L%d", label_count++);
    return strdup(buf);
}
%}

// Definição da união para os valores semânticos
%union {
    int int_val;
    float float_val;
    char *str_val;
    struct record *rec;
}

// Declaração dos tokens
%token UNIT FLOAT INT RATIONAL MATRIX BST PRINT RETURN IF WHILE
%token REF AMPERSAND
%token ARROW_LEFT PLUS MINUS MUL DIV
%token LT LE GT GE EQ NE
%token SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA
%token <str_val> ID
%token <int_val> INT_LIT
%token <float_val> FLOAT_LIT

// Definição dos tipos para os não-terminais
%type <rec> program decl_list func_decl param_list_opt param_list param
%type <rec> stmt_list stmt var_decl_stmt assignment_stmt func_call_stmt print_stmt return_stmt if_stmt while_stmt
%type <rec> type lvalue expr func_call arg_list_opt arg_list

// Definição da precedência e associatividade dos operadores
%left PLUS MINUS
%left MUL DIV
%left LT LE GT GE EQ NE

%%

// --- REGRAS DA GRAMÁTICA ---

program:
    decl_list {
        fprintf(yyout,
            "#include <stdio.h>\n"
            "#include <stdlib.h>\n"
            "#include <stdbool.h>\n"
            "#include \"lib/rational.h\"\n"
            "#include \"lib/matrix.h\"\n"
            "#include \"lib/bst.h\"\n\n" // Inclui a biblioteca de BST
            "float read() { float v; if (scanf(\"%%f\", &v)!=1) return -1.0f; return v;}\n\n"
        );
        fprintf(yyout, "%s\n", $1->code);
        freeRecord($1);
    }
;

decl_list:
      func_decl
    | decl_list func_decl {
        char *s = cat($1->code, "\n\n", $2->code, "", "");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($2);
    }
;

func_decl:
    type ID LPAREN param_list_opt RPAREN LBRACE stmt_list RBRACE {
        const char *rt = strcmp($2, "main")==0 ? "int" : map_type($1->code);
        char *h = cat(rt, " ", $2, "(", $4->code);
        char *b = cat(h, ") {\n", $7->code, "}\n", "");
        $$ = createRecord(b, ""); free(h); free(b);
        freeRecord($1); free($2); freeRecord($4); freeRecord($7);
    }
  | type ID LPAREN param_list_opt RPAREN SEMICOLON {
        const char *rt = map_type($1->code);
        char *h = cat(rt, " ", $2, "(", $4->code);
        char *p = cat(h, ");\n", "", "", "");
        $$ = createRecord(p, ""); free(h); free(p);
        freeRecord($1); free($2); freeRecord($4);
    }
;

param_list_opt:
      /* vazio */ { $$ = createRecord("", ""); }
    | param_list
;

param_list:
      param
    | param_list COMMA param {
        char *s = cat($1->code, ", ", $3->code, "", "");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($3);
    }
;

param:
    type ID {
        char *s = cat($1->code, " ", $2, "", "");
        $$ = createRecord(s, $1->opt1);
        free(s); freeRecord($1); free($2);
    }
  | REF type ID {
        const char* c_type = map_type($2->code);
        char* ptr_type = cat(c_type, "*", "", "", "");
        char* param_decl = cat(ptr_type, " ", $3, "", "");
        char* lang_type = cat("ref", $2->opt1, "", "", "");
        $$ = createRecord(param_decl, lang_type);
        free(ptr_type); free(param_decl); free(lang_type);
        freeRecord($2); free($3);
    }
;

stmt_list:
      /* vazio */ { $$ = createRecord("", ""); }
    | stmt_list stmt {
        char *s = cat($1->code, $2->code, "\n", "", "");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($2);
    }
;

stmt:
      var_decl_stmt
    | assignment_stmt
    | print_stmt
    | return_stmt
    | func_call_stmt
    | if_stmt
    | while_stmt
;

var_decl_stmt:
    type ID SEMICOLON {
        char *s = cat("    ", $1->code, " ", $2, ";");
        $$ = createRecord(s, ""); free(s);
        insertSymbol($2, $1->opt1);
        freeRecord($1); free($2);
    }
  | type ID ARROW_LEFT expr SEMICOLON {
        char *p = cat("    ", $1->code, " ", $2, " = ");
        char *s = cat(p, $4->code, ";", "", "");
        $$ = createRecord(s, ""); free(p); free(s);
        insertSymbol($2, $1->opt1);
        freeRecord($1); free($2); freeRecord($4);
    }
;

lvalue:
    ID { 
        const char* type = lookupSymbol($1);
        // Se o tipo começa com "ref", é um parâmetro por referência
        if (strncmp(type, "ref", 3) == 0) {
            char* deref_code = cat("*", $1, "", "", "");
            char* base_type = strdup(type + 3); // Remove "ref" do início
            $$ = createRecord(deref_code, base_type);
            free(deref_code); free(base_type);
        } else {
            $$ = createRecord($1, strdup(type));
        }
        free($1); 
    }
  | MUL ID {
        char* deref_code = cat("*", $2, "", "", "");
        const char* ptr_type = lookupSymbol($2);
        char* base_type = strdup(ptr_type ? ptr_type + 3 : "Unknown");
        $$ = createRecord(deref_code, base_type);
        free(deref_code); free(base_type); free($2);
    }
;

assignment_stmt:
    lvalue ARROW_LEFT expr SEMICOLON {
        char *s = cat("    ", $1->code, " = ", $3->code, ";");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($3);
    }
;

func_call_stmt:
    func_call SEMICOLON {
        char *s = cat("    ", $1->code, ";", "", "");
        $$ = createRecord(s, ""); free(s); freeRecord($1);
    }
;

print_stmt:
    PRINT expr SEMICOLON {
        char *s;
        if (strcmp($2->opt1, "Float") == 0) {
            s = cat("    printf(\"%f\\n\", ", $2->code, ");", "", "");
        } else if (strcmp($2->opt1, "Int") == 0) {
            s = cat("    printf(\"%d\\n\", ", $2->code, ");", "", "");
        } else if (strcmp($2->opt1, "Rational") == 0) {
            s = cat("    print_rational(", $2->code, ");", "", "");
        } else if (strcmp($2->opt1, "Matrix") == 0) {
            s = cat("    print_matrix(", $2->code, ");", "", "");
        } else if (strcmp($2->opt1, "BST") == 0) {
            s = cat("    print_bst_by_level(", $2->code, ");", "", "");
        } else {
            s = cat("    /* tipo desconhecido para print */", "", "", "", "");
        }
        $$ = createRecord(s, ""); free(s); freeRecord($2);
    }
;

return_stmt:
    RETURN expr SEMICOLON {
        char *s = cat("    return ", $2->code, ";", "", "");
        $$ = createRecord(s, ""); free(s); freeRecord($2);
    }
;

if_stmt:
    IF LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        char *lend = new_label();
        char *cond = cat("    if (!(", $3->code, ")) goto ", lend, ";");
        char *body = $6->code;
        char *code = cat(cond, "\n", body, "\n", lend);
        code = cat(code, ":", "", "", "");
        $$ = createRecord(code, ""); free(cond); free(lend); freeRecord($3); freeRecord($6);
    }
;

while_stmt:
    WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        char *lbegin = new_label();
        char *lend   = new_label();
        char *start = cat(lbegin, ":\n", "", "", "");
        char *cond  = cat("    if (!(", $3->code, ")) goto ", lend, ";");
        char *body  = $6->code;
        char *back  = cat("    goto ", lbegin, ";", "", "");
        char *end   = cat(lend, ":", "", "", "");
        char *tmp   = cat(start, cond, "\n", body, "\n");
        tmp = cat(tmp, back, "\n", end, "");
        $$ = createRecord(tmp, ""); free(tmp); freeRecord($3); freeRecord($6);
    }
;

type:
    INT      { $$ = createRecord("int", "Int"); }
  | FLOAT    { $$ = createRecord("float", "Float"); }
  | UNIT     { $$ = createRecord("void", "Unit"); }
  | RATIONAL { $$ = createRecord("rational_t", "Rational"); }
  | MATRIX   { $$ = createRecord("matrix_t*", "Matrix"); }
  | BST      { $$ = createRecord("TreeNode*", "BST"); }
;

expr:
      expr PLUS expr   { char *s=cat("(", $1->code, " + ", $3->code, ")"); $$=createRecord(s,$1->opt1); free(s); freeRecord($1); freeRecord($3); }
    | expr MINUS expr { char *s=cat("(", $1->code, " - ", $3->code, ")"); $$=createRecord(s,$1->opt1); free(s); freeRecord($1); freeRecord($3); }
    | expr MUL expr   { char *s=cat("(", $1->code, " * ", $3->code, ")"); $$=createRecord(s,$1->opt1); free(s); freeRecord($1); freeRecord($3); }
    | expr DIV expr   { char *s=cat("(", $1->code, " / ", $3->code, ")"); $$=createRecord(s,$1->opt1); free(s); freeRecord($1); freeRecord($3); }
    | expr LT expr    { char *s=cat("(", $1->code, " < ",  $3->code, ")"); $$=createRecord(s,(char*)"Int"); free(s); freeRecord($1); freeRecord($3); }
    | expr LE expr    { char *s=cat("(", $1->code, " <= ", $3->code, ")"); $$=createRecord(s,(char*)"Int"); free(s); freeRecord($1); freeRecord($3); }
    | expr GT expr    { char *s=cat("(", $1->code, " > ",  $3->code, ")"); $$=createRecord(s,(char*)"Int"); free(s); freeRecord($1); freeRecord($3); }
    | expr GE expr    { char *s=cat("(", $1->code, " >= ", $3->code, ")"); $$=createRecord(s,(char*)"Int"); free(s); freeRecord($1); freeRecord($3); }
    | expr EQ expr    { char *s=cat("(", $1->code, " == ", $3->code, ")"); $$=createRecord(s,(char*)"Int"); free(s); freeRecord($1); freeRecord($3); }
    | expr NE expr    { char *s=cat("(", $1->code, " != ", $3->code, ")"); $$=createRecord(s,(char*)"Int"); free(s); freeRecord($1); freeRecord($3); }
    | LPAREN expr RPAREN { $$ = $2; }
    | AMPERSAND ID {
        char* addr_expr = cat("&", $2, "", "", "");
        const char* base_type = lookupSymbol($2);
        char* ptr_type_name = cat("ref", base_type, "", "", "");
        $$ = createRecord(addr_expr, ptr_type_name);
        free(addr_expr); free(ptr_type_name); free($2);
    }
    | ID                { 
        const char *t = lookupSymbol($1); 
        // Se o tipo começa com "ref", é um parâmetro por referência
        if (strncmp(t, "ref", 3) == 0) {
            char* deref_code = cat("*", $1, "", "", "");
            char* base_type = strdup(t + 3); // Remove "ref" do início
            $$ = createRecord(deref_code, base_type);
            free(deref_code); free(base_type);
        } else {
            $$ = createRecord($1, strdup(t));
        }
        free($1); 
    }
    | INT_LIT           { char b[32]; sprintf(b,"%d",$1); $$=createRecord(strdup(b),(char*)"Int"); }
    | FLOAT_LIT         { char b[32]; sprintf(b,"%f",$1); $$=createRecord(strdup(b),(char*)"Float"); }
    | func_call         { $$ = $1; }
;

func_call:
    ID LPAREN arg_list_opt RPAREN {
        char *s = cat($1, "(", $3->code, ")", "");
        const char *type = "Unit"; // Tipo padrão para funções sem retorno (void)

        // Lógica para determinar o tipo de retorno das funções
        if (strcmp($1, "create_rational") == 0 || strcmp($1, "add") == 0 ||
            strcmp($1, "subtract") == 0 || strcmp($1, "multiply") == 0 ||
            strcmp($1, "divide") == 0 || strcmp($1, "negate") == 0 ||
            strcmp($1, "inverse") == 0) {
            type = "Rational";
        } else if (strcmp($1, "are_equal") == 0) {
            type = "Int";
        } else if (strcmp($1, "create_matrix") == 0 || strcmp($1, "add_matrices") == 0 ||
                   strcmp($1, "multiply_matrices") == 0) {
            type = "Matrix";
        } else if (strcmp($1, "create_bst_from_sequence") == 0) {
            type = "BST";
        } else if (strcmp($1, "get_min_value") == 0 || strcmp($1, "get_min_level") == 0 ||
                   strcmp($1, "get_max_value") == 0 || strcmp($1, "get_max_level") == 0) {
            type = "Int";
        }
        
        $$ = createRecord(s, (char*)type);
        free(s); free($1); freeRecord($3);
    }
;

arg_list_opt:
      /* empty */ { $$ = createRecord("", ""); }
    | arg_list
;

arg_list:
      expr
    | arg_list COMMA expr { char *s=cat($1->code, ", ", $3->code, "", ""); $$=createRecord(s,""); free(s); freeRecord($1); freeRecord($3); }
;

%%

// --- CÓDIGO AUXILIAR ---

void yyerror(const char *s) {
    fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
    exit(1); // Termina o programa com erro
}

// Concatena até 5 strings
char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5) {
    size_t len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5) + 1;
    char *o = malloc(len);
    if (!o) { fprintf(stderr, "Erro de malloc!\n"); exit(1); }
    sprintf(o, "%s%s%s%s%s", s1, s2, s3, s4, s5);
    return o;
}

// Mapeia o tipo interno da linguagem para o tipo correspondente em C
const char* map_type(const char* o) {
    if (strcmp(o, "Int") == 0) return "int";
    if (strcmp(o, "Float") == 0) return "float";
    if (strcmp(o, "Unit") == 0) return "void";
    if (strcmp(o, "Rational") == 0) return "rational_t";
    if (strcmp(o, "Matrix") == 0) return "matrix_t*";
    if (strcmp(o, "BST") == 0) return "TreeNode*";
    return "void"; // Padrão
}

// Função principal que orquestra a compilação
int main(int argc, char **argv) {
    if (argc != 3) { fprintf(stderr, "Uso: %s <in> <out>\n", argv[0]); return 1; }
    yyin = fopen(argv[1], "r"); if (!yyin) { perror("fopen"); return 1; }
    yyout = fopen(argv[2], "w"); if (!yyout) { perror("fopen"); fclose(yyin); return 1; }
    
    initSymbolTable();
    yyparse();
    freeSymbolTable();
    
    fclose(yyin);
    fclose(yyout);
    
    return 0;
}
