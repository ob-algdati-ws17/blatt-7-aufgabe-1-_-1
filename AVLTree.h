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

public:
    friend AVLTree &operator+=(AVLTree &, int value);

    friend AVLTree &operator-=(AVLTree &, int value);

    bool isEmpty() const;
};


#endif //TREE_TREE_H
