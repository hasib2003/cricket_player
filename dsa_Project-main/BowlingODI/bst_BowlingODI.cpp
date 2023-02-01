//
// Created by Ahmad on 12/30/2022.
//


#include "bst_BowlingODI.h"
#include "bst_node_BowlingODI.h"


#include <iostream>
using namespace  std;
#include "string.h"
bst_BowlingODI ::bst_BowlingODI() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}
bool bst_BowlingODI::isEmpty() {

    return this->root == nullptr;

}


BowlingODI* bst_BowlingODI::search(string value)
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
        std::cout<<loc->name<<" "<<loc->span;
    }
    return loc;



}


BowlingODI* bst_BowlingODI::InsertWithoutDuplication(BowlingODI p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_BowlingODI * nn = new bst_node_BowlingODI();
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
            return nn;
        }

        else
        {
            std::cout << "value already present" << std::endl;
            return loc;
        }
    }
    else
    {
        bst_node_BowlingODI * nn = new bst_node_BowlingODI();

        root = nn;
        root->name = value;

    }

}


void bst_BowlingODI ::preOrder(bst_node_BowlingODI * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_BowlingODI ::postOrder(bst_node_BowlingODI * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_BowlingODI ::inOrder(bst_node_BowlingODI * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}



int bst_BowlingODI :: height(bst_node_BowlingODI * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_BowlingODI ::destroy(bst_node_BowlingODI * root)
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