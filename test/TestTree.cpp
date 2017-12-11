//
// Created by janne on 07.12.2017.
//

#include "TestTree.h"

using namespace std;

TEST(TestTree, Test_Empty) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(0, tree.getHeight());
}

TEST(TestTree, Test_Insert_1) {
    AVLTree tree;
    tree += 1;
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_EQ(1, tree.getHeight());
}

TEST(TestTree, Test_Insert_same) {
    AVLTree tree;
    tree += 1;
    tree += 1;
    EXPECT_EQ(1, tree.getHeight());
}

TEST(TestTree, Test_Insert_231) {
    AVLTree tree;
    tree += 2;
    tree += 3;
    tree += 1;
    EXPECT_EQ(2, tree.getHeight());
}

TEST(TestTree, Test_Insert_rotation_right) {
    AVLTree tree;
    tree += 3;
    tree += 2;
    tree += 1;
    EXPECT_EQ(2, tree.getHeight());
}

TEST(TestTree, Test_Insert_rotation_left) {
    AVLTree tree;
    tree += 1;
    tree += 2;
    tree += 3;
    EXPECT_EQ(2, tree.getHeight());
}