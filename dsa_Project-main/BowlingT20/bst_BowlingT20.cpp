//
// Created by Ahmad on 12/28/2022.
//

#include "bst_BowlingT20.h"

#include "BowlingT20.h"
#include <iostream>
using namespace  std;

bst_BowlingT20 ::bst_BowlingT20() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst_BowlingT20::isEmpty() {

    return this->root == nullptr;

}


BowlingT20 * bst_BowlingT20::search(string value)
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
        std::cout<<loc->name<<" "<<std::endl;
    }
    return loc;





}


BowlingT20 * bst_BowlingT20::InsertWithoutDuplication(BowlingT20 p )
{

    std::string value = p.name;
    std::cout<<"name recieved is "<<value<<std::endl;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_BowlingT20 * nn = new bst_node_BowlingT20();
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
            return  loc;
        }
    }
    else
    {
        bst_node_BowlingT20 * nn = new bst_node_BowlingT20();

        root = nn;
        root->name = value;
        return nn;
    }

}


void bst_BowlingT20 ::preOrder(bst_node_BowlingT20 * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_BowlingT20 ::postOrder(bst_node_BowlingT20 * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_BowlingT20 ::inOrder(bst_node_BowlingT20 * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}

int bst_BowlingT20 :: height(bst_node_BowlingT20 * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}
//


void bst_BowlingT20 ::destroy(bst_node_BowlingT20 * root)
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

