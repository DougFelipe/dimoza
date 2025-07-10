#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void teste() {
    int x = 10;
    printf("%d\n", x);
}


int main() {
    int a = 5;
    printf("%d\n", a);
    teste();
}

