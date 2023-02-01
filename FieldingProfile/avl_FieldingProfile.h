//
// Created by Ahmad on 12/31/2022.
//
#pragma once
#define DSA_PROJECT_AVL_FIELDING_H
#include "bst_FieldingProfile.h"

class avl_FieldingProfile : public bst_FieldingProfile{
public:
    bst_node_FieldingProfile* rightRotation(bst_node_FieldingProfile *);
    bst_node_FieldingProfile* leftRotation(bst_node_FieldingProfile *);
    bst_node_FieldingProfile* leftRightRotation(bst_node_FieldingProfile *);
    bst_node_FieldingProfile* rightLeftRotation(bst_node_FieldingProfile *);

    bst_node_FieldingProfile * checkAVL(bst_node_FieldingProfile *);

    FieldingProfile * InsertWithoutDuplication(FieldingProfile);
};


