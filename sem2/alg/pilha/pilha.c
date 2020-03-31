#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha_{
  ITEM *item[TAM];
  int topo;
};

PILHA *pilha_criar(void){
  PILHA *p = (PILHA *)malloc(sizeof(PILHA));
  if(p != NULL)
    p->topo = 0;
  return p;
}
void pilha_apagar(PILHA **p){

}

bool pilha_vazia(PILHA *p){
  return (p != NULL) ? p->topo == 0 : ERRO);
}

bool pilha_cheia(PILHA *p){
  return (p != NULL) ? p->topo == TAM : ERRO);
}

bool pilha_empilhar(PILHA *p, ITEM *i){
  if(p!=NULL && !pilha_cheia(p)){
    p->item[p->topo] = item;
    p->topo++;
    return TRUE;
  }
  return ERRO;
}

ITEM *pilha_desempilhar(PILHA *p){
  ITEM *i;
  if(p!=NULL && !pilha_cheia(p)){
    i = p->item[p->topo-1];
    pilha->topo--;
    return i;
  }
  return NULL;
}
void pilha_imprimir(PILHA *p){
  int i = p->topo;
  while(i>=0){
    imprimir_item(p->item[i]);
    i--;
  }
}

PILHA *pilha_inverter(PILHA *p){
  PILHA *u = pilha_criar;
  for(int i=0; i<p->topo; i++){
    u->item[i] = pilha_desempilhar(p);
    u->topo++;
  }
  return u;
}
