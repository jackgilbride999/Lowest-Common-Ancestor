#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
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
void bfs(int node, int *graph, int* edgesTo, int* depths){
    int current_depth = 0;
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
                    depths[i] = current_depth;
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
        current_depth++;
    }
}

// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct stack* createStack(unsigned capacity) 
{ 
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct stack* stack, int item) 
{ 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct stack* stack) 
{ 
    return stack->array[stack->top--]; 
} 
  
// Function to return the top from stack without removing it 
int peek(struct stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
}

void find_lca_attempt2_recursive(int * graph, struct stack * stack, int current, int x, int y, struct stack * paths1[], struct stack * paths2[]){
    push(stack, current);
    if(current==x){
        struct stack * current_stack = createStack(SIZE);
        for(int i = 0; i<=stack->top; i++){
            push(current_stack, stack->array[i]);
        }
        int j;
        for(j=0; paths1[j]!=NULL; j++);
        paths1[j] = current_stack;
    }
    if(current==y){
        struct stack * current_stack = createStack(SIZE);
        for(int i = 0; i<=stack->top; i++){
            push(current_stack, stack->array[i]);
        }
        int j;
        for(j=0; paths2[j]!=NULL; j++);
        paths2[j] = current_stack;
    }
    for(int i=0; i<SIZE; i++){
        if(is_edge(graph, current, i)){
            find_lca_attempt2_recursive(graph, stack, i, x, y, paths1, paths2);
        }
    }
    pop(stack);
    return;
}

int * find_lca_attempt2(int * graph, int root, int x, int y){
    // Stack to keep track of the current path
    struct stack * stack = createStack(SIZE);
    // Arrays to store paths to nodes that we find
    struct stack * paths1[SIZE] = {NULL};
    struct stack * paths2[SIZE] = {NULL};
    // Depth-first-search
    find_lca_attempt2_recursive(graph, stack, root, x, y, paths1, paths2);
    int greatestCommonAncestor = -1;
    int depth = -1;
    // for all the paths from root to x
    for(int i = 0; paths1[i]!=NULL; i++){
        struct  stack * path1 = paths1[i];
        // for all the paths from root to y
        for(int j = 0; paths2[j]!=NULL; j++){
            struct  stack * path2 = paths2[j];
            int len1 = sizeof(paths1);
            int len2 = sizeof(paths2);
            int length = 0;
            if(len1 >= len2){
                length = len1;
            } else{
                length = len2;
            }
            int currentCommonAncestor = -1;
            // traverse path1 and path2 to find 
            for(int k = 0; k < length; k++){
                int path1Node = -1;
                int path2Node = -1;
                if(k<len1){
                    path1Node = path1->array[k];
                }
                if(k<len2){
                    path2Node = path2->array[k];
                }
                if(path1Node == path2Node){
                    greatestCommonAncestor = path1Node;
                }
                else if(k > depth){
                    greatestCommonAncestor = currentCommonAncestor;
                    depth = i;
                    break;
                }
            }
        }
    }
    return greatestCommonAncestor;
}

/*
    Recursive function. Find the parents of x. Call function to find
    the parents of x's parents.
*/
void get_ancestors(int x, int* edgesTo, int * x_ancestors_depth, int depth){
    
}

/*  
    Find the lowest common ancestor of x and y in the
    directed acyclic graph in respect to root.
*/
int lca_dag(int* graph, int root, int x, int y){
    // create the row-major array edgesTo
    int* edgesTo = calloc(0, sizeof(int)*SIZE*SIZE);
    // call bfs on the graph from the root
    bfs(root, graph, edgesTo);
    // allocate an array of the depth of the ancestors of x in respect to root
    int * x_ancestors_depth = calloc(0, sizeof(int)*SIZE);
    // same for y
    int * y_ancestors_depth = calloc(0, sizeof(int)*SIZE);
    // find the ancestors of x
    get_ancestors(x, edgesTo, x_ancestors_depth, 0); //??
}