#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int x = 5;
    float y = 3.140000;
    printf("%d\n", x);
    printf("%f\n", y);
    int resultado = (x + 10);
    printf("%d\n", resultado);
}

