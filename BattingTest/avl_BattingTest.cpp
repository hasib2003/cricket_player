

#include "avl_BattingTest.h"
#include <iostream>
bst_node_BattingTest * avl_BattingTest ::checkAVL(bst_node_BattingTest *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_BattingTest::height(root->leftChild) - bst_BattingTest::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_BattingTest * temp = root->leftChild;

            int balanceVector2 = bst_BattingTest::height(temp->leftChild) - bst_BattingTest::height(temp->rightChild);


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
            bst_node_BattingTest * temp = root->rightChild;

            int balanceVector2 = bst_BattingTest::height(temp->leftChild) - bst_BattingTest::height(temp->rightChild);

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



bst_node_BattingTest* avl_BattingTest::rightRotation(bst_node_BattingTest* parent)
{
//    parent === x

    bst_node_BattingTest * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_BattingTest* avl_BattingTest::leftRotation(bst_node_BattingTest * parent)
{
    bst_node_BattingTest * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_BattingTest* avl_BattingTest::leftRightRotation(bst_node_BattingTest * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_BattingTest* avl_BattingTest::rightLeftRotation(bst_node_BattingTest * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

BattingTest * avl_BattingTest ::InsertWithoutDuplication(BattingTest p) {

    BattingTest * interm = nullptr;
    interm = bst_BattingTest::InsertWithoutDuplication(p);
    checkAVL(root);
    return  interm;
}