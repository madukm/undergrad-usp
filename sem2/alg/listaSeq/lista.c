#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct _lista{
  int lista[TAM_MAX];
  int inicio;
  int fim;
};

LISTA* inicializa(void){
  LISTA *lista;
  lista = (LISTA *)malloc(sizeof(LISTA));
  if(lista != NULL){
    lista->inicio = 0;
    lista->fim = lista->inicio; //lista vazia
  }
  return lista;
}

int lista_cheia(LISTA *lista){
  if(lista->fim >= TAM_MAX) return 1;
  else return 0;
}

int tamanho(LISTA *lista){
  return (lista->fim-lista->inicio);
}

//já que lista->fim é a primeira posicão vazia da lista, teremos que o tamanho sera fim - inicio

int confereEinsere(LISTA *lista, int val){
  int i, comparacoes = 0;
  for(i=lista->inicio; i<lista->fim; i++){
    comparacoes++;
    if(lista != NULL && val == lista->lista[i])
      return comparacoes;
  }
  //se ainda não houver tal valor na lista, esse valor é inserido no final da lista
  lista->lista[lista->fim] = val;
  (lista->fim)++;
  return comparacoes;
}

//a funcao confereEinsere retorna o numero de comparacoes que foram feitas nessa inserção

void imprimir(LISTA *lista){
  int i;
  for(i=lista->inicio; i<lista->fim; i++){
    printf("%d\t", lista->lista[i]);
  }
  printf("\n");
}

void apaga(LISTA *lista){
  free(lista);
}
