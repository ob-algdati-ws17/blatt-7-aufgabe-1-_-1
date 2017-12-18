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
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_TRUE(tree.isEmpty());
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
    EXPECT_EQ(0, tree.getBalanceAt(2));
    tree += 3;
    EXPECT_EQ(1, tree.getBalanceAt(2));
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}

TEST(TestTree, Test_Insert_rotation_right) {
    AVLTree tree;
    tree += 3;
    tree += 2;
    EXPECT_EQ(-1, tree.getBalanceAt(3));
    tree += 1;
    EXPECT_EQ(0, tree.getBalanceAt(1));
    EXPECT_EQ(0, tree.getBalanceAt(2));
    EXPECT_EQ(0, tree.getBalanceAt(3));
    EXPECT_EQ(1, tree.getHeightAt(2));
    EXPECT_EQ(2, tree.getHeightAt(1));
    EXPECT_EQ(2, tree.getHeightAt(3));
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
    EXPECT_EQ(0, tree.getBalanceAt(8));
    EXPECT_EQ(0, tree.getBalanceAt(7));
    EXPECT_EQ(0, tree.getBalanceAt(6));
    EXPECT_EQ(1, tree.getHeightAt(7));
    EXPECT_EQ(2, tree.getHeightAt(6));
    EXPECT_EQ(2, tree.getHeightAt(8));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
    tree += 5;
    EXPECT_EQ(0, tree.getBalanceAt(8));
    EXPECT_EQ(-1, tree.getBalanceAt(7));
    EXPECT_EQ(-1, tree.getBalanceAt(6));
    EXPECT_EQ(1, tree.getHeightAt(7));
    EXPECT_EQ(2, tree.getHeightAt(6));
    EXPECT_EQ(2, tree.getHeightAt(8));
    EXPECT_EQ(3, tree.getHeightAt(5));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 4;
    EXPECT_EQ(0, tree.getBalanceAt(8));
    EXPECT_EQ(-1, tree.getBalanceAt(7));
    EXPECT_EQ(0, tree.getBalanceAt(6));
    EXPECT_EQ(0, tree.getBalanceAt(4));
    EXPECT_EQ(0, tree.getBalanceAt(5));
    EXPECT_EQ(1, tree.getHeightAt(7));
    EXPECT_EQ(2, tree.getHeightAt(5));
    EXPECT_EQ(2, tree.getHeightAt(8));
    EXPECT_EQ(3, tree.getHeightAt(6));
    EXPECT_EQ(3, tree.getHeightAt(4));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 3;
    EXPECT_EQ(0, tree.getBalanceAt(7));
    EXPECT_EQ(-1, tree.getBalanceAt(4));
    EXPECT_EQ(0, tree.getBalanceAt(5));
    EXPECT_EQ(0, tree.getBalanceAt(3));
    EXPECT_EQ(0, tree.getBalanceAt(6));
    EXPECT_EQ(0, tree.getBalanceAt(8));
    EXPECT_EQ(1, tree.getHeightAt(5));
    EXPECT_EQ(2, tree.getHeightAt(4));
    EXPECT_EQ(2, tree.getHeightAt(7));
    EXPECT_EQ(3, tree.getHeightAt(3));
    EXPECT_EQ(3, tree.getHeightAt(6));
    EXPECT_EQ(3, tree.getHeightAt(8));
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
    EXPECT_EQ(0, tree.getBalanceAt(1));
    EXPECT_EQ(0, tree.getBalanceAt(2));
    EXPECT_EQ(0, tree.getBalanceAt(3));
    EXPECT_EQ(1, tree.getHeightAt(2));
    EXPECT_EQ(2, tree.getHeightAt(1));
    EXPECT_EQ(2, tree.getHeightAt(3));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}


TEST(TestTree, Test_Insert_double_rotation_right) {
    AVLTree tree;
    tree += 3;
    tree += 1;
    tree += 2;
    EXPECT_EQ(0, tree.getBalanceAt(1));
    EXPECT_EQ(0, tree.getBalanceAt(2));
    EXPECT_EQ(0, tree.getBalanceAt(3));
    EXPECT_EQ(1, tree.getHeightAt(2));
    EXPECT_EQ(2, tree.getHeightAt(1));
    EXPECT_EQ(2, tree.getHeightAt(3));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}

TEST(TestTree, Test_Insert_double_rotation_left) {
    AVLTree tree;
    tree += 1;
    tree += 3;
    tree += 2;
    EXPECT_EQ(0, tree.getBalanceAt(1));
    EXPECT_EQ(0, tree.getBalanceAt(2));
    EXPECT_EQ(0, tree.getBalanceAt(3));
    EXPECT_EQ(1, tree.getHeightAt(2));
    EXPECT_EQ(2, tree.getHeightAt(1));
    EXPECT_EQ(2, tree.getHeightAt(3));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
}


TEST(TestTree, Test_Insert_multiple_different_rotations) {
    AVLTree tree;
    tree += 7;
    tree += 9;
    tree += 8;
    EXPECT_EQ(0, tree.getBalanceAt(7));
    EXPECT_EQ(0, tree.getBalanceAt(8));
    EXPECT_EQ(0, tree.getBalanceAt(9));
    EXPECT_EQ(1, tree.getHeightAt(8));
    EXPECT_EQ(2, tree.getHeightAt(9));
    EXPECT_EQ(2, tree.getHeightAt(7));
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
    tree += 5;
    EXPECT_EQ(-1, tree.getBalanceAt(7));
    EXPECT_EQ(-1, tree.getBalanceAt(8));
    EXPECT_EQ(0, tree.getBalanceAt(9));
    EXPECT_EQ(1, tree.getHeightAt(8));
    EXPECT_EQ(2, tree.getHeightAt(9));
    EXPECT_EQ(2, tree.getHeightAt(7));
    tree += 6;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 4;
    tree += 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree += 10;
    tree += 11;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(4, tree.getHeight());
    tree += 2;
    tree += 12;
    tree += 1;
    tree += 13;
    tree += 15;
    tree += 14;
    EXPECT_TRUE(tree.checkIntegrity());
}

TEST(TestTree, Test_Delete_Double_Rotation) {
    AVLTree tree;
    tree += 4;
    tree += 5;
    tree += 2;
    tree += 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree -= 5;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
    EXPECT_EQ(1, tree.getHeightAt(3));
    tree -= 4;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 2;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_TRUE(tree.isEmpty());
}

TEST(TestTree, Test_Delete_Rotation) {
    AVLTree tree;
    tree += 3;
    tree += 2;
    tree += 4;
    tree += 5;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(3, tree.getHeight());
    tree -= 2;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(2, tree.getHeight());
    EXPECT_EQ(1, tree.getHeightAt(4));
    tree -= 4;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 5;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_TRUE(tree.isEmpty());
}

TEST(TestTree, Test_Delete_Two_Children) {
    AVLTree tree;
    tree += 2;
    tree += 3;
    tree += 1;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 2;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 1;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 3;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_TRUE(tree.isEmpty());
}

TEST(TestTree, Test_Delete_Two_Children2) {
    AVLTree tree;
    tree += 2;
    tree += 4;
    tree += 1;
    tree += 3;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 2;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 1;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 3;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 4;
    EXPECT_TRUE(tree.isEmpty());
}

TEST(TestTree, Test_Delete_with_one_child) {
    AVLTree tree;
    tree += 2;
    tree += 3;
    tree += 1;
    tree += 4;
    EXPECT_EQ(1, tree.getBalanceAt(3));
    EXPECT_EQ(3, tree.getHeightAt(4));
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 3;
    EXPECT_EQ(2, tree.getHeightAt(4));
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 4;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 2;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_EQ(1, tree.getHeightAt(1));
    tree -= 1;
    EXPECT_TRUE(tree.checkIntegrity());
    EXPECT_TRUE(tree.isEmpty());
}
TEST(TestTree, Test_Delete_with_one_child2) {
    AVLTree tree;
    tree += 2;
    tree += 4;
    tree += 1;
    tree += 3;
    EXPECT_TRUE(tree.checkIntegrity());
    tree -= 3;
    EXPECT_TRUE(tree.checkIntegrity());
}