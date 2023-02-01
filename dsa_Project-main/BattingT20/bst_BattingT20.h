//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BST_BATTINGT20_H
#define DSA_PROJECT_BST_BATTINGT20_H
#include "bst_node_BattingT20.h"
#include "BattingT20.h"

class bst_BattingT20 {
public:

    bst_node_BattingT20 * root;
    bst_node_BattingT20 * loc;
    bst_node_BattingT20 * ploc;

    bst_BattingT20();

    bool isEmpty();


    void search(std::string);
    void InsertWithoutDuplication(BattingT20);

    void preOrder(bst_node_BattingT20*);
    void postOrder(bst_node_BattingT20*);
    void inOrder(bst_node_BattingT20*);



    int height(bst_node_BattingT20 *);


    void destroy(bst_node_BattingT20 *);
};


#endif //DSA_PROJECT_BST_BATTINGT20_H
