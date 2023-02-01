//
// Created by Ahmad on 12/28/2022.
//
#pragma once

#include "bst_BattingTest.h"

class avl_BattingTest : public bst_BattingTest{
public:
    bst_node_BattingTest* rightRotation(bst_node_BattingTest *);
    bst_node_BattingTest* leftRotation(bst_node_BattingTest *);
    bst_node_BattingTest* leftRightRotation(bst_node_BattingTest *);
    bst_node_BattingTest* rightLeftRotation(bst_node_BattingTest *);

    bst_node_BattingTest * checkAVL(bst_node_BattingTest *);

    BattingTest * InsertWithoutDuplication(BattingTest);

};


