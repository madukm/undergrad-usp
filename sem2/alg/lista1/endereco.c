#include "endereco.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

struct endereco{
  char rua[50];
  int numero;
  char bairro[50];
  char cidade[50];
  char estado[50];
  long long int cep;
};

struct lista_{
  ENDERECO lista[TAM_MAX];
  int inicio;
  int fim;
};


 ENDERECO busca(LISTA *l, long long int CEP){
   int i;
   for(i=l->inicio; i<l->fim; i++){
     if(CEP == lista->lista[i]->cep)
      return lista->lista[i];
   }
   printf("Não há endereço cadastrado com tal cep\n");
   return NULL;
 }
