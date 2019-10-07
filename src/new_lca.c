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

struct node * get_lca_recursive(struct node * this, int x, int y){
    int x_matched = 0;
    int y_matched = 0;
    if(this == NULL){
        // end of recursion, return NULL
        return NULL;
    }
    if(this->key == x || this->key ==y){
        // key has been matched, return non-NULL value
        return this;
    }
    struct node * lca_left = get_lca(this->left, x, y);
    struct node * lca_right = get_lca(this->right, x, y);
    if(lca_left && lca_right){
        // key has been matched on both left and right subtrees, this is LCA
        return this;
    } else if(lca_left){
        return lca_left;
    } else if(lca_right){
        return lca_right;
    }
}

struct node * get_lca(struct node * root, int x, int y){
    struct node * result = get_lca_recursive(root, x, y);
    if(result==NULL || result->key == x || result ->key == y){
        // LCA has not been found if NULL or either of the keys was returned
        return NULL;
    }
    return result;
}