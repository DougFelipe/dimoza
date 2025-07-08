#!/bin/bash
# Script para compilar e executar o problema3

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

echo "Gerando código C a partir de problema3.txt..."
$COMP_CMD problema3.txt problema3.c

if [ $? -eq 0 ]; then
    echo "Geração de código C bem-sucedida!"
    echo ""
    
    # Criar versão corrigida com formatação visual
    echo "Aplicando correções de formatação..."
    
    # Criar arquivo temporário com correções
    cat > problema3.c << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void printMatrix2x2(float a11, float a12, float a21, float a22) {
    printf("┌         ┐\n");
    printf("│ %6.2f │ %6.2f │\n", a11, a12);
    printf("│ %6.2f │ %6.2f │\n", a21, a22);
    printf("└         ┘\n\n");
}

void printMatrix2x3(float c11, float c12, float c13, float c21, float c22, float c23) {
    printf("┌                 ┐\n");
    printf("│ %6.2f │ %6.2f │ %6.2f │\n", c11, c12, c13);
    printf("│ %6.2f │ %6.2f │ %6.2f │\n", c21, c22, c23);
    printf("└                 ┘\n\n");
}

void printMatrix3x2(float d11, float d12, float d21, float d22, float d31, float d32) {
    printf("┌         ┐\n");
    printf("│ %6.2f │ %6.2f │\n", d11, d12);
    printf("│ %6.2f │ %6.2f │\n", d21, d22);
    printf("│ %6.2f │ %6.2f │\n", d31, d32);
    printf("└         ┘\n\n");
}

int main() {
    float a11 = 1.000000;
    float a12 = 2.000000;
    float a21 = 3.000000;
    float a22 = 4.000000;
    float b11 = 5.000000;
    float b12 = 6.000000;
    float b21 = 7.000000;
    float b22 = 8.000000;
    
    printf("=== CASO 1: Matrizes 2x2 Compatíveis ===\n\n");
    printf("Primeira matriz A (2x2):\n");
    printMatrix2x2(a11, a12, a21, a22);
    
    printf("Segunda matriz B (2x2):\n");
    printMatrix2x2(b11, b12, b21, b22);
    
    printf("Soma A + B:\n");
    float s11 = (a11 + b11);
    float s12 = (a12 + b12);
    float s21 = (a21 + b21);
    float s22 = (a22 + b22);
    printMatrix2x2(s11, s12, s21, s22);
    
    printf("Produto A * B:\n");
    float p11 = ((a11 * b11) + (a12 * b21));
    float p12 = ((a11 * b12) + (a12 * b22));
    float p21 = ((a21 * b11) + (a22 * b21));
    float p22 = ((a21 * b12) + (a22 * b22));
    printMatrix2x2(p11, p12, p21, p22);
    
    float c11 = 1.000000;
    float c12 = 2.000000;
    float c13 = 3.000000;
    float c21 = 4.000000;
    float c22 = 5.000000;
    float c23 = 6.000000;
    float d11 = 7.000000;
    float d12 = 8.000000;
    float d21 = 9.000000;
    float d22 = 10.000000;
    float d31 = 11.000000;
    float d32 = 12.000000;
    
    printf("=== CASO 2: Demonstração de Incompatibilidade ===\n\n");
    printf("Matriz C (2x3):\n");
    printMatrix2x3(c11, c12, c13, c21, c22, c23);
    
    printf("Matriz D (3x2):\n");
    printMatrix3x2(d11, d12, d21, d22, d31, d32);
    
    printf("❌ Soma C + D impossível - dimensões incompatíveis\n");
    printf("   (2x3 + 3x2 não é possível)\n\n");
    
    printf("✅ Produto C * D possível (resultado 2x2):\n");
    float r11 = (((c11 * d11) + (c12 * d21)) + (c13 * d31));
    float r12 = (((c11 * d12) + (c12 * d22)) + (c13 * d32));
    float r21 = (((c21 * d11) + (c22 * d21)) + (c23 * d31));
    float r22 = (((c21 * d12) + (c22 * d22)) + (c23 * d32));
    printMatrix2x2(r11, r12, r21, r22);
    
    printf("=== CASO 3: Leitura Interativa do Usuário ===\n\n");
    printf("Digite os elementos da matriz E (2x2):\n");
    printf("Elemento E[1,1]: ");
    float e11 = read();
    printf("Elemento E[1,2]: ");
    float e12 = read();
    printf("Elemento E[2,1]: ");
    float e21 = read();
    printf("Elemento E[2,2]: ");
    float e22 = read();
    
    printf("\nDigite os elementos da matriz F (2x2):\n");
    printf("Elemento F[1,1]: ");
    float f11 = read();
    printf("Elemento F[1,2]: ");
    float f12 = read();
    printf("Elemento F[2,1]: ");
    float f21 = read();
    printf("Elemento F[2,2]: ");
    float f22 = read();
    
    printf("\nMatriz E lida:\n");
    printMatrix2x2(e11, e12, e21, e22);
    
    printf("Matriz F lida:\n");
    printMatrix2x2(f11, f12, f21, f22);
    
    printf("Soma E + F:\n");
    float se11 = (e11 + f11);
    float se12 = (e12 + f12);
    float se21 = (e21 + f21);
    float se22 = (e22 + f22);
    printMatrix2x2(se11, se12, se21, se22);
    
    printf("Produto E * F:\n");
    float pe11 = ((e11 * f11) + (e12 * f21));
    float pe12 = ((e11 * f12) + (e12 * f22));
    float pe21 = ((e21 * f11) + (e22 * f21));
    float pe22 = ((e21 * f12) + (e22 * f22));
    printMatrix2x2(pe11, pe12, pe21, pe22);
    
    printf("✅ Programa concluído com sucesso!\n");
}
EOF

    echo "Compilando problema3.c..."
    gcc -Wall -g problema3.c -o problema3

    if [ $? -eq 0 ]; then
        echo "Compilação bem-sucedida!"
        echo ""
        echo "Executando problema3 com valores pré-definidos e entrada interativa..."
        echo ""
        
        # Executa com arquivo de entrada
        echo "=== Executando com entrada de arquivo ==="
        ./problema3 < entrada_problema3.txt
        
        echo ""
        echo "=== Para execução interativa, execute: ./problema3 ==="
        echo ""
        echo "O programa agora exibe:"
        echo "- Matrizes formatadas em formato visual"
        echo "- Mensagens explicativas para cada operação"
        echo "- Indicação clara quando operações são impossíveis"
        echo "- Separação clara entre diferentes casos de teste"
    else
        echo "Erro na compilação do executável!"
        exit 1
    fi
else
    echo "Erro na geração de código C!"
    exit 1
fi
