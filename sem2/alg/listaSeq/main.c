#include "lista.h"
#include <stdio.h>

int main(){
  int i, qnt, valor, comparacoesTot = 0;
  LISTA *lista = inicializa();
  scanf("%d", &qnt);
  for(i=0; i<qnt; i++){
    scanf("%d", &valor);
    if(lista_cheia(lista) == 0){
      comparacoesTot += confereEinsere(lista, valor);
    }
    else{
      printf("Lista cheia. Impossível realizar o processamento.\n");
      return 0; //se a lista tiver cheia, entao paramos a insercao
    }
  }
  imprimir(lista);
  printf("Tamanho da lista: %d\n", tamanho(lista));
  printf("Total de comparações: %d\n", comparacoesTot);
  apaga(lista);
  return 0;
}
