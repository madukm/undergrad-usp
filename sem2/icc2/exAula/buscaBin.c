#include <stdio.h>

int buscaBin(int x, int ini, int fim, int v[]){
  if(ini>fim) return -1;
  else{
    int m = (ini+fim)/2;
    if (v[m] == x) return m;
    if (v[m] < x) return buscaBin(x, m+1, fim, v);
    else return buscaBin(x, ini, m-1, v);
  }
}
