#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void criar_racional(int a, int b, int* numerador, int* denominador) {
    if (!((b == 0))) goto L0;
    printf("ERRO: Denominador zero!\n");
    *numerador = 0;
    *denominador = 1;

L0:
    if (!((b != 0))) goto L2;
    *numerador = a;
    *denominador = b;
    if (!((*denominador < 0))) goto L1;
    *numerador = (0 - *numerador);
    *denominador = (0 - *denominador);

L1:

L2:
}


void comparar_igualdade(int num1, int den1, int num2, int den2, int* resultado) {
    int produto1 = (num1 * den2);
    int produto2 = (num2 * den1);
    if (!((produto1 == produto2))) goto L3;
    *resultado = 1;

L3:
    if (!((produto1 != produto2))) goto L4;
    *resultado = 0;

L4:
}


void somar_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    *result_num = ((num1 * den2) + (num2 * den1));
    *result_den = (den1 * den2);
    if (!((*result_den < 0))) goto L5;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L5:
}


void negar_racional(int num, int den, int* result_num, int* result_den) {
    *result_num = (0 - num);
    *result_den = den;
}


void subtrair_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    *result_num = ((num1 * den2) - (num2 * den1));
    *result_den = (den1 * den2);
    if (!((*result_den < 0))) goto L6;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L6:
}


void multiplicar_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    *result_num = (num1 * num2);
    *result_den = (den1 * den2);
    if (!((*result_den < 0))) goto L7;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L7:
}


void inverter_racional(int num, int den, int* result_num, int* result_den) {
    if (!((num == 0))) goto L8;
    printf("ERRO: Inverso de zero!\n");
    *result_num = 0;
    *result_den = 1;

L8:
    if (!((num != 0))) goto L10;
    *result_num = den;
    *result_den = num;
    if (!((*result_den < 0))) goto L9;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L9:

L10:
}


void dividir_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    if (!((num2 == 0))) goto L11;
    printf("ERRO: Divisao por zero!\n");
    *result_num = 0;
    *result_den = 1;

L11:
    if (!((num2 != 0))) goto L13;
    *result_num = (num1 * den2);
    *result_den = (den1 * num2);
    if (!((*result_den < 0))) goto L12;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L12:

L13:
}


void imprimir_racional(int num, int den) {
    if (!((den == 1))) goto L14;
    printf("%d\n", num);

L14:
    if (!((den != 1))) goto L15;
    printf("%d\n", num);
    printf("/\n");
    printf("%d\n", den);

L15:
}


int main() {
    printf("=== PROBLEMA 4: NUMEROS RACIONAIS ===\n");
    printf("\n");
    float entrada1 = read();
    int r1_num = entrada1;
    float entrada2 = read();
    int r1_den = entrada2;
    float entrada3 = read();
    int r2_num = entrada3;
    float entrada4 = read();
    int r2_den = entrada4;
    printf("Entrada processada:\n");
    printf("Primeiro racional: \n");
    printf("%d\n", r1_num);
    printf("/\n");
    printf("%d\n", r1_den);
    printf("Segundo racional: \n");
    printf("%d\n", r2_num);
    printf("/\n");
    printf("%d\n", r2_den);
    printf("\n");
    if (!((r1_den == 0))) goto L16;
    printf("ERRO: Primeiro denominador e zero!\n");

L16:
    if (!((r2_den == 0))) goto L17;
    printf("ERRO: Segundo denominador e zero!\n");

L17:
    if (!((r1_den != 0))) goto L21;
    if (!((r2_den != 0))) goto L20;
    printf("=== REQUISITO A: Criacao ===\n");
    int rat1_num = 0;
    int rat1_den = 0;
    int rat2_num = 0;
    int rat2_den = 0;
    criar_racional(r1_num, r1_den, &rat1_num, &rat1_den);
    printf("Primeiro criado: \n");
    imprimir_racional(rat1_num, rat1_den);
    criar_racional(r2_num, r2_den, &rat2_num, &rat2_den);
    printf("Segundo criado: \n");
    imprimir_racional(rat2_num, rat2_den);
    printf("\n");
    printf("=== REQUISITO B: Comparacao ===\n");
    int sao_iguais = 0;
    comparar_igualdade(rat1_num, rat1_den, rat2_num, rat2_den, &sao_iguais);
    printf("Sao iguais? \n");
    if (!((sao_iguais == 1))) goto L18;
    printf("SIM\n");

L18:
    if (!((sao_iguais == 0))) goto L19;
    printf("NAO\n");

L19:
    printf("\n");
    printf("=== REQUISITO C: Operacoes ===\n");
    int soma_num = 0;
    int soma_den = 0;
    somar_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &soma_num, &soma_den);
    printf("Soma: \n");
    imprimir_racional(soma_num, soma_den);
    int neg1_num = 0;
    int neg1_den = 0;
    negar_racional(rat1_num, rat1_den, &neg1_num, &neg1_den);
    printf("Negacao primeiro: \n");
    imprimir_racional(neg1_num, neg1_den);
    int neg2_num = 0;
    int neg2_den = 0;
    negar_racional(rat2_num, rat2_den, &neg2_num, &neg2_den);
    printf("Negacao segundo: \n");
    imprimir_racional(neg2_num, neg2_den);
    int sub_num = 0;
    int sub_den = 0;
    subtrair_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &sub_num, &sub_den);
    printf("Subtracao: \n");
    imprimir_racional(sub_num, sub_den);
    int mult_num = 0;
    int mult_den = 0;
    multiplicar_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &mult_num, &mult_den);
    printf("Multiplicacao: \n");
    imprimir_racional(mult_num, mult_den);
    int inv1_num = 0;
    int inv1_den = 0;
    inverter_racional(rat1_num, rat1_den, &inv1_num, &inv1_den);
    printf("Inverso primeiro: \n");
    imprimir_racional(inv1_num, inv1_den);
    int inv2_num = 0;
    int inv2_den = 0;
    inverter_racional(rat2_num, rat2_den, &inv2_num, &inv2_den);
    printf("Inverso segundo: \n");
    imprimir_racional(inv2_num, inv2_den);
    int div_num = 0;
    int div_den = 0;
    dividir_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &div_num, &div_den);
    printf("Divisao: \n");
    imprimir_racional(div_num, div_den);
    printf("\n");
    printf("=== PROGRAMA CONCLUIDO ===\n");

L20:

L21:
}

