#include <stdio.h>
#include <string.h>

void nextPerm(int v[], int n){
  int i = n-2, j = n-1;
  for(int x = 0; x<n; x++){
    printf("%d", v[x]);
  }
  printf("\n");
  while(i>=0){
    if(v[i]<v[i+1])
      break;
    i--;
  }
  if(i<0) return;
  while(1){
    if(v[j]>v[i]){
      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j = n-1;
      while(i<j){
        int aux2 = v[i];
        v[i] = v[j];
        v[j] = aux2;
        i++;
        j--;
      }
      break;
    }
    j--;
  }
  nextPerm(v, n);
}

/*
void comb(int n, char *str){
  int i;
  if(strlen(str) == n){
    printf("%s\n", str);
    return;
  }
  char *str2 = (char *)malloc((n+1)*sizeof(char));
  strcpy(str2, str);
  for(i=0; i<n; i++){
    char j = 'A' + i;
    char *p = strchr(str2, j);
    if(p == NULL){
      str2[strlen(str)] = j;
      str2[strlen(str)+1] = '\0';
      comb(n, str2);
      free(str2);
    }
  }
}
*/
int main(){
  int n;
  scanf("%d", &n);
  int v[n];
  for(int i=0; i<n; i++)
    v[i] = i+1;
  nextPerm(v, n);
  return 0;
}
