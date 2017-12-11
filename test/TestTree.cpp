//
// Created by janne on 07.12.2017.
//

#include "TestTree.h"

using namespace std;

TEST(TestTree, Test_Insert_1) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(0,tree.getHeight());
}