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
        std::cout<<loc->name<<" "<<std::endl;
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
            nn->BowlT20 = p.BowlT20;


//            nn->Country =p.Country;
//            nn->start =p.start;
//            nn->end = p.end;


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
        bst_node_Bowling * nn = new bst_node_Bowling();

        root = nn;
        root->name = value;
        root->BowlT20 = p.BowlT20;

//        nn->Country =p.Country;
//        nn->start =p.start;
//        nn->end = p.end;
        return nn;

    }
    std::cout<<"inserted into avl with root "<<root->name<<std::endl;
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

        std::cout<<root->name<<" ";
        delete root;
    }
    else{
        this->root = nullptr;
    }
}
