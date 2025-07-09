#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    float x = 3.000000;
    float y = 2.500000;
    int c = 10;
    float resultado = (((x * x) - y) + c);
    printf("%f\n", resultado);
}

