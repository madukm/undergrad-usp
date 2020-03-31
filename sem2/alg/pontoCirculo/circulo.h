#ifndef CIRCULO_H
#define CIRCULO_H
#include "ponto.h"

typedef struct _Circulo CIRCULO;

CIRCULO *circulo_criar(PONTO *p, float r);
void circulo_apagar(CIRCULO *c);
PONTO *getPonto(CIRCULO *c);
float getDistancia(CIRCULO *c, PONTO *p);
void dentroFora(float d, float r);

#endif
