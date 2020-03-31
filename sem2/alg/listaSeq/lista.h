#ifndef LISTA_H
#define LISTA_H
#define TAM_MAX 100

typedef struct _lista LISTA;

LISTA *inicializa(void);
void apaga(LISTA *lista);
int confereEinsere(LISTA *lista, int val);
int tamanho(LISTA *lista);
void imprimir(LISTA *lista);
int lista_cheia(LISTA *lista);

#endif
