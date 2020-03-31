#include "lista.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM_MAX 100

struct lista{
  float lista[TAM_MAX];
  int inicio;
  int fim;
};

LISTA *inicializa(void){
  LISTA *lista;
  lista = (LISTA *)malloc(sizeof(LISTA));
  if(lista != NULL){
    lista->inicio = 0;
    lista->fim = lista->inicio;
  }
  return lista;
}

void libera(LISTA *lista){
  free(lista);
}

int tamanho(LISTA *lista){
  return (lista->fim - lista->inicio);
}

void imprime(LISTA *lista){
  int i;
  for(i=list->inicio; i<lista->fim; i++){
    printf("%f ", lista->lista[i]);
  }
  printf("\n");
}

int insere_final(LISTA *lista, float val){
  if(!lista_cheia(lista)){
    lista->lista[lista->fim] = val;
    lista->fim++;
    return 1;
  }
  else return 0;
}

int insere_posicao(LISTA *lista, float val, int pos){
  int i;
  if(!lista_cheia(lista) && pos <= lista->fim - 1){
    for(i=lista->fim-1; i>=pos; i--){
      lista->lista[i+1] = lista->lista[i];
    }
    lista->lista[pos] = val;
    lista->fim++;
    return 1;
  }
  else return 0;
}

int remove_final(LISTA *lista){
  if(!lista_cheia(lista)){
    lista->fim--;
    return 1;
  }
  else return 0;
}
int remove_posicao(LISTA *lista, int pos){
  int i;
  if(!lista_cheia(lista) && pos < lista->fim){
    for(i=pos+1; i<lista->fim; i++){
      lista->lista[i] = lista->lista[i-1];
    }
    lista->fim--;
    return 1;
  }
  else return 0;
}

int lista_cheia(LISTA *lista){
  if(lista->fim < TAM_MAX) return 0;
  else return 1;
}

float minimo(LISTA *lista){
  int i
  float min = lista->ini;
  for(i=lista->ini+1; i<lista->fim; i++){
    if(min>lista->lista[i]){
      min = lista->lista[i];
    }
  }
  return min;
}

float maximo(LISTA *lista){
  int i
  float max = lista->ini;
  for(i=lista->ini+1; i<lista->fim; i++){
    if(max<lista->lista[i]){
      max = lista->lista[i];
    }
  }
  return max;
}

float media(LISTA *lista){
  int i;
  float med = 0;
  for(i=lista->ini; i<lista->fim; i++){
    med += lista->lista[i];
  }
  med = med/tamanho(lista);
  return med;
}

float desvioPadrao(LISTA *lista){
  int i;
  float somatorio = 0;
  for(i=lista->ini; i<lista->fim; i++){
    somatorio += pow(i - media(lista), 2);
  }
  return sqrt(somatorio/tamanho(lista));
}

float mediana(LISTA *lista){

}
