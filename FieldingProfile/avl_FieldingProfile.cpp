//
// Created by Ahmad on 12/28/2022.
//

#include "avl_FieldingProfile.h"
#include <iostream>
bst_node_FieldingProfile * avl_FieldingProfile ::checkAVL(bst_node_FieldingProfile *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_FieldingProfile::height(root->leftChild) - bst_FieldingProfile::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_FieldingProfile * temp = root->leftChild;

            int balanceVector2 = bst_FieldingProfile::height(temp->leftChild) - bst_FieldingProfile::height(temp->rightChild);


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
            bst_node_FieldingProfile * temp = root->rightChild;

            int balanceVector2 = bst_FieldingProfile::height(temp->leftChild) - bst_FieldingProfile::height(temp->rightChild);

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



bst_node_FieldingProfile* avl_FieldingProfile::rightRotation(bst_node_FieldingProfile* parent)
{
//    parent === x

    bst_node_FieldingProfile * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_FieldingProfile* avl_FieldingProfile::leftRotation(bst_node_FieldingProfile * parent)
{
    bst_node_FieldingProfile * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_FieldingProfile* avl_FieldingProfile::leftRightRotation(bst_node_FieldingProfile * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_FieldingProfile* avl_FieldingProfile::rightLeftRotation(bst_node_FieldingProfile * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

FieldingProfile * avl_FieldingProfile ::InsertWithoutDuplication(FieldingProfile p) {

    FieldingProfile * interm = nullptr;
    interm = bst_FieldingProfile::InsertWithoutDuplication(p);
    checkAVL(root);
    return  interm;
}