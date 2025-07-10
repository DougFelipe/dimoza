#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void mdc(int n, int m, int* r);


int resto_divisao(int n, int m) {
    if (!((m == 0))) goto L0;
    return n;

L0:
    return (n - (m * (n / m)));
}


void mdc(int n, int m, int* r) {
    if (!((m == 0))) goto L1;
    *r = n;
    return;

L1:
    mdc(m, resto_divisao(n, m), r);
}


int main() {
    int num1;
    int num2;
    int resultado_mdc;
    num1 = 54;
    num2 = 24;
    printf("===================================\n");
    printf("Calculando o MDC de 54 e 24 (Recursivo)\n");
    printf("===================================\n");
    mdc(num1, num2, &resultado_mdc);
    printf("O resultado e:\n");
    printf("%d\n", resultado_mdc);
    num1 = 105;
    num2 = 30;
    printf("\n");
    printf("===================================\n");
    printf("Calculando o MDC de 105 e 30 (Recursivo)\n");
    printf("===================================\n");
    mdc(num1, num2, &resultado_mdc);
    printf("O resultado e:\n");
    printf("%d\n", resultado_mdc);
}

