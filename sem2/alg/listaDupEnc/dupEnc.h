#ifndef DUPENC_H
#define DUPENC_H

typedef struct no_ NO;
typedef struct lista_ LISTA;

LISTA *lista_criar(void);
void item_apagar(NO *ptr);
void lista_apagar(LISTA **ptr);
boolean lista_cheia(LISTA *l);
//void lista_esvazia(NO *ptr); -> nao coloca pq é só auxiliar. esconde as q n usam lista, colocar as q aparece lista cm argumento só
void lista_imprimir(LISTA *l);
boolean lista_inserir_ini(LISTA *lista, ITEM *i);
boolean lista_inserir_fim(LISTA *lista, ITEM *i);

#endif
