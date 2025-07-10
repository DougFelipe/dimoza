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
    printf("   OK: Nó \n");
    printf("%d\n", value);
    printf(" inserido como nova raiz/folha\n");
    return new_node;

L0:
    if (!((value < root->key))) goto L1;
    printf("   --> \n");
    printf("%d\n", value);
    printf(" < \n");
    printf("%d\n", root->key);
    printf(" → inserindo à esquerda\n");
    root->left = insert(root->left, value);

L1:
    if (!((value > root->key))) goto L2;
    printf("   --> \n");
    printf("%d\n", value);
    printf(" > \n");
    printf("%d\n", root->key);
    printf(" → inserindo à direita\n");
    root->right = insert(root->right, value);

L2:
    if (!((value == root->key))) goto L3;
    printf("   AVISO: Valor \n");
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
    printf("BUSCA: Nível \n");
    printf("%d\n", level);
    printf(": examinando nó \n");
    printf("%d\n", node->key);
    if (!((node->left == NULL))) goto L5;
    printf("\n");
    printf("ENCONTRADO: CHAVE MÍNIMA ENCONTRADA:\n");
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
    printf("BUSCA: Nível \n");
    printf("%d\n", level);
    printf(": examinando nó \n");
    printf("%d\n", node->key);
    if (!((node->right == NULL))) goto L7;
    printf("\n");
    printf("ENCONTRADO: CHAVE MÁXIMA ENCONTRADA:\n");
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


void print_single_node(TreeNode* node, int width) {
    if (!((node == NULL))) goto L14;
    int i1 = 1;
L10:
    if (!((i1 <= ((width - 3) / 2)))) goto L11;
    printf(" \n");
    i1 = (i1 + 1);

    goto L10;
L11:
    printf("---\n");
    int j1 = 1;
L12:
    if (!((j1 <= ((width - 3) / 2)))) goto L13;
    printf(" \n");
    j1 = (j1 + 1);

    goto L12;
L13:

L14:
    if (!((node != NULL))) goto L21;
    int value_len = 3;
    int padding = ((width - value_len) / 2);
    int i2 = 1;
L15:
    if (!((i2 <= padding))) goto L16;
    printf(" \n");
    i2 = (i2 + 1);

    goto L15;
L16:
    if (!((node->key < 10))) goto L17;
    printf(" \n");

L17:
    if (!((node->key < 100))) goto L18;
    printf(" \n");

L18:
    printf("%d\n", node->key);
    int j2 = 1;
L19:
    if (!((j2 <= padding))) goto L20;
    printf(" \n");
    j2 = (j2 + 1);

    goto L19;
L20:

L21:
}


void print_connections(int level, int max_height, int nodes_in_level) {
    int total_width = 80;
    int node_width = (total_width / nodes_in_level);
    if (!((level >= max_height))) goto L22;
    return;

L22:
    int i = 1;
L27:
    if (!((i <= nodes_in_level))) goto L28;
    int center = (((i - 1) * node_width) + (node_width / 2));
    int left_child = (center - (node_width / 4));
    int right_child = (center + (node_width / 4));
    int spaces_before_left = (left_child - ((i - 1) * node_width));
    int j = 1;
L23:
    if (!((j <= spaces_before_left))) goto L24;
    printf(" \n");
    j = (j + 1);

    goto L23;
L24:
    printf("/\n");
    int spaces_between = ((right_child - left_child) - 1);
    int k = 1;
L25:
    if (!((k <= spaces_between))) goto L26;
    printf(" \n");
    k = (k + 1);

    goto L25;
L26:
    printf("\\\n");
    i = (i + 1);

    goto L27;
L28:
    printf("\n");
}


void print_level_nodes(TreeNode* root, int level, int nodes_printed, int total_nodes) {
    if (!((level == 1))) goto L29;
    print_single_node(root, (80 / total_nodes));
    return;

L29:
    if (!((root != NULL))) goto L30;
    print_level_nodes(root->left, (level - 1), nodes_printed, total_nodes);
    print_level_nodes(root->right, (level - 1), nodes_printed, total_nodes);

L30:
    if (!((root == NULL))) goto L32;
    if (!((level > 1))) goto L31;
    print_level_nodes(NULL, (level - 1), nodes_printed, total_nodes);
    print_level_nodes(NULL, (level - 1), nodes_printed, total_nodes);

L31:

L32:
}


void print_level_visual(TreeNode* root, int target_level, int spacing) {
    if (!((target_level == 1))) goto L37;
    if (!((root != NULL))) goto L33;
    printf("[\n");
    printf("%d\n", root->key);
    printf("]\n");

L33:
    if (!((root == NULL))) goto L34;
    printf("---\n");

L34:
    int espacos = 1;
L35:
    if (!((espacos <= 4))) goto L36;
    printf(" \n");
    espacos = (espacos + 1);

    goto L35;
L36:
    return;

L37:
    if (!((root != NULL))) goto L38;
    print_level_visual(root->left, (target_level - 1), spacing);
    print_level_visual(root->right, (target_level - 1), spacing);

L38:
    if (!((root == NULL))) goto L39;
    print_level_visual(NULL, (target_level - 1), spacing);
    print_level_visual(NULL, (target_level - 1), spacing);

L39:
}


void print_connections_simple(TreeNode* root, int target_level, int spacing) {
    if (!((target_level == 1))) goto L51;
    if (!((root != NULL))) goto L48;
    int tem_filhos = 0;
    if (!((root->left != NULL))) goto L40;
    tem_filhos = 1;

L40:
    if (!((root->right != NULL))) goto L41;
    tem_filhos = 1;

L41:
    if (!((tem_filhos == 1))) goto L46;
    if (!((root->left != NULL))) goto L42;
    printf("/\n");

L42:
    if (!((root->left == NULL))) goto L43;
    printf(" \n");

L43:
    printf(" \n");
    if (!((root->right != NULL))) goto L44;
    printf("\\\n");

L44:
    if (!((root->right == NULL))) goto L45;
    printf(" \n");

L45:

L46:
    if (!((tem_filhos == 0))) goto L47;
    printf("   \n");

L47:

L48:
    int espacos2 = 1;
L49:
    if (!((espacos2 <= 2))) goto L50;
    printf(" \n");
    espacos2 = (espacos2 + 1);

    goto L49;
L50:
    return;

L51:
    if (!((root != NULL))) goto L53;
    if (!((target_level > 1))) goto L52;
    print_connections_simple(root->left, (target_level - 1), spacing);
    print_connections_simple(root->right, (target_level - 1), spacing);

L52:

L53:
    if (!((root == NULL))) goto L55;
    if (!((target_level > 1))) goto L54;
    print_connections_simple(NULL, (target_level - 1), spacing);
    print_connections_simple(NULL, (target_level - 1), spacing);

L54:

L55:
}


void print_level_order(TreeNode* root) {
    if (!((root == NULL))) goto L56;
    printf("ERRO: Árvore vazia - nada para imprimir\n");
    return;

L56:
    int height = get_height(root);
    printf("VISUALIZAÇÃO HIERÁRQUICA DA BST\n");
    printf("===============================================\n");
    printf("Altura da árvore: \n");
    printf("%d\n", height);
    printf(" níveis\n");
    printf("\n");
    printf("Legenda: [valor] = nó existente | --- = nó ausente\n");
    printf("         /\\ = conexões pai-filho\n");
    printf("\n");
    int level = 1;
L62:
    if (!((level <= height))) goto L63;
    int spaces_before = ((height - level) * 2);
    printf("Nível \n");
    printf("%d\n", level);
    printf(": \n");
    int espacamento = 1;
L57:
    if (!((espacamento <= spaces_before))) goto L58;
    printf(" \n");
    espacamento = (espacamento + 1);

    goto L57;
L58:
    print_level_visual(root, level, 0);
    printf("\n");
    if (!((level < height))) goto L61;
    printf("        \n");
    int espacamento2 = 1;
L59:
    if (!((espacamento2 <= spaces_before))) goto L60;
    printf(" \n");
    espacamento2 = (espacamento2 + 1);

    goto L59;
L60:
    print_connections_simple(root, level, 0);
    printf("\n");

L61:
    level = (level + 1);

    goto L62;
L63:
    printf("\n");
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
    if (!((quantidade <= 0))) goto L64;
    printf("❌ ERRO: Quantidade deve ser positiva!\n");
    printf("Programa encerrado.\n");
    return 1;

L64:
    printf("\n");
    printf("📝 Digite os \n");
    printf("%d\n", quantidade);
    printf(" valores inteiros (um por linha):\n");
    printf("\n");
    i = 1;
L65:
    if (!((i <= quantidade))) goto L66;
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

    goto L65;
L66:
    printf("OK: BST construída com sucesso!\n");
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
    printf("OK: Todas as operações da BST foram executadas com sucesso!\n");
    return 0;
}

