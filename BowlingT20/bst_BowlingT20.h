//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_BST_BOWLINGT20_H
#define DSA_PROJECT_BST_BOWLINGT20_H

#include "bst_node_BowlingT20.h"
#include "BowlingT20.h"

using namespace std;
class bst_BowlingT20 {
public:

    bst_node_BowlingT20 * root;
    bst_node_BowlingT20 * loc;
    bst_node_BowlingT20 * ploc;

    bst_BowlingT20();

    bool isEmpty();


    BowlingT20 *  search(std::string);
    BowlingT20 *  InsertWithoutDuplication(BowlingT20);

    void preOrder(bst_node_BowlingT20*);
    void postOrder(bst_node_BowlingT20*);
    void inOrder(bst_node_BowlingT20*);



    int height(bst_node_BowlingT20 *);


    void destroy(bst_node_BowlingT20 *);
};


#endif //DSA_PROJECT_BST_BOWLINGT20_H
