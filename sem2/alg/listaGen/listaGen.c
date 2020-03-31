#include <stdio.h>
#include <stdlib.h>
#include "listaGen.h"

struct lista_{
  NO *ini;
  int prof;
};

struct no_{
  int tipo;
  union{ //só pode usar uma de cada vez
    ITEM *atomo;
    NO *sublista;
  }info;
  NO *prox;
};

LISTA *lista_criar(void){
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
  if(lista != NULL){
    lista->ini = NULL;
    lista->prof = 0;
  }
  return lista;
}

void imprimir(NO *cabeca){
  NO *p;
  p = cabeca;
  if(p == NULL) return;
  if(p->tipo == 0) printf("%d\n", p->info.atomo);
  else imprimir(p->info.sublista);
  //p = p->prox; precisa do while (p!=NULL)
  imprimir(p->prox);
}
