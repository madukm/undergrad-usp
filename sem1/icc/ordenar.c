#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ordena(int *vetor, int ini, int fim){
  int i, j, pivo, aux;
  i = ini;
  j = fim;
  pivo = vetor[(ini+fim)/2];
  while(i<=j){
    while(vetor[i] < pivo){
      i++;
    }
    while(vetor[j] > pivo){
      j--;
    }
    if(i<=j){
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
      i++;
      j--;
    }
  }
  if(j > ini){
    ordena(vetor, ini, j);
  }
  if(i < fim){
    ordena(vetor, i, fim);
  }
}

int main(){
  int i;
  int vetor[10] = {10, 3, 7, 6, 2, 4, 1, 8, 9, 5};
  ordena(vetor, 0, 9);
  for(i=0; i<10; i++){
    printf("%d ", vetor[i]);
  }
  return 0;
}
