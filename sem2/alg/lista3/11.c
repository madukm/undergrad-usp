#include <stdio.h>
#include <stdlib.h>
//#include "../fila/estatica/fila.h"
#define n 6
#define TAM 6
#define bool int
#define TRUE 1
#define FALSE 0


struct fila_{
  int item[TAM];
  int ini;
  int fim;
  int tamanho;
};

typedef struct fila_ FILA;

FILA *fila_criar(void){
  FILA *f = malloc(sizeof(FILA));
  f->ini = 0;
  f->fim = 0;
  f->tamanho = 0;
  return f;
}

bool fila_cheia(FILA *f){
  return(f->tamanho == TAM);
}

bool fila_vazia(FILA *f){
  return(f->tamanho == 0);
}

bool fila_inserir(FILA *f, int i){
  if(f!=NULL && !fila_cheia(f)){
    f->item[f->fim] = i;
    f->fim = (f->fim + 1)%TAM;
    f->tamanho++;
    return TRUE;
  }
  return FALSE;
}

int fila_remover(FILA *f){
  if(f!=NULL && !fila_vazia(f)){
    int i = f->item[f->ini];
    f->ini = (f->ini+1)%TAM;
    f->tamanho--;
    return i;
  }
}


int *bsf(int A[n][n], int orig){
  FILA *f = fila_criar();
  fila_inserir(f, orig);
  int *d = (int *)malloc(sizeof(int));
  for(int i=0; i<n; i++){
    d[i] = -1;
  }
  d[orig] = 0;
  while(!fila_vazia(f)){
    int node = fila_remover(f);
    for(int i = 0; i<n; i++){
      if(A[node][i] == 1){
        if(d[i] == -1){
          d[i] = d[node] + 1;
          fila_inserir(f, i);
        }
      }
    }
  }
  return d;
}

int main(){
  int A[6][6] = {{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,0,1,0},{0,0,1,0,1,0},{1,0,0,0,0,0},{0,1,0,0,0,0}};
  int *d = bsf(A, 3);
  for(int i=0; i<n; i++){
    printf("%d ", d[i]);
  }
  return 0;
}
