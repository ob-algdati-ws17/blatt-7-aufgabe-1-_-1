//
// Created by janne on 06.12.2017.
//

#include "AVLTree.h"
#include <stdio.h>
#include <iostream>

AVLTree &operator+=(AVLTree &, int value) {

}

AVLTree &operator-=(AVLTree &, int value) {

}

bool AVLTree::isEmpty() const {
    return root == nullptr;
}
