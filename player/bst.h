//
// Created by hasib on 11/22/22.
//

#ifndef LAB10_BST_H
#define LAB10_BST_H

#include "bst_node.h"
#include "player.h"
class bst {
public:

bst_node * root;
bst_node * loc;
bst_node * ploc;

bst();

bool isEmpty();


player * search(std::string);
player * InsertWithoutDuplication(player);

void preOrder(bst_node*);
void postOrder(bst_node*);
void inOrder(bst_node*);


int height(bst_node *);

void destroy(bst_node *);


}
;

#endif //LAB10_BST_H
