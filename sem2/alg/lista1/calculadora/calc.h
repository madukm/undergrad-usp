#ifndef CALC_H
#define CALC_H

double *criar(double x);
double *soma(double x, double y);
double *subtracao(double x, double y); //faz x-y
double *produto(double x, double y);
double *divisao(double x, double y); //faz x/y
void liberar(double *x);

#endif
