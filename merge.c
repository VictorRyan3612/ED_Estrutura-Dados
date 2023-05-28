

void merge (int v[], int s, int m, int e){
    int p = s;
    int q = m+1;
    for (int i = 0; i < (e-s+1); i++){
        if ((q>e) || ((p<=m) && (v[p] < v[q]))) {
            v[i] = v[p];
            p = p+1;
        }
        else{
            v[i] = v[q];
            q= q+1;
        }
    }
    for (int i = 0; i< (e-s+1); i++){
        v[s+i] = v[i];
    }
}


void merge_sort (v,s,e){
    if (s<e){
        int m =((s+e)/2);
        merge_sort(v,s,m);
        merge_sort(v,m+1,e);
        merge(v,s,m,e);
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
