#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int A = 0;
    int B = 0;
    printf("Digite o valor para A:\n");
    float input_A = read();
    A = input_A;
    printf("Digite o valor para B:\n");
    float input_B = read();
    B = input_B;
    if (!((A > 5))) goto L2;
    printf("primeiro if\n");
    if (!((B > 5))) goto L0;
    printf("segundo if\n");

    goto L1;
L0:
    printf("primeiro else\n");

L1:

    goto L3;
L2:
    printf("no else\n");

L3:
    printf("Fim do teste.\n");
}

