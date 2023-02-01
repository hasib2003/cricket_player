//
// Created by Ahmad on 12/28/2022.
//

#include "bst_BattingT20.h"
#include "bst_node_BattingT20.h"


#include <iostream>
using namespace  std;
#include "string.h"
bst_BattingT20 ::bst_BattingT20() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}
bool bst_BattingT20::isEmpty() {

    return this->root == nullptr;

}


void bst_BattingT20::search(string value)
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


void bst_BattingT20::InsertWithoutDuplication(BattingT20 p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_BattingT20 * nn = new bst_node_BattingT20();
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
        bst_node_BattingT20 * nn = new bst_node_BattingT20();

        root = nn;
        root->name = value;

    }

}


void bst_BattingT20 ::preOrder(bst_node_BattingT20 * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_BattingT20 ::postOrder(bst_node_BattingT20 * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_BattingT20 ::inOrder(bst_node_BattingT20 * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}



int bst_BattingT20 :: height(bst_node_BattingT20 * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_BattingT20 ::destroy(bst_node_BattingT20 * root)
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