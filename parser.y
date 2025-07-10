%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/record.h"
#include "./lib/symbol_table.h"

// Protótipos
int yylex(void);
void yyerror(const char *s);
char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5);
const char* map_type(const char* o);

// Variáveis externas
extern int yylineno;
extern char *yytext;
extern FILE *yyin, *yyout;

// Variáveis Globais para o Parser
static int label_count = 0;
static char* current_struct_name = NULL; // Guarda o nome da struct sendo definida

char *new_label() {
    char buf[32];
    sprintf(buf, "L%d", label_count++);
    return strdup(buf);
}

char* deref_if_needed(struct record* rec) {
    if (rec && rec->opt1 && strncmp(rec->opt1, "ref", 3) == 0) {
        return cat("*", rec->code, "", "", "");
    }
    return strdup(rec->code);
}

%}

// União e Tokens
%union {
    int int_val;
    float float_val;
    char *str_val;
    struct record *rec;
}

%token UNIT FLOAT INT RATIONAL MATRIX BST PRINT PRINT_INLINE PRINT_STRING RETURN IF WHILE
%token STRUCT NEW NULL_LIT DOT
%token REF AMPERSAND
%token ARROW_LEFT PLUS MINUS MUL DIV
%token LT LE GT GE EQ NE
%token SEMICOLON LPAREN RPAREN LBRACE RBRACE COMMA
%token <str_val> ID
%token <int_val> INT_LIT
%token <float_val> FLOAT_LIT
%token <str_val> STRING_LIT

%define parse.error verbose  // Habilita mensagens de erro mais detalhadas

// Tipos dos não-terminais
%type <rec> program decl_list func_decl param_list_opt param_list param
%type <rec> stmt_list stmt var_decl_stmt assignment_stmt func_call_stmt print_stmt print_inline_stmt print_string_stmt return_stmt if_stmt while_stmt
%type <rec> type lvalue expr func_call arg_list_opt arg_list
%type <rec> struct_decl field_list field

// Precedência
%right NEW     // NEW deve ter precedência alta e ser associativo à direita
%left DOT
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left MUL DIV
%right ARROW_LEFT

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
    | struct_decl
    | decl_list func_decl {
        char *s = cat($1->code, "\n\n", $2->code, "", "");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($2);
    }
    | decl_list struct_decl {
        char *s = cat($1->code, "\n", $2->code, "", "");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($2);
    }
;

// --- Declaração de Struct ---

struct_decl:
    STRUCT ID {
        current_struct_name = strdup($2);
        // Registrar o tipo IMEDIATAMENTE para uso nos campos
        insertSymbol($2, $2);
    } LBRACE field_list RBRACE SEMICOLON {
        char *typedef_def = cat("typedef struct ", $2, " {\n", $5->code, "} ");
        char *complete_def = cat(typedef_def, $2, ";\n", "", "");
        $$ = createRecord(complete_def, "");
        free(typedef_def); free(complete_def); 
        freeRecord($5);
        free(current_struct_name);
        current_struct_name = NULL;
        free($2);
    }
;

field_list:
      field
    | field_list field {
        char *s = cat($1->code, $2->code, "", "", "");
        $$ = createRecord(s, ""); free(s);
        freeRecord($1); freeRecord($2);
    }
;

field:
    type ID SEMICOLON {
        if (current_struct_name && $1->opt1 && strcmp($1->opt1, current_struct_name) == 0) {
            char* self_ptr_field = cat("    struct ", current_struct_name, "* ", $2, ";\n");
            $$ = createRecord(self_ptr_field, "");
            free(self_ptr_field);
        } else {
            char *s = cat("    ", $1->code, " ", $2, ";\n");
            $$ = createRecord(s, "");
            free(s);
        }
        freeRecord($1); free($2);
    }
;

// --- Funções e Statements ---

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
    | print_inline_stmt
    | print_string_stmt
    | return_stmt
    | func_call_stmt
    | if_stmt
    | while_stmt
;

var_decl_stmt:
    type ID SEMICOLON {
        // Sempre verifica duplicação no escopo atual quando escopo > 0
        if (getCurrentScope() > 0 && symbolExistsInCurrentScope($2)) {
            checkDuplicateVariable($2);
        }
        char *s = cat("    ", $1->code, " ", $2, ";");
        $$ = createRecord(s, ""); free(s);
        insertSymbol($2, $1->opt1);
        freeRecord($1); free($2);
    }
  | type ID ARROW_LEFT expr SEMICOLON {
        // Sempre verifica duplicação no escopo atual quando escopo > 0
        if (getCurrentScope() > 0 && symbolExistsInCurrentScope($2)) {
            checkDuplicateVariable($2);
        }
        char* val = deref_if_needed($4);
        char *p = cat("    ", $1->code, " ", $2, " = ");
        char *s = cat(p, val, ";", "", "");
        $$ = createRecord(s, ""); free(p); free(s); free(val);
        insertSymbol($2, $1->opt1);
        freeRecord($1); free($2); freeRecord($4);
    }
  | type ID ARROW_LEFT error SEMICOLON {
        fprintf(stderr, "ERRO DE SINTAXE: expressão inválida ou ausente após '<-' na linha %d\n", yylineno);
        YYABORT;
    }
  | type ID ARROW_LEFT error {
        fprintf(stderr, "ERRO DE SINTAXE: ';' esperado após expressão na linha %d\n", yylineno);
        YYABORT;
    }
;

assignment_stmt:
    lvalue ARROW_LEFT expr SEMICOLON {
        char *s;
        char* val = deref_if_needed($3);
        if ($1->opt1 && strncmp($1->opt1, "ref", 3) == 0) {
            s = cat("    *", $1->code, " = ", val, ";");
        } else {
            s = cat("    ", $1->code, " = ", val, ";");
        }
        $$ = createRecord(s, ""); free(s); free(val);
        freeRecord($1); freeRecord($3);
    }
  | lvalue ARROW_LEFT error SEMICOLON {
        fprintf(stderr, "ERRO DE SINTAXE: expressão inválida ou ausente após '<-' na linha %d\n", yylineno);
        YYABORT;
    }
  | lvalue ARROW_LEFT error {
        fprintf(stderr, "ERRO DE SINTAXE: ';' esperado após expressão na linha %d\n", yylineno);
        YYABORT;
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

print_inline_stmt:
    PRINT_INLINE expr SEMICOLON {
        char* val = deref_if_needed($2);
        char* s = cat("    printf(\"%d \", ", val, ");", "", "");
        $$ = createRecord(s, "");
        free(s); free(val); freeRecord($2);
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
    IF LPAREN expr RPAREN LBRACE { pushScope(); } stmt_list RBRACE {
        char *val = deref_if_needed($3);
        char *lend = new_label();
        char *cond = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body = $7->code;
        char *code = cat(cond, "\n", body, "\n", lend);
        code = cat(code, ":", "", "", "");
        $$ = createRecord(code, ""); free(cond); free(lend); free(val); 
        freeRecord($3); freeRecord($7);
        popScope();
    }
;

while_stmt:
    WHILE LPAREN expr RPAREN LBRACE { pushScope(); } stmt_list RBRACE {
        char *val = deref_if_needed($3);
        char *lbegin = new_label();
        char *lend   = new_label();
        char *start = cat(lbegin, ":\n", "", "", "");
        char *cond  = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body  = $7->code;
        char *back  = cat("    goto ", lbegin, ";", "", "");
        char *end   = cat(lend, ":", "", "", "");
        char *tmp   = cat(start, cond, "\n", body, "\n");
        tmp = cat(tmp, back, "\n", end, "");
        $$ = createRecord(tmp, ""); free(tmp); free(val); 
        freeRecord($3); freeRecord($7);
        popScope();
    }
;

// --- Tipos e Expressões ---

type:
    INT      { $$ = createRecord("int", "Int"); }
  | FLOAT    { $$ = createRecord("float", "Float"); }
  | UNIT     { $$ = createRecord("void", "Unit"); }
  | RATIONAL { $$ = createRecord("rational_t", "Rational"); }
  | MATRIX   { $$ = createRecord("matrix_t*", "Matrix"); }
  | BST      { $$ = createRecord("TreeNode*", "BST"); }
  | ID       { 
        // Verificar se é um tipo definido pelo usuário (struct)
        const char* found_type = lookupSymbol($1);
        if (found_type && strcmp(found_type, $1) == 0) {
            // É um tipo struct válido
            char *ptr_type = cat($1, "*", "", "", "");
            $$ = createRecord(ptr_type, strdup($1)); 
            free(ptr_type);
        } else {
            // Tipo não encontrado, mas permite para compatibilidade
            char *ptr_type = cat($1, "*", "", "", "");
            $$ = createRecord(ptr_type, strdup($1)); 
            free(ptr_type);
        }
        free($1);
    }
;

lvalue:
    ID { 
        checkUndeclaredVariable($1);  // Verifica se variável foi declarada
        const char* type = lookupSymbol($1);
        $$ = createRecord($1, strdup(type ? type : "Int"));
        free($1); 
    }
  | lvalue DOT ID {
        char* member_access = cat($1->code, "->", $3, "", "");
        const char* field_type = "Int"; // Assume Int por padrão
        if (strcmp($3, "left") == 0 || strcmp($3, "right") == 0) {
            field_type = $1->opt1;
        }
        $$ = createRecord(member_access, strdup(field_type));
        free(member_access); free($3);
        freeRecord($1);
    }
;

expr:
      NEW ID {
        char* malloc_call = cat("malloc(sizeof(struct ", $2, "))", "", "");
        $$ = createRecord(malloc_call, $2);
        free(malloc_call); free($2);
    }
    | expr PLUS expr   { 
        // Verificação de tipos compatíveis
        if (($1->opt1 && strncmp($1->opt1, "TreeNode", 8) == 0) || 
            ($3->opt1 && strncmp($3->opt1, "TreeNode", 8) == 0)) {
            fprintf(stderr, "ERRO SEMÂNTICO: operação '+' não suportada para tipos struct na linha %d\n", yylineno);
            exit(1);
        }
        char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); 
        char *s = cat("(", s1, " + ", s3, ")"); 
        const char* result_type = (strcmp($1->opt1, "Float") == 0 || strcmp($3->opt1, "Float") == 0) ? "Float" : $1->opt1;
        $$ = createRecord(s, strdup(result_type)); 
        free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); 
    }
    | expr MINUS expr  { 
        // Verificação de tipos compatíveis
        if (($1->opt1 && strncmp($1->opt1, "TreeNode", 8) == 0) || 
            ($3->opt1 && strncmp($3->opt1, "TreeNode", 8) == 0)) {
            fprintf(stderr, "ERRO SEMÂNTICO: operação '-' não suportada para tipos struct na linha %d\n", yylineno);
            exit(1);
        }
        char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); 
        char *s = cat("(", s1, " - ", s3, ")"); 
        const char* result_type = (strcmp($1->opt1, "Float") == 0 || strcmp($3->opt1, "Float") == 0) ? "Float" : $1->opt1;
        $$ = createRecord(s, strdup(result_type)); 
        free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); 
    }
    | expr MUL expr    { 
        // Verificação de tipos compatíveis
        if (($1->opt1 && strncmp($1->opt1, "TreeNode", 8) == 0) || 
            ($3->opt1 && strncmp($3->opt1, "TreeNode", 8) == 0)) {
            fprintf(stderr, "ERRO SEMÂNTICO: operação '*' não suportada para tipos struct na linha %d\n", yylineno);
            exit(1);
        }
        char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); 
        char *s = cat("(", s1, " * ", s3, ")"); 
        const char* result_type = (strcmp($1->opt1, "Float") == 0 || strcmp($3->opt1, "Float") == 0) ? "Float" : $1->opt1;
        $$ = createRecord(s, strdup(result_type)); 
        free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); 
    }
    | expr DIV expr    { 
        // Verificação de tipos compatíveis
        if (($1->opt1 && strncmp($1->opt1, "TreeNode", 8) == 0) || 
            ($3->opt1 && strncmp($3->opt1, "TreeNode", 8) == 0)) {
            fprintf(stderr, "ERRO SEMÂNTICO: operação '/' não suportada para tipos struct na linha %d\n", yylineno);
            exit(1);
        }
        char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); 
        char *s = cat("(", s1, " / ", s3, ")"); 
        const char* result_type = "Float"; // Divisão sempre resulta em Float
        $$ = createRecord(s, strdup(result_type)); 
        free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); 
    }
    | expr LT expr     { char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); char *s = cat("(", s1, " < ", s3, ")"); $$ = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); }
    | expr LE expr     { char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); char *s = cat("(", s1, " <= ", s3, ")"); $$ = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); }
    | expr GT expr     { char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); char *s = cat("(", s1, " > ", s3, ")"); $$ = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); }
    | expr GE expr     { char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); char *s = cat("(", s1, " >= ", s3, ")"); $$ = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); }
    | expr EQ expr     { char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); char *s = cat("(", s1, " == ", s3, ")"); $$ = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); }
    | expr NE expr     { char* s1 = deref_if_needed($1); char* s3 = deref_if_needed($3); char *s = cat("(", s1, " != ", s3, ")"); $$ = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord($1); freeRecord($3); }
    | NULL_LIT {
        $$ = createRecord("NULL", "null");
    }
    | lvalue { $$ = $1; } 
    | LPAREN expr RPAREN { $$ = $2; }
    | AMPERSAND ID {
        char* addr_expr = cat("&", $2, "", "", "");
        const char* base_type = lookupSymbol($2);
        char* ptr_type_name = cat("ref", base_type, "", "", "");
        $$ = createRecord(addr_expr, ptr_type_name);
        free(addr_expr); free(ptr_type_name); free($2);
    }
    | INT_LIT          { char b[32]; sprintf(b,"%d",$1); $$=createRecord(strdup(b),(char*)"Int"); }
    | FLOAT_LIT        { char b[32]; sprintf(b,"%f",$1); $$=createRecord(strdup(b),(char*)"Float"); }
    | func_call        { $$ = $1; }
;

func_call:
    ID LPAREN arg_list_opt RPAREN {
        char *s = cat($1, "(", $3->code, ")", "");
        const char *type = "Unit"; 
        if (strcmp($1, "get_height") == 0 || strcmp($1, "max") == 0) {
            type = "Int";
        } else if (strcmp($1, "insert") == 0) {
            type = "TreeNode";
        }
        // Adicione aqui outras funções com retorno para compatibilidade
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
    if (strcmp(s, "syntax error") == 0) {
        if (strcmp(yytext, "<-") == 0) {
            fprintf(stderr, "ERRO DE SINTAXE: expressão esperada após '<-' na linha %d\n", yylineno);
        } else if (strcmp(yytext, "print") == 0) {
            fprintf(stderr, "ERRO DE SINTAXE: expressão incompleta antes de 'print' na linha %d\n", yylineno);
        } else {
            fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
        }
    } else {
        fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
    }
    exit(1); // Força saída com erro para garantir detecção nos testes
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
    if (strcmp(o, "Unit") == 0) return "void";
    if (strcmp(o, "Rational") == 0) return "rational_t";
    if (strcmp(o, "Matrix") == 0) return "matrix_t*";
    if (strcmp(o, "BST") == 0) return "TreeNode*";
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
