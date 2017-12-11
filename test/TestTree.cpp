//
// Created by janne on 07.12.2017.
//

#include "TestTree.h"

using namespace std;

TEST(TestTree, Test_Empty) {
    AVLTree tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(0, tree.getHeight());
}

TEST(TestTree, Test_Insert_1) {
    AVLTree tree;
    tree += 1;
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(1, tree.getHeight());
}

TEST(TestTree, Test_Insert_same) {
    AVLTree tree;
    tree += 1;
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(1, tree.getHeight());
}

TEST(TestTree, Test_Insert_231) {
    AVLTree tree;
    tree += 2;
    tree += 3;
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}

TEST(TestTree, Test_Insert_rotation_right) {
    AVLTree tree;
    tree += 3;
    tree += 2;
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}

TEST(TestTree, Test_Insert_multiple_rotations) {
    AVLTree tree;
    EXPECT_EQ(0, tree.getHeight());
    tree += 8;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(1, tree.getHeight());
    tree += 7;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
    tree += 6;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
    tree += 5;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 4;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 2;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(4, tree.getHeight());
}

TEST(TestTree, Test_Insert_rotation_left) {
    AVLTree tree;
    tree += 1;
    tree += 2;
    tree += 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}