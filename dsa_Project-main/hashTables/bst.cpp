//
// Created by hasib on 11/22/22.
//
#include <iostream>
using namespace  std;
#include "bst.h"
#include "string.h"
bst ::bst() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst::isEmpty() {

    return this->root == nullptr;

}


void bst::search(string value)
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




}


void bst::InsertWithoutDuplication(player p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node * nn = new bst_node();
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
        bst_node * nn = new bst_node();

        root = nn;
        root->name = value;

    }

}


void bst ::preOrder(bst_node * root)
{


    if (root->leftChild){
    preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
    preOrder(root->rightChild);

}
}
void bst ::postOrder(bst_node * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

}
    std::cout<<root->name<<std::endl;
}
void bst ::inOrder(bst_node * node)
{
    if (node) {
        std::cout << node->name << std::endl;

            inOrder(node->leftChild);

            inOrder(node->rightChild);

    }
}



int bst :: height(bst_node * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst ::destroy(bst_node * root)
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



