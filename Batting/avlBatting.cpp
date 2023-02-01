//
// Created by Ahmad on 12/28/2022.
//

#include "avlBatting.h"
#include <iostream>
bst_node_Batting * avlBatting ::checkAVL(bst_node_Batting *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_Batting::height(root->leftChild) - bst_Batting::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_Batting * temp = root->leftChild;

            int balanceVector2 = bst_Batting::height(temp->leftChild) - bst_Batting::height(temp->rightChild);


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
            bst_node_Batting * temp = root->rightChild;

            int balanceVector2 = bst_Batting::height(temp->leftChild) - bst_Batting::height(temp->rightChild);

            if(balanceVector2 == 1)
            {

                return(rightRotation(temp));
            }

            return(leftRotation(root));

        }


        return root;
    }
    return nullptr;

}



bst_node_Batting* avlBatting::rightRotation(bst_node_Batting* parent)
{
//    parent === x

    bst_node_Batting * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_Batting* avlBatting::leftRotation(bst_node_Batting * parent)
{
    bst_node_Batting * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_Batting* avlBatting::leftRightRotation(bst_node_Batting * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_Batting* avlBatting::rightLeftRotation(bst_node_Batting * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}


Batting * avlBatting ::InsertWithoutDuplication(Batting p) {

    Batting * interm =  bst_Batting::InsertWithoutDuplication(p);
    checkAVL(root);

    return interm;
}