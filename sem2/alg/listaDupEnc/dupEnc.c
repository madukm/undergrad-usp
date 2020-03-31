#include <stdio.h>
#include <stdlib.h>
#include "depEnc.h"
#include "item.h"

#define TRUE 1
#define FALSE 0

struct no_{
  ITEM *item;
  NO *ant;
  NO *prox;
};

struct lista_{
  NO *ini;
  NO *fim;
  int tamanho;
}

void item_apagar(NO *ptr);

boolean lista_cheia(LISTA *l){
    if(l->tamanho > TAM_MAX) return (TRUE);
    else return (FALSE);
}
LISTA *lista_criar(void){
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
  if(lista != NULL){
    lista->ini = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
  }
}

//pq **? pq senao a gnt perde a referencia, precisa colocar q lista é nulo, n se da free no ponteiro, se da free aonde o ponteiro aponta!!! BOAS PRATICAS DE PROGRAMACAO
void lista_apagar(LISTA **ptr){
    if(*ptr != NULL) return;
    lista_esvazia((*ptr)->ini);
    free(*ptr);
    *ptr = NULL;
}


//problema de recursao -> pode estourar a memoria, estourar a pilha
//recebe o inicio da lista como argumento e esvazia a mesma:
void lista_esvazia(NO *ptr){ //tem q ser NO e n LISTA pq é recursivo
  if(ptr != NULL){
    if(ptr->prox != NULL)
      lista_esvazia(ptr->prox);
    }
    item_apagar(&ptr->item); //é uma funcao do tad item
    ptr->ant = NULL;
    free(ptr);
    ptr = NULL;
  }
}

boolean lista_inserir_ini(LISTA *lista, ITEM *i){
  if(lista != NULL && lista_cheia(lista) == 0){
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->item = i;
    if(lista->ini == NULL){//lista vazia
      lista->fim = novo;
      novo->prox = NULL;
    }
    else{
      lista->ini->ant = novo;
      novo->prox = lista->ini;
    }
    novo->ant = NULL;
    lista->ini = novo;
    lista->tamanho++;
    return (TRUE);
  }
  else return (FALSE);
}

boolean lista_inserir_fim(LISTA *lista, ITEM *i){
  if(lista != NULL && lista_cheia(lista) == 0){
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->item = i;
    if(lista->fim == NULL){//lista vazia
      lista->fim = novo;
      novo->prox = NULL;
    }
    else{
      lista->fim->prox = novo;
      novo->ant = lista->fim
    }
    novo->prox = NULL;
    lista->fim = novo;
    lista->tamanho++;
    return (TRUE);
  }
  else return (FALSE);
}

boolean lista_remover_ini(LISTA *lista){
  if(lista != NULL && lista_vazia(lista) == 0){
    NO *p = (NO *)malloc(sizeof(NO));
    lista->ini = p->prox;
    p->prox->ant = NULL;
    p->prox = NULL;
    free(p);
    p = NULL;
  }
}

boolean lista_removver_fim(LISTA *lista){
  if(lista != NULL && lista_vazia(lista) == 0){
    NO *p = (NO *)malloc(sizeof(NO));
    no = lista->fim;
    lista->fim = p->ant;
    p->ant = NULL;
    lista->fim->prox = NULL;
    free(p);
    p = NULL;
}
