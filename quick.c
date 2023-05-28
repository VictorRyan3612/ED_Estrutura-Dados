void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
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
