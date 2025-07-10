%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int error_count = 0;  // Contador de erros léxicos
%}

%option noyywrap
%option yylineno

%%

"Unit"          { return UNIT; }
"Float"         { return FLOAT; }
"Int"           { return INT; }
"Rational"      { return RATIONAL; }
"Matrix"        { return MATRIX; }
"BST"           { return BST; }
"struct"        { return STRUCT; }
"new"           { return NEW; }
"NEW"           { return NEW; }
"null"          { return NULL_LIT; }
"."             { return DOT; }
"ref"           { return REF; }

"print"         { return PRINT; }
"print_inline"  { return PRINT_INLINE; }
"print_string"  { return PRINT_STRING; }
"return"        { return RETURN; }
"if"            { return IF; }
"while"         { return WHILE; }

"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
">"             { return GT; }
"<-"            { return ARROW_LEFT; }
"&"             { return AMPERSAND; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

[0-9]+\.[0-9]+  { yylval.float_val = atof(yytext); return FLOAT_LIT; }
[0-9]+          { yylval.int_val   = atoi(yytext); return INT_LIT; }
\"[^\"]*\"       { yylval.str_val = strdup(yytext); return STRING_LIT; }
\"[^\"]*$       { fprintf(stderr, "ERRO LÉXICO: string não terminada na linha %d\n", yylineno); exit(1); }
[0-9]+[a-zA-Z_]+ { fprintf(stderr, "ERRO LÉXICO: identificador inválido '%s' na linha %d (não pode começar com número)\n", yytext, yylineno); exit(1); }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str_val = strdup(yytext); return ID; }

[ \t\r\n]+      { /* Ignora espaços em branco */ }
"//".* { /* Ignora comentários de linha */ }

[!@#$%^&|~`]    { 
    fprintf(stderr, "ERRO LÉXICO: caractere inválido '%s' na linha %d\n", yytext, yylineno); 
    error_count++;
    exit(1); 
}

.               { 
    fprintf(stderr, "ERRO LÉXICO: '%s' na linha %d\n", yytext, yylineno); 
    error_count++;
    exit(1); 
}

%%

/* Função para obter o número de erros léxicos */
int get_lex_error_count() {
    return error_count;
}
