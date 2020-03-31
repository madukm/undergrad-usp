#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i, j;
  double raiz;
  raiz = sqrt(600851475143);
  long long int x;
  x = raiz;
  //printf("raiz = %lld\n", x);
  long long int mat[x];
  for(i=0; i<=x; i++){
    mat[i] = i;
  }
  mat[1] = 0;
  for(i=2; i<=x; i++){
    if(mat[i] != 0){
        j = 2;
        while(i * j < x){
          mat[i * j] = 0;
          j++;
        }
    }
  }
  for(i=x; i>=1; i--){
    if(mat[i] != 0){
      if(600851475143 % mat[i] == 0){
        printf("%lld\n", mat[i]);
        break;
      }
    }
  }




  return 0;
}
