//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_AVL_BOWLINGT20_H
#define DSA_PROJECT_AVL_BOWLINGT20_H
#include "bst_BowlingT20.h"

class avl_BowlingT20 : public bst_BowlingT20{
public:
    bst_node_BowlingT20* rightRotation(bst_node_BowlingT20 *);
    bst_node_BowlingT20* leftRotation(bst_node_BowlingT20 *);
    bst_node_BowlingT20* leftRightRotation(bst_node_BowlingT20 *);
    bst_node_BowlingT20* rightLeftRotation(bst_node_BowlingT20 *);

    bst_node_BowlingT20 * checkAVL(bst_node_BowlingT20 *);

    BowlingT20 * InsertWithoutDuplication(BowlingT20);
};


#endif //DSA_PROJECT_AVL_BOWLINGT20_H
