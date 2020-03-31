#include "complexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complexo{
  double r;
  double i;
};

Complexo *criar(double real, double imag){
  struct complexo *c = malloc(sizeof(struct complexo));
  c->r = real;
  c->i = imag;
  return c;
}

void liberar (Complexo *c){
  free(c);
}

void copiar (Complexo *source, Complexo *target){
  target->r = source->r;
  target->i = source->i;
}

Complexo *adicao (Complexo *a, Complexo *b){
  struct complexo *c;
  c->r = a->r + b->r;
  c->i = a->i + b->i;
  return c;
}

Complexo *subtracao (Complexo *a, Complexo *b){
  struct complexo *c;
  c->r = a->r - b->r;
  c->i = a->i - b->i;
  return c;
}

int e_real(Complexo *c){
  if(c->i == 0) return 1;
  else return 0;
}

double real (Complexo *c){
  return c->r;
}

double imag (Complexo *c){
  return c->i;
}

void atribuir(Complexo *c, double real, double imag){
  c->r = real;
  c->i = imag;
}

void atribuir_real(Complexo *c, double real){
  c->r = real;
}

void atribuir_imag(Complexo *c, double imag){
  c->i = imag;
}
