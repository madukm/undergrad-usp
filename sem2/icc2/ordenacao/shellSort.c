#include <stdio.h>

void printissae(int v[], int n)
{
  for (size_t i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

}

void shellSort(int v[], int n, int incrementos[], int numinc){
  int x, aux;
  for(int i=0; i<numinc; i++){
    int h = incrementos[i];
    for(int j=h;j<n; j+=h){
      x = v[j];
      aux = j-h;
      while((aux>=0) && (x<v[aux])){
        v[aux+h] = v[aux];
        aux -= h;
      }
      v[aux+h] = x;
      printissae(v, n);
    }
  }
}

int main(){
  int v[]={25,57,48,37,12,92,86,33};
  int h[]={5,3,1};
  shellSort(v, 8, h, 3);

}
