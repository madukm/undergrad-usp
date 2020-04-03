#ifndef MATRIZADJ_H
#define MATRIZADJ_H

typedef struct graph Graph;

Graph *create_graph(int n, int m);
void insert_edge(Graph *graph, int vertix1, int vertix2);
void remove_edge(Graph *graph, int vertix1, int vertix2);
void show_matrix(Graph *graph);
void remove_graph(Graph **graph);

#endif
