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
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    } else {
        if (valor <= raiz->valor) {
            raiz->esquerda = inserir(raiz->esquerda, valor);
        } else {
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
}

// Função para percorrer a árvore em ordem (in-order traversal)
void percorrer(No* raiz) {
    if (raiz != NULL) {
        percorrer(raiz->esquerda);
        printf("%d ", raiz->valor);
        percorrer(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;

    // Exemplo de inserção de valores na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Exemplo de percorrimento da árvore em ordem
    printf("Árvore em ordem: ");
    percorrer(raiz);
    printf("\n");

    return 0;
}