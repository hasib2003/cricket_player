//
// Created by Ahmad on 12/28/2022.
//

#include "avl_BowlingTest.h"
#include <iostream>
bst_node_BowlingTest * avl_BowlingTest ::checkAVL(bst_node_BowlingTest *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_BowlingTest::height(root->leftChild) - bst_BowlingTest::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_BowlingTest * temp = root->leftChild;

            int balanceVector2 = bst_BowlingTest::height(temp->leftChild) - bst_BowlingTest::height(temp->rightChild);

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
            bst_node_BowlingTest * temp = root->rightChild;

            int balanceVector2 = bst_BowlingTest::height(temp->leftChild) - bst_BowlingTest::height(temp->rightChild);
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



bst_node_BowlingTest* avl_BowlingTest::rightRotation(bst_node_BowlingTest* parent)
{
//    parent === x

    bst_node_BowlingTest * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_BowlingTest* avl_BowlingTest::leftRotation(bst_node_BowlingTest * parent)
{
    bst_node_BowlingTest * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_BowlingTest* avl_BowlingTest::leftRightRotation(bst_node_BowlingTest * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_BowlingTest* avl_BowlingTest::rightLeftRotation(bst_node_BowlingTest * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

BowlingTest * avl_BowlingTest ::InsertWithoutDuplication(BowlingTest p) {

    BowlingTest * interm = nullptr;
    interm = bst_BowlingTest::InsertWithoutDuplication(p);
    checkAVL(root);
    return  interm;
}