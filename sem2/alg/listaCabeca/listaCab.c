#include <stdio.h>
#include <stdlib.h>
#include "listaCab.h"

struct item_{
  int conteudo;
};

struct no_{
  ITEM *item;
  NO* prox;
};

struct lista_{
  NO *cabeca;
  NO *fim;
  int tamanho;
};

boolean lista_vazia(LISTA *l){
  return (l->cabeca->prox == NULL);
}

LISTA *lista_criar(void){
  LISTA *l = (LISTA *)malloc(sizeof(LISTA));
  if(l != NULL){
    l->cabeca = (NO *)malloc(sizeof(NO));
    if(l->cabeca == NULL) return NULL;
    l->cabeca->prox = NULL;
    l->fim = NULL;
    l->tamanho = 0;
  }
  return l;
}

boolean inserir_ordenado(LISTA *l, ITEM *i){
  NO *novo = (NO *)malloc(sizeof(NO));
  novo->item = i;
  NO *p, *q;
  p = l->cabeca;
  q = p->prox;
  if(l != NULL && !lista_cheia(l)){
    while(q != NULL && q < i->conteudo){
      p = q;
      q = q->prox;
    }
    if(q == NULL){
      p->prox = novo;
      l->fim = novo;
      novo->prox = NULL;
    }
    else{
      p->prox = novo;
      novo->prox = q;
    }
    l->tamanho++;
    free(p);
    free(q);
    return TRUE;
  }
  return FALSE;
}

boolean remover_chave(LISTA *l, ITEM *i){
  NO *p, *q;
  p = l->cabeca;
  q = p->prox;
  if(l != NULL && !lista_vazia(l)){
    while(q != NULL && q->item != i){
      p = q;
      q = q->prox;
    }
    if(q == l->fim){
      l->fim = p;
      l->fim->prox = NULL;
    }
    else{
      p->prox = q->prox;
      q->prox = NULL;
    }
    l->tamanho++;
    free(p);
    free(q);
    return TRUE;
  }
  return FALSE;
}
