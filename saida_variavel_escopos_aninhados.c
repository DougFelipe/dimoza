#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int x = 10;
    printf("%d\n", x);
    if (!((x > 5))) goto L0;
    int x = 20;
    printf("%d\n", x);

L0:
    printf("%d\n", x);
    return;
}

