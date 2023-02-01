//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_BST_NODE_FIELDING_H
#define DSA_PROJECT_BST_NODE_FIELDING_H
#include "FieldingProfile.h"

class bst_node_FieldingProfile : public FieldingProfile{
public:
    bst_node_FieldingProfile * leftChild=NULL;
    bst_node_FieldingProfile * rightChild=NULL;
};


#endif //DSA_PROJECT_BST_NODE_FIELDING_H
