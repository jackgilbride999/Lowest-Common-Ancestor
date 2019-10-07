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
    if(this == NULL){
        // end of recursion, return NULL
        return NULL;
    }
    if(this->key == x || this->key == y){
        // key has been matched, return non-NULL value
        return this;
    }
    struct node * lca_left = get_lca_recursive(this->left, x, y);
    struct node * lca_right = get_lca_recursive(this->right, x, y);
    if(lca_left!=NULL && lca_right!=NULL){
        // key has been matched on both left and right subtrees, this is LCA
        return this;
    } else if(lca_left!=NULL){
        return lca_left;
    } else if(lca_right!=NULL){
        return lca_right;
    }
}

struct node * get_lca(struct node * root, int x, int y){
    struct node * result = get_lca_recursive(root, x, y);
    if(result==NULL){
        // LCA has not been found if NULL or either of the keys was returned
        return NULL;
    }
  //  printf("Key is %d\n", result->key);
    if(result->key == x || result -> key == y){
        return NULL;
    }
    return result;
}