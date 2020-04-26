#include <stdio.h>
#include <stdlib.h>
#include "listaAdj.h"

/**
 * Lista que representa um grafo não orientado.
 */
struct no{
	int vertice; //Representa o vértice em que está ligado.
	No *next; //Aponta para o próximo nó.
};

struct grafo{
	int vertices; //Número de vértices do grafo.
	int arestas; //Número de arestas do grafo.
	No **listaAdj;
};

/**
 * Função para criar um grafo, com uma lista de adjacência de n nós.
 * Vértices = n.
 * Arestas = 0.
 */
Grafo *criar_grafo(int n){
	Grafo *grafo;
   	grafo =	(Grafo *)malloc(sizeof(Grafo));
	if(grafo != NULL){
		grafo->vertices = n;
		grafo->arestas = 0;
		grafo->listaAdj = (No **)malloc(n*sizeof(No *));
	}
	for(int i=0; i<n; i++)
		grafo->listaAdj[i] = NULL;
	return grafo;
}


/**
 * Função para apagar o grafo, utilizando uma função recursiva auxiliar.
 */
void apagar_grafo(Grafo *grafo){
	if(grafo == NULL) return;
	int i;
	for(i=0; i<grafo->vertices; i++){
		No *no = grafo->listaAdj[i];
		apagar_grafo_aux(no);
	}
	free(grafo->listaAdj);
	free(grafo);
}

void apagar_grafo_aux(No *no){
	No *aux;
	while(no != NULL){
		aux = no->next;
    	free(no);
		no = aux;
	}
}

/**
 * Função para inserir uma aresta.
 * Já que as conexões são não direcionadas, teremos que colocar o vértice 1 na lista adjacente do vértice 2 e vice-versa.
 * O nó representando o vértice é sempre colocado ao final da lista.
 * Utilizaremos a função inserir_aresta_dir para auxiliar.
 */
void inserir_aresta(Grafo *grafo, int v1, int v2){
	inserir_aresta_dir(grafo, v1, v2);
	inserir_aresta_dir(grafo, v2, v1);
	grafo->arestas++;
}

/**
 * Nessa função para auxiliar a inserir_aresta representaremos uma aresta direcionada, do vértice 1 para o vértice 2. 
 * V1 ---> V2
 * A função checa se já há tal conexão para não repetí-la.
 */
void inserir_aresta_dir(Grafo *grafo, int v1, int v2){
	if(grafo == NULL) return;
	No *no;
    no = (No *)malloc(sizeof(No));
	if(no != NULL){
		no->vertice = v2;
		no->next = NULL;
	}
	if(grafo->listaAdj[v1] == NULL){
		grafo->listaAdj[v1] = no;
		return;
	}
	No *p;
	p = grafo->listaAdj[v1];
	//Caso em que ainda não há conexões em V1.
	while(p->next != NULL){
		if(p->vertice == v2)
			break;
		p = p->next;
	}
	if(p->vertice != v2)
		p->next = no;
}

/**
 * Função para remover aresta de um grafo.
 * Já que as arestas são não direcionadas, é preciso remover o vértice 2 da lista de adjacência do vértice 1 e vice versa.
 * Utiliza-se a função auxiliar remover_aresta_dir().
 */

void remover_aresta(Grafo *grafo, int v1, int v2){
	remover_aresta_dir(grafo, v1, v2);
	remover_aresta_dir(grafo, v2, v1);
	grafo->arestas--;
}

/**
 * Função auxiliar que remove a aresta direcionada V1 -----> V2.
 * Portanto retira-se o vértice V2 da lista adjacente do vértice V1.
 */
void remover_aresta_dir(Grafo *grafo, int v1, int v2){
	//Caso em que a lista está vazia.
	if(grafo == NULL) return;
	if(grafo->listaAdj[v1] == NULL) return;
	No *p, *q;
   	p = NULL;
	q = grafo->listaAdj[v1];
	//Caso em que V2 está no começo da lista.
	if(q->vertice == v2){
		grafo->listaAdj[v1] = q->next;
	}
	else
		while(q != NULL){
			if(q->vertice == v2){
				p->next = q->next;
				q->next = NULL;
				break;
			}
			p = q;
			q = q->next;
		}
}

/**
 * Fiunção que imprime a lista de adjacência no formato solicitado.
 * Exemplo:
 * 0     
   |
   |
   2-----1
 * Lista de Adjacência:
   0: 2
   1: 2
   2: 1 0
 */
void printar_lista(Grafo *grafo){
	No *no;
	for(int i=0; i<grafo->vertices; i++){
		no = grafo->listaAdj[i];
		printf("%d: ", i);
		while(no != NULL){
			printf("%d ", no->vertice);
			no = no->next;
		}
		printf("\n");
	}
	printf("\n");
	free(no);
}
