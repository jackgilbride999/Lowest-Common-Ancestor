// A recursive C program to find LCA of two nodes n1 and n2. 
#include <stdio.h> 
#include <stdlib.h> 
#include "lca.h"

/* C program to find LCA of n1 and n2 using one traversal of Binary Tree. 
It handles all cases even when n1 or n2 is not there in Binary Tree */

// Utility function to create a new tree Node 
struct node* newNode(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = node->right = NULL; 
	return node; 
} 

// This function returns pointer to LCA of two given values n1 and n2. 
// v1 is set as true by this function if n1 is found 
// v2 is set as true by this function if n2 is found 
struct node *findLCAUtil(struct node* root, int n1, int n2, int v1, int v2) 
{ 
	// Base case 
	if (root == NULL) return NULL; 

	// If either n1 or n2 matches with root's key, report the presence 
	// by setting v1 or v2 as true and return root (Note that if a key 
	// is ancestor of other, then the ancestor key becomes LCA) 
	if (root->key == n1) 
	{ 
		v1 = 1; 
		return root; 
	} 
	if (root->key == n2) 
	{ 
		v2 = 1; 
		return root; 
	} 

	// Look for keys in left and right subtrees 
	struct node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2); 
	struct node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 

	// If both of the above calls return Non-NULL, then one key 
	// is present in once subtree and other is present in other, 
	// So this node is the LCA 
	if (left_lca && right_lca) return root; 

	// Otherwise check if left subtree or right subtree is LCA 
	return (left_lca != NULL)? left_lca: right_lca; 
} 

// Returns true if key k is present in tree rooted with root 
int find(struct node *root, int k) 
{ 
	// Base Case 
	if (root == NULL) 
		return 0; 

	// If key is present at root, or in left subtree or right subtree, 
	// return true; 
	if (root->key == k || find(root->left, k) || find(root->right, k)) 
		return 1; 

	// Else return false 
	return 0; 
} 

// This function returns LCA of n1 and n2 only if both n1 and n2 are present 
// in tree, otherwise returns NULL; 
struct node *findLCA(struct node *root, int n1, int n2) 
{ 
	// Initialize n1 and n2 as not visited 
	int v1 = 0, v2 = 0; 

	// Find lca of n1 and n2 using the technique discussed above 
	struct node *lca = findLCAUtil(root, n1, n2, v1, v2); 

	// Return LCA only if both n1 and n2 are present in tree 
	if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1)) 
		return lca; 

	// Else return NULL 
	return NULL; 
} 

/*
// Driver program to test above functions 
int main() 
{ 
	// Let us create binary tree given in the above example 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	Node *lca = findLCA(root, 4, 5); 
	if (lca != NULL) 
	cout << "LCA(4, 5) = " << lca->key; 
	else
	cout << "Keys are not present "; 

	lca = findLCA(root, 4, 10); 
	if (lca != NULL) 
	cout << "nLCA(4, 10) = " << lca->key; 
	else
	cout << "nKeys are not present "; 

	return 0; 
}


/* Function to find LCA of n1 and n2. The function assumes that both 
n1 and n2 are present in BST 
struct node *lca(struct node* root, int n1, int n2) 
{ 
	if (root == NULL) return NULL; 

	// If both n1 and n2 are smaller than root, then LCA lies in left 
	if (root->data > n1 && root->data > n2) 
		return lca(root->left, n1, n2); 

	// If both n1 and n2 are greater than root, then LCA lies in right 
	if (root->data < n1 && root->data < n2) 
		return lca(root->right, n1, n2); 

	return root; 
} 

/* Helper function that allocates a new node with the given data.
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return(node); 
} 

/* Driver program to test lca()
int main() 
{ 
	// Let us construct the BST shown in the above figure 
	struct node *root	 = newNode(20); 
	root->left			 = newNode(8); 
	root->right			 = newNode(22); 
	root->left->left		 = newNode(4); 
	root->left->right	 = newNode(12); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(14); 

	int n1 = 10, n2 = 14; 
	struct node *t = lca(root, n1, n2); 
	printf("LCA of %d and %d is %d \n", n1, n2, t->data); 

	n1 = 14, n2 = 8; 
	t = lca(root, n1, n2); 
	printf("LCA of %d and %d is %d \n", n1, n2, t->data); 

	n1 = 10, n2 = 22; 
	t = lca(root, n1, n2); 
	printf("LCA of %d and %d is %d \n", n1, n2, t->data); 

	getchar(); 
	return 0; 
} */
