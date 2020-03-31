//MERGE SORT

#include <stdio.h>
#include <stdlib.h>

void intercala(int *mat, int ini, int meio, int fim){
  int i, j, k;
  int n1 = meio - ini + 1;
  int n2 = fim - meio;
  int *L, *R, *A;
  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));
  A = (int *)malloc((n1+n2) * sizeof(int));
  for(i=0; i<n1; i++)
    L[i] = mat[i+ini];
  for(i=0; i<n2; i++)
    R[i] = mat[meio+i+1];
  L[n1] = 1000000; //infinito
  R[n2] = 1000000; //infinito
  k = ini;
  i = 0;
  j = 0;
  while(k <= fim){
    if(L[i]<R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    k++;
  }
  //passando o vetor ordenado pro vetor original:
  for(k=ini; k<=fim; k++){
    mat[k] = A[k];
  }
  free(A);
  free(R);
  free(L);
}

void ordena(int *mat, int ini, int fim){
  if(ini<fim){
    int meio = (ini+fim)/2;
    ordena(mat, ini, meio);
    ordena(mat, meio+1, fim);
    intercala(mat, ini, meio, fim);
  }
}

int main(){
  int i, ini, fim, tam;
  int *mat;
  scanf("%d", &tam);
  ini = 0;
  fim = tam-1;
  mat = (int *)malloc(tam * sizeof(int));
  for(i=0; i<tam; i++){
    scanf("%d", &mat[i]);
  }
  ordena(mat, ini, fim);
  for(i=ini; i<=fim; i++){
    printf("%d ", mat[i]);
  }
  printf("\n");
  free(mat);
  return 0;
}
