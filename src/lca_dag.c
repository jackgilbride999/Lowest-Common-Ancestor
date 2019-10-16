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
    memset(q, 0, sizeof(struct queue));
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
        q->front = q->rear = -1;
     }
    return item;
}

/*
    Do a breadth-first search on a graph given
    a root. edgesTo is a 2D array mapped to a 1D
    array in row-major order. If there is a path
    from root to node x, then edgesTo[x][0] will
    contain the edge connecting x to that path. 
    If x has multiple parents then edgesTo[x][1] 
    will also be populated, then edgesTo[x][2] etc.
    This array can then be traversed from x to find
    all ancestors of x with respect to root.
*/
void bfs(int node, int *graph, int* edgesTo){
    struct queue * queue = createQueue();
    int* visited = malloc(SIZE*sizeof(int));
    enqueue(queue, node);
    visited[node] = 1;
    while(!isEmpty(queue)){
        int currentVertex = dequeue(queue);
        for(int i=0; i<SIZE; i++){
            if(is_edge(graph, currentVertex, i)){
                // if there is an edge from the dequeued vertex to the other vertex
                if(visited[i]==0){
                    // and if the neighbouring vertex is unvisited
                    enqueue(queue, i);
                    visited[i]=1;
                }
                if(edgesTo[i*SIZE]==0){
                    edgesTo[i*SIZE] = currentVertex;
                } else{
                    int j;
                    for(j = i*SIZE; edgesTo[j]!=0; j++);
                    edgesTo[j]=currentVertex;
                }
            }
        }
    }
}

int lca_dag(int* graph, int root){

}