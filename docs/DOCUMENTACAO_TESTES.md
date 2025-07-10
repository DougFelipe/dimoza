# Documentação dos Testes de Avaliação do Compilador

## Visão Geral

Este documento apresenta a suíte completa de testes implementada para validar todos os critérios de avaliação do compilador. Os testes cobrem: estrutura sintática, variáveis, expressões e passagem de parâmetros.


## Como Executar os Testes

### Pré-requisitos

1. **Compilador**: Certifique-se de que o compilador está compilado:
   ```bash
   make
   ```

2. **Permissões**: No Linux/WSL, dê permissão de execução aos scripts:
   ```bash
   chmod +x run_tests.sh
   chmod +x testes/*.sh
   ```

### Execução dos Testes

```bash
# Linux/WSL
./run_tests.sh

# Windows (PowerShell)
bash run_tests.sh
```

O script executa automaticamente todos os testes da pasta `/testes` e exibe se cada teste passou ou falhou.

### Interpretação dos Resultados

**Relatório Final:**
O script sempre exibe um relatório final com:
- Total de testes executados
- Número de testes aprovados
- Taxa de sucesso
- Status geral (PASSOU/FALHOU)

### Solução de Problemas

**Erro: "Compilador não encontrado"**
- Execute `make` primeiro para compilar o compilador

**Erro: "Permission denied"**
- Execute `chmod +x run_tests.sh` (Linux/WSL)


## 1. Estrutura Sintática

### (A) Detecção de Erros Léxicos e Sintáticos

#### Teste de Erro Léxico: `teste_erro_lexico.txt`
```
// Teste de erro léxico - caractere inválido
Unit main() {
    Int x <- 5;
    Int y @ 10;  // Erro: caractere '@' inválido
    print x;
}
```
**Objetivo**: Verificar se o scanner detecta caracteres inválidos.
**Resultado Esperado**: `ERRO LÉXICO: caractere inválido '@' na linha 4`

#### Teste de Erro Sintático: `teste_erro_sintatico.txt`
```
// Teste de erro sintático - expressão incompleta
Unit main() {
    Int x <-   // Erro: expressão incompleta após <-
    print x;
}
```
**Objetivo**: Verificar se o parser detecta expressões incompletas.
**Resultado Esperado**: `ERRO DE SINTAXE: syntax error, unexpected PRINT na linha 4`

### (B) Derivação das Regras Sintáticas

#### Teste de Derivação: `teste_derivacao_regras.txt`
```
// Teste 1B: Derivação de Regras Sintáticas
Unit main() {
    // Declaração de variáveis seguindo as regras gramaticais
    Int x <- 10;
    Float y <- 3.14;
    
    // Estruturas de controle seguindo as regras
    if (x > 5) {
        print y;
        while (x > 0) {
            x <- x - 1;
        }
    }
    
    return;
}
```
**Objetivo**: Demonstrar que o programa pode ser derivado completamente das regras sintáticas.
**Resultado Esperado**: Compilação bem-sucedida com código C gerado.

### (C) Conflitos Shift-Reduce

#### Teste de Precedência: `teste_conflitos_precedencia.txt`
```
// Teste 1C: Conflitos Shift-Reduce
Unit main() {
    Int a <- 5;
    Int b <- 3;
    Int c <- 2;
    
    // Expressão com múltiplos operadores para testar precedência
    Int result <- a + b * c - 1;  // Deve ser: a + (b * c) - 1 = 10
    print result;
    
    // Expressão com operadores relacionais e aritméticos
    if (a + b > c * 2) {  // Deve ser: (a + b) > (c * 2) = true
        print_string "Precedencia correta!";
    }
    
    return;
}
```
**Objetivo**: Verificar se conflitos shift-reduce são resolvidos corretamente com precedência.
**Resultado Esperado**: Compilação bem-sucedida seguindo as regras de precedência.

#### Teste de Conflitos de Precedência: `teste_conflitos_precedencia.txt`
```
// Teste 1C: Conflitos Shift-Reduce
// Construção que pode gerar conflitos de precedência
Unit main() {
    Int a <- 5;
    Int b <- 3;
    Int c <- 2;
    
    // Expressão com múltiplos operadores para testar precedência
    Int result <- a + b * c - 1;  // Deve ser: a + (b * c) - 1 = 5 + 6 - 1 = 10
    print result;
    
    // Expressão com operadores relacionais e aritméticos
    if (a + b > c * 2) {  // Deve ser: (a + b) > (c * 2) = 8 > 4 = true
        print_string "Precedencia correta!";
    }
    
    return;
}
```
**Objetivo**: Verificar resolução de conflitos shift-reduce em expressões complexas.
**Resultado Esperado**: Compilação bem-sucedida com precedência correta.

## 2. Variáveis

### (A) Variáveis Omitidas

#### Teste de Variável Não Declarada: `teste_variavel_omitida.txt`
```
// Teste 2A: Variáveis omitidas - detectar erros
Unit main() {
    Int x <- 10;
    print y;  // ERRO: y não foi declarada
    return;
}
```
**Objetivo**: Detectar uso de variáveis não declaradas.
**Resultado Esperado**: `ERRO SEMÂNTICO: variável 'y' não declarada`

### (B) Variáveis Duplicadas no Mesmo Escopo

#### Teste de Duplicação: `teste_variavel_duplicada_mesmo_escopo.txt`
```
// Teste 2B: Variáveis duplicadas no mesmo escopo
Unit main() {
    Int condition <- 1;
    if (condition > 0) {
        Int x <- 10;
        Float x <- 3.14;  // ERRO: x já foi declarada no mesmo escopo
        print x;
    }
    return;
}
```
**Objetivo**: Detectar variáveis declaradas mais de uma vez no mesmo escopo.
**Resultado Esperado**: `ERRO SEMÂNTICO: variável 'x' já declarada no escopo atual`

### (C) Variáveis em Escopos Distintos (Não-aninhados)

#### Teste de Escopos Distintos: `teste_variavel_escopos_distintos.txt`
```
// Teste 2C: Variáveis duplicadas em escopos distintos
Unit main() {
    Int condition1 <- 1;
    Int condition2 <- 1;
    
    if (condition1 > 0) {
        Int x <- 10;  // x no primeiro escopo
        print x;
    }
    
    if (condition2 > 0) {
        Int x <- 20;  // x no segundo escopo (OK)
        print x;
    }
    
    return;
}
```
**Objetivo**: Verificar que variáveis com mesmo nome podem existir em escopos distintos.
**Resultado Esperado**: Compilação bem-sucedida.

### (D) Variáveis em Escopos Aninhados (Shadowing)

#### Teste de Shadowing: `teste_variavel_escopos_aninhados.txt`
```
// Teste 2D: Variáveis duplicadas em escopos aninhados
Unit main() {
    Int x <- 10;  // x no escopo externo
    print x;      // Deve imprimir 10
    
    if (x > 5) {
        Int x <- 20;  // x no escopo interno (shadowing)
        print x;      // Deve imprimir 20
    }
    
    print x;      // Deve imprimir 10 (escopo externo)
    return;
}
```
**Objetivo**: Verificar comportamento correto de shadowing em escopos aninhados.
**Resultado Esperado**: Compilação bem-sucedida com shadowing correto.

## 3. Expressões

### (A) Coerções Permitidas

#### Teste de Coerções: `teste_coercoes_permitidas.txt`
```
// Teste 3A: Coerções permitidas - compatibilização de tipos
Unit main() {
    Int a <- 10;
    Float b <- 3.14;
    
    // Coerções permitidas (Int para Float)
    Float result1 <- a + b;     // Int + Float = Float
    Float result2 <- a * 2.5;   // Int * Float = Float
    Int result3 <- a + 5;       // Int + Int = Int
    
    print result1;
    print result2;
    print result3;
    
    return;
}
```
**Objetivo**: Verificar que coerções entre tipos compatíveis funcionam corretamente.
**Resultado Esperado**: Compilação bem-sucedida com coerções automáticas.

### (B) Tipos Incompatíveis

#### Teste de Incompatibilidade: `teste_tipos_incompativeis.txt`
```
// Teste 3B: Tipos incompatíveis - detectar erros
struct TreeNode {
    Int key;
    TreeNode left;
    TreeNode right;
};

Unit main() {
    Int a <- 10;
    TreeNode node <- NEW TreeNode;
    
    // Tentativas de operações com tipos incompatíveis
    Int invalid1 <- a + node;     // ERRO: Int + TreeNode
    Float invalid2 <- node * 2.5; // ERRO: TreeNode * Float
    
    return;
}
```
**Objetivo**: Detectar operações entre tipos incompatíveis.
**Resultado Esperado**: `ERRO SEMÂNTICO: operação '+' não suportada para tipos struct`

## 4. Passagem de Parâmetros

### (A) e (B) Transmissão e Alteração de Parâmetros

#### Teste de Passagem de Parâmetros: `teste_passagem_parametros.txt`
```
// Teste 4A/B: Passagem de parâmetros por valor e referência
Unit modifyByValue(Int x) {
    x <- x + 10;  // Modifica apenas a cópia local
    return;
}

Unit modifyByReference(ref Int x) {
    x <- x + 10;  // Modifica o valor original
    return;
}

Unit main() {
    Int a <- 5;
    Int b <- 5;
    
    print_string "Valores iniciais:";
    print a;  // Deve imprimir 5
    print b;  // Deve imprimir 5
    
    modifyByValue(a);      // a não deve ser alterado
    modifyByReference(&b); // b deve ser alterado
    
    print_string "Valores apos funcoes:";
    print a;  // Deve imprimir 5 (inalterado)
    print b;  // Deve imprimir 15 (alterado)
    
    return;
}
```
**Objetivo**: Verificar comportamento correto de passagem por valor vs. referência.
**Resultado Esperado**: Compilação bem-sucedida com comportamento diferenciado.

#### Teste de Referência: `teste_referencia.txt`
```
// Teste básico de funções 
Unit teste() {
    Int x <- 10;
    print x;
}

Unit main() {
    Int a <- 5;
    print a;
    teste();
}
```
**Objetivo**: Verificar funcionamento básico de chamadas de função.
**Resultado Esperado**: Compilação bem-sucedida com chamadas corretas.

## 5. Testes Adicionais

### Erro de Identificador: `teste_id_error.txt`
```
// Teste de erro em identificador inválido
Unit main() {
    Int 123invalid <- 5;  // Erro: identificador não pode começar com número
    print 123invalid;
}
```
**Objetivo**: Detectar identificadores inválidos que começam com números.
**Resultado Esperado**: `ERRO LÉXICO: identificador inválido`

### Erro de String: `teste_string_error.txt`  
```
// Teste de erro em string malformada
Unit main() {
    String msg <- "string sem fechamento
    print msg;
}
```
**Objetivo**: Detectar strings malformadas sem fechamento.
**Resultado Esperado**: `ERRO LÉXICO: string não fechada`

### Teste de Tipos Especializados: `teste_tipos_especializados.txt`
```
// Teste de tipos básicos e especializados 
Unit main() {
    // Teste com tipos básicos
    Int x <- 5;
    Float y <- 3.14;
    
    print x;
    print y;
    
    // Teste de operações
    Int resultado <- x + 10;
    print resultado;
}
```
**Objetivo**: Verificar funcionamento correto de tipos básicos e operações.
**Resultado Esperado**: Compilação bem-sucedida com tipos corretos.

## Resumo 

### Cobertura de Testes Implementada

| Critério | Testes | Status |
|----------|--------|--------|
| **1. Estrutura Sintática** | | |
| (A) Erros Léxicos e Sintáticos | 2 testes | ✅ Implementado |
| (B) Derivação de Regras | 1 teste | ✅ Implementado |
| (C) Conflitos Shift-Reduce | 2 testes | ✅ Implementado |
| **2. Variáveis** | | |
| (A) Variáveis Omitidas | 1 teste | ✅ Implementado |
| (B) Variáveis Duplicadas | 1 teste | ✅ Implementado |
| (C) Escopos Distintos | 1 teste | ✅ Implementado |
| (D) Escopos Aninhados | 1 teste | ✅ Implementado |
| (E) Estruturas de Controle | 1 teste | ✅ Implementado |
| **3. Expressões** | | |
| (A) Coerções Permitidas | 1 teste | ✅ Implementado |
| (B) Tipos Incompatíveis | 1 teste | ✅ Implementado |
| (C) Tipos Especializados | 1 teste | ✅ Implementado |
| **4. Passagem de Parâmetros** | | |
| (A) Passagem por Valor | 1 teste | ✅ Implementado |
| (B) Passagem por Referência | 1 teste | ✅ Implementado |
| **5. Testes Adicionais** | | |
| Erro de Identificador | 1 teste | ✅ Implementado |
| Erro de String | 1 teste | ✅ Implementado |
| **TOTAL** | **17 testes** | ✅ **100% Cobertura** |
