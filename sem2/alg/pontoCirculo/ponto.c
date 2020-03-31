#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

struct _Ponto{
  float x;
  float y;
};

PONTO *ponto_criar(float a, float b){
  PONTO *p = (PONTO*) malloc(sizeof(struct _Ponto));
  p->x = a;
  p->y = b;
  return p;
}
void ponto_apagar(PONTO *p){
  free(p);
}

//funcoes pra acessar o x e o y do ponto, necessarias pra calcular a ditancia depois
float ponto_getX(PONTO *p){
  return p->x;
}
float ponto_getY(PONTO *p){
  return p->y;
}
