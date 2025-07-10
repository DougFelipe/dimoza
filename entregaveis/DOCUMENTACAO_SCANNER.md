# Documentação do Scanner (scanner.l)

## Visão Geral

O arquivo `scanner.l` implementa o analisador léxico (lexer) do compilador usando a ferramenta **Flex**. Este componente é responsável por reconhecer padrões no código-fonte de entrada e convertê-los em tokens que serão processados pelo parser.

## Estrutura do Arquivo

### Seção de Definições 
```c
%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
```

- **parser.tab.h**: Contém as definições dos tokens gerados pelo Bison
- **Bibliotecas padrão**: Para funções de I/O, conversão e manipulação de strings

### Opções do Flex
```c
%option noyywrap
%option yylineno
```

- **noyywrap**: Desabilita a função `yywrap()`, assumindo que há apenas um arquivo de entrada
- **yylineno**: Habilita o contador automático de linhas para relatórios de erro

## Tokens Reconhecidos

### 1. Tipos de Dados Primitivos
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `"Unit"` | `UNIT` | Tipo unitário |
| `"Float"` | `FLOAT` | Tipo ponto flutuante |
| `"Int"` | `INT` | Tipo inteiro |


### 2. Palavras-chave Estruturais
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `"struct"` | `STRUCT` | Definição de estrutura |
| `"NEW"` | `NEW` | Alocação de memória |
| `"null"` | `NULL_LIT` | Literal nulo |
| `"ref"` | `REF` | Referência para ponteiro|
| `"."` | `DOT` | Operador de acesso |

### 4. Palavras-chave de Controle
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `"if"` | `IF` | Condicional |
| `"while"` | `WHILE` | Laço de repetição |
| `"return"` | `RETURN` | Retorno de função |

### 5. Funções de Saída
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `"print"` | `PRINT` | Impressão com quebra de linha |
| `"print_inline"` | `PRINT_INLINE` | Impressão sem quebra de linha |
| `"print_string"` | `PRINT_STRING` | Impressão de string |

### 6. Operadores Relacionais
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `"<="` | `LE` | Menor ou igual |
| `">="` | `GE` | Maior ou igual |
| `"=="` | `EQ` | Igualdade |
| `"!="` | `NE` | Diferença |
| `"<"` | `LT` | Menor que |
| `">"` | `GT` | Maior que |

### 7. Operadores Aritméticos e Especiais
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `"+"` | `PLUS` | Adição |
| `"-"` | `MINUS` | Subtração |
| `"*"` | `MUL` | Multiplicação |
| `"/"` | `DIV` | Divisão |
| `"<-"` | `ARROW_LEFT` | Atribuição/Seta esquerda |
| `"&"` | `AMPERSAND` | E comercial (referência) |

### 8. Delimitadores
| Padrão | Token | Descrição |
|--------|-------|-----------|
| `";"` | `SEMICOLON` | Ponto e vírgula |
| `","` | `COMMA` | Vírgula |
| `"("` | `LPAREN` | Parêntese esquerdo |
| `")"` | `RPAREN` | Parêntese direito |
| `"{"` | `LBRACE` | Chave esquerda |
| `"}"` | `RBRACE` | Chave direita |

## Padrões de Literais

### Números
```c
[0-9]+\.[0-9]+  { yylval.float_val = atof(yytext); return FLOAT_LIT; }
[0-9]+          { yylval.int_val   = atoi(yytext); return INT_LIT; }
```

- **FLOAT_LIT**: Números com ponto decimal (ex: `3.14`, `0.5`)
- **INT_LIT**: Números inteiros (ex: `42`, `0`, `123`)

### Strings
```c
\"[^\"]*\"       { yylval.str_val = strdup(yytext); return STRING_LIT; }
```

- **STRING_LIT**: Strings delimitadas por aspas duplas
- O padrão `[^\"]*` captura qualquer caractere exceto aspas duplas

### Identificadores
```c
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str_val = strdup(yytext); return ID; }
```

- **ID**: Identificadores que começam com letra ou underscore
- Podem conter letras, dígitos e underscores nas posições subsequentes

## Tratamento de Espaços em Branco e Comentários

```c
[ \t\r\n]+      { }      // Ignora espaços, tabs, quebras de linha
"//".* { }               // Ignora comentários de linha
```

- Espaços em branco são consumidos sem gerar tokens
- Comentários de linha (`//`) são ignorados até o final da linha

## Exemplo de Uso

Para um código de entrada:
```
Int x <- 42;
Float y <- 3.14;
print("Resultado:", x + y);
```

O scanner geraria a sequência de tokens:
`INT ID ARROW_LEFT INT_LIT SEMICOLON FLOAT ID ARROW_LEFT FLOAT_LIT SEMICOLON PRINT LPAREN STRING_LIT COMMA ID PLUS ID RPAREN SEMICOLON`

## Tratamento de Erros

O scanner implementa um tratamento de erros léxicos com as verificações abaixo:

### Tipos de Erros Detectados

1. **Caracteres Inválidos Específicos**:
   ```c
   [!@#$%^&|~`]    { 
       fprintf(stderr, "ERRO LÉXICO: caractere inválido '%s' na linha %d\n", yytext, yylineno); 
       exit(1); 
   }
   ```
   Detecta caracteres especiais não permitidos na linguagem.

2. **Strings Não Terminadas**:
   ```c
   \"[^\"]*$       { 
       fprintf(stderr, "ERRO LÉXICO: string não terminada na linha %d\n", yylineno); 
       exit(1); 
   }
   ```
   Captura strings que não foram fechadas com aspas duplas.

3. **Identificadores Inválidos**:
   ```c
   [0-9]+[a-zA-Z_]+ { 
       fprintf(stderr, "ERRO LÉXICO: identificador inválido '%s' na linha %d (não pode começar com número)\n", yytext, yylineno); 
       exit(1); 
   }
   ```
   Identifica tentativas de criar identificadores que começam com números.

4. **Caracteres Não Reconhecidos (Fallback)**:
   ```c
   .               { 
       fprintf(stderr, "ERRO LÉXICO: '%s' na linha %d\n", yytext, yylineno); 
       exit(1); 
   }
   ```
   Regra de fallback para qualquer caractere não reconhecido pelas regras anteriores.

### Recursos de tratamento de erros

- **Contador de Erros**: Mantém `error_count` global para estatísticas
- **Localização Precisa**: Usa `yylineno` para informar linha exata do erro
- **Mensagens Específicas**: Contexto detalhado para cada tipo de erro
