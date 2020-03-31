#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2000001

int main(){
  int i, j, mat[N];
  //mat = (int *) malloc(N * sizeof(int));
  long long int soma = 0;
  for(i=0; i<N; i++){
    mat[i] = i;
    //printf("mat[%d] = %d\n", i, mat[i]);
  }
  mat[1] = 0;
  for(i=2; i<N; i++){
    if(mat[i] != 0){
        j = 2;
        while(i * j < N){
          mat[i * j] = 0;
          j++;
        }
    }
  }
  for(i=0; i<N; i++){
    //printf("mat[%d] = %d\n", i, mat[i]);
    if(mat[i] != 0){
        //printf("%d ", mat[i]);
        soma += mat[i];
    }
  }
  printf("%lld\n", soma);
  return 0;
}
