#ifndef LISTAENC_H
#define LISTAENC_H
#define TRUE 1
#define FALSE 0
#define boolean int

typedef struct item_ ITEM;
typedef struct no_ NO;
typedef struct lista_ LISTA;

boolean lista_cheia(LISTA *l);
boolean lista_vazia(LISTA *l);
LISTA *lista_criar(void);
void lista_apagar(LISTA **l);
void inserir_ini(LISTA *l, ITEM *i);
void inserir_fim(LISTA *l, ITEM *i);
boolean inserir_ordenado(LISTA *l, ITEM *i);
boolean remover_chave(LISTA *l, ITEM *i);
boolean remover_ini(LISTA *l);
boolean remover_fim(LISTA *l);

#endif
