#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int a = 5;
    int b = 3;
    int c = 2;
    int result = ((a + (b * c)) - 1);
    printf("%d\n", result);
    if (!(((a + b) > (c * 2)))) goto L0;
    printf("Precedencia correta!\n");

L0:
    return;
}

