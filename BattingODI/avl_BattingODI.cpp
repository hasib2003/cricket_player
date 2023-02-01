//
// Created by Ahmad on 12/28/2022.
//

#include "avl_BattingODI.h"

#include <iostream>
bst_node_BattingODI * avl_BattingODI ::checkAVL(bst_node_BattingODI *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_BattingODI::height(root->leftChild) - bst_BattingODI::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_BattingODI * temp = root->leftChild;

            int balanceVector2 = bst_BattingODI::height(temp->leftChild) - bst_BattingODI::height(temp->rightChild);


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
            bst_node_BattingODI * temp = root->rightChild;

            int balanceVector2 = bst_BattingODI::height(temp->leftChild) - bst_BattingODI::height(temp->rightChild);

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



bst_node_BattingODI* avl_BattingODI::rightRotation(bst_node_BattingODI* parent)
{
//    parent === x

    bst_node_BattingODI * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_BattingODI* avl_BattingODI::leftRotation(bst_node_BattingODI * parent)
{
    bst_node_BattingODI * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_BattingODI* avl_BattingODI::leftRightRotation(bst_node_BattingODI * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_BattingODI* avl_BattingODI::rightLeftRotation(bst_node_BattingODI * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

BattingODI * avl_BattingODI ::InsertWithoutDuplication(BattingODI p) {
    BattingODI * interm = nullptr;

    interm = bst_BattingODI::InsertWithoutDuplication(p);
    checkAVL(root);
    return  interm;
}