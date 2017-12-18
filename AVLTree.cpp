//
// Created by janne on 06.12.2017.
//

#include "AVLTree.h"
#include <iostream>
#include <list>

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
    tree.remove(tree.root, value);
    return tree;
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
                node->bal = 0;
                node->parent->bal = 0;
                rotateRight(node);

            } else {
                // case 1.3.2 double rotation right
                rotateLeft(node->right);
                node = node->parent;
                rotateRight(node);
                node->bal = 0;
                node->left->bal = static_cast<short>(getHeight(node->right, 0) - getHeight(node->left, 0));
                node->right->bal = static_cast<short>(getHeight(node->right, 0) - getHeight(node->left, 0));
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
                node->bal = 0;
                node->parent->bal = 0;
                // case 1.3.1 rotation left
                rotateLeft(node);
            } else {
                // case 1.3.2 double rotation right
                rotateRight(node->left);
                node = node->parent;
                rotateLeft(node);
                node->bal = 0;
                node->left->bal = static_cast<short>(getHeight(node->right, 0) - getHeight(node->left, 0));
                node->right->bal = static_cast<short>(getHeight(node->right, 0) - getHeight(node->left, 0));
            }
        }
    }
}

void AVLTree::rotateLeft(AVLTree::node *node) {
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
}

void AVLTree::rotateRight(AVLTree::node *node) {
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
}

bool AVLTree::checkIntegrity(AVLTree::node *node) const {
    bool tmp = true;
    if (node->left != nullptr) {
        if (node->left->value >= node->value || node->left->parent->value != node->value)return false;
        tmp = tmp && checkIntegrity(node->left) && (node->right != nullptr || node->bal == -1);
    }
    if (node->right != nullptr) {
        if (node->right->value <= node->value || node->right->parent->value != node->value)return false;
        tmp = tmp && checkIntegrity(node->right) && (node->left != nullptr || node->bal == 1);
    }
    if (node->left != nullptr && node->right != nullptr) {
        tmp = tmp && node->bal == getHeight(node->right, 0) - getHeight(node->left, 0);
    }
    return tmp;
}

bool AVLTree::checkIntegrity() const {
    return isEmpty() ? true : checkIntegrity(root);
}

int AVLTree::getHeightAt(AVLTree::node *node, int value, int height) {
    if (node->value == value)
        return height + 1;
    else if (value < node->value) {
        if (node->left == nullptr) return 0;
        return getHeightAt(node->left, value, height + 1);
    } else {
        if (node->right == nullptr) return 0;
        return getHeightAt(node->right, value, height + 1);
    }
}

int AVLTree::getHeightAt(int value) {
    return isEmpty() ? 0 : getHeightAt(root, value, 0);
}

short AVLTree::getBalanceAt(AVLTree::node *node, int value) {
    if (node->value == value)
        return node->bal;
    else if (value < node->value) {
        if (node->left == nullptr) return 0;
        return getBalanceAt(node->left, value);
    } else {
        if (node->right == nullptr) return 0;
        return getBalanceAt(node->right, value);
    }
}

short AVLTree::getBalanceAt(int value) {
    return static_cast<short>(isEmpty() ? 0 : getBalanceAt(root, value));
}

void AVLTree::remove(AVLTree::node *node, int value) {
    if (node == nullptr)
        return;
    if (value < node->value) {
        remove(node->left, value);
    } else if (value > node->value) {
        remove(node->right, value);
    } else {
        bool isRoot = node->parent == nullptr;
        bool isLeftChild = (!isRoot) ? node->value < node->parent->value : false;
        if (node->left == nullptr && node->right == nullptr) {
            // node has no children
            if (isRoot) {
                // node is root
                root = nullptr;
            } else {
                if (node->parent->bal == 0) {
                    // height of rest 1
                    changeParentPointer(node, nullptr);
                } else if ((isLeftChild && node->parent->bal < 0) || (!isLeftChild && node->parent->bal > 0)) {
                    // height of rest 0
                    changeParentPointer(node, nullptr);
                    upout(node->parent);
                } else {
                    // height of rest 2
                    upout(node);
                    changeParentPointer(node, nullptr);
                }

            }
        } else if (node->left == nullptr) {
            // node has only one child
            if (isRoot) {
                root = node->right;
                root->parent = nullptr;
            } else {
                changeParentPointer(node, node->right);
                node->right->parent = node->parent;
                upout(node->parent);
            }
        } else if (node->right == nullptr) {
            // node has only one child
            if (isRoot) {
                root = node->left;
                root->parent = nullptr;
            } else {
                changeParentPointer(node, node->left);
                node->left->parent = node->parent;
                upout(node->parent);
            }
        } else {
            // node has two children
            auto *tmp = node->right;
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }
            int tmpValue = tmp->value;
            remove(tmp, tmpValue);
            node->value = tmpValue;
            return;
        }
        delete node;
    }
}

void AVLTree::changeParentPointer(AVLTree::node *node, AVLTree::node *newChild) {
    if (node->value < node->parent->value) {
        node->parent->bal++;
        node->parent->left = newChild;
    } else {
        node->parent->bal--;
        node->parent->right = newChild;
    }
}

void AVLTree::upout(AVLTree::node *node) {
    // root
    if (node->parent == nullptr)return;
    if (node->parent->left != nullptr && node->parent->left->value == node->value) {
        if (node->parent->bal < 0) {
            // case 1.1
            node->parent->bal = 0;
            upout(node);
        } else if (node->parent->bal == 0) {
            // case 1.2
            node->parent->bal = 1;
            upout(node->parent);
        } else {
            // case 1.3
            auto right = node->parent->right;
            if (right->bal == 0) {
                // case 1.3.1 rotation left
                right->bal = -1;
                rotateLeft(right);
            } else if (right->bal > 0) {
                // case 1.3.2 rotation left
                node->parent->bal = 0;
                right->bal = 0;
                rotateLeft(right);
                upout(right);
            } else {
                // case 1.3.3 double rotation left
                right = right->left;
                rotateRight(right);
                rotateLeft(right);
                right->bal = 0;
                right->left->bal = 0;
                right->right->bal = 0;
                upout(right);
            }
        }
    } else {
        if (node->parent->bal > 0) {
            // case 1.1
            node->parent->bal = 0;
            upout(node->parent);
        } else if (node->parent->bal == 0) {
            // case 1.2
            node->parent->bal = -1;
            upout(node->parent);
        } else {
            // case 1.3
            auto left = node->parent->left;
            if (left->bal == 0) {
                // case 1.3.1 rotation left
                left->bal = 1;
                rotateRight(left);
            } else if (left->bal < 0) {
                // case 1.3.2 rotation left
                node->parent->bal = 0;
                left->bal = 0;
                rotateRight(left);
                upout(left);
            } else {
                // case 1.3.3 double rotation left
                left = left->right;
                rotateLeft(left);
                rotateRight(left);
                left->bal = 0;
                left->left->bal = 0;
                left->right->bal = 0;
                upout(left);
            }
        }
    }
}

