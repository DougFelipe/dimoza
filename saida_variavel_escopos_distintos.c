#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int condition1 = 1;
    int condition2 = 1;
    if (!((condition1 > 0))) goto L0;
    int x = 10;
    printf("%d\n", x);

L0:
    if (!((condition2 > 0))) goto L1;
    int x = 20;
    printf("%d\n", x);

L1:
    return;
}

