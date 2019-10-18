/* Code to test lca.c using Unity unit testing framework. */
#include "new_lca.h"
#include "unity.h"
#include <assert.h>
#include <stdlib.h>

/*
    Test get_lca when the root pointer is NULL
*/
void test_EmptyTree(void){
    struct node* lca;

    // both ints as zero
    lca = get_lca(NULL, 0, 0);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of NULL tree was not NULL.");
    free(lca);

    // both ints as equal, non-zero values
    lca = get_lca(NULL, 5, 5);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of NULL tree was not NULL.");
    free(lca);

    // both ints different
    lca = get_lca(NULL, 10, 4);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of NULL tree was not NULL.");
    free(lca);
}


/*
    Test get_lca for a single node tree. All tests should return NULL as
    a single node is not an ancestor of any other nodes.
*/
void test_SingleNodeTree(void){
    struct node* root;
    struct node* lca;

    // both ints as zero
    root = new_node(0);
    lca = get_lca(root, 0, 0);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of single node tree was not NULL.");
    free(root);

    // both ints different, one is zero
    root = new_node(0);
    lca = get_lca(root, 0, 1);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of single node tree was not NULL.");
    free(root);

    // both ints different, non-zero values
    root = new_node(5);
    lca = get_lca(root, 10, 15);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of single node tree was not NULL.")
    free(root);

    // both ints equal, non-zero values
    root = new_node(40);
    lca = get_lca(root, 40, 40);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 40, "LCA of single node tree was not NULL.");
    free(root);
}

/*
    Test get_lca for a two node tree. All tests should return NULL as
    both nodes must share an ancestor but a node cannot be an ancestor
    of itself. Therefore there is not a third node that both nodes can
    share.
*/
void test_TwoNodeTree(void){
    struct node* root;
    struct node* lca;

    // two zero nodes, with ints as zero, leaning left
    root = new_node(0);
    root -> left = new_node(0);
    lca = get_lca(root, 0, 0);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of a two node tree was not NULL.");
    free(root->left);
    free(root);

    // two zero nodes, with ints as zero, leaning right
    root = new_node(0);
    root -> right = new_node(0);
    lca = get_lca(root, 0, 0);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of a two node tree was not NULL.");
    free(root->right);
    free(root);

    // two non-zero equal nodes, with ints as node parameters, leaning left
    root = new_node(2);
    root -> left = new_node(2);
    lca = get_lca(root, 2, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 2, "LCA of a two node tree was not NULL.");
    free(root->left);
    free(root);

    // two non-zero equal nodes, with ints as node parameters, leaning right
    root = new_node(2);
    root -> right = new_node(2);
    lca = get_lca(root, 2, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 2, "LCA of a two node tree was not NULL.");
    free(root->right);
    free(root);

    // two non-zero non-equal nodes, with ints as node parameters, leaning left 
    root = new_node(1);
    root -> left = new_node(2);
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 1, "LCA of a two node tree was not NULL.");
    free(root->left);
    free(root);

    // two non-zero non-equal nodes, with ints as node parameters, leaning right
    root = new_node(1);
    root -> right = new_node(2);
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 1, "LCA of a two node tree was not NULL.");
    free(root->right);
    free(root);

    // two non-zero non-equal nodes, with ints NOT as node parameters, leaning left
    root = new_node(1);
    root -> left = new_node(2);
    lca = get_lca(root, 3, 4);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(root->left);
    free(root);

    // two non-zero non-equal nodes, with ints NOT as node parameters, leaning right
    root = new_node(1);
    root -> right = new_node(2);
    lca = get_lca(root, 3, 4);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(root->right);
    free(root);
}

/*
    Test get_lca for a three node balanced tree.
*/
void test_ThreeNodeBalancedTree(void){
    struct node* root;
    struct node* lca;

     // three distinct values in the nodes
    root = new_node(0);
    root -> left = new_node(1);
    root -> right = new_node(2);    
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);

    // three more distinct values in the nodes
    root = new_node('a');
    root -> left = new_node('b');
    root -> right = new_node('c');    
    lca = get_lca(root, 'b', 'c');
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 'a', "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);     

    // three more distinct values in the nodes
    root = new_node('a');
    root -> left = new_node('b');
    root -> right = new_node('c');    
    lca = get_lca(root, 'b', 'c');
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 'a', "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);   

    // three non-distinct values in the nodes
    root = new_node(0);
    root -> left = new_node(0);
    root -> right = new_node(0);    
    lca = get_lca(root, 0, 0);
 //   TEST_ASSERT_NULL_MESSAGE(lca, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);

    // one leaf has the same key as the root
    root = new_node(0);
    root -> left = new_node(0);
    root -> right = new_node(1);    
    lca = get_lca(root, 0, 1);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);      

    // two leaves have the same key
    root = new_node('a');
    root -> left = new_node('b');
    root -> right = new_node('b');    
    lca = get_lca(root, 'b', 'b');
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 'a', "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);

    // one value not in tree
    root = new_node('a');
    root -> left = new_node('b');
    root -> right = new_node('c');    
    lca = get_lca(root, 'd', 'c');
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);

    // both values not in tree
    root = new_node('a');
    root -> left = new_node('b');
    root -> right = new_node('c');    
    lca = get_lca(root, 'd', 'e');
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);
}

/*
    Test get_lca for a three node leaning tree.
*/
void test_ThreeNodeUnbalancedTree(void){
    struct node* root;
    struct node* lca;

    // three non distinct values, leaning left
    root = new_node(1);
    root->left = new_node(1);
    root->left->left = new_node(1);
    lca = get_lca(root, 1, 1);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 1, "LCA of three node tree did not have expected value");
    free(root->left->left);
    free(root->left);
    free(root);

    // three non distinct values, leaning right
    root = new_node(2);
    root->right = new_node(2);
    root->right->right = new_node(2);
    lca = get_lca(root, 2, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 2, "LCA of three node tree did not have expected value");
    free(root->right->right);
    free(root->right);
    free(root);

    // three distinct values, leaning left
    root = new_node(3);
    root->left = new_node(2);
    root->left->left = new_node(1);
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 2, "LCA of three node tree did not have expected value");
    free(root->left->left);
    free(root->left);
    free(root);

    // three distinct values, leaning left where lca is root
    root = new_node(3);
    root->left = new_node(2);
    root->left->left = new_node(1);
    lca = get_lca(root, 3, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 3, "LCA of three node tree did not have expected value");
    free(root->left->left);
    free(root->left);
    free(root);

    // three distinct values, leaning left
    root = new_node(3);
    root->right = new_node(2);
    root->right->right = new_node(1);
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 2, "LCA of three node tree did not have expected value");
    free(root->right->right);
    free(root->right);
    free(root);

    // three distinct values, leaning left where lca is root
    root = new_node(3);
    root->right = new_node(2);
    root->right->right = new_node(1);
    lca = get_lca(root, 3, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 3, "LCA of three node tree did not have expected value");
    free(root->right->right);
    free(root->right);
    free(root);
}

/*
    a 
      - b
          - d
              - 
              - 
          - e
              - h   
                  - l
                  -
              - 
      - c
          - f
              - NULL
              - i
                  -
                  - m
          - g
              - j
              - k
*/
void test_LargeTree(void){
    struct node* root;
    struct node* a;
    struct node* b;
    struct node* c;
    struct node* d;
    struct node* e;
    struct node* f;
    struct node* g;
    struct node* h;
    struct node* i;
    struct node* j;
    struct node* k;
    struct node* l;
    struct node* m;


    struct node* lca;

    a = root = new_node('a');
    b = a->left = new_node('b');
    c = a->right = new_node('c');
    d = b->left = new_node('d');
    e = b->right = new_node('e');
    f = c->left = new_node('f');
    g = c->right = new_node('g');
    h = e->left = new_node('h');
    i = f->right = new_node('i');
    j = g->left = new_node('j');
    k = g->right = new_node('k');
    l = h->left = new_node('l');
    m = i->right = new_node('m');
    
    TEST_ASSERT_NULL_MESSAGE(get_lca(a, 'z', 'y'), "LCA on large tree did not return as expected");
    TEST_ASSERT_NULL_MESSAGE(get_lca(a, 'a', 'x'), "LCA on large tree did not return as expected")
    TEST_ASSERT_NULL_MESSAGE(get_lca(a, 'w', 'k'), "LCA on large tree did not return as expected")


   TEST_ASSERT_EQUAL_PTR_MESSAGE(a, get_lca(a, 'a', 'a'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(a, get_lca(a, 'a', 'b'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(a, get_lca(a, 'a', 'd'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(a, get_lca(a, 'a', 'h'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(a, get_lca(a, 'a', 'm'), "LCA on large tree did not return as expected");

   TEST_ASSERT_EQUAL_PTR_MESSAGE(b, get_lca(a, 'b', 'l'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(b, get_lca(a, 'd', 'h'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(b, get_lca(a, 'l', 'd'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(b, get_lca(a, 'd', 'e'), "LCA on large tree did not return as expected");

   TEST_ASSERT_EQUAL_PTR_MESSAGE(c, get_lca(a, 'c', 'm'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(c, get_lca(a, 'f', 'k'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(c, get_lca(a, 'j', 'm'), "LCA on large tree did not return as expected");
   TEST_ASSERT_EQUAL_PTR_MESSAGE(c, get_lca(a, 'i', 'g'), "LCA on large tree did not return as expected");

    TEST_ASSERT_EQUAL_PTR_MESSAGE(d, get_lca(a, 'd', 'd'), "LCA on large tree did not return as expected");

    TEST_ASSERT_EQUAL_PTR_MESSAGE(e, get_lca(a, 'e', 'e'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(e, get_lca(a, 'h', 'e'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(e, get_lca(a, 'e', 'l'), "LCA on large tree did not return as expected");
    
    TEST_ASSERT_EQUAL_PTR_MESSAGE(f, get_lca(a, 'f', 'f'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(f, get_lca(a, 'i', 'f'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(f, get_lca(a, 'f', 'm'), "LCA on large tree did not return as expected");

    TEST_ASSERT_EQUAL_PTR_MESSAGE(g, get_lca(a, 'j', 'k'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(g, get_lca(a, 'g', 'k'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(g, get_lca(a, 'g', 'j'), "LCA on large tree did not return as expected");   

    TEST_ASSERT_EQUAL_PTR_MESSAGE(h, get_lca(a, 'h', 'h'), "LCA on large tree did not return as expected"); 
    TEST_ASSERT_EQUAL_PTR_MESSAGE(h, get_lca(a, 'l', 'h'), "LCA on large tree did not return as expected"); 

    TEST_ASSERT_EQUAL_PTR_MESSAGE(i, get_lca(a, 'i', 'i'), "LCA on large tree did not return as expected");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(i, get_lca(a, 'm', 'i'), "LCA on large tree did not return as expected");
    
    free(a); free(b); free(c); free(d); free(e); free(f); free(g); free(h); free(i); free(j); free(k); free(l); free(m);
 
}

void test_SampleDAG(void){
   /* struct node* root;
    struct node* a;
    struct node* b;
    struct node* c;
    struct node* d;
    struct node* e;
    struct node* f;
    struct node* g;

    a = root = new_node('a');
    b = a->left = new_node('b');
    c = b->left = new_node('c');
    d = a->right = new_node('d');
    e = d->right = new_node('e');
    f = c->right = e->right = new_node('f');
    g = f->right = new_node('g');

    TEST_ASSERT_EQUAL_PTR_MESSAGE(e, get_lca(a, 'e', 'f'), "LCA on large tree did not return as expected");*/

    int * graph = create_graph(256);
    create_edge(graph, 'a', 'b');
    create_edge(graph, 'b', 'c');
    create_edge(graph, 'b', 'e');
    create_edge(graph, 'c','d');
    create_edge(graph, 'e', 'f');
    create_edge(graph, 'd', 'g');
    create_edge(graph, 'f', 'g');
    TEST_ASSERT_EQUAL_INT64_MESSAGE('e', find_lca_dag(graph, 'a', 'e', 'f'), "LCA on DAG did not return as expected");
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_EmptyTree);
    RUN_TEST(test_SingleNodeTree);
    RUN_TEST(test_TwoNodeTree);
    RUN_TEST(test_ThreeNodeBalancedTree);
    RUN_TEST(test_ThreeNodeUnbalancedTree);
    RUN_TEST(test_LargeTree);
    RUN_TEST(test_SampleDAG);
    return UNITY_END();
}