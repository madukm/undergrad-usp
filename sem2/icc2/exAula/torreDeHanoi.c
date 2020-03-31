//Jogo
/*
recursivo:
caso com 1 bloco só, mover de O para D;
mover(N, O, T, D);
mover(N-1, 'O', 'D', 'T');
move bloco N de 'O' para 'D';
mover(N-1, 'T', 'O', 'D');
*/
/*
#include <stdio.h>
#include <stdlib.h>

void mover(int n, char o, char t, char d);

int main(){
  mover (3, 'O', 'T', 'D');
  system("pause"); //ver oq é isso :)
  return 0;
}

void mover(int n, char o, char t, char d){
  if(n==1)printf("mover o disco %d haste %c para %c", n, o, d);
  else{
    mover(n-1, o, d, t);
    printf("mover o disco %d haste %c para %c", n, o, d);
    mover(n-1, t, o, d);
  }
}*/

//unir dois vetores ordenados

#include <stdio.h>

void unir(int v1[], int v2[], int v3[], int n1, int n2){
  if(n1 == 0 && n2 == 0) return;

  if(n1 == 0){
    v3[0] = v2[0];
    unir(v1, n1, ++v2, --n2, ++v3);
  }
  else if(n2 == 0){

  }
}


//uma lista
