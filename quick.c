
void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}


int partition (int *v[],int s, int e){
    int d = s;
    for (int i =0; i< (e-1); i++){
        if (v[i] < v[e]){
            swap(v[i], v[d+1]);
            d += 1;
        }
        swap (v[d+1], v[i]);

    }
    return d;
}

void quick_sort(int *v[], int s, int e){
    if (s<e){
        int p = partition (v,s,e);
        quick_sort(v,s,p-1);
        quick_sort(v,s+1,e);
    }
}