

void merge (int v[], int s, int m, int e){
    int p = s;
    int q = m+1;
    for (int i; i < (e-s+1); i++){
        if ((q>e) || ((p<=m) && (v[p] < v[q]))) {
            v[i] = v[p];
            p = p+1;
        }
        else{
            v[i] = v[q];
            q= q+1;
        }
    }
    for (int i; i< (e-s+1); i++){
        v[s+i-1] = v[i];
    }
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
