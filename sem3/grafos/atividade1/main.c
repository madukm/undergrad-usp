#include <stdio.h>
#include <stdlib.h>
#include "matrizAdj.h"

int main(){
	int n, m, first_vertex, second_vertex, numberOperations, operation;
	scanf("%d%d", &n, &m);
	Graph *g = create_graph(n, m); // n = number of vertex, m = number of edges
	for(int i=0; i<m; i++){
		scanf("%d%d", &first_vertex, &second_vertex);
		insert_edge(g, first_vertex, second_vertex);
	}	
	scanf("%d", &numberOperations);
	for(int i=0; i<numberOperations; i++){
		scanf("%d", &operation);
		switch(operation){
			case 1: //insert_edge
				scanf("%d%d", &first_vertex, &second_vertex);
				insert_edge(g, first_vertex, second_vertex);
				break;
			case 2: //remove_edge
				scanf("%d%d", &first_vertex, &second_vertex);
				remove_edge(g, first_vertex, second_vertex);
				break;
			case 3:
				show_matrix(g); //show adjacent matrix
				break;
		}
	}
	remove_graph(&g);
	return 0;
}
