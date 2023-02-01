//
// Created by Ahmad on 12/28/2022.
//

#include "avl_Bowling.h"
#include <iostream>
bst_node_Bowling * avl_Bowling ::checkAVL(bst_node_Bowling *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_Bowling::height(root->leftChild) - bst_Bowling::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_Bowling * temp = root->leftChild;

            int balanceVector2 = bst_Bowling::height(temp->leftChild) - bst_Bowling::height(temp->rightChild);


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
            bst_node_Bowling * temp = root->rightChild;

            int balanceVector2 = bst_Bowling::height(temp->leftChild) - bst_Bowling::height(temp->rightChild);

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



bst_node_Bowling* avl_Bowling::rightRotation(bst_node_Bowling* parent)
{
//    parent === x

    bst_node_Bowling * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_Bowling* avl_Bowling::leftRotation(bst_node_Bowling * parent)
{
    bst_node_Bowling * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_Bowling* avl_Bowling::leftRightRotation(bst_node_Bowling * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_Bowling* avl_Bowling::rightLeftRotation(bst_node_Bowling * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}


Bowling* avl_Bowling ::InsertWithoutDuplication(Bowling p) {

    Bowling * interm =  bst_Bowling::InsertWithoutDuplication(p);
    checkAVL(root);

    return interm;
}