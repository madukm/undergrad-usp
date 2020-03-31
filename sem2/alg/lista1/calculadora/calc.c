#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *criar(double x){
  double *n;
  n = (double*)malloc(sizeof(double));
  *n = x;
  return n;
}

double *soma(double *x, double *y){
  double *s;
  *s = *x + *y;
  return s;
}

double *subtracao(double *x, double *y){
  double *s;
  *s = *x - *y;
  return s;
}

double *produto(double *x, double *y){
  double *s;
  *s = (*x)*(*y);
  return s;
}

double *divisao(double *x, double *y){
  double *s;
  if(y == 0){
    printf("Nao e possivel fazer tal operacao.\n");
    return NULL;
  }
  *s = *x / *y;
  return s;
}

void liberar(double *x){
  free(x);
}
