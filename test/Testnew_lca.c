/* Code to test lca.c using Unity unit testing framework. */

#include "new_lca.h"
#include "unity.h"
#include <assert.h>
#include <stdlib.h>

/*
    Test get_lca when the root pointer is NULL
*/
void test_EmptyTree(void){
    // both ints as zero
    struct node* lca = get_lca(NULL, 0, 0);
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
    // both ints as zero
    struct node* root = new_node(0);
    struct node* lca = get_lca(root, 0, 0);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of single node tree was not NULL.")
    free(root);
    free(lca);

    // both ints different, one is zero
    root = new_node(0);
    lca = get_lca(root, 0, 1);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of single node tree was not NULL.")
    free(root);
    free(lca);

    // both ints different, non-zero values
    root = new_node(5);
    lca = get_lca(root, 10, 15);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of single node tree was not NULL.")
    free(root);
    free(lca);

    // both ints equal, non-zero values
    root = new_node(40);
    lca = get_lca(root, 40, 40);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of single node tree was not NULL.")
    free(root);
    free(lca);
}

/*
    Test get_lca for a two node tree. All tests should return NULL as
    both nodes must share an ancestor but a node cannot be an ancestor
    of itself. Therefore there is not a third node that both nodes can
    share.
*/
void test_TwoNodeTree(void){
    // two zero nodes, with ints as zero, leaning left
    struct node* root = new_node(0);
    root -> left = new_node(0);
    struct node * lca = get_lca(root, 0, 0);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->left);
    free(root);

    // two zero nodes, with ints as zero, leaning right
    root = new_node(0);
    root -> right = new_node(0);
    lca = get_lca(root, 0, 0);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->right);
    free(root);

    // two non-zero equal nodes, with ints as node parameters, leaning left
    root = new_node(2);
    root -> left = new_node(2);
    lca = get_lca(root, 2, 2);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->left);
    free(root);

    // two non-zero equal nodes, with ints as node parameters, leaning right
    root = new_node(2);
    root -> right = new_node(2);
    lca = get_lca(root, 2, 2);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->right);
    free(root);

    // two non-zero non-equal nodes, with ints as node parameters, leaning left
    root = new_node(1);
    root -> left = new_node(2);
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->left);
    free(root);

    // two non-zero non-equal nodes, with ints as node parameters, leaning right
    root = new_node(1);
    root -> right = new_node(2);
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->right);
    free(root);

    // two non-zero non-equal nodes, with ints NOT as node parameters, leaning left
    root = new_node(1);
    root -> left = new_node(2);
    lca = get_lca(root, 3, 4);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->left);
    free(root);

    // two non-zero non-equal nodes, with ints NOT as node parameters, leaning right
    root = new_node(1);
    root -> right = new_node(2);
    lca = get_lca(root, 3, 4);
    TEST_ASSERT_NULL_MESSAGE(lca, "LCA of a two node tree was not NULL.");
    free(lca);
    free(root->right);
    free(root);
}

/*
    Test get_lca for a three node balanced tree. This is the first function
    where some tests should pass, when the function gets passed the
    keys of the root's two children.
*/
void test_ThreeNodeBalancedTree(void){
     // three distinct values in the nodes
    struct node* root = new_node(0);
    root -> left = new_node(1);
    root -> right = new_node(2);    
    struct node * lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);

    // three more distinct values in the nodes
    root = new_node(0);
    root -> left = new_node(1);
    root -> right = new_node(2);    
    lca = get_lca(root, 1, 2);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(lca->key, 0, "LCA of three node tree did not have expected value");
    free(root->left);
    free(root->right);
    free(root);     
}


int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_EmptyTree);
    RUN_TEST(test_SingleNodeTree);
    RUN_TEST(test_TwoNodeTree);
    RUN_TEST(test_ThreeNodeBalancedTree);
    return UNITY_END();
}