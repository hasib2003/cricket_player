//
// Created by hasib on 12/30/22.
//

#ifndef CRICKET_PLAYER_BST_COUNTRY_NODE_H
#define CRICKET_PLAYER_BST_COUNTRY_NODE_H

#include "country.h"
class bst_country_node: public country {
public:
    bst_country_node * leftChild;
    bst_country_node * rightChild;
    bst_country_node();

};


#endif //CRICKET_PLAYER_BST_COUNTRY_NODE_H
