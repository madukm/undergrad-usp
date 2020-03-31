#include <stdio.h>
#include <stdlib.h>

int maximo(int n, int v[]){
  if(n == 1) return v[0];
  else{
    int x;
    x = maximo (n-1, v);
    if(x > v[n-1]) return x;
    else return v[n-1];
  }
}

int main(){
  int i, n, *v;
  scanf("%d", &n);
  v = (int *)malloc(n * sizeof(int));
  for(i=0; i<n; i++){
    scanf("%d", &v[i]);
  }
  printf("Maximo = %d\n", maximo(n, v));
  free(v);
  return 0;
}
