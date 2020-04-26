#include <stdio.h>
#include <stdlib.h>
#include "listaAdj.h"

int main(){
	// n = Número de vértices.
	// m = Número de arestas.
	int n, m, i;
	scanf("%d%d", &n, &m);
	Grafo *grafo;
	grafo = criar_grafo(n);
	for(i=0; i<m; i++){
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		inserir_aresta(grafo, v1, v2);
	}
	int qnt_op, op, v1, v2;
	scanf("%d", &qnt_op);//Quantidade de operações.
	for(int i=0; i<qnt_op; i++){
		scanf("%d", &op);//Número da operação.
		switch(op){
			case 1: //Inserir aresta
				scanf("%d%d", &v1, &v2);
				inserir_aresta(grafo, v1, v2);
				break;
			case 2:
				scanf("%d%d", &v1, &v2);
				remover_aresta(grafo, v1, v2);
				break;
			case 3:
				printar_lista(grafo);
				break;
		}
	}
	apagar_grafo(grafo);
	return 0;
}
