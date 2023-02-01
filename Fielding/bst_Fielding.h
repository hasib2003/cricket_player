//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_BST_FIELDING_H
#define DSA_PROJECT_BST_FIELDING_H
#include "bst_node_Fielding.h"
#include "Fielding.h"

class bst_Fielding {
public:

    bst_node_Fielding * root;
    bst_node_Fielding * loc;
    bst_node_Fielding * ploc;

    bst_Fielding();

    bool isEmpty();


    Fielding* search(std::string);
    Fielding* InsertWithoutDuplication(Fielding);

    void preOrder(bst_node_Fielding*);
    void postOrder(bst_node_Fielding*);
    void inOrder(bst_node_Fielding*);



    int height(bst_node_Fielding *);


    void destroy(bst_node_Fielding *);
};


#endif //DSA_PROJECT_BST_FIELDING_H
