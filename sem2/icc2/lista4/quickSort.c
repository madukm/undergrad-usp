#include <stdio.h>

void quickSort(int v[], int ini, int fim){
  int i, j, pivo, aux;
  i = ini;
  j = fim;
  pivo = (ini+fim)/2;
  while(i<=j){
    while(v[i]<pivo)
      i++;
    while(v[j]>pivo)
      j--;
    if(i<j){
      aux = v[i];
      v[i]=v[j];
      v[j]=aux;
      i++;
      j--;
    }
  }
  if(j>ini) quickSort(v, ini, j);
  if(i<fim) quickSort(v, i, fim);
}
