#include <stdio.h>
#include <stdlib.h>

long long unsigned int fib(long long unsigned int n){
  if(n == 0) return 0;
  if(n == 1) return 1;
  else{
    return fib(n-1) + fib(n-2);
  }
}

int main(){
  long long unsigned int n;
  scanf("%llu", &n);
  printf("Fibonacci(%llu) = %llu\n", n, fib(n));
  return 0;
}
