struct node 
{ 
	int data; 
	struct node* left, *right; 
}; 

struct node *lca(struct node* root, int n1, int n2);

struct node* newNode(int data);

int main();