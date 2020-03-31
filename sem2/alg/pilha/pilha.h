#ifndef PILHA_H
#define PILHA_H

#define ERRO 32000
#define TAM 100
#define bool int
#define TRUE 1
#define FALSE 0

typedef struct pilha_ PILHA;

PILHA *pilha_criar(void);
void pilha_apagar(PILHA **p);
bool pilha_vazia(PILHA *p);
bool pilha_cheia(PILHA *p);
bool pilha_inverter(PILHA *p);
void pilha_imprimir(PILHA *p);


#endif
