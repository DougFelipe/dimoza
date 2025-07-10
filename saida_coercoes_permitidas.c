#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int a = 10;
    float b = 3.140000;
    float result1 = (a + b);
    float result2 = (a * 2.500000);
    int result3 = (a + 5);
    printf("%f\n", result1);
    printf("%f\n", result2);
    printf("%d\n", result3);
    return;
}

