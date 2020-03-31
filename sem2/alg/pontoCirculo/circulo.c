#include "circulo.h"
#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct _Circulo{
  float raio;
  PONTO *ponto;
};

CIRCULO *circulo_criar(PONTO *p, float r){
  struct _Circulo *c = malloc(sizeof(struct _Circulo));
  c->ponto = p;
  c->raio = r;
  return c;
}

void circulo_apagar(CIRCULO *c){
  free(c);
}

float getDistancia(CIRCULO *c, PONTO *p){
  float d = sqrt(pow(ponto_getX(c->ponto) - ponto_getX(p), 2)+pow(ponto_getY(c->ponto) - ponto_getY(p), 2));
  return d;
}

void dentroFora(float d, float r){
  if(d>r) printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", d);
  else if(d == r) printf("O ponto pertence à circunferência.\nDistância: %.2f\n", d);
  else {
    printf("O ponto é interior à circunferência.\nDistância: %.2f\n", d);
  }
}
