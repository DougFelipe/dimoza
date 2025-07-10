#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

int main() {
    printf("==================================================================\n");
    printf("         OPERAÇÕES COM MATRIZES - LINGUAGEM DIMOZA\n");
    printf("==================================================================\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    CONFIGURAÇÃO DAS MATRIZES\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🔢 CONFIGURAÇÃO DA MATRIZ A:\n");
    printf("Digite o número de linhas da Matriz A (1-3):\n");
    float entrada_linhas_A = read();
    int linhas_A = entrada_linhas_A;
    printf("Digite o número de colunas da Matriz A (1-3):\n");
    float entrada_colunas_A = read();
    int colunas_A = entrada_colunas_A;
    printf("\n");
    printf("🔢 CONFIGURAÇÃO DA MATRIZ B:\n");
    printf("Digite o número de linhas da Matriz B (1-3):\n");
    float entrada_linhas_B = read();
    int linhas_B = entrada_linhas_B;
    printf("Digite o número de colunas da Matriz B (1-3):\n");
    float entrada_colunas_B = read();
    int colunas_B = entrada_colunas_B;
    printf("\n");
    printf("🔍 VALIDANDO DIMENSÕES...\n");
    printf("\n");
    int dimensoes_validas = 1;
    if (!((linhas_A <= 0))) goto L0;
    printf("❌ ERRO: Número de linhas da Matriz A deve ser positivo!\n");
    dimensoes_validas = 0;

L0:
    if (!((linhas_A > 3))) goto L1;
    printf("❌ ERRO: Número de linhas da Matriz A não pode exceder 3!\n");
    dimensoes_validas = 0;

L1:
    if (!((colunas_A <= 0))) goto L2;
    printf("❌ ERRO: Número de colunas da Matriz A deve ser positivo!\n");
    dimensoes_validas = 0;

L2:
    if (!((colunas_A > 3))) goto L3;
    printf("❌ ERRO: Número de colunas da Matriz A não pode exceder 3!\n");
    dimensoes_validas = 0;

L3:
    if (!((linhas_B <= 0))) goto L4;
    printf("❌ ERRO: Número de linhas da Matriz B deve ser positivo!\n");
    dimensoes_validas = 0;

L4:
    if (!((linhas_B > 3))) goto L5;
    printf("❌ ERRO: Número de linhas da Matriz B não pode exceder 3!\n");
    dimensoes_validas = 0;

L5:
    if (!((colunas_B <= 0))) goto L6;
    printf("❌ ERRO: Número de colunas da Matriz B deve ser positivo!\n");
    dimensoes_validas = 0;

L6:
    if (!((colunas_B > 3))) goto L7;
    printf("❌ ERRO: Número de colunas da Matriz B não pode exceder 3!\n");
    dimensoes_validas = 0;

L7:
    if (!((dimensoes_validas == 1))) goto L114;
    printf("✅ Dimensões validadas com sucesso!\n");
    printf("\n");
    printf("📋 RESUMO DAS CONFIGURAÇÕES:\n");
    printf("   Matriz A: \n");
    printf("%d\n", linhas_A);
    printf(" × \n");
    printf("%d\n", colunas_A);
    printf("   Matriz B: \n");
    printf("%d\n", linhas_B);
    printf(" × \n");
    printf("%d\n", colunas_B);
    printf("\n");
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
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    ENTRADA DOS ELEMENTOS\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("📝 PREENCHENDO A MATRIZ A:\n");
    printf("Digite os elementos linha por linha...\n");
    printf("\n");
    if (!((linhas_A >= 1))) goto L11;
    printf("🔹 Linha 1 da Matriz A:\n");
    if (!((colunas_A >= 1))) goto L8;
    printf("   A[1,1] = \n");
    a11 = read();

L8:
    if (!((colunas_A >= 2))) goto L9;
    printf("   A[1,2] = \n");
    a12 = read();

L9:
    if (!((colunas_A >= 3))) goto L10;
    printf("   A[1,3] = \n");
    a13 = read();

L10:
    printf("   ✅ Linha 1 preenchida!\n");
    printf("\n");

L11:
    if (!((linhas_A >= 2))) goto L15;
    printf("🔹 Linha 2 da Matriz A:\n");
    if (!((colunas_A >= 1))) goto L12;
    printf("   A[2,1] = \n");
    a21 = read();

L12:
    if (!((colunas_A >= 2))) goto L13;
    printf("   A[2,2] = \n");
    a22 = read();

L13:
    if (!((colunas_A >= 3))) goto L14;
    printf("   A[2,3] = \n");
    a23 = read();

L14:
    printf("   ✅ Linha 2 preenchida!\n");
    printf("\n");

L15:
    if (!((linhas_A >= 3))) goto L19;
    printf("🔹 Linha 3 da Matriz A:\n");
    if (!((colunas_A >= 1))) goto L16;
    printf("   A[3,1] = \n");
    a31 = read();

L16:
    if (!((colunas_A >= 2))) goto L17;
    printf("   A[3,2] = \n");
    a32 = read();

L17:
    if (!((colunas_A >= 3))) goto L18;
    printf("   A[3,3] = \n");
    a33 = read();

L18:
    printf("   ✅ Linha 3 preenchida!\n");
    printf("\n");

L19:
    printf("✅ Matriz A preenchida com sucesso!\n");
    printf("\n");
    printf("📝 PREENCHENDO A MATRIZ B:\n");
    printf("Digite os elementos linha por linha...\n");
    printf("\n");
    if (!((linhas_B >= 1))) goto L23;
    printf("🔹 Linha 1 da Matriz B:\n");
    if (!((colunas_B >= 1))) goto L20;
    printf("   B[1,1] = \n");
    b11 = read();

L20:
    if (!((colunas_B >= 2))) goto L21;
    printf("   B[1,2] = \n");
    b12 = read();

L21:
    if (!((colunas_B >= 3))) goto L22;
    printf("   B[1,3] = \n");
    b13 = read();

L22:
    printf("   ✅ Linha 1 preenchida!\n");
    printf("\n");

L23:
    if (!((linhas_B >= 2))) goto L27;
    printf("🔹 Linha 2 da Matriz B:\n");
    if (!((colunas_B >= 1))) goto L24;
    printf("   B[2,1] = \n");
    b21 = read();

L24:
    if (!((colunas_B >= 2))) goto L25;
    printf("   B[2,2] = \n");
    b22 = read();

L25:
    if (!((colunas_B >= 3))) goto L26;
    printf("   B[2,3] = \n");
    b23 = read();

L26:
    printf("   ✅ Linha 2 preenchida!\n");
    printf("\n");

L27:
    if (!((linhas_B >= 3))) goto L31;
    printf("🔹 Linha 3 da Matriz B:\n");
    if (!((colunas_B >= 1))) goto L28;
    printf("   B[3,1] = \n");
    b31 = read();

L28:
    if (!((colunas_B >= 2))) goto L29;
    printf("   B[3,2] = \n");
    b32 = read();

L29:
    if (!((colunas_B >= 3))) goto L30;
    printf("   B[3,3] = \n");
    b33 = read();

L30:
    printf("   ✅ Linha 3 preenchida!\n");
    printf("\n");

L31:
    printf("✅ Matriz B preenchida com sucesso!\n");
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    MATRIZES INSERIDAS\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("📊 MATRIZ A:\n");
    printf("┌─────────────────┐\n");
    if (!((linhas_A >= 1))) goto L35;
    printf("│ \n");
    if (!((colunas_A >= 1))) goto L32;
    printf("%f\n", a11);
    printf("  \n");

L32:
    if (!((colunas_A >= 2))) goto L33;
    printf("%f\n", a12);
    printf("  \n");

L33:
    if (!((colunas_A >= 3))) goto L34;
    printf("%f\n", a13);
    printf("  \n");

L34:
    printf("│\n");

L35:
    if (!((linhas_A >= 2))) goto L39;
    printf("│ \n");
    if (!((colunas_A >= 1))) goto L36;
    printf("%f\n", a21);
    printf("  \n");

L36:
    if (!((colunas_A >= 2))) goto L37;
    printf("%f\n", a22);
    printf("  \n");

L37:
    if (!((colunas_A >= 3))) goto L38;
    printf("%f\n", a23);
    printf("  \n");

L38:
    printf("│\n");

L39:
    if (!((linhas_A >= 3))) goto L43;
    printf("│ \n");
    if (!((colunas_A >= 1))) goto L40;
    printf("%f\n", a31);
    printf("  \n");

L40:
    if (!((colunas_A >= 2))) goto L41;
    printf("%f\n", a32);
    printf("  \n");

L41:
    if (!((colunas_A >= 3))) goto L42;
    printf("%f\n", a33);
    printf("  \n");

L42:
    printf("│\n");

L43:
    printf("└─────────────────┘\n");
    printf("\n");
    printf("📊 MATRIZ B:\n");
    printf("┌─────────────────┐\n");
    if (!((linhas_B >= 1))) goto L47;
    printf("│ \n");
    if (!((colunas_B >= 1))) goto L44;
    printf("%f\n", b11);
    printf("  \n");

L44:
    if (!((colunas_B >= 2))) goto L45;
    printf("%f\n", b12);
    printf("  \n");

L45:
    if (!((colunas_B >= 3))) goto L46;
    printf("%f\n", b13);
    printf("  \n");

L46:
    printf("│\n");

L47:
    if (!((linhas_B >= 2))) goto L51;
    printf("│ \n");
    if (!((colunas_B >= 1))) goto L48;
    printf("%f\n", b21);
    printf("  \n");

L48:
    if (!((colunas_B >= 2))) goto L49;
    printf("%f\n", b22);
    printf("  \n");

L49:
    if (!((colunas_B >= 3))) goto L50;
    printf("%f\n", b23);
    printf("  \n");

L50:
    printf("│\n");

L51:
    if (!((linhas_B >= 3))) goto L55;
    printf("│ \n");
    if (!((colunas_B >= 1))) goto L52;
    printf("%f\n", b31);
    printf("  \n");

L52:
    if (!((colunas_B >= 2))) goto L53;
    printf("%f\n", b32);
    printf("  \n");

L53:
    if (!((colunas_B >= 3))) goto L54;
    printf("%f\n", b33);
    printf("  \n");

L54:
    printf("│\n");

L55:
    printf("└─────────────────┘\n");
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    OPERAÇÃO 1: SOMA DE MATRIZES\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    int soma_possivel = 0;
    if (!((linhas_A == linhas_B))) goto L57;
    if (!((colunas_A == colunas_B))) goto L56;
    soma_possivel = 1;

L56:

L57:
    if (!((soma_possivel == 1))) goto L70;
    printf("✅ A soma é possível (matrizes de mesma dimensão)\n");
    printf("\n");
    printf("🔢 Calculando A + B...\n");
    printf("\n");
    printf("📊 RESULTADO DA SOMA (A + B):\n");
    printf("┌─────────────────┐\n");
    if (!((linhas_A >= 1))) goto L61;
    printf("│ \n");
    if (!((colunas_A >= 1))) goto L58;
    float soma11 = (a11 + b11);
    printf("%f\n", soma11);
    printf("  \n");

L58:
    if (!((colunas_A >= 2))) goto L59;
    float soma12 = (a12 + b12);
    printf("%f\n", soma12);
    printf("  \n");

L59:
    if (!((colunas_A >= 3))) goto L60;
    float soma13 = (a13 + b13);
    printf("%f\n", soma13);
    printf("  \n");

L60:
    printf("│\n");

L61:
    if (!((linhas_A >= 2))) goto L65;
    printf("│ \n");
    if (!((colunas_A >= 1))) goto L62;
    float soma21 = (a21 + b21);
    printf("%f\n", soma21);
    printf("  \n");

L62:
    if (!((colunas_A >= 2))) goto L63;
    float soma22 = (a22 + b22);
    printf("%f\n", soma22);
    printf("  \n");

L63:
    if (!((colunas_A >= 3))) goto L64;
    float soma23 = (a23 + b23);
    printf("%f\n", soma23);
    printf("  \n");

L64:
    printf("│\n");

L65:
    if (!((linhas_A >= 3))) goto L69;
    printf("│ \n");
    if (!((colunas_A >= 1))) goto L66;
    float soma31 = (a31 + b31);
    printf("%f\n", soma31);
    printf("  \n");

L66:
    if (!((colunas_A >= 2))) goto L67;
    float soma32 = (a32 + b32);
    printf("%f\n", soma32);
    printf("  \n");

L67:
    if (!((colunas_A >= 3))) goto L68;
    float soma33 = (a33 + b33);
    printf("%f\n", soma33);
    printf("  \n");

L68:
    printf("│\n");

L69:
    printf("└─────────────────┘\n");
    printf("\n");
    printf("✅ Soma calculada com sucesso!\n");

L70:
    if (!((soma_possivel == 0))) goto L71;
    printf("❌ A soma NÃO é possível!\n");
    printf("\n");
    printf("📋 MOTIVO: As matrizes devem ter as mesmas dimensões\n");
    printf("   • Matriz A: \n");
    printf("%d\n", linhas_A);
    printf(" × \n");
    printf("%d\n", colunas_A);
    printf("   • Matriz B: \n");
    printf("%d\n", linhas_B);
    printf(" × \n");
    printf("%d\n", colunas_B);
    printf("\n");
    printf("💡 DICA: Para somar matrizes, elas devem ter\n");
    printf("          exatamente as mesmas dimensões.\n");

L71:
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  OPERAÇÃO 2: MULTIPLICAÇÃO DE MATRIZES\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    int produto_possivel = 0;
    if (!((colunas_A == linhas_B))) goto L72;
    produto_possivel = 1;

L72:
    if (!((produto_possivel == 1))) goto L112;
    printf("✅ A multiplicação é possível!\n");
    printf("\n");
    printf("📐 Dimensão do resultado: \n");
    printf("%d\n", linhas_A);
    printf(" × \n");
    printf("%d\n", colunas_B);
    printf("\n");
    printf("🔢 Calculando A × B...\n");
    printf("\n");
    printf("📊 RESULTADO DA MULTIPLICAÇÃO (A × B):\n");
    printf("┌─────────────────┐\n");
    if (!((linhas_A >= 1))) goto L85;
    printf("│ \n");
    if (!((colunas_B >= 1))) goto L76;
    float prod11 = 0.000000;
    if (!((colunas_A >= 1))) goto L73;
    prod11 = (prod11 + (a11 * b11));

L73:
    if (!((colunas_A >= 2))) goto L74;
    prod11 = (prod11 + (a12 * b21));

L74:
    if (!((colunas_A >= 3))) goto L75;
    prod11 = (prod11 + (a13 * b31));

L75:
    printf("%f\n", prod11);
    printf("  \n");

L76:
    if (!((colunas_B >= 2))) goto L80;
    float prod12 = 0.000000;
    if (!((colunas_A >= 1))) goto L77;
    prod12 = (prod12 + (a11 * b12));

L77:
    if (!((colunas_A >= 2))) goto L78;
    prod12 = (prod12 + (a12 * b22));

L78:
    if (!((colunas_A >= 3))) goto L79;
    prod12 = (prod12 + (a13 * b32));

L79:
    printf("%f\n", prod12);
    printf("  \n");

L80:
    if (!((colunas_B >= 3))) goto L84;
    float prod13 = 0.000000;
    if (!((colunas_A >= 1))) goto L81;
    prod13 = (prod13 + (a11 * b13));

L81:
    if (!((colunas_A >= 2))) goto L82;
    prod13 = (prod13 + (a12 * b23));

L82:
    if (!((colunas_A >= 3))) goto L83;
    prod13 = (prod13 + (a13 * b33));

L83:
    printf("%f\n", prod13);
    printf("  \n");

L84:
    printf("│\n");

L85:
    if (!((linhas_A >= 2))) goto L98;
    printf("│ \n");
    if (!((colunas_B >= 1))) goto L89;
    float prod21 = 0.000000;
    if (!((colunas_A >= 1))) goto L86;
    prod21 = (prod21 + (a21 * b11));

L86:
    if (!((colunas_A >= 2))) goto L87;
    prod21 = (prod21 + (a22 * b21));

L87:
    if (!((colunas_A >= 3))) goto L88;
    prod21 = (prod21 + (a23 * b31));

L88:
    printf("%f\n", prod21);
    printf("  \n");

L89:
    if (!((colunas_B >= 2))) goto L93;
    float prod22 = 0.000000;
    if (!((colunas_A >= 1))) goto L90;
    prod22 = (prod22 + (a21 * b12));

L90:
    if (!((colunas_A >= 2))) goto L91;
    prod22 = (prod22 + (a22 * b22));

L91:
    if (!((colunas_A >= 3))) goto L92;
    prod22 = (prod22 + (a23 * b32));

L92:
    printf("%f\n", prod22);
    printf("  \n");

L93:
    if (!((colunas_B >= 3))) goto L97;
    float prod23 = 0.000000;
    if (!((colunas_A >= 1))) goto L94;
    prod23 = (prod23 + (a21 * b13));

L94:
    if (!((colunas_A >= 2))) goto L95;
    prod23 = (prod23 + (a22 * b23));

L95:
    if (!((colunas_A >= 3))) goto L96;
    prod23 = (prod23 + (a23 * b33));

L96:
    printf("%f\n", prod23);
    printf("  \n");

L97:
    printf("│\n");

L98:
    if (!((linhas_A >= 3))) goto L111;
    printf("│ \n");
    if (!((colunas_B >= 1))) goto L102;
    float prod31 = 0.000000;
    if (!((colunas_A >= 1))) goto L99;
    prod31 = (prod31 + (a31 * b11));

L99:
    if (!((colunas_A >= 2))) goto L100;
    prod31 = (prod31 + (a32 * b21));

L100:
    if (!((colunas_A >= 3))) goto L101;
    prod31 = (prod31 + (a33 * b31));

L101:
    printf("%f\n", prod31);
    printf("  \n");

L102:
    if (!((colunas_B >= 2))) goto L106;
    float prod32 = 0.000000;
    if (!((colunas_A >= 1))) goto L103;
    prod32 = (prod32 + (a31 * b12));

L103:
    if (!((colunas_A >= 2))) goto L104;
    prod32 = (prod32 + (a32 * b22));

L104:
    if (!((colunas_A >= 3))) goto L105;
    prod32 = (prod32 + (a33 * b32));

L105:
    printf("%f\n", prod32);
    printf("  \n");

L106:
    if (!((colunas_B >= 3))) goto L110;
    float prod33 = 0.000000;
    if (!((colunas_A >= 1))) goto L107;
    prod33 = (prod33 + (a31 * b13));

L107:
    if (!((colunas_A >= 2))) goto L108;
    prod33 = (prod33 + (a32 * b23));

L108:
    if (!((colunas_A >= 3))) goto L109;
    prod33 = (prod33 + (a33 * b33));

L109:
    printf("%f\n", prod33);
    printf("  \n");

L110:
    printf("│\n");

L111:
    printf("└─────────────────┘\n");
    printf("\n");
    printf("✅ Multiplicação calculada com sucesso!\n");

L112:
    if (!((produto_possivel == 0))) goto L113;
    printf("❌ A multiplicação NÃO é possível!\n");
    printf("\n");
    printf("📋 MOTIVO: O número de colunas de A deve ser igual\n");
    printf("          ao número de linhas de B\n");
    printf("\n");
    printf("   • Matriz A tem \n");
    printf("%d\n", colunas_A);
    printf(" colunas\n");
    printf("   • Matriz B tem \n");
    printf("%d\n", linhas_B);
    printf(" linhas\n");
    printf("\n");
    printf("💡 CONDIÇÃO: Para multiplicar A × B, precisamos:\n");
    printf("             colunas(A) = linhas(B)\n");

L113:
    printf("\n");
    printf("==================================================================\n");
    printf("                      PROGRAMA FINALIZADO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("✅ Todas as operações foram executadas com sucesso!\n");
    printf("\n");
    printf("      OPERAÇÕES REALIZADAS:\n");
    printf("   • Validação de dimensões\n");
    printf("   • Verificação de compatibilidade para operações\n");
    printf("   • Cálculo de soma de matrizes\n");
    printf("   • Cálculo de multiplicação de matrizes\n");

L114:
    if (!((dimensoes_validas == 0))) goto L115;
    printf("\n");
    printf("==================================================================\n");
    printf("                    PROGRAMA ENCERRADO COM ERRO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("❌ O programa foi encerrado devido a dimensões inválidas.\n");
    printf("\n");
    printf("📋 REQUISITOS PARA EXECUÇÃO:\n");
    printf("   • Dimensões devem ser números inteiros positivos\n");
    printf("   • Dimensões devem estar entre 1 e 3 (inclusive)\n");
    printf("   • Tanto linhas quanto colunas devem ser válidas\n");
    printf("\n");
    printf("💡 DICA: Execute o programa novamente e insira\n");
    printf("         valores válidos para as dimensões.\n");

L115:
}

