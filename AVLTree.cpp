//
// Created by janne on 06.12.2017.
//

#include "AVLTree.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree &operator+=(AVLTree &tree, int value) {
    if (tree.isEmpty()) {
        AVLTree::node *tmp = new AVLTree::node(value, 0);
        tree.root = tmp;
    }
}

AVLTree &operator-=(AVLTree &tree, int value) {

}

bool AVLTree::isEmpty() const {
    return root == nullptr;
}

int AVLTree::getHeight() const {
    return getHeight(root, 0);
}

int AVLTree::getHeight(AVLTree::node *node, int height) const {
    if (node == nullptr) {
        return height;
    }
    return std::max(getHeight(node->left, height + 1), getHeight(node->right, height + 1));
}
