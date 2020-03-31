#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i, j, codAux, q, **clientes, *cod, *qtd, n, y;
  clientes = (int **)malloc(1 * sizeof(int*));
  cod = (int *)malloc(1 * sizeof(int));
  qtd = (int *)malloc(1 * sizeof(int));
  *clientes = (int *)malloc(1 * sizeof(int));
  scanf("%d %d", &cod[0], &clientes[0][0]);
  qtd[0] = 1;
  n = 0;
  while(scanf("%d ", &codAux) > 0){
    scanf("%d ", &q);
    for(i=qtd[n]-1; i>=0; i--){
      if(codAux == cod[i]){
        clientes[i] = (int *)realloc(clientes[i], (qtd[0]+1) * sizeof(int));
        clientes[i][n] = codAux;
        qtd[n]++;
        y = 1;
        break;
      }
    }
    if(y != 1){
      clientes = (int **)realloc(clientes, (qtd[n]+1) * sizeof(int *));
      clientes[n+1] = (int *)malloc(1 * sizeof(int));
      clientes[n+1][0] = q;
      cod = (int *)realloc(cod, (qtd[n]+1)*sizeof(int));
      qtd = (int *)realloc(qtd, (qtd[n]+1)*sizeof(int));
      cod[n+1] = codAux;
      qtd[n+1] = 1;
      n++;
    }
  }
  for(i=0; i<n; i--){
    printf("%d %d ", cod[i], qtd[i]);
    for(j=0; j<qtd[i]; j++){
      printf("%d", clientes[i][j]);
    }
  printf("\n");
  }
//  int *qd, *qs, *sf, *dfs;






free(cod);
free(qtd);







  return 0;
}
