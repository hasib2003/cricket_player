//
// Created by hasib on 12/25/22.
//

#ifndef LAB10_AVL_H
#define LAB10_AVL_H
#include "bst.h"
//#include "bst_node.h"
class avl: public bst{

public:
     bst_node* rightRotation(bst_node *);
    bst_node* leftRotation(bst_node *);
    bst_node* leftRightRotation(bst_node *);
    bst_node* rightLeftRotation(bst_node *);

     bst_node * checkAVL(bst_node *);

     player * InsertWithoutDuplication(player);

     // should return the node that is imbalanced
//     int deleteNode(player);








};


#endif //LAB10_AVL_H
