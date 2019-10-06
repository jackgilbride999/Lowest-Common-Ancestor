/*struct node 
{ 
	int data; 
	struct node* left, *right; 
};

struct node *lca(struct node* root, int n1, int n2);

struct node* newNode(int data);

int main();
*/
// A Binary Tree Node 
struct node 
{ 
	struct node *left, *right; 
	int key; 
}; 

struct node* newNode(int key);

struct node *findLCAUtil(struct node* root, int n1, int n2, int v1, int v2);

int find(struct node *root, int k);

struct node *findLCA(struct node *root, int n1, int n2);

