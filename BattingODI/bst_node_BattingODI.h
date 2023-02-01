//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BST_NODE_BATTINGODI_H
#define DSA_PROJECT_BST_NODE_BATTINGODI_H
#include "BattingODI.h"


class bst_node_BattingODI : public BattingODI{
public:
    bst_node_BattingODI * leftChild;
    bst_node_BattingODI * rightChild;
    bst_node_BattingODI()
    {
        leftChild = nullptr;
        rightChild = nullptr;
    }
};


#endif //DSA_PROJECT_BST_NODE_BATTINGODI_H
