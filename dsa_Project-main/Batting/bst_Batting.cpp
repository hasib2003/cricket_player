//
// Created by Ahmad on 12/28/2022.
//
#include "bst_Batting.h"
#include "bst_node_Batting.h"
#include "string.h"
#include "bst_Batting.h"

#include <iostream>
using namespace  std;
bst_Batting ::bst_Batting()  {
    ploc= NULL;
    loc = ploc;
    root = ploc;
}
bool bst_Batting::isEmpty() {

    return this->root == nullptr;

}


void bst_Batting::search(string value)
{
    ploc= nullptr;
    loc = root;
//    std:: string value = p.name;

    while (loc!= nullptr && loc->name != value)
    {
        ploc = loc;
        if(value > loc->name)
        {
            loc = loc->rightChild;
        }
        else
        {
            loc=loc->leftChild;
        }
    }

    if(loc)
    {
        std::cout<<loc->name<<" "<<loc->name;
    }




}


void bst_Batting::InsertWithoutDuplication(Batting p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_Batting * nn = new bst_node_Batting();
            nn->name = value;
            if (ploc) // insertion not at root
            {
                if(value > ploc->name){
                    ploc->rightChild = nn;
                }
                else
                {
                    ploc->leftChild = nn;
                }
            }
            else {


                root = nn;
                nn->leftChild = nullptr;
                nn->rightChild = nullptr;
            }
        }

        else
        {
            std::cout << "value already present" << std::endl;
        }
    }
    else
    {
        bst_node_Batting * nn = new bst_node_Batting();

        root = nn;
        root->name = value;

    }

}


void bst_Batting ::preOrder(bst_node_Batting * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_Batting ::postOrder(bst_node_Batting * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_Batting ::inOrder(bst_node_Batting * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}



int bst_Batting :: height(bst_node_Batting * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_Batting ::destroy(bst_node_Batting * root)
{
    if (root){
        destroy(root->rightChild);
        destroy(root->leftChild);

        std::cout<<root->name<<" ";
        delete root;
    }
    else{
        this->root = nullptr;
    }
}