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


int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_EmptyTree);
    RUN_TEST(test_SingleNodeTree);
    RUN_TEST(test_TwoNodeTree);
    RUN_TEST(test_ThreeNodeBalancedTree);
    RUN_TEST(test_ThreeNodeUnbalancedTree);
    return UNITY_END();
}