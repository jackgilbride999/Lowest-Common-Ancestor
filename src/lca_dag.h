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

const int SIZE = 256;
