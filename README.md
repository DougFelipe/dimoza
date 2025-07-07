# Compilador Dimoza

## Visão Geral
Este projeto implementa um compilador completo para uma linguagem de programação Dimoza que suporta tipos especializados como números racionais, matrizes e árvores de busca binária (BST). O compilador traduz código fonte para C, permitindo execução eficiente.

## Características da Linguagem
- **Tipos básicos**: Int, Float, Unit (void)
- **Tipos especializados**: Rational, Matrix, BST
- **Operador de atribuição**: `<-` (seta esquerda)
- **Estruturas de controle**: if, while
- **Funções**: com suporte a passagem por referência (`ref`)
- **Comentários**: `//` (linha)

## Estrutura do Projeto
```
dimoza/
├── scanner.l              # Analisador léxico (Flex)
├── parser.y               # Analisador sintático (Bison)
├── makefile               # Automação de compilação
├── compiler.exe           # Compilador executável
├── lib/                   # Bibliotecas auxiliares
│   ├── symbol_table.h/c   # Tabela de símbolos
│   ├── record.h/c         # Estruturas de dados
│   ├── rational.h/c       # Operações com racionais
│   ├── matrix.h/c         # Operações com matrizes
│   └── bst.h/c           # Árvores de busca binária
├── tests/                 # Arquivos de teste
├── problema[1-6].txt      # Exemplos de programas
└── DOCUMENTACAO_*.md      # Documentação detalhada
```

## Compilação e Uso

## Requisitos do Sistema
- GCC ou compilador C equivalente
- Flex (gerador de analisadores léxicos)
- Bison/Yacc (gerador de analisadores sintáticos)
- Make (para automação)
- 
###  Compilação do Compilador

####  Usando Makefile
```bash
make
```
Este comando executa:
1. `bison -d parser.y` - Gera parser.tab.c e parser.tab.h
2. `flex scanner.l` - Gera lex.yy.c
3. `gcc -o compiler.exe parser.tab.c lex.yy.c lib/*.c` - Compila o executável

#### 3.2.2 Compilação Manual
```bash
# Gerar parser
bison -d parser.y

# Gerar scanner
flex scanner.l

# Compilar todas as bibliotecas
gcc -c lib/symbol_table.c -o lib/symbol_table.o
gcc -c lib/record.c -o lib/record.o
gcc -c lib/rational.c -o lib/rational.o
gcc -c lib/matrix.c -o lib/matrix.o
gcc -c lib/bst.c -o lib/bst.o

# Compilar o compilador
gcc -o compiler.exe parser.tab.c lex.yy.c lib/*.o
```

###  Uso do Compilador

#### Sintaxe de Comando
```bash
./compiler.exe <arquivo_entrada> <arquivo_saida>
```

**Parâmetros:**
- `arquivo_entrada`: Arquivo fonte na linguagem definida (.txt)
- `arquivo_saida`: Arquivo C gerado (.c)

#### Exemplo de Uso
```bash
# Compilar programa
./compiler.exe programa.txt saida.c

# Compilar o código C gerado
gcc saida.c -o programa_final

# Executar programa final
./programa_final
```


## Executar Automaticamente Problemas 1-6
```bash
# Executar todos os testes de avaliação
chmod +x run_tests.sh
./run_tests.sh
```

## Executar Automaticamente Testes de Avaliação
```bash
# Executar todos os testes de avaliação
chmod +x teste_avaliacao.sh
./teste_avaliacao.sh
```




## Arquivos de Teste
- `problema1.txt`: Operações aritméticas básicas
- `problema2.txt`: Estruturas de controle (if/while)
- `problema3.txt`: Operações com matrizes
- `problema4.txt`: Números racionais
- `problema5.txt`: Árvores de busca binária
- `problema6.txt`: Funções e referências

## Testes de Avaliação Específicos
- `teste_erro_lexico.txt`: Validação de detecção de erros léxicos
- `teste_erro_sintatico.txt`: Validação de detecção de erros sintáticos
- `teste_precedencia.txt`: Validação de precedência de operadores
- `teste_referencia.txt`: Validação de passagem por referência
- `teste_tipos_especializados.txt`: Validação de tipos especializados
- `teste_estruturas_controle.txt`: Validação de estruturas de controle
- `teste_avaliacao.sh`: Script para executar todos os testes de avaliação



## Documentação Completa
- `DOCUMENTACAO_COMPILADOR.md`: Documentação completa do compilador
- `DOCUMENTACAO_SCANNER.md`: Documentação do analisador léxico
- `DOCUMENTACAO_PARSER.md`: Documentação do analisador sintático
- `AVALIACAO_TECNICA.md`: Análise técnica dos aspectos de avaliação
- `GUIA_AVALIACAO.md`: Guia completo para avaliação do projeto
