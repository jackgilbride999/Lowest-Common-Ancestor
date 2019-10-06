/* Code to test lca.c using Unity unit testing framework. */

#include "lca.h"
#include "unity.h"

void test_EmptyTree(void){
    TEST_ASSERT_NULL_MESSAGE(findLCA(NULL, 0, 0), "LCA of null tree was not null");
}

void test_SingleNode(void){
   /* struct node* testTree = newNode(1);
    struct node* result = findLCA(testTree, 1, 1);
  //  TEST_ASSERT_EQUAL_INT64_MESSAGE(result, NULL, "LCA of one node tree was not correct");
    struct node * secondNode = newNode(2);
    testTree->left=secondNode;
    result = findLCA(testTree, 1, 2)->key;
    //TEST_ASSERT_EQUAL_INT64_MESSAGE(result, 1, "LCA of one node tree was not correct");
    struct node * thirdNode = newNode(3);
    testTree->right=secondNode;
    result = findLCA(testTree, 2, 3)->key;
    printf("%d", result);
    TEST_ASSERT_EQUAL_INT64_MESSAGE(result, 1, "LCA of one node tree was not correct");
*/
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_EmptyTree);
    RUN_TEST(test_SingleNode);
    return UNITY_END();
}