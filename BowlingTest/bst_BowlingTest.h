//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_BST_BOWLINGTEST_H
#define DSA_PROJECT_BST_BOWLINGTEST_H
#include "bst_node_BowlingTest.h"
#include "BowlingTest.h"

class bst_BowlingTest {
public:

    bst_node_BowlingTest * root;
    bst_node_BowlingTest * loc;
    bst_node_BowlingTest * ploc;

    bst_BowlingTest();

    bool isEmpty();


    BowlingTest *  search(std::string);
    BowlingTest *  InsertWithoutDuplication(BowlingTest);

    void preOrder(bst_node_BowlingTest*);
    void postOrder(bst_node_BowlingTest*);
    void inOrder(bst_node_BowlingTest*);



    int height(bst_node_BowlingTest *);


    void destroy(bst_node_BowlingTest *);
};


#endif //DSA_PROJECT_BST_BOWLINGTEST_H
