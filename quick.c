
void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}


void partition (int *v[],int s, int e){
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