#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    printf("=== CALCULADORA DE EXPRESSÃO ARITMÉTICA ===\n");
    printf("Este programa calcula: x² - y + c\n");
    printf("Onde x e y são números decimais e c é um inteiro\n");
    printf("\n");
    float x;
    float y;
    int c;
    float resultado;
    printf("Digite o valor de x (número decimal):\n");
    x = read();
    printf("Digite o valor de y (número decimal):\n");
    y = read();
    printf("Digite o valor de c (número inteiro):\n");
    c = read();
    printf("\n");
    printf("=== VALORES RECEBIDOS ===\n");
    printf("x (Float) =\n");
    printf("%f\n", x);
    printf("y (Float) =\n");
    printf("%f\n", y);
    printf("c (Int) =\n");
    printf("%d\n", c);
    printf("\n");
    printf("=== CÁLCULO DA EXPRESSÃO ===\n");
    printf("Calculando: x² - y + c\n");
    printf("Substituindo os valores...\n");
    resultado = (((x * x) - y) + c);
    printf("\n");
    printf("=== RESULTADO FINAL ===\n");
    printf("x² - y + c =\n");
    printf("%f\n", resultado);
    printf("\n");
    printf("Cálculo realizado com sucesso!\n");
}

