#include <stdio.h>
#include <string.h>

int main(){
  int c = 0, i;
  char palavra[30];
  scanf("%s", palavra);
  for(i=0; i<strlen(palavra); i++){
    switch(palavra[i]){
      case 'a':
        c++;
        break;
      case 'e':
        c++;
        break;
      case 'i':
        c++;
        break;
      case 'o':
        c++;
        break;
      case 'u':
        c++;
        break;
      case'A':
        c++;
        break;
      case 'E':
        c++;
        break;
      case 'I':
        c++;
        break;
      case 'O':
        c++;
        break;
      case 'U':
        c++;
        break;
    }
  }
  printf("%d\n", c);
  return 0;
}
