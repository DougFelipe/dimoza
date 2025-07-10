# Documentação do Parser - Linguagem Dimoza

## 1. Apresentação da Linguagem Proposta

### 1.1 Introdução

**Linguagem Dimoza** é uma linguagem de programação projetada com foco em expressividade e manipulação de estruturas de dados, a linguagem foi idelizada para proporcionar clareza sintática, inspirada em linguagens como C, Python e R.

Seu compilador foi desenvolvido do zero, cobrindo todas as etapas do processo de compilação — desde a análise léxica até a verificação semântica.

### Arquitetura do Compilador

O compilador Dimoza segue uma arquitetura clássica de compilação:

```
Código Dimoza → Scanner → Parser → Gerador → Código C → GCC → Executável
```


Dimoza oferece suporte nativo a **tipos especializados**, como:

- **Números racionais**: permitindo operações precisas com frações
- **Matrizes**: fundamentais para aplicações científicas, gráficas e de engenharia;
- **Árvores binárias de busca (BSTs)**: essenciais para representação e manipulação eficiente de dados hierárquicos.



### 1.2 Objetivos e Características Principais
- **Simplicidade**: Sintaxe limpa e intuitiva, ideal para ensino de conceitos de compilação
- **Tipos Especializados**: Suporte nativo a números racionais, matrizes e árvores de busca binária
- **Verificação Semântica**: Sistema robusto de verificação de tipos e escopo
- **Geração de Código**: Tradução direta para C, permitindo execução eficiente
- **Passagem por Referência**: Suporte explícito a passagem de parâmetros por referência

### 1.3 Tipos de Dados Suportados

#### Tipos Básicos
- **Int**: Números inteiros de 32 bits
- **Float**: Números de ponto flutuante
- **Unit**: Tipo void (sem retorno)

#### Suporte a implementaçãp de tipos especializados 
- **Racionais**
- **Matrizes**
- **BST**

#### Tipos Definidos pelo Usuário
- **struct**: Estruturas personalizadas com campos nomeados

### 1.4 Sintaxe Básica e Exemplos

#### Declaração de Variáveis
```dimoza
Int x;                    // Declaração simples
Float y <- 3.14;         // Declaração com inicialização
```

#### Estruturas de Controle
```dimoza
// Condicional
if (x > 0) {
    print x;
}

// Laço de repetição
while (x > 0) {
    x <- x - 1;
}
```

#### Funções e Passagem por Referência
```dimoza
Unit modificar(ref Int valor) {
    valor <- valor + 10;
    return;
}

Unit main() {
    Int num <- 5;
    modificar(&num);  // Passagem por referência
    print num;        // Imprime 15
}
```

#### Estruturas Personalizadas
```dimoza
struct Pessoa {
    Int idade;
    Float altura;
};

Unit main() {
    Pessoa p <- new Pessoa;
    p.idade <- 25;
    p.altura <- 1.75;
}
```

## 2. Design da Implementação

### 2A. Transformação do Código-Fonte em Unidades Léxicas

O analisador léxico da linguagem Dimoza foi implementado utilizando **Flex**

#### Estrutura do Scanner (`scanner.l`)

##### Tokens Reconhecidos
```flex
// Palavras-chave da linguagem
"Unit"          { return UNIT; }
"Int"           { return INT; }
"Float"         { return FLOAT; }
"Rational"      { return RATIONAL; }
"Matrix"        { return MATRIX; }
"BST"           { return BST; }
"struct"        { return STRUCT; }
"new"           { return NEW; }
"if"            { return IF; }
"while"         { return WHILE; }
"ref"           { return REF; }

// Operadores especiais
"<-"            { return ARROW_LEFT; }    // Operador de atribuição
"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"&"             { return AMPERSAND; }     // Para referências
```

##### Tratamento de Literais
```flex
[0-9]+\.[0-9]+     { yylval.float_val = atof(yytext); return FLOAT_LIT; }
[0-9]+             { yylval.int_val = atoi(yytext); return INT_LIT; }
\"[^\"]*\"         { yylval.str_val = strdup(yytext); return STRING_LIT; }
```

##### Detecção de Erros Léxicos
O scanner implementa detecção específica de erros:

```flex
// String não terminada
\"[^\"]*$       { 
    fprintf(stderr, "ERRO LÉXICO: string não terminada na linha %d\n", yylineno); 
    exit(1); 
}

// Identificador inválido (começando com número)
[0-9]+[a-zA-Z_]+ { 
    fprintf(stderr, "ERRO LÉXICO: identificador inválido '%s' na linha %d\n", yytext, yylineno); 
    exit(1); 
}

// Caracteres inválidos
[!@#$%^&|~`]    { 
    fprintf(stderr, "ERRO LÉXICO: caractere inválido '%s' na linha %d\n", yytext, yylineno); 
    exit(1); 
}
```

#### Características 
- **Contador de Linhas**: `%option yylineno` para rastreamento preciso de erros
- **Tratamento de Comentários**: Suporte a comentários de linha (`//`)
- **Estatísticas de Erro**: Sistema de contagem de erros léxicos
- **Recuperação de Erro**: Saída controlada com mensagens informativas

### 2B. Representação de Símbolos, Tabela de Símbolos e Funções Associadas

#### Estrutura da Tabela de Símbolos (`symbol_table.h/c`)

##### Representação Interna
```c
typedef struct Symbol {
    char* name;           // Nome do identificador
    char* type;           // Tipo da variável/função
    int scope;            // Nível de escopo
    struct Symbol* next;  // Lista encadeada
} Symbol;

// Estrutura principal da tabela
typedef struct SymbolTable {
    Symbol* head;         // Início da lista
    int current_scope;    // Escopo atual
    int max_scope;        // Maior escopo já utilizado
} SymbolTable;
```

##### Funções de Manipulação
```c
// Inicialização e cleanup
void initSymbolTable();
void freeSymbolTable();

// Gerenciamento de escopo
void pushScope();         // Entra em novo escopo
void popScope();          // Sai do escopo atual
int getCurrentScope();    // Retorna escopo atual

// Operações com símbolos
void insertSymbol(const char* name, const char* type);
const char* lookupSymbol(const char* name);
int symbolExists(const char* name);
int symbolExistsInCurrentScope(const char* name);
```

#### Verificações Semânticas Implementadas
```c
// Verifica se variável foi declarada antes do uso
void checkUndeclaredVariable(const char* name) {
    if (!symbolExists(name)) {
        fprintf(stderr, "ERRO SEMÂNTICO: variável '%s' não declarada na linha %d\n", 
                name, yylineno);
        exit(1);
    }
}

// Verifica duplicação no mesmo escopo
void checkDuplicateVariable(const char* name) {
    if (symbolExistsInCurrentScope(name)) {
        fprintf(stderr, "ERRO SEMÂNTICO: variável '%s' já declarada no escopo atual\n", name);
        exit(1);
    }
}
```

#### Sistema de Records (`record.h/c`)
Para facilitar a passagem de informações entre as regras do parser:

```c
struct record {
    char* code;     // Código C gerado
    char* opt1;     // Informação adicional (tipo, rótulo, etc.)
};

struct record* createRecord(char* code, char* opt1);
void freeRecord(struct record* rec);
```

### 2C. Tratamento de Estruturas Condicionais e de Repetição

O parser implementa estruturas de controle através de geração de rótulos e saltos condicionais em C.

#### Estrutura Condicional (if)
```yacc
if_stmt:
    IF LPAREN expr RPAREN LBRACE { pushScope(); } stmt_list RBRACE {
        char *val = deref_if_needed($3);
        char *lend = new_label();                    // Gera rótulo único
        char *cond = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body = $7->code;
        char *code = cat(cond, "\n", body, "\n", lend);
        code = cat(code, ":", "", "", "");
        $$ = createRecord(code, "");
        // ... cleanup e popScope()
    }
;
```

**Código C Gerado:**
```c
// Para: if (x > 0) { print x; }
if (!(x > 0)) goto L1;
    printf("%d\n", x);
L1:
```

#### Estrutura de Repetição (while)
```yacc
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
        // Concatena todas as partes
        $$ = createRecord(final_code, "");
        // ... cleanup e popScope()
    }
;
```

**Código C Gerado:**
```c
// Para: while (x > 0) { x <- x - 1; }
L2:
    if (!(x > 0)) goto L3;
    x = x - 1;
    goto L2;
L3:
```

#### Gerenciamento de Escopo
Ambas as estruturas automaticamente:
- **Abrem novo escopo** antes de processar o corpo
- **Fecham o escopo** após o processamento
- **Verificam declarações** dentro do bloco
- **Permitem sombreamento** de variáveis de escopos externos

### 2D. Tratamento de Subprogramas

A linguagem Dimoza oferece suporte completo a funções com passagem de parâmetros por valor e por referência.

#### Declaração de Funções
```yacc
func_decl:
    type ID LPAREN param_list_opt RPAREN LBRACE stmt_list RBRACE {
        const char *rt = strcmp($2, "main")==0 ? "int" : $1->code;
        char *header = cat(rt, " ", $2, "(", $4->code);
        char *body = cat(header, ") {\n", $7->code, "}\n", "");
        $$ = createRecord(body, "");
        // ... cleanup
    }
;
```

#### Passagem de Parâmetros

##### Por Valor (Padrão)
```yacc
param:
    type ID {
        char *param_decl = cat($1->code, " ", $2, "", "");
        $$ = createRecord(param_decl, $1->opt1);
        insertSymbol($2, $1->opt1);  // Registra na tabela de símbolos
    }
```

##### Por Referência (ref)
```yacc
param:
    REF type ID {
        const char* c_type = map_type($2->opt1);
        char* ptr_type = cat(c_type, "*", "", "", "");      // Gera tipo ponteiro
        char* param_decl = cat(ptr_type, " ", $3, "", "");
        char* lang_type = cat("ref", $2->opt1, "", "", "");  // Marca como referência
        $$ = createRecord(param_decl, lang_type);
        insertSymbol($3, lang_type);
    }
```

#### Chamadas de Função
```yacc
func_call:
    ID LPAREN arg_list_opt RPAREN {
        char *call = cat($1, "(", $3->code, ")", "");
        // Determina tipo de retorno baseado na função
        const char *return_type = "Unit";
        if (strcmp($1, "get_height") == 0) return_type = "Int";
        if (strcmp($1, "insert") == 0) return_type = "TreeNode";
        $$ = createRecord(call, (char*)return_type);
    }
```

#### Tratamento de Referências
A linguagem implementa desreferenciamento automático quando necessário:

```c
char* deref_if_needed(struct record* rec) {
    if (rec && rec->opt1 && strncmp(rec->opt1, "ref", 3) == 0) {
        return cat("*", rec->code, "", "", "");  // Adiciona * para desreferenciar
    }
    return strdup(rec->code);                     // Retorna valor direto
}
```

#### Mapeamento de Tipos
```c
const char* map_type(const char* orig_type) {
    if (strcmp(orig_type, "Int") == 0) return "int";
    if (strcmp(orig_type, "Float") == 0) return "float";
    if (strcmp(orig_type, "Unit") == 0) return "void";
    if (strcmp(orig_type, "Rational") == 0) return "rational_t";
    if (strcmp(orig_type, "Matrix") == 0) return "matrix_t*";
    if (strcmp(orig_type, "BST") == 0) return "TreeNode*";
    return "void";
}
```

### 2E. Verificações Realizadas

#### 2E.1 Verificação de Tipos

##### Operações Aritméticas
```yacc
expr PLUS expr {
    // Verificação de compatibilidade de tipos
    if (($1->opt1 && strncmp($1->opt1, "TreeNode", 8) == 0) || 
        ($3->opt1 && strncmp($3->opt1, "TreeNode", 8) == 0)) {
        fprintf(stderr, "ERRO SEMÂNTICO: operação '+' não suportada para tipos struct na linha %d\n", yylineno);
        exit(1);
    }
    
    // Coerção automática de tipos
    const char* result_type = (strcmp($1->opt1, "Float") == 0 || strcmp($3->opt1, "Float") == 0) 
                              ? "Float" : $1->opt1;
    
    char* code = cat("(", $1->code, " + ", $3->code, ")");
    $$ = createRecord(code, strdup(result_type));
}
```

##### Verificação de Divisão
```yacc
expr DIV expr {
    // Divisão sempre resulta em Float para evitar perda de precisão
    const char* result_type = "Float";
    char* code = cat("(", $1->code, " / ", $3->code, ")");
    $$ = createRecord(code, strdup(result_type));
}
```

#### 2E.2 Verificação de Declarações

##### Variáveis Não Declaradas
```c
void checkUndeclaredVariable(const char* name) {
    if (!symbolExists(name)) {
        fprintf(stderr, "ERRO SEMÂNTICO: variável '%s' não declarada na linha %d\n", 
                name, yylineno);
        exit(1);
    }
}
```

##### Declarações Duplicadas
```yacc
var_decl_stmt:
    type ID ARROW_LEFT expr SEMICOLON {
        // Verifica duplicação apenas no escopo atual
        if (getCurrentScope() > 0 && symbolExistsInCurrentScope($2)) {
            checkDuplicateVariable($2);
        }
        // ... código de geração
        insertSymbol($2, $1->opt1);
    }
```

#### 2E.3 Verificação de Escopo

##### Gerenciamento Automático
- **Escopo Global**: Funções e tipos definidos pelo usuário
- **Escopo Local**: Variáveis dentro de funções
- **Escopo de Bloco**: Variáveis dentro de `if` e `while`

##### Regras de Visibilidade
```c
const char* lookupSymbol(const char* name) {
    Symbol* current = table.head;
    Symbol* found = NULL;
    
    // Busca do escopo atual para o mais externo
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (!found || current->scope > found->scope) {
                found = current;  // Prioriza escopo mais interno
            }
        }
        current = current->next;
    }
    
    return found ? found->type : NULL;
}
```

#### 2E.4 Verificação de Sintaxe

##### Recuperação de Erros
```yacc
var_decl_stmt:
    type ID ARROW_LEFT error SEMICOLON {
        fprintf(stderr, "ERRO DE SINTAXE: expressão inválida após '<-' na linha %d\n", yylineno);
        YYABORT;
    }
  | type ID ARROW_LEFT error {
        fprintf(stderr, "ERRO DE SINTAXE: ';' esperado após expressão na linha %d\n", yylineno);
        YYABORT;
    }
```

##### Tratamento de Strings
```flex
\"[^\"]*$       { 
    fprintf(stderr, "ERRO LÉXICO: string não terminada na linha %d\n", yylineno); 
    exit(1); 
}
```

#### 2E.5 Verificações Específicas da Linguagem

##### Estruturas Definidas pelo Usuário
```yacc
field:
    type ID SEMICOLON {
        // Verifica auto-referência em structs (ponteiro para si mesma)
        if (current_struct_name && $1->opt1 && strcmp($1->opt1, current_struct_name) == 0) {
            char* self_ptr_field = cat("    struct ", current_struct_name, "* ", $2, ";\n");
            $$ = createRecord(self_ptr_field, "");
        } else {
            // Campo normal
            char* field_decl = cat("    ", $1->code, " ", $2, ";\n");
            $$ = createRecord(field_decl, "");
        }
    }
```

##### Verificação de Referências
```yacc
AMPERSAND ID {
    checkUndeclaredVariable($2);  // Verifica se variável existe
    char* addr_expr = cat("&", $2, "", "", "");
    const char* base_type = lookupSymbol($2);
    char* ptr_type = cat("ref", base_type, "", "", "");
    $$ = createRecord(addr_expr, ptr_type);
}
```

#### 2E.6 Resumo das Verificações Implementadas

| Tipo de Verificação | Descrição | Momento |
|---------------------|-----------|---------|
| **Tipos Compatíveis** | Operações aritméticas e lógicas | Tempo de compilação |
| **Variáveis Declaradas** | Uso antes da declaração | Análise semântica |
| **Duplicação de Identificadores** | No mesmo escopo | Declaração |
| **Escopo de Visibilidade** | Acesso a variáveis | Resolução de nomes |
| **Sintaxe de Atribuição** | Operador `<-` e expressões | Análise sintática |
| **Estruturas de Controle** | Condições e blocos | Geração de código |
| **Passagem de Parâmetros** | Compatibilidade valor/ref | Chamadas de função |
| **Auto-referência em Structs** | Ponteiros para próprio tipo | Definição de tipos |

## 3. Instruções de Uso do Compilador

### 3.1 Pré-requisitos e Dependências

#### Software Necessário
- **GCC** (GNU Compiler Collection) 
- **Flex** (Fast Lexical Analyzer Generator) 
- **Bison** (GNU Parser Generator) 
- **Make** (GNU Make) 

#### Verificação das Dependências
```bash
# Verificar se as ferramentas estão instaladas
gcc --version
flex --version
bison --version
make --version
```

#### Instalação no Ubuntu/Debian
```bash
sudo apt update
sudo apt install gcc flex bison make
```

#### Instalação no Windows
- **Opção 1**: MSys2/MinGW-w64
- **Opção 2**: WSL (Windows Subsystem for Linux)
- **Opção 3**: Cygwin

### 3.2 Compilação do Compilador

#### Usando Makefile (Recomendado)
```bash
# Clone ou navegue até o diretório do projeto
cd /caminho/para/projeto

# Compilação automática
make

# Ou compilação com verbose para debug
make clean && make
```

#### Compilação Manual (Passo a Passo)
```bash
# 1. Gerar o parser
bison -d parser.y

# 2. Gerar o scanner  
flex scanner.l

# 3. Compilar todas as dependências
gcc -o compiler parser.tab.c lex.yy.c lib/symbol_table.c lib/record.c -lfl

# 4. Verificar se foi gerado corretamente
ls -la compiler
```

#### Estrutura Gerada
```
projeto/
├── parser.tab.c       # Parser gerado pelo Bison
├── parser.tab.h       # Headers do parser
├── lex.yy.c          # Scanner gerado pelo Flex
├── compiler          # Executável final
└── parser.output     # Arquivo de debug (opcional)
```

### 3.3 Uso do Compilador

#### Sintaxe Básica
```bash
./compiler <arquivo_entrada.txt> <arquivo_saida.c>
```

#### Exemplos de Uso
```bash
# Compilar um programa básico
./compiler problema1.txt saida1.c

# Compilar programa com estruturas complexas
./compiler programa_bst.txt bst_output.c

# Compilar com verificação de sintaxe
./compiler teste_sintaxe.txt /dev/null
```

#### Fluxo Completo de Compilação e Execução
```bash
# 1. Compilar código Dimoza para C
./compiler problema1.txt saida1.c

# 2. Compilar código C gerado
gcc -o programa saida1.c

# 3. Executar programa final
./programa
```

### 3.4 Exemplos Práticos

#### Programa Básico (problema1.txt)
```dimoza
Unit main() {
    Float x <- 3.0;
    Float y <- 2.5;
    Int c <- 10;
    Float resultado <- x * x - y + c;
    print resultado;
}
```

#### Compilação e Execução
```bash
# Compilar
./compiler problema1.txt saida1.c

# Verificar código C gerado
cat saida1.c

# Compilar para executável
gcc -o exemplo1 saida1.c

# Executar
./exemplo1
# Saída: 16.500000
```


### 3.5 Scripts de Automação

```bash
# Script para compilar e executar automaticamente
#!/bin/bash
echo "Compilando $1..."
./compiler "$1" temp_output.c
if [ $? -eq 0 ]; then
    gcc -o temp_program temp_output.c lib/*.c
    echo "Executando..."
    ./temp_program
    rm temp_output.c temp_program
else
    echo "Erro na compilação!"
fi
```

## 4. Testes Automatizados

### 4.1 Visão Geral do Sistema de Testes

O compilador Dimoza implementa um sistema abrangente de testes automatizados localizado no diretório `/testes`. Este sistema foi projetado para validar todos os aspectos críticos do compilador, desde a análise léxica até a geração de código, garantindo a robustez e confiabilidade da implementação.

### 4.2 Estrutura dos Testes

#### Organização dos Arquivos
```
testes/
├── teste_erro_lexico.txt              # Detecção de erros léxicos
├── teste_erro_sintatico.txt           # Detecção de erros sintáticos  
├── teste_derivacao_regras.txt         # Derivação sintática
├── teste_conflitos_precedencia.txt    # Resolução de precedência
├── teste_precedencia.txt              # Operadores e precedência
├── teste_variavel_omitida.txt         # Variáveis não declaradas
├── teste_variavel_duplicada_mesmo_escopo.txt  # Duplicação de identificadores
├── teste_variavel_escopos_distintos.txt       # Escopos diferentes
├── teste_variavel_escopos_aninhados.txt       # Escopos aninhados
├── teste_estruturas_controle.txt      # If e while
├── teste_coercoes_permitidas.txt      # Conversões de tipo
├── teste_tipos_incompativeis.txt      # Incompatibilidade de tipos
├── teste_tipos_especializados.txt     # Tipos Rational, Matrix, BST
├── teste_passagem_parametros.txt      # Passagem por valor
├── teste_referencia.txt               # Passagem por referência
├── teste_id_error.txt                 # Identificadores inválidos
└── teste_string_error.txt             # Strings malformadas
```

### 4.3 Execução dos Testes

#### Script Unificado
```bash
# Executar todos os testes
./run_tests.sh

# Exemplo de saída:
=== EXECUÇÃO DE TODOS OS TESTES DE AVALIAÇÃO ===

=== 1. ESTRUTURA SINTÁTICA ===
Teste: erro_lexico          PASSOU
Teste: erro_sintatico       PASSOU
Teste: derivacao_regras     PASSOU
Teste: conflitos_precedencia PASSOU
Teste: precedencia          PASSOU

=== 2. VARIÁVEIS ===
Teste: variavel_omitida              PASSOU
Teste: variavel_duplicada_mesmo_escopo PASSOU
Teste: variavel_escopos_distintos    PASSOU
Teste: variavel_escopos_aninhados    PASSOU
Teste: estruturas_controle           PASSOU

=== 3. EXPRESSÕES ===
Teste: coercoes_permitidas    PASSOU
Teste: tipos_incompativeis    PASSOU
Teste: tipos_especializados   PASSOU

=== 4. PASSAGEM DE PARÂMETROS ===
Teste: passagem_parametros    PASSOU
Teste: referencia            PASSOU

=== TESTES ADICIONAIS ===
Teste: id_error              PASSOU
Teste: string_error          PASSOU

=== RELATÓRIO FINAL ===
Total de testes: 17
Testes aprovados: 17
Testes falharam: 0
RESULTADO: TODOS OS TESTES PASSARAM!
Taxa de sucesso: 100%
```

### 4.4 Categorias de Teste
### Detalhes em entregaveis\DOCUMENTACAO_TESTES.md

#### 4.5.1 Cobertura 
Os testes automatizados cobrem os critérios de avaliação:
- ✅ **5 testes** de estrutura sintática
- ✅ **5 testes** de variáveis e escopo  
- ✅ **3 testes** de expressões e tipos
- ✅ **2 testes** de passagem de parâmetros
- ✅ **2 testes** adicionais de robustez



#### 4.5.2 Execução dos testes
```bash
# Validação completa em uma única execução
./run_tests.sh

# Relatório final confirma:
# - Taxa de sucesso: 100%
```

### 4.6 Conclusão sobre os Testes

**O compilador Dimoza passou em todos os testes**

---

## Observações Finais

### Compatibilidade com Bibliotecas C

Embora o parser da linguagem Dimoza reconheça e suporte a integração com bibliotecas externas da linguagem C, **todos os problemas propostos e exemplos apresentados foram implementados exclusivamente utilizando a sintaxe e recursos nativos da linguagem Dimoza**.
