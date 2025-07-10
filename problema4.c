#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void criar_racional(int a, int b, int* numerador, int* denominador) {
    if (!((b == 0))) goto L0;
    printf("❌ ERRO: Denominador não pode ser zero!\n");
    printf("   Criando racional padrão: 0/1\n");
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
    printf("✅ Racional criado com sucesso!\n");

L2:
}


void comparar_igualdade(int num1, int den1, int num2, int den2, int* resultado) {
    int produto1 = (num1 * den2);
    int produto2 = (num2 * den1);
    if (!((produto1 == produto2))) goto L3;
    *resultado = 1;
    printf("✅ Os números racionais são iguais\n");

L3:
    if (!((produto1 != produto2))) goto L4;
    *resultado = 0;
    printf("ℹ️  Os números racionais são diferentes\n");

L4:
}


void somar_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    *result_num = ((num1 * den2) + (num2 * den1));
    *result_den = (den1 * den2);
    if (!((*result_den < 0))) goto L5;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L5:
    printf("➕ Soma calculada\n");
}


void negar_racional(int num, int den, int* result_num, int* result_den) {
    *result_num = (0 - num);
    *result_den = den;
    printf("➖ Negação calculada\n");
}


void subtrair_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    *result_num = ((num1 * den2) - (num2 * den1));
    *result_den = (den1 * den2);
    if (!((*result_den < 0))) goto L6;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L6:
    printf("➖ Subtração calculada\n");
}


void multiplicar_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    *result_num = (num1 * num2);
    *result_den = (den1 * den2);
    if (!((*result_den < 0))) goto L7;
    *result_num = (0 - *result_num);
    *result_den = (0 - *result_den);

L7:
    printf("✖️  Multiplicação calculada\n");
}


void inverter_racional(int num, int den, int* result_num, int* result_den) {
    if (!((num == 0))) goto L8;
    printf("❌ ERRO: Não é possível calcular o inverso de zero!\n");
    printf("   Retornando racional padrão: 0/1\n");
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
    printf("🔄 Inverso calculado\n");

L10:
}


void dividir_racionais(int num1, int den1, int num2, int den2, int* result_num, int* result_den) {
    if (!((num2 == 0))) goto L11;
    printf("❌ ERRO: Divisão por zero não é permitida!\n");
    printf("   Retornando racional padrão: 0/1\n");
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
    printf("➗ Divisão calculada\n");

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
    printf("==================================================================\n");
    printf("         NÚMEROS RACIONAIS - LINGUAGEM DIMOZA\n");
    printf("==================================================================\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    ENTRADA DOS NÚMEROS RACIONAIS\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("📝 Digite os dados dos números racionais:\n");
    printf("\n");
    printf("🔢 PRIMEIRO NÚMERO RACIONAL:\n");
    printf("Digite o numerador:\n");
    float entrada1 = read();
    int r1_num = entrada1;
    printf("Digite o denominador:\n");
    float entrada2 = read();
    int r1_den = entrada2;
    printf("\n");
    printf("🔢 SEGUNDO NÚMERO RACIONAL:\n");
    printf("Digite o numerador:\n");
    float entrada3 = read();
    int r2_num = entrada3;
    printf("Digite o denominador:\n");
    float entrada4 = read();
    int r2_den = entrada4;
    printf("\n");
    printf("📋 CONFIRMAÇÃO DOS DADOS INSERIDOS:\n");
    printf("   Primeiro racional:  \n");
    printf("%d\n", r1_num);
    printf("/\n");
    printf("%d\n", r1_den);
    printf("   Segundo racional:   \n");
    printf("%d\n", r2_num);
    printf("/\n");
    printf("%d\n", r2_den);
    printf("\n");
    printf("🔍 VALIDANDO DENOMINADORES...\n");
    printf("\n");
    int dados_validos = 1;
    if (!((r1_den == 0))) goto L16;
    printf("❌ ERRO: Primeiro denominador não pode ser zero!\n");
    dados_validos = 0;

L16:
    if (!((r2_den == 0))) goto L17;
    printf("❌ ERRO: Segundo denominador não pode ser zero!\n");
    dados_validos = 0;

L17:
    if (!((dados_validos == 1))) goto L20;
    printf("✅ Denominadores validados com sucesso!\n");
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  MÓDULO A: CRIAÇÃO DE RACIONAIS\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    int rat1_num = 0;
    int rat1_den = 0;
    int rat2_num = 0;
    int rat2_den = 0;
    printf("🔧 Criando primeiro número racional...\n");
    criar_racional(r1_num, r1_den, &rat1_num, &rat1_den);
    printf("   Resultado: \n");
    imprimir_racional(rat1_num, rat1_den);
    printf("\n");
    printf("🔧 Criando segundo número racional...\n");
    criar_racional(r2_num, r2_den, &rat2_num, &rat2_den);
    printf("   Resultado: \n");
    imprimir_racional(rat2_num, rat2_den);
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  MÓDULO B: COMPARAÇÃO DE IGUALDADE\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    int sao_iguais = 0;
    printf("🔍 Comparando os números racionais...\n");
    comparar_igualdade(rat1_num, rat1_den, rat2_num, rat2_den, &sao_iguais);
    printf("   Resultado: \n");
    if (!((sao_iguais == 1))) goto L18;
    printf("SIM - são iguais\n");

L18:
    if (!((sao_iguais == 0))) goto L19;
    printf("NÃO - são diferentes\n");

L19:
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  MÓDULO C: OPERAÇÕES ARITMÉTICAS\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🧮 OPERAÇÃO 1: SOMA\n");
    int soma_num = 0;
    int soma_den = 0;
    somar_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &soma_num, &soma_den);
    printf("   \n");
    imprimir_racional(rat1_num, rat1_den);
    printf(" + \n");
    imprimir_racional(rat2_num, rat2_den);
    printf(" = \n");
    imprimir_racional(soma_num, soma_den);
    printf("\n");
    printf("🧮 OPERAÇÃO 2: NEGAÇÃO\n");
    int neg1_num = 0;
    int neg1_den = 0;
    negar_racional(rat1_num, rat1_den, &neg1_num, &neg1_den);
    printf("   -\n");
    imprimir_racional(rat1_num, rat1_den);
    printf(" = \n");
    imprimir_racional(neg1_num, neg1_den);
    int neg2_num = 0;
    int neg2_den = 0;
    negar_racional(rat2_num, rat2_den, &neg2_num, &neg2_den);
    printf("   -\n");
    imprimir_racional(rat2_num, rat2_den);
    printf(" = \n");
    imprimir_racional(neg2_num, neg2_den);
    printf("\n");
    printf("🧮 OPERAÇÃO 3: SUBTRAÇÃO\n");
    int sub_num = 0;
    int sub_den = 0;
    subtrair_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &sub_num, &sub_den);
    printf("   \n");
    imprimir_racional(rat1_num, rat1_den);
    printf(" - \n");
    imprimir_racional(rat2_num, rat2_den);
    printf(" = \n");
    imprimir_racional(sub_num, sub_den);
    printf("\n");
    printf("🧮 OPERAÇÃO 4: MULTIPLICAÇÃO\n");
    int mult_num = 0;
    int mult_den = 0;
    multiplicar_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &mult_num, &mult_den);
    printf("   \n");
    imprimir_racional(rat1_num, rat1_den);
    printf(" × \n");
    imprimir_racional(rat2_num, rat2_den);
    printf(" = \n");
    imprimir_racional(mult_num, mult_den);
    printf("\n");
    printf("🧮 OPERAÇÃO 5: INVERSO\n");
    int inv1_num = 0;
    int inv1_den = 0;
    inverter_racional(rat1_num, rat1_den, &inv1_num, &inv1_den);
    printf("   Inverso de \n");
    imprimir_racional(rat1_num, rat1_den);
    printf(" = \n");
    imprimir_racional(inv1_num, inv1_den);
    int inv2_num = 0;
    int inv2_den = 0;
    inverter_racional(rat2_num, rat2_den, &inv2_num, &inv2_den);
    printf("   Inverso de \n");
    imprimir_racional(rat2_num, rat2_den);
    printf(" = \n");
    imprimir_racional(inv2_num, inv2_den);
    printf("\n");
    printf("🧮 OPERAÇÃO 6: DIVISÃO\n");
    int div_num = 0;
    int div_den = 0;
    dividir_racionais(rat1_num, rat1_den, rat2_num, rat2_den, &div_num, &div_den);
    printf("   \n");
    imprimir_racional(rat1_num, rat1_den);
    printf(" ÷ \n");
    imprimir_racional(rat2_num, rat2_den);
    printf(" = \n");
    imprimir_racional(div_num, div_den);
    printf("\n");
    printf("\n");
    printf("==================================================================\n");
    printf("                      PROGRAMA FINALIZADO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("✅ Todas as operações foram executadas com sucesso!\n");
    printf("\n");
    printf("     RESUMO DAS OPERAÇÕES REALIZADAS:\n");
    printf("   • Criação de números racionais\n");
    printf("   • Normalização (denominador sempre positivo)\n");
    printf("   • Comparação de igualdade   \n");
    printf("   • Operações aritméticas: soma, subtração, multiplicação, divisão\n");
    printf("   • Operações especiais: negação e inverso\n");

L20:
    if (!((dados_validos == 0))) goto L21;
    printf("\n");
    printf("==================================================================\n");
    printf("                    PROGRAMA ENCERRADO COM ERRO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("❌ O programa foi encerrado devido a denominadores inválidos.\n");
    printf("\n");
    printf("📋 REQUISITOS PARA EXECUÇÃO:\n");
    printf("   • Denominadores devem ser números inteiros não-zero\n");
    printf("   • Numeradores podem ser qualquer número inteiro\n");
    printf("   • Entrada deve conter exatamente 4 números inteiros\n");
    printf("\n");
    printf("          Execute o programa novamente e insira\n");
    printf("         denominadores válidos (diferentes de zero).\n");

L21:
}

