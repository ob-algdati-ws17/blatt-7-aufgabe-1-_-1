//
// Created by janne on 06.12.2017.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <string>


class AVLTree {
private:
    struct node {
        int value;
        node *parent;
        node *left;
        node *right;
        short bal;

        node(const int v, node *p) : value(v), bal(0), left(nullptr), right(nullptr), parent(p) {}

        node(const int v, node *l, node *r, node *p) : value(v), bal(0), left(l), right(r), parent(p) {}
    };

    node *root;

    int getHeight(node *node, int height) const;

    void insert(node *node, int value);

    void remove(node *node, int value);

    void upin(node *node);

    void upout(node *node);

    bool checkIntegrity(node *node) const;

    short getBalanceAt(node *node, int value);

    int getHeightAt(AVLTree::node *node, int value, int height);

    void changeParentPointer(node *node, AVLTree::node *newChild);

public:

    AVLTree();

    friend AVLTree &operator+=(AVLTree &, int value);

    friend AVLTree &operator-=(AVLTree &, int value);

    bool isEmpty() const;

    int getHeight() const;

    bool checkIntegrity() const;

    void rotateRight(node *node);

    void rotateLeft(node *node);

    short getBalanceAt(int value);

    int getHeightAt(int value);

};


#endif //TREE_TREE_H
