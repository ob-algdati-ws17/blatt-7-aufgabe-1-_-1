//
// Created by janne on 06.12.2017.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H


class AVLTree {
private:
    struct node {
        const int value;
        node *left;
        node *right;
        short bal;

        node(const int v, short b) : value(v), bal(b), left(nullptr), right(nullptr) {}

        node(const int v, node *l, node *r, short b) : value(v), bal(b), left(l), right(r) {}
    };

    node *root;

    int getHeight(node *node, int height) const;

public:
    AVLTree();

    friend AVLTree &operator+=(AVLTree &, int value);

    friend AVLTree &operator-=(AVLTree &, int value);

    bool isEmpty() const;

    int getHeight() const;
};


#endif //TREE_TREE_H
