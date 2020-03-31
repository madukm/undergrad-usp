#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[30];
  char disciplina[30];
  long long int numeroUsp;
  float media;
} Cadastro;

int main(){
  Cadastro x;
  strcpy(x.nome, "maria eduarda");
  strcpy(x.disciplina, "calculo 1");
  x.numeroUsp = 11218751;
  x.media = 9.125;
  printf("Nome: %s\n", x.nome);
  printf("Disciplina: %s\n", x.disciplina);
  printf("Numero USP: %lld\n", x.numeroUsp);
  printf("Media: %f\n", x.media);






  return 0;
}
