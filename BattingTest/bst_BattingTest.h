//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BST_BATTINGTEST_H
#define DSA_PROJECT_BST_BATTINGTEST_H
#include "bst_node_BattingTest.h"
#include "BattingTest.h"

class bst_BattingTest {
public:

    bst_node_BattingTest * root;
    bst_node_BattingTest * loc;
    bst_node_BattingTest * ploc;

    bst_BattingTest();

    bool isEmpty();


    BattingTest *  search(std::string);
    BattingTest *  InsertWithoutDuplication(BattingTest);

    void preOrder(bst_node_BattingTest*);
    void postOrder(bst_node_BattingTest*);
    void inOrder(bst_node_BattingTest*);



    int height(bst_node_BattingTest *);


    void destroy(bst_node_BattingTest *);
};


#endif //DSA_PROJECT_BST_BATTINGTEST_H
