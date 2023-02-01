//
// Created by Ahmad on 12/30/2022.
//

#include "avl_BowlingODI.h"
bst_node_BowlingODI * avl_BowlingODI ::checkAVL(bst_node_BowlingODI *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_BowlingODI::height(root->leftChild) - bst_BowlingODI::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_BowlingODI * temp = root->leftChild;

            int balanceVector2 = bst_BowlingODI::height(temp->leftChild) - bst_BowlingODI::height(temp->rightChild);


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
            bst_node_BowlingODI * temp = root->rightChild;

            int balanceVector2 = bst_BowlingODI::height(temp->leftChild) - bst_BowlingODI::height(temp->rightChild);

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



bst_node_BowlingODI* avl_BowlingODI::rightRotation(bst_node_BowlingODI* parent)
{
//    parent === x

    bst_node_BowlingODI * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_BowlingODI* avl_BowlingODI::leftRotation(bst_node_BowlingODI * parent)
{
    bst_node_BowlingODI * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_BowlingODI* avl_BowlingODI::leftRightRotation(bst_node_BowlingODI * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_BowlingODI* avl_BowlingODI::rightLeftRotation(bst_node_BowlingODI * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

BowlingODI * avl_BowlingODI ::InsertWithoutDuplication(BowlingODI p) {

    BowlingODI * interm =  bst_BowlingODI::InsertWithoutDuplication(p);
    checkAVL(root);

    return interm;
}