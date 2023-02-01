//
// Created by Ahmad on 12/28/2022.
//

#include "avl_BattingT20.h"
#include <iostream>
bst_node_BattingT20 * avl_BattingT20 ::checkAVL(bst_node_BattingT20 *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_BattingT20::height(root->leftChild) - bst_BattingT20::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_BattingT20 * temp = root->leftChild;

            int balanceVector2 = bst_BattingT20::height(temp->leftChild) - bst_BattingT20::height(temp->rightChild);


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
            bst_node_BattingT20 * temp = root->rightChild;

            int balanceVector2 = bst_BattingT20::height(temp->leftChild) - bst_BattingT20::height(temp->rightChild);

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



bst_node_BattingT20* avl_BattingT20::rightRotation(bst_node_BattingT20* parent)
{
//    parent === x

    bst_node_BattingT20 * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_BattingT20* avl_BattingT20::leftRotation(bst_node_BattingT20 * parent)
{
    bst_node_BattingT20 * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_BattingT20* avl_BattingT20::leftRightRotation(bst_node_BattingT20 * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_BattingT20* avl_BattingT20::rightLeftRotation(bst_node_BattingT20 * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

BattingT20 * avl_BattingT20 ::InsertWithoutDuplication(BattingT20 p) {

    BattingT20 * interm = nullptr;
    interm = bst_BattingT20::InsertWithoutDuplication(p);
    checkAVL(root);

    return  interm;
}