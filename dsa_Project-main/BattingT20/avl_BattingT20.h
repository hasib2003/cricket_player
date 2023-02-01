//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_AVL_BATTINGT20_H
#define DSA_PROJECT_AVL_BATTINGT20_H
#include "bst_BattingT20.h"

class avl_BattingT20 : public bst_BattingT20{
public:
    bst_node_BattingT20* rightRotation(bst_node_BattingT20 *);
    bst_node_BattingT20* leftRotation(bst_node_BattingT20 *);
    bst_node_BattingT20* leftRightRotation(bst_node_BattingT20 *);
    bst_node_BattingT20* rightLeftRotation(bst_node_BattingT20 *);

    bst_node_BattingT20 * checkAVL(bst_node_BattingT20 *);

    void InsertWithoutDuplication(BattingT20);

};


#endif //DSA_PROJECT_AVL_BATTINGT20_H
