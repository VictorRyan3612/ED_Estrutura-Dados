#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLOCK_MONOTONIC 1

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
    int altura;
} No;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No* root) {
    if (root == NULL) {
        return 0;
    }
    return root->altura;
}

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int fatorBalanceamento(No* root) {
    if (root == NULL) {
        return 0;
    }
    return altura(root->esquerda) - altura(root->direita);
}

No* inserir(No* root, int valor) {
    if (root == NULL) {
        return criarNo(valor);
    }

    if (valor < root->valor) {
        root->esquerda = inserir(root->esquerda, valor);
    } else if (valor > root->valor) {
        root->direita = inserir(root->direita, valor);
    } else {
        return root; // Não permite valores duplicados
    }

    root->altura = 1 + max(altura(root->esquerda), altura(root->direita));

    int balanceamento = fatorBalanceamento(root);

    if (balanceamento > 1 && valor < root->esquerda->valor) {
        return rotacaoDireita(root);
    }

    if (balanceamento < -1 && valor > root->direita->valor) {
        return rotacaoEsquerda(root);
    }

    if (balanceamento > 1 && valor > root->esquerda->valor) {
        root->esquerda = rotacaoEsquerda(root->esquerda);
        return rotacaoDireita(root);
    }

    if (balanceamento < -1 && valor < root->direita->valor) {
        root->direita = rotacaoDireita(root->direita);
        return rotacaoEsquerda(root);
    }

    return root;
}

void percorrer(No* root) {
    if (root != NULL) {
        percorrer(root->esquerda);
        printf("%d ", root->valor);
        percorrer(root->direita);
    }
}

No* inserirAleatorio(No* root, int quantidade, int valorMaximo) {
    srand(time(NULL));

    for (int i = 0; i < quantidade; i++) {
        int valor = rand() % valorMaximo + 1;
        root = inserir(root, valor);
    }

    return root;
}

No* executarArvore(int n) {
    No* root = NULL;
    root = inserirAleatorio(root, n, 100);
    return root;
}

No* buscaPrimeiroValor(No* root) {
    return root;
}
// Função para imprimir a árvore de forma visual
void visualizarArvore(No* root, int nivel) {
    if (root == NULL) {
        return;
    }

    nivel += 4;

    visualizarArvore(root->direita, nivel);

    printf("\n");

    for (int i = 4; i < nivel; i++) {
        printf(" ");
    }

    printf("%d(%d)\n", root->valor,nivel/4);

    visualizarArvore(root->esquerda, nivel);
}
int main(int argc, char const *argv[]) {
    struct timespec a, b;
    unsigned int t, n;

    No* root = NULL;
    No* primeiroroot = NULL;
    
    n = atoi(argv[1]);

    
    root = executarArvore(n);

    clock_gettime(CLOCK_MONOTONIC, &b);
    primeiroroot = buscaPrimeiroValor(root);
    clock_gettime(CLOCK_MONOTONIC, &a);
    
    // printf("Árvore completa:\n");
    // visualizarArvore(root, 0); 

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    return 0;
}
