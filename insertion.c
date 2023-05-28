
void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


void insertion(int v[], int n){
    for (int i = 0; i<2;i++){
        int j = i;
        while ((j>1) && (v[j] < v[j-1])){
            swap (v[j], v[j-1]);
            j = j-1;
        }
    }
}