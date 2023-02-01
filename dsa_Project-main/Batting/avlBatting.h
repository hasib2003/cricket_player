//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_AVLBATTING_H
#define DSA_PROJECT_AVLBATTING_H
#include "bst_Batting.h"

class avlBatting : public bst_Batting{
public:
    bst_node_Batting* rightRotation(bst_node_Batting *);
    bst_node_Batting* leftRotation(bst_node_Batting *);
    bst_node_Batting* leftRightRotation(bst_node_Batting *);
    bst_node_Batting* rightLeftRotation(bst_node_Batting *);

    bst_node_Batting * checkAVL(bst_node_Batting *);

    void InsertWithoutDuplication(Batting);
};


#endif //DSA_PROJECT_AVLBATTING_H
