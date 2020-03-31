#include <stdio.h>

long long unsigned int fat(unsigned int n){
  if(n == 1) return 1;
  else return n * fat(n-1);
}

int main(){
  int i;
  unsigned int qnt, n;
  scanf("%u", &qnt);
  for(i=0; i<qnt; i++){
    scanf("%u", &n);
    printf("%u! = %llu\n", n, fat(n));
  }
  return 0;
}
