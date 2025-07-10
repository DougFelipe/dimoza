#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    printf("=== PROBLEMA 3: OPERACOES COM MATRIZES ===\n");
    printf("\n");
    printf("Digite as dimensoes da primeira matriz:\n");
    printf("Numero de linhas da matriz A:\n");
    float entrada1 = read();
    int linhas_A = entrada1;
    printf("Numero de colunas da matriz A:\n");
    float entrada2 = read();
    int colunas_A = entrada2;
    printf("Digite as dimensoes da segunda matriz:\n");
    printf("Numero de linhas da matriz B:\n");
    float entrada3 = read();
    int linhas_B = entrada3;
    printf("Numero de colunas da matriz B:\n");
    float entrada4 = read();
    int colunas_B = entrada4;
    if (!((linhas_A <= 0))) goto L0;
    printf("ERRO: Numero de linhas da matriz A deve ser positivo!\n");

L0:
    if (!((colunas_A <= 0))) goto L1;
    printf("ERRO: Numero de colunas da matriz A deve ser positivo!\n");

L1:
    if (!((linhas_B <= 0))) goto L2;
    printf("ERRO: Numero de linhas da matriz B deve ser positivo!\n");

L2:
    if (!((colunas_B <= 0))) goto L3;
    printf("ERRO: Numero de colunas da matriz B deve ser positivo!\n");

L3:
    if (!((linhas_A > 0))) goto L113;
    if (!((colunas_A > 0))) goto L112;
    if (!((linhas_B > 0))) goto L111;
    if (!((colunas_B > 0))) goto L110;
    printf("\n");
    printf("=== DIMENSOES DAS MATRIZES ===\n");
    printf("Matriz A: \n");
    printf("%d\n", linhas_A);
    printf("x\n");
    printf("%d\n", colunas_A);
    printf("Matriz B: \n");
    printf("%d\n", linhas_B);
    printf("x\n");
    printf("%d\n", colunas_B);
    printf("\n");
    printf("=== LEITURA DOS ELEMENTOS ===\n");
    float a11 = 0.000000;
    float a12 = 0.000000;
    float a13 = 0.000000;
    float a21 = 0.000000;
    float a22 = 0.000000;
    float a23 = 0.000000;
    float a31 = 0.000000;
    float a32 = 0.000000;
    float a33 = 0.000000;
    float b11 = 0.000000;
    float b12 = 0.000000;
    float b13 = 0.000000;
    float b21 = 0.000000;
    float b22 = 0.000000;
    float b23 = 0.000000;
    float b31 = 0.000000;
    float b32 = 0.000000;
    float b33 = 0.000000;
    printf("Digite os elementos da matriz A (linha por linha):\n");
    if (!((linhas_A >= 1))) goto L7;
    if (!((colunas_A >= 1))) goto L4;
    printf("A[1,1]:\n");
    a11 = read();

L4:
    if (!((colunas_A >= 2))) goto L5;
    printf("A[1,2]:\n");
    a12 = read();

L5:
    if (!((colunas_A >= 3))) goto L6;
    printf("A[1,3]:\n");
    a13 = read();

L6:

L7:
    if (!((linhas_A >= 2))) goto L11;
    if (!((colunas_A >= 1))) goto L8;
    printf("A[2,1]:\n");
    a21 = read();

L8:
    if (!((colunas_A >= 2))) goto L9;
    printf("A[2,2]:\n");
    a22 = read();

L9:
    if (!((colunas_A >= 3))) goto L10;
    printf("A[2,3]:\n");
    a23 = read();

L10:

L11:
    if (!((linhas_A >= 3))) goto L15;
    if (!((colunas_A >= 1))) goto L12;
    printf("A[3,1]:\n");
    a31 = read();

L12:
    if (!((colunas_A >= 2))) goto L13;
    printf("A[3,2]:\n");
    a32 = read();

L13:
    if (!((colunas_A >= 3))) goto L14;
    printf("A[3,3]:\n");
    a33 = read();

L14:

L15:
    printf("\n");
    printf("Digite os elementos da matriz B (linha por linha):\n");
    if (!((linhas_B >= 1))) goto L19;
    if (!((colunas_B >= 1))) goto L16;
    printf("B[1,1]:\n");
    b11 = read();

L16:
    if (!((colunas_B >= 2))) goto L17;
    printf("B[1,2]:\n");
    b12 = read();

L17:
    if (!((colunas_B >= 3))) goto L18;
    printf("B[1,3]:\n");
    b13 = read();

L18:

L19:
    if (!((linhas_B >= 2))) goto L23;
    if (!((colunas_B >= 1))) goto L20;
    printf("B[2,1]:\n");
    b21 = read();

L20:
    if (!((colunas_B >= 2))) goto L21;
    printf("B[2,2]:\n");
    b22 = read();

L21:
    if (!((colunas_B >= 3))) goto L22;
    printf("B[2,3]:\n");
    b23 = read();

L22:

L23:
    if (!((linhas_B >= 3))) goto L27;
    if (!((colunas_B >= 1))) goto L24;
    printf("B[3,1]:\n");
    b31 = read();

L24:
    if (!((colunas_B >= 2))) goto L25;
    printf("B[3,2]:\n");
    b32 = read();

L25:
    if (!((colunas_B >= 3))) goto L26;
    printf("B[3,3]:\n");
    b33 = read();

L26:

L27:
    printf("\n");
    printf("=== MATRIZES LIDAS ===\n");
    printf("Matriz A:\n");
    if (!((linhas_A >= 1))) goto L31;
    printf("[ \n");
    if (!((colunas_A >= 1))) goto L28;
    printf("%f\n", a11);
    printf(" \n");

L28:
    if (!((colunas_A >= 2))) goto L29;
    printf("%f\n", a12);
    printf(" \n");

L29:
    if (!((colunas_A >= 3))) goto L30;
    printf("%f\n", a13);
    printf(" \n");

L30:
    printf("]\n");

L31:
    if (!((linhas_A >= 2))) goto L35;
    printf("[ \n");
    if (!((colunas_A >= 1))) goto L32;
    printf("%f\n", a21);
    printf(" \n");

L32:
    if (!((colunas_A >= 2))) goto L33;
    printf("%f\n", a22);
    printf(" \n");

L33:
    if (!((colunas_A >= 3))) goto L34;
    printf("%f\n", a23);
    printf(" \n");

L34:
    printf("]\n");

L35:
    if (!((linhas_A >= 3))) goto L39;
    printf("[ \n");
    if (!((colunas_A >= 1))) goto L36;
    printf("%f\n", a31);
    printf(" \n");

L36:
    if (!((colunas_A >= 2))) goto L37;
    printf("%f\n", a32);
    printf(" \n");

L37:
    if (!((colunas_A >= 3))) goto L38;
    printf("%f\n", a33);
    printf(" \n");

L38:
    printf("]\n");

L39:
    printf("\n");
    printf("Matriz B:\n");
    if (!((linhas_B >= 1))) goto L43;
    printf("[ \n");
    if (!((colunas_B >= 1))) goto L40;
    printf("%f\n", b11);
    printf(" \n");

L40:
    if (!((colunas_B >= 2))) goto L41;
    printf("%f\n", b12);
    printf(" \n");

L41:
    if (!((colunas_B >= 3))) goto L42;
    printf("%f\n", b13);
    printf(" \n");

L42:
    printf("]\n");

L43:
    if (!((linhas_B >= 2))) goto L47;
    printf("[ \n");
    if (!((colunas_B >= 1))) goto L44;
    printf("%f\n", b21);
    printf(" \n");

L44:
    if (!((colunas_B >= 2))) goto L45;
    printf("%f\n", b22);
    printf(" \n");

L45:
    if (!((colunas_B >= 3))) goto L46;
    printf("%f\n", b23);
    printf(" \n");

L46:
    printf("]\n");

L47:
    if (!((linhas_B >= 3))) goto L51;
    printf("[ \n");
    if (!((colunas_B >= 1))) goto L48;
    printf("%f\n", b31);
    printf(" \n");

L48:
    if (!((colunas_B >= 2))) goto L49;
    printf("%f\n", b32);
    printf(" \n");

L49:
    if (!((colunas_B >= 3))) goto L50;
    printf("%f\n", b33);
    printf(" \n");

L50:
    printf("]\n");

L51:
    printf("\n");
    printf("=== OPERACAO 1: SOMA DE MATRIZES ===\n");
    int soma_possivel = 0;
    if (!((linhas_A == linhas_B))) goto L53;
    if (!((colunas_A == colunas_B))) goto L52;
    soma_possivel = 1;

L52:

L53:
    if (!((soma_possivel == 1))) goto L66;
    printf("A soma e possivel (matrizes de mesma dimensao)\n");
    printf("Resultado da soma A + B:\n");
    if (!((linhas_A >= 1))) goto L57;
    printf("[ \n");
    if (!((colunas_A >= 1))) goto L54;
    float soma11 = (a11 + b11);
    printf("%f\n", soma11);
    printf(" \n");

L54:
    if (!((colunas_A >= 2))) goto L55;
    float soma12 = (a12 + b12);
    printf("%f\n", soma12);
    printf(" \n");

L55:
    if (!((colunas_A >= 3))) goto L56;
    float soma13 = (a13 + b13);
    printf("%f\n", soma13);
    printf(" \n");

L56:
    printf("]\n");

L57:
    if (!((linhas_A >= 2))) goto L61;
    printf("[ \n");
    if (!((colunas_A >= 1))) goto L58;
    float soma21 = (a21 + b21);
    printf("%f\n", soma21);
    printf(" \n");

L58:
    if (!((colunas_A >= 2))) goto L59;
    float soma22 = (a22 + b22);
    printf("%f\n", soma22);
    printf(" \n");

L59:
    if (!((colunas_A >= 3))) goto L60;
    float soma23 = (a23 + b23);
    printf("%f\n", soma23);
    printf(" \n");

L60:
    printf("]\n");

L61:
    if (!((linhas_A >= 3))) goto L65;
    printf("[ \n");
    if (!((colunas_A >= 1))) goto L62;
    float soma31 = (a31 + b31);
    printf("%f\n", soma31);
    printf(" \n");

L62:
    if (!((colunas_A >= 2))) goto L63;
    float soma32 = (a32 + b32);
    printf("%f\n", soma32);
    printf(" \n");

L63:
    if (!((colunas_A >= 3))) goto L64;
    float soma33 = (a33 + b33);
    printf("%f\n", soma33);
    printf(" \n");

L64:
    printf("]\n");

L65:

L66:
    if (!((soma_possivel == 0))) goto L67;
    printf("A soma NAO e possivel!\n");
    printf("Motivo: As matrizes devem ter as mesmas dimensoes\n");
    printf("Matriz A e \n");
    printf("%d\n", linhas_A);
    printf("x\n");
    printf("%d\n", colunas_A);
    printf("Matriz B e \n");
    printf("%d\n", linhas_B);
    printf("x\n");
    printf("%d\n", colunas_B);

L67:
    printf("\n");
    printf("=== OPERACAO 2: PRODUTO DE MATRIZES ===\n");
    int produto_possivel = 0;
    if (!((colunas_A == linhas_B))) goto L68;
    produto_possivel = 1;

L68:
    if (!((produto_possivel == 1))) goto L108;
    printf("O produto e possivel\n");
    printf("Dimensao do resultado: \n");
    printf("%d\n", linhas_A);
    printf("x\n");
    printf("%d\n", colunas_B);
    printf("Resultado do produto A x B:\n");
    if (!((linhas_A >= 1))) goto L81;
    printf("[ \n");
    if (!((colunas_B >= 1))) goto L72;
    float prod11 = 0.000000;
    if (!((colunas_A >= 1))) goto L69;
    prod11 = (prod11 + (a11 * b11));

L69:
    if (!((colunas_A >= 2))) goto L70;
    prod11 = (prod11 + (a12 * b21));

L70:
    if (!((colunas_A >= 3))) goto L71;
    prod11 = (prod11 + (a13 * b31));

L71:
    printf("%f\n", prod11);
    printf(" \n");

L72:
    if (!((colunas_B >= 2))) goto L76;
    float prod12 = 0.000000;
    if (!((colunas_A >= 1))) goto L73;
    prod12 = (prod12 + (a11 * b12));

L73:
    if (!((colunas_A >= 2))) goto L74;
    prod12 = (prod12 + (a12 * b22));

L74:
    if (!((colunas_A >= 3))) goto L75;
    prod12 = (prod12 + (a13 * b32));

L75:
    printf("%f\n", prod12);
    printf(" \n");

L76:
    if (!((colunas_B >= 3))) goto L80;
    float prod13 = 0.000000;
    if (!((colunas_A >= 1))) goto L77;
    prod13 = (prod13 + (a11 * b13));

L77:
    if (!((colunas_A >= 2))) goto L78;
    prod13 = (prod13 + (a12 * b23));

L78:
    if (!((colunas_A >= 3))) goto L79;
    prod13 = (prod13 + (a13 * b33));

L79:
    printf("%f\n", prod13);
    printf(" \n");

L80:
    printf("]\n");

L81:
    if (!((linhas_A >= 2))) goto L94;
    printf("[ \n");
    if (!((colunas_B >= 1))) goto L85;
    float prod21 = 0.000000;
    if (!((colunas_A >= 1))) goto L82;
    prod21 = (prod21 + (a21 * b11));

L82:
    if (!((colunas_A >= 2))) goto L83;
    prod21 = (prod21 + (a22 * b21));

L83:
    if (!((colunas_A >= 3))) goto L84;
    prod21 = (prod21 + (a23 * b31));

L84:
    printf("%f\n", prod21);
    printf(" \n");

L85:
    if (!((colunas_B >= 2))) goto L89;
    float prod22 = 0.000000;
    if (!((colunas_A >= 1))) goto L86;
    prod22 = (prod22 + (a21 * b12));

L86:
    if (!((colunas_A >= 2))) goto L87;
    prod22 = (prod22 + (a22 * b22));

L87:
    if (!((colunas_A >= 3))) goto L88;
    prod22 = (prod22 + (a23 * b32));

L88:
    printf("%f\n", prod22);
    printf(" \n");

L89:
    if (!((colunas_B >= 3))) goto L93;
    float prod23 = 0.000000;
    if (!((colunas_A >= 1))) goto L90;
    prod23 = (prod23 + (a21 * b13));

L90:
    if (!((colunas_A >= 2))) goto L91;
    prod23 = (prod23 + (a22 * b23));

L91:
    if (!((colunas_A >= 3))) goto L92;
    prod23 = (prod23 + (a23 * b33));

L92:
    printf("%f\n", prod23);
    printf(" \n");

L93:
    printf("]\n");

L94:
    if (!((linhas_A >= 3))) goto L107;
    printf("[ \n");
    if (!((colunas_B >= 1))) goto L98;
    float prod31 = 0.000000;
    if (!((colunas_A >= 1))) goto L95;
    prod31 = (prod31 + (a31 * b11));

L95:
    if (!((colunas_A >= 2))) goto L96;
    prod31 = (prod31 + (a32 * b21));

L96:
    if (!((colunas_A >= 3))) goto L97;
    prod31 = (prod31 + (a33 * b31));

L97:
    printf("%f\n", prod31);
    printf(" \n");

L98:
    if (!((colunas_B >= 2))) goto L102;
    float prod32 = 0.000000;
    if (!((colunas_A >= 1))) goto L99;
    prod32 = (prod32 + (a31 * b12));

L99:
    if (!((colunas_A >= 2))) goto L100;
    prod32 = (prod32 + (a32 * b22));

L100:
    if (!((colunas_A >= 3))) goto L101;
    prod32 = (prod32 + (a33 * b32));

L101:
    printf("%f\n", prod32);
    printf(" \n");

L102:
    if (!((colunas_B >= 3))) goto L106;
    float prod33 = 0.000000;
    if (!((colunas_A >= 1))) goto L103;
    prod33 = (prod33 + (a31 * b13));

L103:
    if (!((colunas_A >= 2))) goto L104;
    prod33 = (prod33 + (a32 * b23));

L104:
    if (!((colunas_A >= 3))) goto L105;
    prod33 = (prod33 + (a33 * b33));

L105:
    printf("%f\n", prod33);
    printf(" \n");

L106:
    printf("]\n");

L107:

L108:
    if (!((produto_possivel == 0))) goto L109;
    printf("O produto NAO e possivel!\n");
    printf("Motivo: O numero de colunas de A deve ser igual ao numero de linhas de B\n");
    printf("Matriz A tem \n");
    printf("%d\n", colunas_A);
    printf("colunas\n");
    printf("Matriz B tem \n");
    printf("%d\n", linhas_B);
    printf("linhas\n");
    printf("Para multiplicar A x B, precisamos: colunas(A) = linhas(B)\n");

L109:
    printf("\n");
    printf("=== PROGRAMA CONCLUIDO ===\n");

L110:

L111:

L112:

L113:
}

