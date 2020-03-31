#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void busca(int **segmentada, int **imagem, int iniX, int iniY, int criterio, int n, int m, int consultas, float *media, int *qnt);
float calcMedia(float* mediaAntes, int valor, int qnt);
int borda(int **segmentada, int i, int j, int n, int m);

int main(){
  int i, j, iniX, iniY, consultas, *a, *b, **imagem, **segmentada;
  int criterio;
  char *nomeArquivo;
  a = (int *)malloc(1 * sizeof(int));
  b = (int *)malloc(1 * sizeof(int));
  nomeArquivo = (char *)malloc(40 * sizeof(char));
  FILE *arq = NULL;
  FILE *madu = NULL;
  scanf("%s", nomeArquivo); //lendo a primeira linha que contem o nome do arquivo
  //lendo o arquivo:
  if(((arq = fopen(nomeArquivo, "r")) == NULL)){
    printf("Nao foi possivel abrir o arquivo.\n");
    exit(1);
  } //abrindo o arquivo
  if(((madu = fopen("maduMaravilhosa.pgm", "w")) == NULL)){
    printf("Nao foi possivel abrir o arquivo.\n");
    exit(1);
  }
  fscanf(arq, "%*s "); //lendo a string que deve ser ignorada
  fscanf(arq, "%d %d", b, a); //lendo a quantidade de colunas(m) e linhas(n), respectivamente
  fscanf(arq, "%*d"); //lendo o numero da terceira linha que deve ser ignorado
  if((imagem = (int **)malloc((*a) * sizeof(int *))) == NULL){
    printf("Sem memoria.\n");
    exit(1);
  }
  if((segmentada = (int **)calloc((*a), sizeof(int *))) == NULL){
    printf("Sem memoria.\n");
    exit(1);
  }
  for(i=0; i<(*a); i++){
    if((imagem[i] = (int *)malloc((*b) * sizeof(int))) == NULL){
      printf("Sem memoria.\n");
      exit(1);
    }
    if((segmentada[i] = (int *)calloc((*b), sizeof(int))) == NULL){
      printf("Sem memoria.\n");
      exit(1);
    }
  }//alocando espaço pra imagem
  for(i=0; i<(*a); i++){
    for(j=0; j<(*b); j++)
      fscanf(arq, "%d", &imagem[i][j]); //lendo a matriz da imagem e armazenando na matriz imagem
  }
  fclose(arq);
  //acabou de ler o arquivo
  scanf("%d", &consultas);
  for(i=0; i<consultas; i++){
    scanf("%d %d", &iniX, &iniY); //lendo a posicao do pixel(iniX, iniY) inicial da i-esima consulta
    scanf("%d", &criterio); //lendo o i-esimo criterio
    float *media; //media que sera usada para cada consulta
    if((media = (float *)calloc(1, sizeof(float))) == NULL){
      printf("Sem memoria.\n");
      exit(1);
    }
    int *qnt; //quantidade de elementos na media, que e necessaria para a media
    if((qnt = (int *)calloc(1, sizeof(int))) == NULL){
      printf("Sem memoria.\n");
      exit(1);
    }
    busca(segmentada, imagem, iniX, iniY, criterio, *a, *b, i, media, qnt);
  }

  //matriz segmentada(caso queira ver como está)
  for(i=0; i<(*a); i++){
    for(j=0; j<(*b); j++){
      printf("%d ", segmentada[i][j]); //lendo a matriz da imagem
    }
    printf("\n");
  }
  fprintf(madu, "P2\n%d %d\n 255\n", *a, *b);
  for(i=0; i<(*a); i++){
    for(j=0; j<(*b); j++){
      if(borda(segmentada, i, j, *a, *b) == 1){
        printf("(%d, %d)\n", i, j);
        fprintf(madu, "%d ", 0);
      }
      else{
        fprintf(madu, "%d ", 255);
      }
    }
    fprintf(madu, "\n");
  }//printando as posicoes que sao borda
  fclose(madu);
  //dando free nos ponteiros:
  free(arq);
  free(nomeArquivo);
  for(i=0; i<(*a); i++){
    free(imagem[i]);
    free(segmentada[i]);
  }
  free(imagem);
  free(segmentada);
  free(a);
  free(b);
  return 0;
}

float calcMedia(float* mediaAntes, int valor, int qnt){
  return ((*mediaAntes)*qnt + valor)/(qnt+1);
}

void busca(int **segmentada, int **imagem, int iniX, int iniY, int criterio, int n, int m, int consultas, float *media, int *qnt){
  if(segmentada[iniX][iniY] != 0) return; //se a o pixel ja for segmentada entao deve-se sair da funcao
  segmentada[iniX][iniY] = consultas + 1; //os pixels que nao forem segmentados ficaram na segmentacao (consultas + 1)
  *media = calcMedia(media, imagem[iniX][iniY], *qnt); //calculando a media
  (*qnt)++; //aumentando a quantidade de elementos na media
  if((iniX-1) >= 0 && segmentada[iniX-1][iniY] == 0 && (fabs(imagem[iniX-1][iniY] - *media) <= criterio))
    busca(segmentada, imagem, iniX-1, iniY, criterio, n, m, consultas, media, qnt);
  if((iniY+1) < m && segmentada[iniX][iniY+1] == 0 && (fabs(imagem[iniX][iniY+1] - *media)) <= criterio)
    busca(segmentada, imagem, iniX, iniY+1, criterio, n, m, consultas, media, qnt);
  if((iniX+1) < n && segmentada[iniX+1][iniY] == 0 && (fabs(imagem[iniX+1][iniY] - *media)) <= criterio)
    busca(segmentada, imagem, iniX+1, iniY, criterio, n, m, consultas, media, qnt);
  if((iniY-1) >= 0 && segmentada[iniX][iniY-1] == 0 && (fabs(imagem[iniX][iniY-1] - *media)) <= criterio)
    busca(segmentada, imagem, iniX, iniY-1, criterio, n, m, consultas, media, qnt);
}

int borda(int **segmentada, int i, int j, int n, int m){
    if((i-1)>=0 && segmentada[i-1][j] != segmentada[i][j])
      return 1;
    if((j+1)<m && segmentada[i][j+1] != segmentada[i][j])
      return 1;
    if((i+1)<n && segmentada[i+1][j] != segmentada[i][j])
      return 1;
    if((j-1)>=0 && segmentada[i][j-1] != segmentada[i][j])
      return 1;
    return 0;
    //os que sao borda retornarao 1, caso nao seja, retorna 0
}
