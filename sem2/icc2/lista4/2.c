#include <stdio.h>

int maximo(int v[], int ini, int fim){
  if(ini < fim){
    int meio = (ini+fim)/2;
    int a = maximo(v, ini, meio);
    int b = maximo(v, meio+1, fim);
    if(a > b) return a;
    return b;
  }
}

int main(){
  int i, v[10];
  for(i=0; i<10; i++){
    scanf("%d", &v[i]);
  }
  printf("%d\n", maximo(v, 0, 9));
  return 0;
}
