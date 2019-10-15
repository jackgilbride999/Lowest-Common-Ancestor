
struct node 
{ 
	struct node *left;
    struct node *right; 
	int key; 
};

struct node* new_node(int key);

struct node * get_lca(struct node * root, int x, int y);

struct node * get_lca_dag(struct node * all_nodes, struct node * x, struct node * y);