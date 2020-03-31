#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int busca(float *xBuraco, float *yBuraco, float xCoelho, float yCoelho, float xRaposa, float yRaposa, int i, int qnt);

int main(){
  FILE *arq = NULL;
  float *xBuraco, *yBuraco, xCoelho, yCoelho, xRaposa, yRaposa;
  int qnt, i, resultado;
  char *nomeArquivo;
  nomeArquivo = (char *)malloc(40 * sizeof(char));
  scanf("%s", nomeArquivo);
  printf("%s", nomeArquivo);
  if(((arq = fopen(nomeArquivo, "r")) == NULL)){
    printf("erro na abertura do arquivo.\n");
    exit(1);
  }
  fscanf(arq, "%f %f %f %f", &xCoelho, &yCoelho, &xRaposa, &yRaposa);
  fscanf(arq, "%d", &qnt);
  xBuraco = (float *)malloc(qnt * sizeof(float));
  yBuraco = (float *)malloc(qnt * sizeof(float));
  for(i=0; i<qnt; i++){
    fscanf(arq, "%f%f", &xBuraco[i], &yBuraco[i]);
  }
  fclose(arq);
  resultado = busca(xBuraco, yBuraco, xCoelho, yCoelho, xRaposa, yRaposa, 0, qnt);
  if(resultado != -1)
    printf("O coelho pode escapar pelo buraco (%.3f, %.3f).", xBuraco[resultado], yBuraco[resultado]);
  else
    printf("O coelho nao pode escapar.");
  free(arq);
  free(xBuraco);
  free(yBuraco);
  free(nomeArquivo);
  return 0;
}

int busca(float *xBuraco, float *yBuraco, float xCoelho, float yCoelho, float xRaposa, float yRaposa, int i, int qnt){
  float dCoelho, dRaposa;
  do{
    dCoelho = sqrt(pow(xBuraco[i]-xCoelho, 2) + pow(yBuraco[i]-yCoelho, 2));
    dRaposa = sqrt(pow(xBuraco[i]-xRaposa, 2) + pow(yBuraco[i]-yRaposa, 2));
    if(dCoelho < dRaposa/2)
      return i;
    else
      busca(xBuraco, yBuraco, xCoelho, yCoelho, xRaposa, yRaposa, i + 1, qnt);
  }while(i <= qnt);
  return -1;
}
