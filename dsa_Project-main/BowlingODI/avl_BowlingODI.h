//
// Created by Ahmad on 12/30/2022.
//

#ifndef DSA_PROJECT_AVL_BOWLINGODI_H
#define DSA_PROJECT_AVL_BOWLINGODI_H
#include "bst_BowlingODI.h"

class avl_BowlingODI :public bst_BowlingODI{
public:
    bst_node_BowlingODI* rightRotation(bst_node_BowlingODI *);
    bst_node_BowlingODI* leftRotation(bst_node_BowlingODI *);
    bst_node_BowlingODI* leftRightRotation(bst_node_BowlingODI *);
    bst_node_BowlingODI* rightLeftRotation(bst_node_BowlingODI *);

    bst_node_BowlingODI * checkAVL(bst_node_BowlingODI *);

    BowlingODI * InsertWithoutDuplication(BowlingODI);
};


#endif //DSA_PROJECT_AVL_BOWLINGODI_H
