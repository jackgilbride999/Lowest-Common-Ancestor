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