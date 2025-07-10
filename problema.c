#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    printf("=== CLASSIFICADOR DE NÚMEROS POR INTERVALOS ===\n");
    printf("Este programa classifica números nos seguintes intervalos:\n");
    printf("[0-25], [26-50], [51-75], [76-100]\n");
    printf("\n");
    printf("Digite números positivos (ENTER após cada um)\n");
    printf("Para finalizar, digite qualquer número negativo\n");
    printf("\n");
    int contador_0_25 = 0;
    int contador_26_50 = 0;
    int contador_51_75 = 0;
    int contador_76_100 = 0;
    float numero_atual = 0.000000;
    int programa_ativo = 1;
    int numero_entrada = 0;
L10:
    if (!((programa_ativo == 1))) goto L11;
{
    printf("Digite um número (negativo para sair):\n");
    numero_atual = read();
    if (!((numero_atual < 0.000000))) goto L8;
{
    programa_ativo = 0;
    printf("Número negativo detectado. Encerrando programa...\n");
}

    goto L9;
L8:
{
    numero_entrada = (numero_entrada + 1);
    if (!((numero_atual <= 25.000000))) goto L6;
{
    contador_0_25 = (contador_0_25 + 1);
    printf("-> Classificado no intervalo [0-25]\n");
}

    goto L7;
L6:
{
    if (!((numero_atual <= 50.000000))) goto L4;
{
    contador_26_50 = (contador_26_50 + 1);
    printf("-> Classificado no intervalo [26-50]\n");
}

    goto L5;
L4:
{
    if (!((numero_atual <= 75.000000))) goto L2;
{
    contador_51_75 = (contador_51_75 + 1);
    printf("-> Classificado no intervalo [51-75]\n");
}

    goto L3;
L2:
{
    if (!((numero_atual <= 100.000000))) goto L0;
{
    contador_76_100 = (contador_76_100 + 1);
    printf("-> Classificado no intervalo [76-100]\n");
}

    goto L1;
L0:
{
    printf("-> AVISO: Número fora dos intervalos monitorados (>100)\n");
}

L1:;
}

L3:;
}

L5:;
}

L7:;
    printf("\n");
}

L9:;
}
    goto L10;
L11:;
    printf("\n");
    printf("========== RELATÓRIO FINAL ==========\n");
    printf("Total de números processados:\n");
    printf("%d\n", numero_entrada);
    printf("\n");
    printf("Distribuição por intervalos:\n");
    printf("Intervalo [0-25]:\n");
    printf("%d\n", contador_0_25);
    printf("Intervalo [26-50]:\n");
    printf("%d\n", contador_26_50);
    printf("Intervalo [51-75]:\n");
    printf("%d\n", contador_51_75);
    printf("Intervalo [76-100]:\n");
    printf("%d\n", contador_76_100);
    printf("\n");
    printf("Programa finalizado com sucesso!\n");
}

