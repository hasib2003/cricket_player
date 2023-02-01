//
// Created by Ahmad on 12/28/2022.
//
#include "bst_Bowling.h"
#include "string.h"
#include "Bowling.h"
#include <iostream>
using namespace  std;

bst_Bowling ::bst_Bowling(){
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst_Bowling::isEmpty() {

    return (this->root == nullptr);

}


Bowling * bst_Bowling::search(string value)
{

    ploc= nullptr;
    loc = root;
//    std:: string value = p.name;

    while (loc!= nullptr && loc->name != value)
    {
//        std::cout<<"name = "<<loc->name;
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
    }
    return loc;




}


Bowling * bst_Bowling::InsertWithoutDuplication(Bowling p )
{
    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_Bowling * nn = new bst_node_Bowling();


            //linking with the t20 , odi and test profiles

            nn->name = value;
            if(p.BowlODI)
            {
                nn->BowlODI = p.BowlODI;
            }
            if (p.BowlT20)
            {
                nn->BowlT20 = p.BowlT20;
            }
            if (p.BoTest)
            {
                nn->BoTest = p.BoTest;

            }




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
            return loc;
        }
    }
    else
    {

        bst_node_Bowling * nn = new bst_node_Bowling();


        root = nn;
        root->name = value;

        if(p.BowlODI)
        {
            root->BowlODI = p.BowlODI;
        }
        if (p.BowlT20)
        {

            root->BowlT20 = p.BowlT20;
        }
        if (p.BoTest)
        {
            root->BoTest = p.BoTest;

        }

        return root;

    }
}


void bst_Bowling ::preOrder(bst_node_Bowling * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_Bowling ::postOrder(bst_node_Bowling * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_Bowling ::inOrder(bst_node_Bowling * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}


int bst_Bowling :: height(bst_node_Bowling * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}

void bst_Bowling ::destroy(bst_node_Bowling * root)
{
    if (root){
        destroy(root->rightChild);
        destroy(root->leftChild);

        delete root;
    }
    else{
        this->root = nullptr;
    }
}
