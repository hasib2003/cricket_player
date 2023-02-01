//
// Created by hasib on 11/22/22.
//

#ifndef LAB10_BST_NODE_H
#define LAB10_BST_NODE_H

#include "player.h"

class bst_node : public player {
public:

    bst_node * leftChild;
    bst_node * rightChild;
    bst_node();
};




#endif //LAB10_BST_NODE_H
