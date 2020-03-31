#ifndef LISTACAB_H
#define LISTACAB_H

typedef struct item_ ITEM;
typedef struct no_ NO;
typedef struct lista_ LISTA;

boolean lista_vazia(LISTA *l);
LISTA *lista_criar(void);
boolean inserir_ordenado(LISTA *l, ITEM *i);
boolean remover_chave(LISTA *l, ITEM *i);

#endif
