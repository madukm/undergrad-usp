#include <stdio.h>

int main(){
  int N, i;
  scanf("%d", &N);
  i = 1;
  while(i <= N){
    printf("%d ", i);
    i += 2;
  }
  return 0;
}
