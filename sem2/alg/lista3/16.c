#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int iguais(PILHA *p1, PILHA *p2){
  if(piliha_tamanho(p1) != pilha_tamanho(p2))
    return 0;
  PILHA *a1, *a2;
  ITEM *i1, *i2;
  a1 = pilha_copia(p1);
  a2 = pilha_copia(p2);
  while(!pilha_vazia(p1) && !pilha_vazia(p2)){
    i1 = pilha_desempilhar(a1);
    i2 = pilha_desempilhar(a2);
    if(i1 != i2){
      free(a1);
      free(a2);
      free(i1);//conferir se apaga i1 ou i2
      free(i2);
      return 0;

    }
  }
  free(a1);
  free(a2);
  free(i1);
  free(i2);
  return 1;
}
