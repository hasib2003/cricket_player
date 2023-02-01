//
// Created by hasib on 12/30/22.
//

#ifndef CRICKET_PLAYER_BST_COUNTRY_H
#define CRICKET_PLAYER_BST_COUNTRY_H



#include "bst_country_node.h"
#include "country.h"


class bst_country {
public:

    bst_country_node * root;
    bst_country_node * loc;
    bst_country_node * ploc;

    bst_country();

    bool isEmpty();


    country *  search(std::string);
    country * InsertWithoutDuplication(country);

    void preOrder(bst_country_node*);
    void postOrder(bst_country_node*);
    void inOrder(bst_country_node*);



    int height(bst_country_node *);


    void destroy(bst_country_node *);



}
;






#endif //CRICKET_PLAYER_BST_COUNTRY_H
