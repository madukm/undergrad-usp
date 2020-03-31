#include <stdio.h>
#include <stdlib.h>

#define inf 1000000
#define N 5

void merge(int v[], int ini, int meio, int fim){
  int n1 = meio-ini+1;
  int n2 = fim-meio;
  int *L, *R, *A;
  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));
  A = (int *)malloc((n1+n2) * sizeof(int));
  for(int i=0; i<n1; i++){
    L[i] = v[ini+i];
  }
  for(int i=0; i<n2; i++){
    R[i] = v[meio+i+1];
  }
  L[n1] = inf;
  R[n2] = inf;
  int k = ini;
  int i = 0, j = 0;
  while(k<=fim){
    if(L[i]<R[j]){
      A[k++] = L[i++];
    }
    else{
      A[k++] = R[j++];
    }
  }
  for(int i=ini; i<=fim; i++){
    v[i] = A[i];
  }
  free(L);
  free(R);
  free(A);
}

void mergeSort(int v[], int ini, int fim){
  if(ini>=fim)return;
  else{
    int meio = (ini+fim)/2;
    mergeSort(v, ini, meio);
    mergeSort(v, meio+1, fim);
    merge(v, ini, meio, fim);
  }
}

int main(){
  int mat[N];
  for(int i=0; i<N; i++){
    scanf("%d", &mat[i]);
  }
  mergeSort(mat, 0, N-1);
  for(int i=0; i<N; i++){
    printf("%d", mat[i]);
  }
  return 0;
}
