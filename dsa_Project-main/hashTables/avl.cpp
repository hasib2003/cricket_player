//
// Created by hasib on 12/25/22.
//

#include "avl.h"
#include <iostream>
bst_node * avl ::checkAVL(bst_node *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst::height(root->leftChild) - bst::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node * temp = root->leftChild;

            int balanceVector2 = bst::height(temp->leftChild) - bst::height(temp->rightChild);

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
            bst_node * temp = root->rightChild;

            int balanceVector2 = bst::height(temp->leftChild) - bst::height(temp->rightChild);
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



bst_node* avl::rightRotation(bst_node* parent)
{
//    parent === x

bst_node * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node* avl::leftRotation(bst_node * parent)
{
    bst_node * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node* avl::leftRightRotation(bst_node * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node* avl::rightLeftRotation(bst_node * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

void avl ::InsertWithoutDuplication(player p) {

    bst::InsertWithoutDuplication(p);
    checkAVL(root);
}

