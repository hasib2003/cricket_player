//
// Created by Ahmad on 12/28/2022.
//
#include <iostream>
#include "Batting.h"
using namespace std;
#ifndef DSA_PROJECT_BST_NODE_BATTING_H
#define DSA_PROJECT_BST_NODE_BATTING_H


class bst_node_Batting : public Batting{
public:
    bst_node_Batting * leftChild;
    bst_node_Batting * rightChild;
    bst_node_Batting();
};


#endif //DSA_PROJECT_BST_NODE_BATTING_H
