//
// Created by Ahmad on 12/28/2022.
//
#include "bst_Batting.h"
#include "string.h"
#include "Batting.h"
#include <iostream>
using namespace  std;

bst_Batting ::bst_Batting(){
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst_Batting::isEmpty() {

    return (this->root == nullptr);

}


Batting * bst_Batting::search(string value)
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


Batting * bst_Batting::InsertWithoutDuplication(Batting p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_Batting * nn = new bst_node_Batting();


            //linking with the t20 , odi and test profiles

            nn->name = value;
            if(p.BaT20)
            {
                nn->BaT20 = p.BaT20;
            }
            if (p.BatTest)
            {
                nn->BatTest = p.BatTest;
            }
            if (p.BatODI)
            {
                nn->BatODI = p.BatODI;

            }


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
            return loc;
        }
    }
    else
    {
        bst_node_Batting * nn = new bst_node_Batting();

        root = nn;
        root->name = value;
        if(p.BaT20)
        {
            nn->BaT20 = p.BaT20;
        }
        if (p.BatTest)
        {
            nn->BatTest = p.BatTest;
        }
        if (p.BatODI)
        {
            nn->BatODI = p.BatODI;

        }
//

//        nn->Country =p.Country;
//        nn->start =p.start;
//        nn->end = p.end;
        return nn;

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

        delete root;
    }
    else{
        this->root = nullptr;
    }
}
