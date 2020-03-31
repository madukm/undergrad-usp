#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define TAM 6

struct fila_{
  int *item[TAM];
  int ini;
  int fim;
  int tamanho;
};

FILA *fila_criar(void){
  FILA *f = malloc(sizeof(FILA));
  f->ini = 0;
  f->fim = 0;
  f->tamanho = 0;
  return f;
}

bool fila_cheia(FILA *f){
  return(f->tamanho == TAM);
}

bool fila_vazia(FILA *f){
  return(f->tamanho == 0);
}

bool fila_inserir(FILA *f, int i){
  if(f!=NULL && !fila_cheia(f)){
    fila->item[fila->fim] = i;
    fila->fim = (fila->fim + 1)%TAM;
    fila->tamanho++;
    return TRUE;
  }
  return FALSE;
}

int fila_remover(FILA *f){
  if(f!=NULL && !fila_vazia(f)){
    int i = f->item[f->ini];
    f->item[f->ini] = NULL;
    f->ini = (f->ini+1)%TAM;
    f->tamanho--;
    return i;
  }
  return NULL;
}
