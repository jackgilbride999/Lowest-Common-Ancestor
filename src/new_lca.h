
struct node 
{ 
	struct node *left;
    struct node *right; 
	int key; 
};

struct node* new_node(int key);

struct node * get_lca(struct node * root, int x, int y);