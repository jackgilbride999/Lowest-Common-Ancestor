#include <stdio.h> 
#include <stdlib.h> 

const int SIZE = 256;
/*
    Return a new graph represented by a 2D array mapped to
    a 1D array in row-major order. An edge from node i to node j 
    is represented by the value 1 in [i][j]. Otherwise the value 
    is 0. There are a maximum of 256 nodes to accomodate the 
    extended ASCII set.
*/
int * create_graph(int size){
    int* graph = malloc(sizeof(int)*SIZE*SIZE);
    return graph;
}

void create_edge(int * graph, int i, int j){
    graph[SIZE*i+j] = 1;
}

int is_edge(int * graph, int i, int j){
    return (graph[SIZE*i+j] == 1);
}