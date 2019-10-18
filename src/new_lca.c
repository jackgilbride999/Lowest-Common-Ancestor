#include <stdio.h> 
#include <stdlib.h> 
#include "new_lca.h"
#include <limits.h>
#include <string.h>

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

void find_lca_dag_recursive(int * graph, struct stack * stack, int current, int x, int y, struct stack * paths1[], struct stack * paths2[]){
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
            find_lca_dag_recursive(graph, stack, i, x, y, paths1, paths2);
        }
    }
    pop(stack);
    return;
}

int find_lca_dag(int * graph, int root, int x, int y){
    // Stack to keep track of the current path
    struct stack * stack = createStack(SIZE);
    // Arrays to store paths to nodes that we find
    struct stack * paths1[SIZE] = {NULL};
    struct stack * paths2[SIZE] = {NULL};
    // Depth-first-search
    find_lca_dag_recursive(graph, stack, root, x, y, paths1, paths2);
    int lowestCommonAncestor = -1;
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
                    lowestCommonAncestor = path1Node;
                }
                else if(k > depth){
                    lowestCommonAncestor = currentCommonAncestor;
                    depth = i;
                    break;
                }
            }
        }
    }
    return lowestCommonAncestor;
}

struct node* new_node(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = node->right = NULL; 
	return node; 
} 

struct node * get_lca_recursive(struct node * this, int x, int y, int* v1, int* v2){
    if(this == NULL){
        // end of recursion, return NULL
        return NULL;
    }
    if(this->key == x){
        // key has been matched, return non-NULL value
        *v1 = 1;
        return this;
    }
    if(this->key == y){
        // key has been matched, return non-NULL value
        *v2 = 1;
        return this;
    }
    struct node * lca_left = get_lca_recursive(this->left, x, y, v1, v2);
    struct node * lca_right = get_lca_recursive(this->right, x, y, v1, v2);
    if(lca_left!=NULL && lca_right!=NULL){
        // key has been matched on both left and right subtrees, this is LCA
        return this;
    } else if(lca_left!=NULL){
        return lca_left;
    } else if(lca_right!=NULL){
        return lca_right;
    }
}

int find(struct node *this, int k){
    if(this==NULL){
        return 0;
    }

    if(this->key == k ||  find(this->left, k) || find(this->right, k)){
        return 1;
    }

    return 0;

}

struct node * get_lca(struct node * root, int x, int y){

    int v1 = 0;
    int v2 = 0;
    struct node * result = get_lca_recursive(root, x, y, &v1, &v2);
    if(result==NULL){
        // LCA has not been found if NULL or either of the keys was returned
        return NULL;
    }
    if(v1 && v2 || v1 && find(result, y) || v2 && find(result, x)){
        return result;
    }
    return NULL;
}
