//
// Created by Ahmad on 12/31/2022.
//
#pragma once

#include "bst_Fielding.h"

class avl_Fielding : public bst_Fielding{
public:
    bst_node_Fielding* rightRotation(bst_node_Fielding *);
    bst_node_Fielding* leftRotation(bst_node_Fielding *);
    bst_node_Fielding* leftRightRotation(bst_node_Fielding *);
    bst_node_Fielding* rightLeftRotation(bst_node_Fielding *);

    bst_node_Fielding * checkAVL(bst_node_Fielding *);

    Fielding* InsertWithoutDuplication(Fielding);
};


