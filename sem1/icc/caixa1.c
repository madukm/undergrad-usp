#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i, j, n, qntd, valor; //clientes
  scanf("%d", &n);
  int **clientes;
  int *qd, *qs;
  float *sf, *dfs, media = 0;
  qd = (int *)calloc(n, sizeof(int));
  qs = (int *)calloc(n, sizeof(int));
  sf = (float *)calloc(n, sizeof(float));
  dfs = (float *)calloc(n, sizeof(float));
  clientes = (int **)malloc(n * sizeof(int *));
  for(i=0; i<n; i++){
    scanf("%d", &qntd);
    clientes[i] = (int *)malloc(qntd * sizeof(int));
    for(j=0; j<qntd; j++){
      scanf("%d", &valor);
      sf[i] += valor;
      media += valor;
      if(valor > 0)
        qd[i]++;
      else
        qs[i]++;
    }
  }
  for(i=0; i<n; i++){
    dfs[i] = fabs((media / n) - sf[i]);
  }
  for(i=0; i<n; i++){
    printf("%d %d %.2f %.2f\n", qd[i], qs[i], sf[i], dfs[i]);
  }

  free(qd);
  free(qs);
  free(sf);
  free(dfs);
  for(i=0; i<n; i++){
    free(clientes[i]);
  }
  free(clientes);



  return 0;
}
