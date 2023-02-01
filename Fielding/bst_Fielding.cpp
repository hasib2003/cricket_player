//
// Created by Ahmad on 12/31/2022.
//

#include "bst_Fielding.h"
#include "bst_node_Fielding.h"


#include <iostream>
using namespace  std;
#include "string.h"
bst_Fielding ::bst_Fielding() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}
bool bst_Fielding::isEmpty() {

    return this->root == nullptr;

}


Fielding* bst_Fielding::search(string value)
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
        std::cout<<loc->name<<" ";
    }




}


Fielding* bst_Fielding::InsertWithoutDuplication(Fielding p )
{
    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_Fielding * nn = new bst_node_Fielding();
            nn->name = value;

            nn->Mat = p.Mat;
            nn->Inns = p.Inns;
            nn->Dis = p.Dis;
            nn->Ct = p.Ct;
            nn->ST = p.ST;
            nn->CT_WK= p.CT_WK;
            nn->CT_Fi = p.CT_Fi;
            nn->MD = p.MD;
            nn->DI = p.DI;

            nn->start = p.start;
            nn->end = p.end;



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
        bst_node_Fielding * nn = new bst_node_Fielding();

        root = nn;
        root->name = value;
        nn->name = value;

        nn->Mat = p.Mat;
        nn->Inns = p.Inns;
        nn->Dis = p.Dis;
        nn->Ct = p.Ct;
        nn->ST = p.ST;
        nn->CT_WK= p.CT_WK;
        nn->CT_Fi = p.CT_Fi;
        nn->MD = p.MD;
        nn->DI = p.DI;

        nn->start = p.start;
        nn->end = p.end;

        return root;

    }

}


void bst_Fielding ::preOrder(bst_node_Fielding * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_Fielding ::postOrder(bst_node_Fielding * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_Fielding ::inOrder(bst_node_Fielding * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}



int bst_Fielding :: height(bst_node_Fielding * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_Fielding ::destroy(bst_node_Fielding * root)
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