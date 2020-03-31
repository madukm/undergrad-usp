#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
/*
p1, p2
coloca a p1 na p2 invertida
retira de p2
coloca a p2 de volta na p1

o tad pilha nesse caso nao se altera
com excecao da operacao de desempilhar
como em uma fila a remocao é feita
sempre no inicio e em pilha sempre no fim
(topo) existe a necessidade de alteracao
da alteracao de desempilhar.
*/

ITEM *pilha_desempilhar(PILHA *p){
  PILHA *a;
  a = pilha_criar();
  ...
  while(!pilha_vazia(p)){
    pilha_empilhar(a, pilha_desempilhar(p));
  }
  ITEM *x = pilha_desempilhar(a);
  while(!pilha_vazia(a)){
    pilha_empilhar(p, pilha_desempilhar(a));
  }
  return x;
}
