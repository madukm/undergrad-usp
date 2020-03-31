#ifndef PONTO_H
#define PONTO_H

typedef struct _Ponto PONTO;

PONTO *ponto_criar(float a, float b);
void ponto_apagar(PONTO *p);
float ponto_getX(PONTO *p);
float ponto_getY(PONTO *p);

#endif
