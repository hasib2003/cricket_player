//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_AVLBATTING_H
#define DSA_PROJECT_AVLBATTING_H
#include "bst_Bowling.h"

class avl_Bowling : public bst_Bowling{
public:
    bst_node_Bowling* rightRotation(bst_node_Bowling *);
    bst_node_Bowling* leftRotation(bst_node_Bowling *);
    bst_node_Bowling* leftRightRotation(bst_node_Bowling *);
    bst_node_Bowling* rightLeftRotation(bst_node_Bowling *);

    bst_node_Bowling * checkAVL(bst_node_Bowling *);

    Bowling * InsertWithoutDuplication(Bowling);
};


#endif //DSA_PROJECT_AVLBATTING_H
