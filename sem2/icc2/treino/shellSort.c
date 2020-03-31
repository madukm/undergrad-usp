#include <stdio.h>

#define N 5

void shellSort(int v[], int n){
  int i, j, x;
  for(i = 1; i<n; i++){
    x = v[i];
    j = i-1;
    while(j>=0 && x<v[j]){
      v[j+1]=v[j];
      j--;
    }
    v[j+1]=x;
  }
}

int main(){
  int mat[N];
  for(int i=0; i<N; i++){
    scanf("%d", &mat[i]);
  }
  shellSort(mat, N);
  for(int i=0; i<N; i++){
    printf("%d", mat[i]);
  }
  return 0;
}
