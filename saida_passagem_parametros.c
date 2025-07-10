#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void modifyByValue(int x) {
    x = (x + 10);
    return;
}


void modifyByReference(int* x) {
    *x = *(*x + 10);
    return;
}


int main() {
    int a = 5;
    int b = 5;
    printf("Valores iniciais:\n");
    printf("%d\n", a);
    printf("%d\n", b);
    modifyByValue(a);
    modifyByReference(&b);
    printf("Valores apos funcoes:\n");
    printf("%d\n", a);
    printf("%d\n", b);
    return;
}

