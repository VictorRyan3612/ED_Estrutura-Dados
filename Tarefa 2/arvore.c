#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserir(No* root, int valor) {
    if (root == NULL) {
        return criarNo(valor);
    } else {
        if (valor <= root->valor) {
            root->esquerda = inserir(root->esquerda, valor);
        } else {
            root->direita = inserir(root->direita, valor);
        }
        return root;
    }
}

// Função para percorrer a árvore em ordem (in-order traversal)
void percorrer(No* root) {
    if (root != NULL) {
        percorrer(root->esquerda);
        printf("%d ", root->valor);
        percorrer(root->direita);
    }
}

int main() {
    No* root = NULL;

    // Exemplo de inserção de valores na árvore
    root = inserir(root, 50);
    root = inserir(root, 30);
    root = inserir(root, 70);
    root = inserir(root, 20);
    root = inserir(root, 40);
    root = inserir(root, 60);
    root = inserir(root, 80);

    // Exemplo de percorrimento da árvore em ordem
    printf("Árvore em ordem: ");
    percorrer(root);
    printf("\n");

    return 0;
}
