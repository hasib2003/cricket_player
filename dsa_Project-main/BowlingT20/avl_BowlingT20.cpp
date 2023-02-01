//
// Created by Ahmad on 12/28/2022.
//

#include "avl_BowlingT20.h"
#include <iostream>
bst_node_BowlingT20 * avl_BowlingT20 ::checkAVL(bst_node_BowlingT20 *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_BowlingT20::height(root->leftChild) - bst_BowlingT20::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_BowlingT20 * temp = root->leftChild;

            int balanceVector2 = bst_BowlingT20::height(temp->leftChild) - bst_BowlingT20::height(temp->rightChild);

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
            bst_node_BowlingT20 * temp = root->rightChild;

            int balanceVector2 = bst_BowlingT20::height(temp->leftChild) - bst_BowlingT20::height(temp->rightChild);
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



bst_node_BowlingT20* avl_BowlingT20::rightRotation(bst_node_BowlingT20* parent)
{
//    parent === x

    bst_node_BowlingT20 * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_BowlingT20* avl_BowlingT20::leftRotation(bst_node_BowlingT20 * parent)
{
    bst_node_BowlingT20 * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_BowlingT20* avl_BowlingT20::leftRightRotation(bst_node_BowlingT20 * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_BowlingT20* avl_BowlingT20::rightLeftRotation(bst_node_BowlingT20 * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

BowlingT20 * avl_BowlingT20 ::InsertWithoutDuplication(BowlingT20 p) {

    BowlingT20 * interm = nullptr;
    interm = bst_BowlingT20::InsertWithoutDuplication(p);
    checkAVL(root);
    return  interm;
}