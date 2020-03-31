#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

LISTA *inicializa(void);
void libera(LISTA *lista);
int tamanho(LISTA *lista);
void imprime(LISTA *lista);
int insere_final(LISTA *lista, float val); //retorna 1 se conseguiu inserir com sucesso e 0 se nao
int insere_posicao(LISTA *lista, float val, int pos);
int remove_final(LISTA *lista);
int remove_posicao(LISTA *lista, int pos);
int lista_cheia(LISTA *lista);
float minimo(LISTA *lista);
float maximo(LISTA *lista);
float media(LISTA *lista);
float desvioPadrao(LISTA *lista);
float mediana(LISTA *lista);

#endif
