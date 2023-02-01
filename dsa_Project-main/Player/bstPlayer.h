//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BSTPLAYER_H
#define DSA_PROJECT_BSTPLAYER_H

#include "bst_node_player.h"
#include "Player.h"

class bstPlayer {
public:

    bst_node_player * root;
    bst_node_player * loc;
    bst_node_player * ploc;

    bstPlayer();

    bool isEmpty();


    void search(std::string);
    void InsertWithoutDuplication(Player);

    void preOrder(bst_node_player*);
    void postOrder(bst_node_player*);
    void inOrder(bst_node_player*);



    int height(bst_node_player *);


    void destroy(bst_node_player *);
};


#endif //DSA_PROJECT_BSTPLAYER_H
