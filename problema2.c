#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int c_0_25 = 0;
    int c_26_50 = 0;
    int c_51_75 = 0;
    int c_76_100 = 0;
    float numero_lido = 0.000000;
    int continuar = 1;
    int condicao_valida = 0;
L13:
    if (!((continuar == 1))) goto L14;
    numero_lido = read();
    if (!((numero_lido < 0.000000))) goto L0;
    continuar = 0;

L0:
    if (!((continuar == 1))) goto L12;
    condicao_valida = 1;
    if (!((numero_lido > 25.000000))) goto L1;
    condicao_valida = 0;

L1:
    if (!((condicao_valida == 1))) goto L2;
    c_0_25 = (c_0_25 + 1);

L2:
    condicao_valida = 1;
    if (!((numero_lido < 26.000000))) goto L3;
    condicao_valida = 0;

L3:
    if (!((numero_lido > 50.000000))) goto L4;
    condicao_valida = 0;

L4:
    if (!((condicao_valida == 1))) goto L5;
    c_26_50 = (c_26_50 + 1);

L5:
    condicao_valida = 1;
    if (!((numero_lido < 51.000000))) goto L6;
    condicao_valida = 0;

L6:
    if (!((numero_lido > 75.000000))) goto L7;
    condicao_valida = 0;

L7:
    if (!((condicao_valida == 1))) goto L8;
    c_51_75 = (c_51_75 + 1);

L8:
    condicao_valida = 1;
    if (!((numero_lido < 76.000000))) goto L9;
    condicao_valida = 0;

L9:
    if (!((numero_lido > 100.000000))) goto L10;
    condicao_valida = 0;

L10:
    if (!((condicao_valida == 1))) goto L11;
    c_76_100 = (c_76_100 + 1);

L11:

L12:

    goto L13;
L14:
    printf("%d\n", c_0_25);
    printf("%d\n", c_26_50);
    printf("%d\n", c_51_75);
    printf("%d\n", c_76_100);
}

