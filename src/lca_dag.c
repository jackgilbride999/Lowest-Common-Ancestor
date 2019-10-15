#include <stdio.h> 
#include <stdlib.h> 
#include "lca_dag.h"
/*
    Return a new graph represented by a 2D array mapped to
    a 1D array in row-major order. An edge from node i to node j 
    is represented by the value 1 in [i][j]. Otherwise the value 
    is 0. There are a maximum of 256 nodes to accomodate the 
    extended ASCII set.
*/
int * create_graph(int size){
    int* graph = malloc(sizeof(int)*SIZE*SIZE);
    memset(graph, 0, sizeof(int)*SIZE*SIZE);
    return graph;
}

void create_edge(int * graph, int i, int j){
    graph[SIZE*i+j] = 1;
    return;
}

int is_edge(int * graph, int i, int j){
    return (graph[SIZE*i+j] == 1);
}

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct queue* q){
    int item;
    item = q->items[q->front];
    q->front++;
    if(q->front > q->rear){
        printf("Resetting queue");
        q->front = q->rear = -1;
     }
    return item;
}

void dfs(int *graph, int* visited, int* edgeTo)