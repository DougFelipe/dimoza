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

// Função auxiliar que adiciona um '*' na frente do código se for uma referência.
// Retorna uma nova string alocada que deve ser liberada.
char* deref_if_needed(struct record* rec) {
    if (rec && rec->opt1 && strncmp(rec->opt1, "ref", 3) == 0) {
        return cat("*", rec->code, "", "", "");
    }
    return strdup(rec->code);
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
%token UNIT FLOAT INT RATIONAL MATRIX BST PRINT PRINT_STRING RETURN IF WHILE ELSE
%token REF AMPERSAND
%token ARROW_LEFT PLUS MINUS MUL DIV
%token LT LE GT GE EQ NE
%token SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA
%token <str_val> ID
%token <int_val> INT_LIT
%token <float_val> FLOAT_LIT
%token <str_val> STRING_LIT

// Definição dos tipos para os não-terminais
%type <rec> program decl_list func_decl param_list_opt param_list param
%type <rec> stmt_list stmt var_decl_stmt assignment_stmt func_call_stmt print_stmt print_string_stmt return_stmt if_stmt while_stmt
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
        const char *rt = strcmp($2, "main")==0 ? "int" : $1->code;
        char *h = cat(rt, " ", $2, "(", $4->code);
        char *b = cat(h, ") {\n", $7->code, "}\n", "");
        $$ = createRecord(b, ""); free(h); free(b);
        freeRecord($1); free($2); freeRecord($4); freeRecord($7);
    }
  | type ID LPAREN param_list_opt RPAREN SEMICOLON {
        const char *rt = $1->code;
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
        insertSymbol($2, $1->opt1);
        free(s); freeRecord($1); free($2);
    }
  | REF type ID {
        const char* c_type = map_type($2->opt1);
        char* ptr_type = cat(c_type, "*", "", "", "");
        char* param_decl = cat(ptr_type, " ", $3, "", "");
        char* lang_type = cat("ref", $2->opt1, "", "", "");
        $$ = createRecord(param_decl, lang_type);
        insertSymbol($3, lang_type);
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
    | print_string_stmt
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
        char* val = deref_if_needed($4);
        char *p = cat("    ", $1->code, " ", $2, " = ");
        char *s = cat(p, val, ";", "", "");
        $$ = createRecord(s, ""); free(p); free(s); free(val);
        insertSymbol($2, $1->opt1);
        freeRecord($1); free($2); freeRecord($4);
    }
;

lvalue:
    ID { 
        const char* type = lookupSymbol($1);
        if (type && strncmp(type, "ref", 3) == 0) {
            char* ref_code = cat("REF_", $1, "", "", "");
            $$ = createRecord(ref_code, strdup(type));
            free(ref_code);
        } else {
            $$ = createRecord($1, strdup(type ? type : "Unknown"));
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
        char *s;
        char* val = deref_if_needed($3);
        if (strncmp($1->code, "REF_", 4) == 0) {
            char* var_name = $1->code + 4;
            s = cat("    *", var_name, " = ", val, ";");
        } else {
            s = cat("    ", $1->code, " = ", val, ";");
        }
        $$ = createRecord(s, ""); free(s); free(val);
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
        char* val = deref_if_needed($2);
        if (strcmp($2->opt1, "Float") == 0) {
            s = cat("    printf(\"%f\\n\", ", val, ");", "", "");
        } else if (strcmp($2->opt1, "Int") == 0) {
            s = cat("    printf(\"%d\\n\", ", val, ");", "", "");
        } else {
            s = cat("    printf(\"unsupported_print_type\\n\");", "", "", "", "");
        }
        $$ = createRecord(s, ""); free(s); free(val); freeRecord($2);
    }
;

print_string_stmt:
    PRINT_STRING STRING_LIT SEMICOLON {
        char *str = $2;
        int len = strlen(str);
        char *clean_str = malloc(len - 1);
        strncpy(clean_str, str + 1, len - 2);
        clean_str[len - 2] = '\0';
        char *s = cat("    printf(\"", clean_str, "\\n\");", "", "");
        $$ = createRecord(s, ""); free(s); free(clean_str); free($2);
    }
;

return_stmt:
    RETURN expr SEMICOLON {
        char* val = deref_if_needed($2);
        char *s = cat("    return ", val, ";", "", "");
        $$ = createRecord(s, ""); free(s); free(val); freeRecord($2);
    }
  | RETURN SEMICOLON {
        $$ = createRecord("    return;", "");
    }
;

if_stmt: 
    IF LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        char *val = deref_if_needed($3);
        char *lend = new_label();
        char *cond = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body = $6->code;
        char *code = cat(cond, "\n", body, "\n", ""); // Alterado aqui
        char *final_code = cat(code, lend, ":", "", ""); // Nova chamada cat
        free(code); // Liberar a string temporária 'code'
        $$ = createRecord(final_code, ""); free(cond); free(lend); free(val); freeRecord($3); freeRecord($6); free(final_code);
    }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE {
        char *val = deref_if_needed($3);
        char *lels = new_label();
        char *lend = new_label();
        char *cond = cat("    if (!(", val, ")) goto ", lels, ";");
        char *if_body = $6->code;
        char *else_body = $10->code;
        
        // As chamadas cat problemáticas foram divididas em múltiplas chamadas:
        char *if_part_tmp = cat(cond, "\n", if_body, "", "");
        char *goto_lend_tmp = cat("\n    goto ", lend, ";\n", "", "");
        char *if_else_code_start = cat(if_part_tmp, goto_lend_tmp, "", "", "");
        free(if_part_tmp);
        free(goto_lend_tmp);
    
        char *else_part_tmp = cat(lels, ":\n", else_body, "", "");
        char *lend_label_tmp = cat("\n", lend, ":", "", "");
        char *final_if_else_code = cat(if_else_code_start, else_part_tmp, lend_label_tmp, "", "");
        free(if_else_code_start);
        free(else_part_tmp);
        free(lend_label_tmp);
    
        $$ = createRecord(final_if_else_code, ""); free(val); free(lels); free(lend); freeRecord($3); freeRecord($6); freeRecord($10); free(final_if_else_code);
    }
;

while_stmt:
    WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        char *val = deref_if_needed($3);
        char *lbegin = new_label();
        char *lend   = new_label();
        char *start = cat(lbegin, ":\n", "", "", "");
        char *cond  = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body  = $6->code;
        char *back  = cat("    goto ", lbegin, ";", "", "");
        char *end   = cat(lend, ":", "", "", "");
        char *tmp   = cat(start, cond, "\n", body, "\n");
        tmp = cat(tmp, back, "\n", end, "");
        $$ = createRecord(tmp, ""); free(tmp); free(val); freeRecord($3); freeRecord($6);
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


/******************************************************************
* CORREÇÃO: Removida a macro #define. A lógica foi expandida
* manualmente em cada regra de expressão abaixo.
******************************************************************/
expr:
      expr PLUS expr   {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " + ", s3, ")");
        $$ = createRecord(s, $1->opt1);
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr MINUS expr  {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " - ", s3, ")");
        $$ = createRecord(s, $1->opt1);
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr MUL expr    {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " * ", s3, ")");
        $$ = createRecord(s, $1->opt1);
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr DIV expr    {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " / ", s3, ")");
        $$ = createRecord(s, $1->opt1);
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr LT expr     {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " < ", s3, ")");
        $$ = createRecord(s, "Int");
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr LE expr     {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " <= ", s3, ")");
        $$ = createRecord(s, "Int");
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr GT expr     {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " > ", s3, ")");
        $$ = createRecord(s, "Int");
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr GE expr     {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " >= ", s3, ")");
        $$ = createRecord(s, "Int");
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr EQ expr     {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " == ", s3, ")");
        $$ = createRecord(s, "Int");
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | expr NE expr     {
        char* s1 = deref_if_needed($1);
        char* s3 = deref_if_needed($3);
        char *s = cat("(", s1, " != ", s3, ")");
        $$ = createRecord(s, "Int");
        free(s); free(s1); free(s3);
        freeRecord($1); freeRecord($3);
      }
    | LPAREN expr RPAREN { $$ = $2; }
    | AMPERSAND ID {
        char* addr_expr = cat("&", $2, "", "", "");
        const char* base_type = lookupSymbol($2);
        char* ptr_type_name = cat("ref", base_type, "", "", "");
        $$ = createRecord(addr_expr, ptr_type_name);
        free(addr_expr); free(ptr_type_name); free($2);
    }
    | ID {
        const char *t = lookupSymbol($1);
        $$ = createRecord($1, strdup(t ? t : "Unknown"));
        free($1); 
    }
    | INT_LIT          { char b[32]; sprintf(b,"%d",$1); $$=createRecord(strdup(b),(char*)"Int"); }
    | FLOAT_LIT        { char b[32]; sprintf(b,"%f",$1); $$=createRecord(strdup(b),(char*)"Float"); }
    | func_call        { $$ = $1; }
;

func_call:
    ID LPAREN arg_list_opt RPAREN {
        char *s = cat($1, "(", $3->code, ")", "");
        const char *type = "Unit"; 
        if (strcmp($1, "resto_divisao") == 0) {
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
    | arg_list COMMA expr { 
        // Na lista de argumentos, não dereferenciamos, apenas passamos o código.
        char *s=cat($1->code, ", ", $3->code, "", ""); 
        $$=createRecord(s,""); 
        free(s); 
        freeRecord($1); 
        freeRecord($3); 
    }
;

%%

// --- CÓDIGO AUXILIAR ---

void yyerror(const char *s) {
    fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
}

char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5) {
    size_t len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5) + 1;
    char *o = malloc(len);
    if (!o) { fprintf(stderr, "Erro de malloc!\n"); exit(1); }
    sprintf(o, "%s%s%s%s%s", s1, s2, s3, s4, s5);
    return o;
}

const char* map_type(const char* o) {
    if (strcmp(o, "Int") == 0) return "int";
    if (strcmp(o, "Float") == 0) return "float";
    return "void";
}

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
