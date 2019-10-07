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

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_EmptyTree);
    RUN_TEST(test_SingleNodeTree);
    return UNITY_END();
}