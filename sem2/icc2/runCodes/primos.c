#include <stdio.h>
#include <math.h>

#define N 1000

int main(){
  int i, j, mat[N], numero;
  for(i=0; i<N; i++)
    mat[i] = i;
  mat[1] = 0; //pois 1 não é primo
  for(i=2; i<N; i++){
    if(mat[i] != 0){
      j = 2;
      while(i*j<N){
        mat[i*j] = 0;
        j++;
      }
    }
  } //aqui ja temos todos os primos ate N
  scanf("%d", &numero);
  if(mat[numero] != 0){
    printf("%d e um numero primo\n", numero);
  }
  else{
    printf("%d nao e um numero primo\n", numero);
  }
  return 0;
}
