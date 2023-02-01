//
// Created by Ahmad on 12/28/2022.
//

#include "avlPlayer.h"

#include <iostream>
bst_node_player * avlPlayer ::checkAVL(bst_node_player *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bstPlayer::height(root->leftChild) - bstPlayer::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_player * temp = root->leftChild;

            int balanceVector2 = bstPlayer::height(temp->leftChild) - bstPlayer::height(temp->rightChild);

            std::cout<<"Vector out of balance at ->"<<root->name<<std::endl;

            if(balanceVector2 == -1)
            {
                return(leftRightRotation(root));
            }
            else {

                return(rightRotation(root));

            }

        }
        else if (balanceVector == -2)
        {
            bst_node_player * temp = root->rightChild;

            int balanceVector2 = bstPlayer::height(temp->leftChild) - bstPlayer::height(temp->rightChild);
            std::cout<<"Vector out of balance at ->"<<root->name<<std::endl;

            if(balanceVector2 == 1)
            {
                std::cout<<"double rotating now right"<<std::endl;

                return(rightRotation(temp));
            }

            return(leftRotation(root));

        }


        return root;
    }
    return nullptr;

}



bst_node_player* avlPlayer::rightRotation(bst_node_player* parent)
{
//    parent === x

    bst_node_player * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_player* avlPlayer::leftRotation(bst_node_player * parent)
{
    bst_node_player * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_player* avlPlayer::leftRightRotation(bst_node_player * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_player* avlPlayer::rightLeftRotation(bst_node_player * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

void avlPlayer ::InsertWithoutDuplication(Player p) {

    bstPlayer::InsertWithoutDuplication(p);
    checkAVL(root);
}

