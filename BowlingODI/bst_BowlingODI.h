//
// Created by Ahmad on 12/30/2022.
//

#ifndef DSA_PROJECT_BST_BOWLINGODI_H
#define DSA_PROJECT_BST_BOWLINGODI_H
#include "bst_node_BowlingODI.h"
#include "BowlingODI.h"

using namespace std;

class bst_BowlingODI {
public:

    bst_node_BowlingODI * root;
    bst_node_BowlingODI * loc;
    bst_node_BowlingODI * ploc;

    bst_BowlingODI();

    bool isEmpty();


    BowlingODI* search(std::string);
    BowlingODI* InsertWithoutDuplication(BowlingODI);

    void preOrder(bst_node_BowlingODI*);
    void postOrder(bst_node_BowlingODI*);
    void inOrder(bst_node_BowlingODI*);



    int height(bst_node_BowlingODI *);


    void destroy(bst_node_BowlingODI *);
};


#endif //DSA_PROJECT_BST_BOWLINGODI_H
