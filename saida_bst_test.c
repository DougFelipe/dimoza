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
    return new_node;

L0:
    if (!((value < root->key))) goto L1;
    root->left = insert(root->left, value);

L1:
    if (!((value > root->key))) goto L2;
    root->right = insert(root->right, value);

L2:
    return root;
}


void find_min(TreeNode* node, int level) {
    if (!((node == NULL))) goto L3;
    return;

L3:
    if (!((node->left == NULL))) goto L4;
    printf("Chave minima encontrada:\n");
    printf("%d\n", node->key);
    printf("Nivel:\n");
    printf("%d\n", level);
    return;

L4:
    find_min(node->left, (level + 1));
}


void find_max(TreeNode* node, int level) {
    if (!((node == NULL))) goto L5;
    return;

L5:
    if (!((node->right == NULL))) goto L6;
    printf("Chave maxima encontrada:\n");
    printf("%d\n", node->key);
    printf("Nivel:\n");
    printf("%d\n", level);
    return;

L6:
    find_max(node->right, (level + 1));
}


int get_height(TreeNode* node) {
    if (!((node == NULL))) goto L7;
    return 0;

L7:
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    if (!((left_height > right_height))) goto L8;
    return (left_height + 1);

L8:
    return (right_height + 1);
}


void print_given_level(TreeNode* root, int level) {
    if (!((root == NULL))) goto L9;
    return;

L9:
    if (!((level == 1))) goto L10;
    printf("%d ", root->key);
    return;

L10:
    print_given_level(root->left, (level - 1));
    print_given_level(root->right, (level - 1));
}


void print_level_order(TreeNode* root) {
    int height = get_height(root);
    int i = 1;
L11:
    if (!((i <= height))) goto L12;
    printf("--- Nivel\n");
    printf("%d\n", i);
    printf("---\n");
    print_given_level(root, i);
    printf("\n");
    i = (i + 1);

    goto L11;
L12:
}


int main() {
    printf("=== BST - Implementacao Real com Algoritmos Completos ===\n");
    printf("\n");
    printf("A) Construindo BST com algoritmo de insercao recursivo\n");
    TreeNode* root = NULL;
    printf("Inserindo: 50, 30, 20, 40, 70, 60, 80\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("BST construida com algoritmo recursivo real!\n");
    printf("\n");
    printf("B) Busca da chave minima (navegacao a esquerda):\n");
    find_min(root, 1);
    printf("\n");
    printf("C) Busca da chave maxima (navegacao a direita):\n");
    find_max(root, 1);
    printf("\n");
    printf("D) Impressao da arvore nivel por nivel:\n");
    print_level_order(root);
    printf("=== BST implementada com algoritmos reais! ===\n");
    return 0;
}

