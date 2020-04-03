#include <stdlib.h>
#include <stdio.h>
#include "matrizAdj.h"

/*to simplify, I'm using a vector to represent the matrix:
 index = column * n + row;
*/

struct graph{
	int *matrix; //adjacent matrix
	int edges; 
	int vertex;
};

Graph *create_graph(int n, int m){
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->matrix = (int *)calloc(n*n, sizeof(int)); //already starts with 0 
	graph->edges = m;
	graph->vertex = n;
	return graph;
}

void insert_edge(Graph *graph, int vertex1, int vertex2){

	graph->matrix[vertex1*(graph->vertex) + vertex2] = graph->matrix[vertex2 *(graph->vertex) + vertex1] = 1;
}

	 
void remove_edge(Graph *graph, int vertex1, int vertex2){
		
	graph->matrix[vertex1*(graph->vertex) + vertex2] = graph->matrix[vertex2 *(graph->vertex) + vertex1] = 0;
}

void show_matrix(Graph *graph){
	for(int i=0; i<graph->vertex; i++){
		for(int j=0; j<graph->vertex; j++){
			printf("%d ", graph->matrix[i*graph->vertex + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void remove_graph(Graph **graph){	
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}
