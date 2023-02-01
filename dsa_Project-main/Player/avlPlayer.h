//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_AVLPLAYER_H
#define DSA_PROJECT_AVLPLAYER_H


#include "bstPlayer.h"
//#include "bst_node.h"
class avlPlayer: public bstPlayer{

public:
    bst_node_player* rightRotation(bst_node_player *);
    bst_node_player* leftRotation(bst_node_player *);
    bst_node_player* leftRightRotation(bst_node_player *);
    bst_node_player* rightLeftRotation(bst_node_player *);

    bst_node_player * checkAVL(bst_node_player *);

    void InsertWithoutDuplication(Player);

};


#endif //DSA_PROJECT_AVLPLAYER_H
