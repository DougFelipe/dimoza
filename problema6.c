#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float read() { float v; if (scanf("%f", &v)!=1) return -1.0f; return v;}

typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* insert(TreeNode* root, int value) {
    if (!((root == NULL))) goto L0;
    TreeNode* new_node = malloc(sizeof(struct TreeNode));
    new_node->key = value;
    new_node->left = NULL;
    new_node->right = NULL;
    printf("   ✅ Nó \n");
    printf("%d\n", value);
    printf(" inserido como nova raiz/folha\n");
    return new_node;

L0:
    if (!((value < root->key))) goto L1;
    printf("   🔄 \n");
    printf("%d\n", value);
    printf(" < \n");
    printf("%d\n", root->key);
    printf(" → inserindo à esquerda\n");
    root->left = insert(root->left, value);

L1:
    if (!((value > root->key))) goto L2;
    printf("   🔄 \n");
    printf("%d\n", value);
    printf(" > \n");
    printf("%d\n", root->key);
    printf(" → inserindo à direita\n");
    root->right = insert(root->right, value);

L2:
    if (!((value == root->key))) goto L3;
    printf("   ⚠️  Valor \n");
    printf("%d\n", value);
    printf(" já existe - ignorando duplicata\n");

L3:
    return root;
}


void find_min(TreeNode* node, int level) {
    if (!((node == NULL))) goto L4;
    printf("❌ Árvore vazia - sem valor mínimo\n");
    return;

L4:
    printf("🔍 Nível \n");
    printf("%d\n", level);
    printf(": examinando nó \n");
    printf("%d\n", node->key);
    if (!((node->left == NULL))) goto L5;
    printf("\n");
    printf("🎯 CHAVE MÍNIMA ENCONTRADA:\n");
    printf("   Valor: \n");
    printf("%d\n", node->key);
    printf("   Nível: \n");
    printf("%d\n", level);
    printf("   (Extremo esquerdo da árvore)\n");
    return;

L5:
    printf(" → continuando à esquerda\n");
    find_min(node->left, (level + 1));
}


void find_max(TreeNode* node, int level) {
    if (!((node == NULL))) goto L6;
    printf("❌ Árvore vazia - sem valor máximo\n");
    return;

L6:
    printf("🔍 Nível \n");
    printf("%d\n", level);
    printf(": examinando nó \n");
    printf("%d\n", node->key);
    if (!((node->right == NULL))) goto L7;
    printf("\n");
    printf("🎯 CHAVE MÁXIMA ENCONTRADA:\n");
    printf("   Valor: \n");
    printf("%d\n", node->key);
    printf("   Nível: \n");
    printf("%d\n", level);
    printf("   (Extremo direito da árvore)\n");
    return;

L7:
    printf(" → continuando à direita\n");
    find_max(node->right, (level + 1));
}


int get_height(TreeNode* node) {
    if (!((node == NULL))) goto L8;
    return 0;

L8:
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    if (!((left_height > right_height))) goto L9;
    return (left_height + 1);

L9:
    return (right_height + 1);
}


void print_given_level(TreeNode* root, int level) {
    if (!((root == NULL))) goto L10;
    return;

L10:
    if (!((level == 1))) goto L11;
    printf("  \n");
    printf("%d\n", root->key);
    return;

L11:
    print_given_level(root->left, (level - 1));
    print_given_level(root->right, (level - 1));
}


void print_level_order(TreeNode* root) {
    if (!((root == NULL))) goto L12;
    printf("❌ Árvore vazia - nada para imprimir\n");
    return;

L12:
    int height = get_height(root);
    int i = 1;
    printf("📊 ESTRUTURA DA ÁRVORE (por níveis):\n");
    printf("   Altura total: \n");
    printf("%d\n", height);
    printf(" níveis\n");
    printf("\n");
L13:
    if (!((i <= height))) goto L14;
    printf("🌳 Nível \n");
    printf("%d\n", i);
    printf(":\n");
    print_given_level(root, i);
    printf("\n");
    i = (i + 1);

    goto L13;
L14:
    printf("✅ Visualização completa da BST finalizada\n");
}


int main() {
    printf("==================================================================\n");
    printf("         ÁRVORE BINÁRIA DE BUSCA (BST) - LINGUAGEM DIMOZA\n");
    printf("==================================================================\n");
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  OPERAÇÃO A: CONSTRUÇÃO DA BST\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    TreeNode* root = NULL;
    int quantidade;
    int i;
    printf("🔢 Digite a quantidade de valores a inserir na BST:\n");
    float entrada_qtd = read();
    quantidade = entrada_qtd;
    if (!((quantidade <= 0))) goto L15;
    printf("❌ ERRO: Quantidade deve ser positiva!\n");
    printf("Programa encerrado.\n");
    return 1;

L15:
    printf("\n");
    printf("📝 Digite os \n");
    printf("%d\n", quantidade);
    printf(" valores inteiros (um por linha):\n");
    printf("\n");
    i = 1;
L16:
    if (!((i <= quantidade))) goto L17;
    printf("🔢 Valor \n");
    printf("%d\n", i);
    printf(": \n");
    float entrada_valor = read();
    int valor = entrada_valor;
    printf("🌱 Inserindo \n");
    printf("%d\n", valor);
    printf(" na BST...\n");
    root = insert(root, valor);
    printf("\n");
    i = (i + 1);

    goto L16;
L17:
    printf("✅ BST construída com sucesso!\n");
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  OPERAÇÃO B: BUSCA DA CHAVE MÍNIMA\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🔍 Buscando a chave mínima (navegação à esquerda)...\n");
    printf("\n");
    find_min(root, 1);
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  OPERAÇÃO C: BUSCA DA CHAVE MÁXIMA\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🔍 Buscando a chave máxima (navegação à direita)...\n");
    printf("\n");
    find_max(root, 1);
    printf("\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("                  OPERAÇÃO D: VISUALIZAÇÃO DA BST\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    printf("\n");
    printf("🌳 Imprimindo árvore binária de busca por níveis...\n");
    printf("\n");
    print_level_order(root);
    printf("\n");
    printf("==================================================================\n");
    printf("                      PROGRAMA FINALIZADO\n");
    printf("==================================================================\n");
    printf("\n");
    printf("✅ Todas as operações da BST foram executadas com sucesso!\n");
    return 0;
}

