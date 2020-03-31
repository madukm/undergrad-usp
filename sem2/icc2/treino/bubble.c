#include <stdio.h>

#define N 5

void bubbleSort(int v[], int n){
  if(n<1)return;
  for(int i=0; i<n; i++){
    if(v[i]>v[i+1]){
      int aux = v[i];
      v[i] = v[i+1];
      v[i+1] = aux;
    }
  }
  bubbleSort(v, n-1);
}

int main(){
  int mat[N];
  for(int i=0; i<N; i++){
    scanf("%d", &mat[i]);
  }
  bubbleSort(mat, N-1);
  for(int i=0; i<N; i++){
    printf("%d", mat[i]);
  }
  return 0;
}
