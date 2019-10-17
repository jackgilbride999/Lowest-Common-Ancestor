#define SIZE 256

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

// A structure to represent a stack 
struct stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct stack_list_node {
    struct stack * stack;
    struct stack * next;
};

int * create_graph(int size);
void create_edge(int * graph, int i, int j);
int is_edge(int * graph, int i, int j);

int * find_lca_dag(int * graph, int root, int x, int y);
struct stack* createStack(unsigned capacity);
int isFull(struct stack* stack) ;
int isEmpty(struct stack* stack);
void push(struct stack* stack, int item) ;
int pop(struct stack* stack);
int peek(struct stack* stack) ;

struct node 
{ 
	struct node *left;
    struct node *right; 
	int key; 
};

struct node* new_node(int key);

struct node * get_lca(struct node * root, int x, int y);

struct node * get_lca_dag(struct node * all_nodes, struct node * x, struct node * y);