#include <stdio.h>

//Busca Ternária

int buscaTer(int v[], int ini, int fim, int x){
  int meio1, meio2;
  if(ini>fim) return -1;
  meio1 = (fim-ini)/3+ini;
  meio2 = (fim-ini)/3*2+ini;
  if(x == v[meio1]) return meio1;
  if(x == v[meio2]) return meio2;
  if(x<v[meio1]) return buscaTer(v, ini, meio1-1, x);
  if(x>v[meio1] && x<v[meio2]) return buscaTer(v, meio1+1, meio2-1, x);
  else return buscaTer(v, meio2+1, fim, x);
}
