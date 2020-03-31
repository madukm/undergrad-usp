#ifndef FILA_H
#define FILA_H
#define bool int
#define TRUE 1
#define FALSE 0

typedef struct fila_ FILA;

FILA *fila_criar(void);
bool fila_cheia(FILA *f);
bool fila_vazia(FILA *f);
bool fila_inserir(FILA *f, int i);
int fila_remover(FILA *f);


#endif
