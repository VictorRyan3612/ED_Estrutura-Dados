#include <time.h>
#include <stdio.h>
// #include <stdlib.h>

#define CLOCK_MONOTONIC 1




void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int *v, int s, int e)
{
    int pivot = v[e];
    int i = s - 1;

    for (int j = s; j <= e - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }

    swap(&v[i + 1], &v[e]);
    return i + 1;
}

void quick_sort(int *v, int s, int e)
{
    if (s < e)
    {
        int p = partition(v, s, e);
        quick_sort(v, s, p - 1);
        quick_sort(v, p + 1, e);
    }
}

criarvetor(int v[], int n)
{
    // Preenche o vetor com valores aleatórios em ordem crescente
    srand(time(NULL));
    v[0] = rand();
    for (int i = 1; i < n; i++){
        v[i] = v[i - 1] + rand();
    }
}




int main(int argc, char const *argv[])
{
    struct timespec a, b;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *) malloc(n * sizeof(int));

    criarvetor(v, n);


    clock_gettime(CLOCK_MONOTONIC, &b);
    quick_sort(v, 0, n-1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}
