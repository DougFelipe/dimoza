#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

void mdc(int n, int m, int* r);


int resto_divisao(int n, int m) {
    if (!((m == 0))) goto L0;
    return n;

L0:
    return (n - (m * (n / m)));
}


void mdc(int n, int m, int* r) {
    printf("🔄 Chamada recursiva: mdc(\n");
    printf("%d\n", n);
    printf(", \n");
    printf("%d\n", m);
    printf(")\n");
    if (!((m == 0))) goto L1;
    printf("✅ Caso base alcançado: MDC = \n");
    printf("%d\n", n);
    *r = n;
    return;

L1:
    int resto = resto_divisao(n, m);
    printf("   → Próxima chamada: mdc(\n");
    printf("%d\n", m);
    printf(", \n");
    printf("%d\n", resto);
    printf(") [resto de \n");
    printf("%d\n", n);
    printf(" ÷ \n");
    printf("%d\n", m);
    printf("]\n");
    mdc(m, resto, r);
}


int main() {
    printf("==================================================================\n");
    printf("         MÁXIMO DIVISOR COMUM (MDC) - LINGUAGEM DIMOZA\n");
    printf("==================================================================\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    PRIMEIRO CASO DE TESTE\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    int num1;
    int num2;
    int resultado_mdc;
    printf("📝 Digite os dois números naturais positivos:\n");
    printf("\n");
    printf("🔢 Digite o primeiro número (n):\n");
    float entrada1 = read();
    num1 = entrada1;
    printf("🔢 Digite o segundo número (m):\n");
    float entrada2 = read();
    num2 = entrada2;
    printf("\n");
    printf("🔍 VALIDANDO ENTRADA...\n");
    int dados_validos = 1;
    if (!((num1 <= 0))) goto L2;
    printf("❌ ERRO: O primeiro número deve ser positivo!\n");
    dados_validos = 0;

L2:
    if (!((num2 <= 0))) goto L3;
    printf("❌ ERRO: O segundo número deve ser positivo!\n");
    dados_validos = 0;

L3:
    if (!((dados_validos == 1))) goto L4;
    printf("✅ Entrada validada com sucesso!\n");
    printf("\n");
    printf("📋 DADOS CONFIRMADOS:\n");
    printf("   Primeiro número:  \n");
    printf("%d\n", num1);
    printf("   Segundo número:   \n");
    printf("%d\n", num2);
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    CÁLCULO DO MDC RECURSIVO\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🧮 Calculando MDC(\n");
    printf("%d\n", num1);
    printf(", \n");
    printf("%d\n", num2);
    printf(") usando o algoritmo de Euclides...\n");
    printf("\n");
    printf("🔍 RASTREAMENTO DAS CHAMADAS RECURSIVAS:\n");
    mdc(num1, num2, &resultado_mdc);
    printf("\n");
    printf("🎯 RESULTADO FINAL: O MDC de \n");
    printf("%d\n", num1);
    printf(" e \n");
    printf("%d\n", num2);
    printf(" é \n");
    printf("%d\n", resultado_mdc);
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                    SEGUNDO CASO DE TESTE\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🧪 Teste adicional com valores pré-definidos: MDC(105, 30)\n");
    printf("\n");
    num1 = 105;
    num2 = 30;
    printf("🔍 RASTREAMENTO DAS CHAMADAS RECURSIVAS:\n");
    mdc(num1, num2, &resultado_mdc);
    printf("\n");
    printf("🎯 RESULTADO: O MDC de 105 e 30 é \n");
    printf("%d\n", resultado_mdc);
    printf(" (valor esperado: 15)\n");
    printf("\n");
    printf("==================================================================\n");
    printf("                      PROGRAMA FINALIZADO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("✅ Todos os cálculos foram executados com sucesso!\n");
    printf("\n");

L4:
    if (!((dados_validos == 0))) goto L5;
    printf("\n");
    printf("==================================================================\n");
    printf("                    PROGRAMA ENCERRADO COM ERRO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("❌ O programa foi encerrado devido a entrada inválida.\n");
    printf("\n");
    printf("📋 REQUISITOS PARA EXECUÇÃO:\n");
    printf("   • Os números devem ser naturais estritamente positivos\n");
    printf("   • Valores devem ser maiores que zero\n");
    printf("   • Entrada deve conter apenas números inteiros\n");
    printf("\n");
    printf("💡 DICA: Execute o programa novamente e insira\n");
    printf("         números naturais positivos (> 0).\n");

L5:
}

