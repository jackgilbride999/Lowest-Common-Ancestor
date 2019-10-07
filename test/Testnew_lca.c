/* Code to test lca.c using Unity unit testing framework. */

#include "new_lca.h"
#include "unity.h"
#include <assert.h>

void test_EmptyTree(void){
    struct node* test = get_lca(NULL, 0, 1);
    TEST_ASSERT_NULL_MESSAGE(test, "LCA of with NULL tree was not NULL.")
}



int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_EmptyTree);
    return UNITY_END();
}