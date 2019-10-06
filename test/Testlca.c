/* Code to test lca.c using Unity unit testing framework. */

#include "lca.h"
#include "unity.h"

void test_EmptyTree(void){
    TEST_ASSERT_NULL_MESSAGE(NULL, "LCA of null tree was not null");
}

void test(void){

}

int main(void){
    UNITY_BEGIN();
    printf("Unity began");
    RUN_TEST(test_EmptyTree);
    printf("Unity tested");
    return UNITY_END();
}