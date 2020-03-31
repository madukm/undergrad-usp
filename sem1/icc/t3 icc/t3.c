#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void busca(int **segmentada, int **imagem, int iniX, int iniY, float criterio, int n, int m, int consultas, float *media, int *qnt);
float calcMedia(float* ini, int x, int qnt);
int borda(int **segmentada, int i, int j, int n, int m);

int main(){
  int i, j, consultas, *a, *b, **imagem, **segmentada, **posicao;
  float *criterio;
  char *nomeArquivo;
  a = (int *)malloc(1 * sizeof(int));
  b = (int *)malloc(1 * sizeof(int));
  nomeArquivo = (char *)malloc(40 * sizeof(char));
  FILE *arq = NULL;
  scanf("%s", nomeArquivo); //lendo a primeira linha que contem o nome do arquivo
  //lendo o arquivo:
  if(((arq = fopen(nomeArquivo, "r")) == NULL)){
    printf("Nao foi possivel abrir o arquivo.\n");
    exit(1);
  } //abrindo o arquivo
  fscanf(arq, "%*s "); //lendo a string que deve ser ignorada
  fscanf(arq, "%d %d", b, a); //lendo a quantidade de colunas(m) e linhas(n), respectivamente
  fscanf(arq, "%*d"); //lendo o numero da terceira linha que deve ser ignorado
  imagem = (int **)malloc((*a) * sizeof(int *));
  for(i=0; i<*a; i++){
    imagem[i] = (int *)malloc((*b) * sizeof(int));
  } //alocando espaço pra imagem
  segmentada = (int **)calloc((*a), sizeof(int *));
  for(i=0; i<(*a); i++){
    segmentada[i] = (int *)calloc((*b), sizeof(int));
  }
  for(i=0; i<(*a); i++){
    for(j=0; j<(*b); j++){
      fscanf(arq, "%d", &imagem[i][j]); //lendo a matriz da imagem
    }
  }
  scanf("%d", &consultas);
  criterio = (float *)malloc(consultas * sizeof(float));
  posicao = (int **)malloc(consultas * sizeof(int *));
  for(i=0; i<consultas; i++){
    posicao[i] = (int *)malloc(2 * sizeof(int));
  }
  for(i=0; i<consultas; i++){
    scanf("%d %d", &posicao[i][0], &posicao[i][1]);
    scanf("%f", &criterio[i]);
  }
  for(i=0; i<consultas; i++){
    //printf("posicoes: %d %d\n", posicao[i][0], posicao[i][1]);
    float *media;
    media = (float *)calloc(1, sizeof(float));
    int *qnt;
    qnt = (int *)calloc(1, sizeof(int));
    busca(segmentada, imagem, posicao[i][0], posicao[i][1], criterio[i], *a, *b, i, media, qnt);
  }
  /*matriz segmentada(caso queira ver como está)
  for(i=0; i<(*a); i++){
    for(j=0; j<(*b); j++){
      printf("%d ", segmentada[i][j]); //lendo a matriz da imagem
    }
    printf("\n");
  }
  */
  for(i=0; i<(*a); i++){
    for(j=0; j<(*b); j++){
      if(borda(segmentada, i, j, *a, *b) == 1)
        printf("(%d, %d)\n", i, j);
    }
  }//printando as posicoes que sao borda
  free(arq);
  free(nomeArquivo);
  for(i=0; i<(*a); i++)
    free(imagem[i]);
  free(imagem);
  for(i=0; i<(*a); i++)
    free(segmentada[i]);
  free(segmentada);
  free(a);
  free(b);
  free(criterio);
  for(i=0; i<consultas; i++){
    free(posicao[i]);
  }
  free(posicao);
  return 0;
}

float calcMedia(float* mediaAntes, int valor, int qnt){
  float media;
  media = ((*mediaAntes)*qnt + valor)/(qnt+1);
  return media;
}

void busca(int **segmentada, int **imagem, int iniX, int iniY, float criterio, int n, int m, int consultas, float *media, int *qnt){
  if(segmentada[iniX][iniY] != 0) return;
  segmentada[iniX][iniY] = consultas + 1;
  *media = calcMedia(media, imagem[iniX][iniY], *qnt);
  (*qnt)++;
  if((iniX-1) >= 0 && segmentada[iniX-1][iniY] == 0 && (fabs(imagem[iniX-1][iniY] - *media) <= criterio)){
    busca(segmentada, imagem, iniX-1, iniY, criterio, n, m, consultas, media, qnt);
  }
  if((iniY+1) < m && segmentada[iniX][iniY+1] == 0 && (fabs(imagem[iniX][iniY+1] - *media)) <= criterio){
    busca(segmentada, imagem, iniX, iniY+1, criterio, n, m, consultas, media, qnt);
  }
  if((iniX+1) < n && segmentada[iniX+1][iniY] == 0 && (fabs(imagem[iniX+1][iniY] - *media)) <= criterio){
    busca(segmentada, imagem, iniX+1, iniY, criterio, n, m, consultas, media, qnt);
  }
  if((iniY-1) >= 0 && segmentada[iniX][iniY-1] == 0 && (fabs(imagem[iniX][iniY-1] - *media)) <= criterio){
    busca(segmentada, imagem, iniX, iniY-1, criterio, n, m, consultas, media, qnt);
  }
}

int borda(int **segmentada, int i, int j, int n, int m){
    if((i-1)>=0 && segmentada[i-1][j] != segmentada[i][j]){
      return 1;
    }
    if((j+1)<m && segmentada[i][j+1] != segmentada[i][j]){
      return 1;
    }

    if((i+1)<n && segmentada[i+1][j] != segmentada[i][j]){
      return 1;
    }

    if((j-1)>=0 && segmentada[i][j-1] != segmentada[i][j]){
      return 1;
    }
    return 0;
}
