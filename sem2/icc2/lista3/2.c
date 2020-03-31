#include <stdio.h>


//recursivo
int fibg(int f0, int f1, int n){
  if(n == 0) return f0;
  if(n == 1) return f1;
  return fibg(f0, f1, n-1)+fibg(f0, f1, n-2);
}

//iterativo
int fibg(int f0, int f1, int n){
  int x = f0, y = f1, i = n-1;
  if(n == 1 || n == 2) return f0;
  while(i>0){
    int temp = y;
    y = y+x;
    x = temp;
    i--;
  }
  return y;
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d\n", fibg(1, 1, n));
  return 0;
}
