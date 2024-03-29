//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BST_BATTING_H
#define DSA_PROJECT_BST_BATTING_H
#include "bst_node_Batting.h"
#include "Batting.h"

class bst_Batting {
public:
    bst_node_Batting * root ;
    bst_node_Batting* loc ;
    bst_node_Batting * ploc;
    bst_Batting();

    bool isEmpty();


    Batting* search(std::string);
    Batting * InsertWithoutDuplication(Batting);

    void preOrder(bst_node_Batting*);
    void postOrder(bst_node_Batting*);
    void inOrder(bst_node_Batting*);



    int height(bst_node_Batting *);


    void destroy(bst_node_Batting *);

};


#endif //DSA_PROJECT_BST_BATTING_H
