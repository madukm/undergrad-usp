#include <stdio.h>

void maiorSub(int arr[]){
  int i, maxi, maxf;
  maxi = arr[0];
  maxf = arr[0];
  for(i=0; i<n; i++){
    maxi = max(arr[i], maxi+arr[i]);
    maxf = max(maxi, maxf);
  }
  printf("%d", maxf);
}

#define max(a,b) (a > b ? a : b)

int subVec(int *vec, int max, int i, int sum){
  if(i == max) return sum;
  int a = subVec(vec, max, i+1, sum+vec[i]);
  int b = subVec(vec, max, i+1, vec[i]);
  return max(a, max(b, sum));
}
