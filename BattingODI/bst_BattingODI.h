//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BST_BATTINGODI_H
#define DSA_PROJECT_BST_BATTINGODI_H
#include "bst_node_BattingODI.h"
#include "BattingODI.h"
#include <iostream>
using namespace std;
class bst_BattingODI {
public:
    bst_node_BattingODI * root;
    bst_node_BattingODI * loc;
    bst_node_BattingODI * ploc;

    bst_BattingODI();

    bool isEmpty();


    BattingODI * search(std::string);
    BattingODI * InsertWithoutDuplication(BattingODI);

    void preOrder(bst_node_BattingODI*);
    void postOrder(bst_node_BattingODI*);
    void inOrder(bst_node_BattingODI*);



    int height(bst_node_BattingODI *);


    void destroy(bst_node_BattingODI *);
};


#endif //DSA_PROJECT_BST_BATTINGODI_H
