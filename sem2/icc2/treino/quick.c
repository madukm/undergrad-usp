#include <stdio.h>
#include <stdlib.h>

#define N 5

void quickSort(int v[], int ini, int fim){
  int i, j, pivo, aux;
  i = ini;
  j = fim;
  pivo = v[(ini+fim)/2];
  while(i<=j){
    while(v[i]<pivo){
      i++;
    }
    while(v[j]>pivo){
      j--;
    }
    if(i<=j){
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    }
  }
  if(j>ini) quickSort(v, ini, j);
  if(i<fim) quickSort(v, i, fim);
}

int main(){
  int mat[N];
  for(int i=0; i<N; i++){
    scanf("%d", &mat[i]);
  }
  quickSort(mat, 0, N-1);
  for(int i=0; i<N; i++){
    printf("%d", mat[i]);
  }
  return 0;
}
