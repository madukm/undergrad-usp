#include <stdio.h>

void ordena(char v[], int n){
  int i = 0, j = i+1;
  for(i=0; i<n; i++){
    if(v[i] == 'B'){
      for(j=i+1; j<n; j++){
        if(v[j] == 'A'){
          char aux = v[j];
          v[j]=v[i];
          v[i]=aux;
          break;
        }
      }
    }
  }
}


int main(){
  int n;
  scanf("%d ", &n);
  char v[n+1];
  for(int i=0; i<n; i++){
    scanf("%c", &v[i]);
  }
  v[n] = '\0';
  /*printf("original ->");
  for(int i=0; i<n; i++){
    printf("%c", v[i]);
  }
  printf("\n");*/
  ordena(v, n);
  //printf("ordenado ->");
  for(int i=0; i<n; i++){
    printf("%c", v[i]);
  }
  printf("\n");
  return 0;
}
