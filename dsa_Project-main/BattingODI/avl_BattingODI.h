//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_AVL_BATTINGODI_H
#define DSA_PROJECT_AVL_BATTINGODI_H
#include "bst_BattingODI.h"
#include <iostream>

using namespace std;
class avl_BattingODI :public bst_BattingODI{
public:
    bst_node_BattingODI* rightRotation(bst_node_BattingODI *);
    bst_node_BattingODI* leftRotation(bst_node_BattingODI *);
    bst_node_BattingODI* leftRightRotation(bst_node_BattingODI *);
    bst_node_BattingODI* rightLeftRotation(bst_node_BattingODI *);

    bst_node_BattingODI * checkAVL(bst_node_BattingODI *);

    void InsertWithoutDuplication(BattingODI);
};


#endif //DSA_PROJECT_AVL_BATTINGODI_H
