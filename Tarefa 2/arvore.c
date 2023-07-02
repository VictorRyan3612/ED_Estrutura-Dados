#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Função para inserir valores aleatórios na árvore
No* inserirAleatorio(No* root, int quantidade, int valorMaximo) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    for (int i = 0; i < quantidade; i++) {
        int valor = rand() % valorMaximo + 1; // Gera um número aleatório entre 1 e valorMaximo
        root = inserir(root, valor);
    }

    return root;
}

int main() {
    No* root = NULL;

    // Inserir 10 valores aleatórios na árvore, com valores entre 1 e 100
    root = inserirAleatorio(root, 10, 100);

    // Exemplo de percorrimento da árvore em ordem
    printf("Árvore em ordem: ");
    percorrer(root);
    printf("\n");

    return 0;
}
