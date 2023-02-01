//
// Created by hasib on 12/30/22.
//

#include "avl_country.h"


#include "avl_country.h"
#include <iostream>

bst_country_node * avl_country ::checkAVL(bst_country_node *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_country::height(root->leftChild) - bst_country::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_country_node * temp = root->leftChild;

            int balanceVector2 = bst_country::height(temp->leftChild) - bst_country::height(temp->rightChild);


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
            bst_country_node * temp = root->rightChild;

            int balanceVector2 = bst_country::height(temp->leftChild) - bst_country::height(temp->rightChild);

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



bst_country_node* avl_country::rightRotation(bst_country_node* parent)
{
//    parent === x

    bst_country_node * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_country_node* avl_country::leftRotation(bst_country_node * parent)
{
    bst_country_node * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_country_node* avl_country::leftRightRotation(bst_country_node * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_country_node* avl_country::rightLeftRotation(bst_country_node * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

country * avl_country ::InsertWithoutDuplication(country p) {

    country * interm =  bst_country::InsertWithoutDuplication(p);
    checkAVL(root);

    return interm;
}



