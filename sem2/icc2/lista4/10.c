#include <stdio.h>
#include <stdlib.h>

#define inf 1000000

int merge(int *mat, int ini, int meio, int fim){
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
  L[n1] = inf; //infinito
  R[n2] = inf; //infinito
  k = ini;
  int ninv = 0;
  int esq = 0;
  i = 0;
  j = 0;
  while(k <= fim){
    if(L[i]<R[j]){
      A[k++] = L[i++];
      esq++;
    }
    else{
      A[k++] = R[j++];
      ninv += esq;
    }
  }

  //passando o vetor ordenado pro vetor original:
  for(k=ini; k<=fim; k++){
    mat[k] = A[k];
  }

  for (int i = ini; i <= fim; i++) {
    printf("%s%d%s",i==ini?"(":"",mat[i],i!=fim?", ":") -> L:");
  }
  for (int i = ini; i <= meio; i++) {
    printf("%s%d%s",i==ini?"(":"",mat[i],i!=meio?", ":")   R:");
  }
  for (int i = meio+1; i <= fim; i++) {
    printf("%s%d%s",i==meio+1?"(":"",mat[i],i!=fim?", ":")\n");
  }
  free(A);
  free(R);
  free(L);
  return ninv;
}

int mergeSort(int *mat, int ini, int fim){
  if(fim-ini == 0) return 0;
  int meio = (ini+fim)/2;
  return mergeSort(mat, ini, meio) + mergeSort(mat, meio+1, fim) + merge(mat, ini, meio, fim);
}

int main(){
  int i, ini, fim, tam;
  int *mat1, *mat2;
  scanf("%d", &tam);
  ini = 0;
  fim = tam-1;
  mat1 = (int *)malloc(tam * sizeof(int));
  mat2 = (int *)malloc(tam * sizeof(int));
  for(i=0; i<tam; i++){
    scanf("%d", &mat1[i]);
  }
  for(i=0; i<tam; i++){
    scanf("%d", &mat2[i]);
  }
  int a = mergeSort(mat1, ini, fim);
  int b = mergeSort(mat2, ini, fim);
  printf("%d\n", a);
  printf("%d\n", b);
  printf("%d\n", abs(a-b));


  /*for(i=ini; i<=fim; i++){
    printf("%d ", mat[i]);
  }
  printf("\n");*/
  free(mat1);
  free(mat2);
  return 0;
}
