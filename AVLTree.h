//
// Created by janne on 06.12.2017.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H


class AVLTree {
private:
    struct node {
        const int value;
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

    void upin(node *node);

    bool checkIntegrity(node *node) const;

public:
    AVLTree();

    friend AVLTree &operator+=(AVLTree &, int value);

    friend AVLTree &operator-=(AVLTree &, int value);

    bool isEmpty() const;

    int getHeight() const;

    bool checkIntegrity() const;
};


#endif //TREE_TREE_H
