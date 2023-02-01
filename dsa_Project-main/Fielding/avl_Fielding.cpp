//
// Created by Ahmad on 12/31/2022.
//

#include "avl_Fielding.h"
bst_node_Fielding * avl_Fielding ::checkAVL(bst_node_Fielding *root) {

    if (root)
    {
        root->leftChild = checkAVL(root->leftChild);
        root->rightChild = checkAVL(root->rightChild);


        int balanceVector = bst_Fielding::height(root->leftChild) - bst_Fielding::height(root->rightChild);

        if(balanceVector == 2 )
        {

            bst_node_Fielding * temp = root->leftChild;

            int balanceVector2 = bst_Fielding::height(temp->leftChild) - bst_Fielding::height(temp->rightChild);

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
            bst_node_Fielding * temp = root->rightChild;

            int balanceVector2 = bst_Fielding::height(temp->leftChild) - bst_Fielding::height(temp->rightChild);
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



bst_node_Fielding* avl_Fielding::rightRotation(bst_node_Fielding* parent)
{
//    parent === x

    bst_node_Fielding * leftChild = parent->leftChild;

    if (parent == root)
    {

        root = parent->leftChild;
    }



    parent->leftChild = leftChild->rightChild;

    leftChild->rightChild= parent;

    return leftChild;

}
bst_node_Fielding* avl_Fielding::leftRotation(bst_node_Fielding * parent)
{
    bst_node_Fielding * rightChild= parent->rightChild;

    if (parent == root)
    {
        root = parent->rightChild;
    }



    parent->rightChild = rightChild->leftChild;

    rightChild->leftChild= parent;

    return rightChild;

}


bst_node_Fielding* avl_Fielding::leftRightRotation(bst_node_Fielding * parent)
{

    parent->leftChild = leftRotation(parent->leftChild);

    return(rightRotation(parent));

}
bst_node_Fielding* avl_Fielding::rightLeftRotation(bst_node_Fielding * parent)
{

    parent->rightChild = rightRotation(parent->rightChild);

    return(leftRotation(parent));

}

void avl_Fielding ::InsertWithoutDuplication(Fielding p) {

    bst_Fielding::InsertWithoutDuplication(p);
    checkAVL(root);
}