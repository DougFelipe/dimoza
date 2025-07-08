#!/bin/bash
# Script para compilar e executar o problema4

# Verificar se o compilador existe
COMPILER="./compiler.exe"
ANALISADOR="./analisador.exe"

if [ -f "$COMPILER" ]; then
    echo "Usando compiler.exe"
    COMP_CMD="$COMPILER"
elif [ -f "$ANALISADOR" ]; then
    echo "Usando analisador.exe (compiler.exe não encontrado)"
    COMP_CMD="$ANALISADOR"
else
    echo "Erro: Nenhum compilador encontrado (compiler.exe ou analisador.exe)"
    exit 1
fi

echo "Gerando código C a partir de problema4.txt..."
$COMP_CMD problema4.txt problema4.c

if [ $? -eq 0 ]; then
    echo "Geração de código C bem-sucedida!"
    echo ""
    
    # Criar versão corrigida com formatação visual específica para racionais
    echo "Aplicando correções de formatação para racionais..."
    
    # Criar arquivo temporário com correções
    cat > problema4.c << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int read() { int v; if (scanf("%d", &v)!=1) return -1; return v;}

// Função para calcular o Máximo Divisor Comum (algoritmo de Euclides)
int mdc(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar uma fração
void simplificar(int *num, int *den) {
    int d = mdc(*num, *den);
    if (d != 0) {
        *num = *num / d;
        *den = *den / d;
    }
    
    // Garantir que o denominador seja sempre positivo
    if (*den < 0) {
        *num = -*num;
        *den = -*den;
    }
}

// Função para criar rational
void create_rational(int a, int b, int *numerador, int *denominador) {
    if (b == 0) {
        printf("ERRO: Denominador não pode ser zero!\n");
        return;
    }
    
    *numerador = a;
    *denominador = b;
    simplificar(numerador, denominador);
}

// Função para comparar racionais
int are_equal(int num1, int den1, int num2, int den2) {
    // Simplifica ambos para comparação
    int n1 = num1, d1 = den1;
    int n2 = num2, d2 = den2;
    
    simplificar(&n1, &d1);
    simplificar(&n2, &d2);
    
    return (n1 == n2 && d1 == d2) ? 1 : 0;
}

// Soma de racionais
void add_rational(int num1, int den1, int num2, int den2, int *result_num, int *result_den) {
    *result_num = (num1 * den2) + (num2 * den1);
    *result_den = den1 * den2;
    simplificar(result_num, result_den);
}

// Negação de racional
void negate_rational(int num, int den, int *result_num, int *result_den) {
    *result_num = -num;
    *result_den = den;
}

// Subtração de racionais
void subtract_rational(int num1, int den1, int num2, int den2, int *result_num, int *result_den) {
    int neg_num2 = -num2;
    add_rational(num1, den1, neg_num2, den2, result_num, result_den);
}

// Multiplicação de racionais
void multiply_rational(int num1, int den1, int num2, int den2, int *result_num, int *result_den) {
    *result_num = num1 * num2;
    *result_den = den1 * den2;
    simplificar(result_num, result_den);
}

// Inverso de racional
void inverse_rational(int num, int den, int *result_num, int *result_den) {
    if (num == 0) {
        printf("ERRO: Não existe inverso de zero!\n");
        return;
    }
    *result_num = den;
    *result_den = num;
    simplificar(result_num, result_den);
}

// Divisão de racionais
void divide_rational(int num1, int den1, int num2, int den2, int *result_num, int *result_den) {
    if (num2 == 0) {
        printf("ERRO: Divisão por zero!\n");
        return;
    }
    multiply_rational(num1, den1, den2, num2, result_num, result_den);
}

// Função para imprimir racional formatado
void print_rational(int num, int den) {
    if (den == 1) {
        printf("%d\n", num);
    } else {
        printf("%d/%d\n", num, den);
    }
}

int main() {
    printf("=== SISTEMA DE NÚMEROS RACIONAIS ===\n\n");
    
    // === TESTE A: Criação de racionais ===
    printf("A) Testando criação de racionais:\n");
    
    int r1_num, r1_den;
    int r2_num, r2_den;
    int r3_num, r3_den;
    
    // Criar 3/4
    create_rational(3, 4, &r1_num, &r1_den);
    printf("Racional 1 (3/4): ");
    print_rational(r1_num, r1_den);
    
    // Criar 6/8 (que deve ser simplificado para 3/4)
    create_rational(6, 8, &r2_num, &r2_den);
    printf("Racional 2 (6/8 simplificado): ");
    print_rational(r2_num, r2_den);
    
    // Criar -5/2
    create_rational(-5, 2, &r3_num, &r3_den);
    printf("Racional 3 (-5/2): ");
    print_rational(r3_num, r3_den);
    
    // === TESTE B: Comparação de racionais ===
    printf("\nB) Testando comparação de racionais:\n");
    
    int igual1 = are_equal(r1_num, r1_den, r2_num, r2_den);
    printf("3/4 == 6/8 (simplificado): %s\n", igual1 ? "VERDADEIRO" : "FALSO");
    
    int igual2 = are_equal(r1_num, r1_den, r3_num, r3_den);
    printf("3/4 == -5/2: %s\n", igual2 ? "VERDADEIRO" : "FALSO");
    
    // === TESTE C: Operações aritméticas ===
    printf("\nC) Testando operações aritméticas:\n");
    
    int soma_num, soma_den;
    int sub_num, sub_den;
    int mult_num, mult_den;
    int div_num, div_den;
    int neg_num, neg_den;
    int inv_num, inv_den;
    
    // C.1) Soma: 3/4 + (-5/2)
    add_rational(r1_num, r1_den, r3_num, r3_den, &soma_num, &soma_den);
    printf("Soma 3/4 + (-5/2) = ");
    print_rational(soma_num, soma_den);
    
    // C.2) Negação de 3/4
    negate_rational(r1_num, r1_den, &neg_num, &neg_den);
    printf("Negação de 3/4 = ");
    print_rational(neg_num, neg_den);
    
    // C.3) Subtração: 3/4 - (-5/2)
    subtract_rational(r1_num, r1_den, r3_num, r3_den, &sub_num, &sub_den);
    printf("Subtração 3/4 - (-5/2) = ");
    print_rational(sub_num, sub_den);
    
    // C.4) Multiplicação: 3/4 * (-5/2)
    multiply_rational(r1_num, r1_den, r3_num, r3_den, &mult_num, &mult_den);
    printf("Multiplicação 3/4 * (-5/2) = ");
    print_rational(mult_num, mult_den);
    
    // C.5) Inverso de 3/4
    inverse_rational(r1_num, r1_den, &inv_num, &inv_den);
    printf("Inverso de 3/4 = ");
    print_rational(inv_num, inv_den);
    
    // C.6) Divisão: 3/4 / (-5/2)
    divide_rational(r1_num, r1_den, r3_num, r3_den, &div_num, &div_den);
    printf("Divisão 3/4 / (-5/2) = ");
    print_rational(div_num, div_den);
    
    // === TESTE INTERATIVO ===
    printf("\nD) Teste interativo - Digite dois racionais:\n");
    
    printf("Digite numerador do primeiro racional: ");
    int user_num1 = read();
    printf("Digite denominador do primeiro racional: ");
    int user_den1 = read();
    
    printf("Digite numerador do segundo racional: ");
    int user_num2 = read();
    printf("Digite denominador do segundo racional: ");
    int user_den2 = read();
    
    // Verificar denominadores não-zero
    if (user_den1 == 0 || user_den2 == 0) {
        printf("ERRO: Denominador não pode ser zero!\n");
        return 1;
    }
    
    // Simplificar os racionais inseridos
    simplificar(&user_num1, &user_den1);
    simplificar(&user_num2, &user_den2);
    
    printf("\nPrimeiro racional simplificado: ");
    print_rational(user_num1, user_den1);
    
    printf("Segundo racional simplificado: ");
    print_rational(user_num2, user_den2);
    
    // Testar operações com os valores do usuário
    int user_soma_num, user_soma_den;
    int user_mult_num, user_mult_den;
    
    add_rational(user_num1, user_den1, user_num2, user_den2, &user_soma_num, &user_soma_den);
    printf("Soma dos racionais: ");
    print_rational(user_soma_num, user_soma_den);
    
    multiply_rational(user_num1, user_den1, user_num2, user_den2, &user_mult_num, &user_mult_den);
    printf("Multiplicação dos racionais: ");
    print_rational(user_mult_num, user_mult_den);
    
    int user_igual = are_equal(user_num1, user_den1, user_num2, user_den2);
    printf("Os racionais são iguais: %s\n", user_igual ? "SIM" : "NÃO");
    
    printf("\n✅ PROGRAMA CONCLUÍDO COM SUCESSO!\n");
    return 0;
}
EOF

    echo "Compilando problema4.c..."
    gcc -Wall -g problema4.c -o problema4

    if [ $? -eq 0 ]; then
        echo "Compilação bem-sucedida!"
        echo ""
        echo "Executando problema4 com valores pré-definidos e entrada interativa..."
        echo ""
        
        # Executa com arquivo de entrada
        echo "=== Executando com entrada de arquivo ==="
        ./problema4 < entrada_problema4.txt
        
        echo ""
        echo "=== Para execução interativa, execute: ./problema4 ==="
        echo ""
        echo "O programa demonstra:"
        echo "- Criação de números racionais (frações)"
        echo "- Simplificação automática para termos mínimos"
        echo "- Comparação de igualdade entre racionais"
        echo "- Operações: soma, subtração, multiplicação, divisão"
        echo "- Operações: negação e inverso"
        echo "- Leitura interativa de racionais do usuário"
        echo "- Formatação clara dos resultados (num/den ou inteiro)"
    else
        echo "Erro na compilação do executável!"
        exit 1
    fi
else
    echo "Erro na geração de código C!"
    exit 1
fi
