//
// Created by janne on 06.12.2017.
//

#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree &operator+=(AVLTree &tree, int value) {
    if (tree.isEmpty()) {
        tree.root = new AVLTree::node(value, nullptr);
    } else {
        tree.insert(tree.root, value);
    }

    return tree;
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

void AVLTree::insert(AVLTree::node *node, int value) {
    if (value == node->value)return;
    if (value < node->value) {
        if (node->left == nullptr) {
            // bal -1 not possible, because then node->left wouldn't be null
            // bal 0 => -1
            // bal 1 => 0
            node->bal -= 1;
            node->left = new AVLTree::node(value, node);
        } else {
            insert(node->left, value);
            return;
        }
    } else {
        if (node->right == nullptr) {
            // bal 1 not possible, because then node->right wouldn't be null
            // bal 0 => 1
            // bal -1 => 0
            node->bal += 1;
            node->right = new AVLTree::node(value, node);
        } else {
            insert(node->right, value);
            return;
        }
    }
}
