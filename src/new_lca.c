#include <stdio.h> 
#include <stdlib.h> 
#include "new_lca.h"

struct node* new_node(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = node->right = NULL; 
	return node; 
} 

struct node * get_lca(struct node * root, int x, int y){
    if(root == NULL){
        return NULL;
    }
}