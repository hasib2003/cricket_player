//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_AVL_BOWLINGTEST_H
#define DSA_PROJECT_AVL_BOWLINGTEST_H
#include "bst_BowlingTest.h"

class avl_BowlingTest : public bst_BowlingTest{
public:
    bst_node_BowlingTest* rightRotation(bst_node_BowlingTest *);
    bst_node_BowlingTest* leftRotation(bst_node_BowlingTest *);
    bst_node_BowlingTest* leftRightRotation(bst_node_BowlingTest *);
    bst_node_BowlingTest* rightLeftRotation(bst_node_BowlingTest *);

    bst_node_BowlingTest * checkAVL(bst_node_BowlingTest *);

    BowlingTest * InsertWithoutDuplication(BowlingTest);
};


#endif //DSA_PROJECT_AVL_BOWLINGTEST_H
