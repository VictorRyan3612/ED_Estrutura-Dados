#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLOCK_MONOTONIC 1


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

    for (int i = 0; i < quantidade-1; i++) {
        int valor = rand() % valorMaximo + 1; // Gera um número aleatório entre 1 e valorMaximo
        root = inserir(root, valor);
    }
    

    return root;
}


No* executararvore(int n) {
    No* root = NULL;

    // Inserir n valores aleatórios na árvore, com valores entre 1 e 100
    root = inserirAleatorio(root, n, 100);
    return root;
}


No* buscaPrimeiroValor(No* root){
    return root;
}


int main(int argc, char const *argv[]) {
    struct timespec a, b;
    unsigned int t, n;
    int i;
    
    No* root = NULL;

    n = atoi(argv[1]);
    int valorBuscado = 42;

    root = executararvore(n); // Execução da árvore

    clock_gettime(CLOCK_MONOTONIC, &b);

    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    return 0;
}
