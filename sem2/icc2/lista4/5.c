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

void buscaSeq(LISTA *l, ITEM *i){
  NO *p = l->ini;
  while(p != NULL){
    if(p->item == i){
        //insere
    }
    p=p->prox;
  }
}

int buscaBin(NO *ini, ITEM *i, int tamanho){
  NO *p = ini;
  int l = 0, r = tamanho-1;
  int meio = (l+r)/2;
  for(int i=0; i<tamanho/2; i++){
    p = p->prox;
  }
  while(l<r){
    if(p->item == i) return 1;
    if(p->item < i){
      r=meio+1;
    }
    else l = meio-1;
    }
  }
