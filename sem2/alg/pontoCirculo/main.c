#include "ponto.h"
#include "circulo.h"
#include <stdio.h>

int main(){
  PONTO *p;
  CIRCULO *c;
  PONTO *pc; //centro do circulo
  float pontoX, pontoY, circuloX, circuloY, circuloR;
  scanf("%f%f%f%f%f", &pontoX, &pontoY, &circuloX, &circuloY, &circuloR);
  p = ponto_criar(pontoX, pontoY);
  pc = ponto_criar(circuloX, circuloY);
  c = circulo_criar(pc, circuloR);
  dentroFora(getDistancia(c, p), circuloR);
  ponto_apagar(p);
  ponto_apagar(pc);
  circulo_apagar(c);
  return 0;
}
