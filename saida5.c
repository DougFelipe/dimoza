#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void mdc(int n, int m, int* r) {
L2:
    if (!((n != m))) goto L3;
    if (!((n > m))) goto L0;
    n = (n - m);

L0:
    if (!((m > n))) goto L1;
    m = (m - n);

L1:

    goto L2;
L3:
    r = n;
}


int main() {
    int resultado = 0;
    mdc(48, 18, &resultado);
    printf("%d\n", resultado);
    mdc(101, 10, &resultado);
    printf("%d\n", resultado);
    mdc(50, 25, &resultado);
    printf("%d\n", resultado);
}

