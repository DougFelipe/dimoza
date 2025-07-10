#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    int x = 10;
    float y = 3.140000;
    if (!((x > 5))) goto L2;
    printf("%f\n", y);
L0:
    if (!((x > 0))) goto L1;
    x = (x - 1);

    goto L0;
L1:

L2:
    return;
}

