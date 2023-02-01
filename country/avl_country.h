//
// Created by hasib on 12/30/22.
//

#ifndef CRICKET_country_AVL_COUNTRY_H
#define CRICKET_country_AVL_COUNTRY_H

#include "bst_country_node.h"
#include "bst_country.h"

    class avl_country: public bst_country{

    public:
        bst_country_node* rightRotation(bst_country_node *);
        bst_country_node* leftRotation(bst_country_node *);
        bst_country_node* leftRightRotation(bst_country_node *);
        bst_country_node* rightLeftRotation(bst_country_node *);

        bst_country_node * checkAVL(bst_country_node *);

        country * InsertWithoutDuplication(country);

        // should return the node that is imbalanced
//     int deleteNode(country);









};


#endif //CRICKET_country_AVL_COUNTRY_H

