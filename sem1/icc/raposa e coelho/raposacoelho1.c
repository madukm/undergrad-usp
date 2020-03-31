#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  FILE *arq = NULL;
  float *xBuraco, *yBuraco, xCoelho, yCoelho, xRaposa, yRaposa;
  int qnt, i;
  char *nomeArquivo, check = 0;
  nomeArquivo = (char *)malloc(40 * sizeof(char));
  scanf("%s", nomeArquivo);
  if(((arq = fopen(nomeArquivo, "r")) == NULL)){
    printf("erro na abertura do arquivo.\n");
    exit(1);
  }
  fscanf(arq, "%f %f %f %f", &xCoelho, &yCoelho, &xRaposa, &yRaposa);
  fscanf(arq, "%d", &qnt);
  xBuraco = (float *)malloc(qnt * sizeof(float));
  yBuraco = (float *)malloc(qnt * sizeof(float));
  for(i=0; i<qnt; i++){
    float dCoelho, dRaposa;
    fscanf(arq, "%f%f", &xBuraco[i], &yBuraco[i]);
    dCoelho = sqrt(pow(xBuraco[i]-xCoelho, 2) + pow(yBuraco[i]-yCoelho, 2));
    dRaposa = sqrt(pow(xBuraco[i]-xRaposa, 2) + pow(yBuraco[i]-yRaposa, 2));
    if(dCoelho < dRaposa/2){
      printf("O coelho pode escapar pelo buraco (%.3f,%.3f).\n", xBuraco[i], yBuraco[i]);
      check = 1;
      break;
    }
  }
  if(check != 1){
    printf("O coelho nao pode escapar.\n");
  }
  fclose(arq);
  free(arq);
  free(xBuraco);
  free(yBuraco);
  free(nomeArquivo);
  return 0;
}
