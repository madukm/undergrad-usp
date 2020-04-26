#ifndef LISTAADJ_H
#define LISTAADJ_H

typedef struct no No;
typedef struct grafo Grafo;

Grafo *criar_grafo(int n);
void apagar_grafo(Grafo *grafo);
void apagar_grafo_aux(No *no);
void inserir_aresta(Grafo *grafo, int v1, int v2);
void inserir_aresta_dir(Grafo *grafo, int v1, int v2);
void remover_aresta(Grafo *grafo, int v1, int v2);
void remover_aresta_dir(Grafo *grafo, int v1, int v2);
void printar_lista(Grafo *grafo);

#endif

