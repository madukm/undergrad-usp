#include "listaEnc.h"
#include <stdio.h>
#include <stdlib.h>

struct item_{
  int conteudo;
};

struct no_{
  ITEM *item;
  NO *prox;
};

struct lista_{
  NO *ini;
  NO *fim;
  int tamanho;
};

boolean lista_cheia(LISTA *l){
  if(l != NULL){
    if(l->tamanho < TAM_MAX) return FALSE;
    else return TRUE;
  }
}

boolean lista_vazia(LISTA *l){
  if(l != NULL){
    if(l->tamanho > 0) return FALSE;
    else return TRUE;
  }
}

LISTA *lista_criar(void){
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
  if(lista != NULL){
    lista->ini = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
  }
  return lista;
}

void lista_apagar(LISTA **l){
  if(*l != NULL) return;
  lista_esvazia((*l)->ini);
  free(*l);
  *l = NULL;
  }
}

void lista_esvazia(NO *no){
  if(no != NULL){
    if(no->prox != NULL){
      lista_esvazia(no->prox);
    }
    no->prox->item = NULL;
    free(l);
    l = NULL;
  }
}

void inserir_ini(LISTA *l, ITEM *i){
  NO *novo = (NO *)malloc(sizeof(NO));
  novo->item = i;
  if(l != NULL && lista_cheia(l) == 0){
    if(l->ini == NULL){
      l->ini = novo;
      l->fim = l->ini;
    }
    else{
      novo->prox = l->ini;
      l->ini = novo;
    }
    l->tamanho++;
  }
}

void inserir_fim(LISTA *l, ITEM *i){
  NO *novo = (NO*)malloc(sizeof(NO));
  novo->item = i;
  if(l != NULL && !lista_cheia(l)){
    if(l->ini == NULL){
      l->ini = novo;
      l->fim = l->ini;
    }
    else{
      novo->prox = NULL;
      l->fim->prox = novo;
      l->fim = novo;
    }
    l->tamanho++;
  }
}

boolean inserir_ordenado(LISTA *l, ITEM *i){
  NO *novo = (NO *)malloc(sizeof(NO));
  novo->item->conteudo = i;
  NO *p, *q;
  p = l->ini;
  q = l->ini->prox;
  if(l != NULL && !lista_cheia(l)){
    if(p->item->conteudo > novo->item->conteudo){
      novo->prox = l->ini;
      l->ini = novo;
    }
    while(q != NULL && q->item->conteudo < novo->conteudo){
      p = q;
      q = q->prox;
    }
    if(q == NULL){
      novo->prox = NULL;
      p->prox = novo;
      l->fim = novo;
    }
    else{
      p->prox = novo;
      novo->prox = q;
    }
    l->tamanho++;
    return TRUE;
  }
  else return FALSE;
}

boolean remover(LISTA *l, ITEM *i){
  NO *p, *q;
  p = l->ini;
  q = l->ini->prox;
  if(l != NULL && !lista_vazia(l)){
    if(p->item == i){
      p->prox = NULL;
      l->ini = q;
    }
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
    l->tamanho--:
    free(p);
    free(q);
    return TRUE;
  }
  return FALSE;
}

boolean remover_ini(LISTA *l);
boolean remover_fim(LISTA *l);
