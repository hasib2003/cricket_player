//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BST_BATTING_H
#define DSA_PROJECT_BST_BATTING_H
#include "bst_node_Bowling.h"
#include "Bowling.h"

class bst_Bowling {
public:
    bst_node_Bowling * root ;
    bst_node_Bowling* loc ;
    bst_node_Bowling * ploc;
    bst_Bowling();

    bool isEmpty();


    Bowling* search(std::string);
    Bowling * InsertWithoutDuplication(Bowling);

    void preOrder(bst_node_Bowling*);
    void postOrder(bst_node_Bowling*);
    void inOrder(bst_node_Bowling*);



    int height(bst_node_Bowling *);


    void destroy(bst_node_Bowling *);

};


#endif //DSA_PROJECT_BST_BATTING_H
