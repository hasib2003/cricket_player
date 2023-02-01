//
// Created by Ahmad on 12/28/2022.
//

#pragma once
#include "Bowling.h"

class bst_node_Bowling : public Bowling{
public:
    bst_node_Bowling * leftChild;
    bst_node_Bowling * rightChild;

    bst_node_Bowling()
    {
        leftChild = nullptr;
        rightChild = nullptr;
    }

};


