#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
  int conteudo;
  struct cel *prox;
}Celula;

//busca ordenada:
void buscaEinsere(Celula *nova, Celula **ini){
  Celula *p = (*ini), *q = (*ini)->prox;
  if(p->conteudo > nova->conteudo){//se o elemento for o menor de todos
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp = *ini;
    *ini = nova;
    nova->prox = tmp;
    return;
  }
  while(q != NULL && q->conteudo < nova->conteudo){//procurando a posicao que o elemento tem que estar
    p = q;
    q = q->prox;
  }
  if(q == NULL){//se for o maior elemento
    p->prox = nova;
  }
  else{//se o elemento for inserido no meio da lista
    nova->prox = q;
    p->prox = nova;
  }
  return;
}

void imprime(Celula *ini){
  Celula *p;
  for(p = ini; p != NULL; p = p->prox){
    printf("%d ", p->conteudo);
  }
  printf("\n");
}

int main(){
  int i, qnt;
  Celula *ini = NULL;
  scanf("%d", &qnt);
  for(i = 0; i<qnt; i++){
    Celula *nova;
    nova = (Celula *)malloc(sizeof(Celula));
    scanf("%d", &nova->conteudo);
    nova->prox = NULL;
    if(i == 0)//se a lista estiver vazia
      ini = nova;
    else
      buscaEinsere(nova, &ini);
  }
  imprime(ini);
  free(ini);
  return 0;
}
