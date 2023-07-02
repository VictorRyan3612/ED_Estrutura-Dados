 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define CLOCK_MONOTONIC 1


void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


void insertion(int v[], int n){
    for (int i = 0; i<n;i++){
        int j = i;
        while ((j>0) && (v[j] < v[j-1])){
            swap (&v[j], &v[j-1]);
            j = j-1;
        }
    }
}

void criarvetor(int v[], int n)
{
    // Preenche o vetor com valores aleatórios em ordem crescente
    srand(time(NULL));
    v[0] = rand();
    for (int i = 1; i < n; i++){
        v[i] = v[i - 1] + rand();
    }
}

int main(int argc, char const* argv[]) {
    struct timespec a, b;
    unsigned int t, n;
    int *v;

    n = atoi(argv[1]);
    v = (int*)malloc(n * sizeof(int));

    clock_gettime(CLOCK_MONOTONIC, &b);

    insertion(v, n);

    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);
    return 0;
}