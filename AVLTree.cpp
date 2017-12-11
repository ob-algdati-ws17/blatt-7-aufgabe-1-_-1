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

    if (node->bal != 0) {
        upin(node);
    }
}

void AVLTree::upin(AVLTree::node *node) {
    // root
    if (node->parent == nullptr)return;
    if (node->parent->left != nullptr && node->parent->left->value == node->value) {
        if (node->parent->bal > 0) {
            // case 1.1
            node->parent->bal = 0;
        } else if (node->parent->bal == 0) {
            // case 1.2
            node->parent->bal = -1;
            upin(node->parent);
        } else {
            // case 1.3
            if (node->bal < 0) {
                // case 1.3.1 rotation right
                node->parent->left = node->right;
                if (node->parent->left != nullptr) {
                    node->parent->left->parent = node->parent;
                }

                node->right = node->parent;
                node->parent = node->parent->parent;
                node->right->parent = node;
                if (node->parent != nullptr) {
                    if (node->parent->value < node->value) {
                        node->parent->right = node;
                    } else {
                        node->parent->left = node;
                    }
                } else {
                    root = node;
                }
                node->bal = 0;
                node->right->bal = 0;
            } else {
                // case 1.3.2 double rotation right
            }
        }
    } else {
        if (node->parent->bal < 0) {
            // case 1.1
            node->parent->bal = 0;
        } else if (node->parent->bal == 0) {
            // case 1.2
            node->parent->bal = +1;
            upin(node->parent);
        } else {
            // case 1.3
            if (node->bal > 0) {
                // case 1.3.1 rotation left
                node->parent->right = node->left;
                if (node->parent->right != nullptr) {
                    node->parent->right->parent = node->parent;
                }

                node->left = node->parent;
                node->parent = node->parent->parent;
                node->left->parent = node;
                if (node->parent != nullptr) {
                    if (node->parent->value < node->value) {
                        node->parent->right = node;
                    } else {
                        node->parent->left = node;
                    }
                } else {
                    root = node;
                }
                node->bal = 0;
                node->left->bal = 0;
            } else {
                // case 1.3.2 double rotation right
            }
        }
    }
}
