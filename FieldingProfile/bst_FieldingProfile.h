//
// Created by Ahmad on 12/31/2022.
//

#pragma once
#include "bst_node_FieldingProfile.h"
#include "FieldingProfile.h"

class bst_FieldingProfile {
public:

    bst_node_FieldingProfile * root;
    bst_node_FieldingProfile * loc;
    bst_node_FieldingProfile * ploc;

    bst_FieldingProfile();

    bool isEmpty();


    FieldingProfile *  search(std::string);
    FieldingProfile *  InsertWithoutDuplication(FieldingProfile);

    void preOrder(bst_node_FieldingProfile*);
    void postOrder(bst_node_FieldingProfile*);
    void inOrder(bst_node_FieldingProfile*);



    int height(bst_node_FieldingProfile *);


    void destroy(bst_node_FieldingProfile *);
};


