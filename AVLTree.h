//
// Created by janne on 06.12.2017.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H


class AVLTree {
private:
    struct node {
        int value;
        node *left;
        node *right;
        short bal;
    };

    node *root;

    int getHeight(node *node,int height) const;

public:
    AVLTree();

    friend AVLTree &operator+=(AVLTree &, int value);

    friend AVLTree &operator-=(AVLTree &, int value);

    bool isEmpty() const;

    int getHeight() const;
};


#endif //TREE_TREE_H
