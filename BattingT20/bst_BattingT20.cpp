//
// Created by Ahmad on 12/28/2022.
//

#include "bst_BattingT20.h"

#include "BattingT20.h"
#include <iostream>
using namespace  std;

bst_BattingT20 ::bst_BattingT20() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst_BattingT20::isEmpty() {

    return this->root == nullptr;

}


BattingT20 * bst_BattingT20::search(string value)
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


BattingT20 * bst_BattingT20::InsertWithoutDuplication(BattingT20 p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_BattingT20 * nn = new bst_node_BattingT20();
            nn->name = value;
            nn->Runs = p.Runs;
            nn->Mat = p.Mat;
            nn->Inns = p.Inns;
            nn->No = p.No;
            nn->Runs = p.Runs;
            nn->HS = p.HS;
            nn->Ave = p.Ave;
            nn->BF = p.BF;
            nn->SR = p.SR;
            nn->Centuries = p.Centuries;
            nn->Fifties = p.Fifties;
            nn->Zero = p.Zero;
            nn->Four = p.Four;
            nn->Six = p.Six;
            nn->end = p.end;
            nn->start = p.start;
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
            else
            {


                root = nn;
                nn->leftChild = nullptr;
                nn->rightChild = nullptr;
            }
            return nn;
        }

        else
        {
            return  loc;
        }
    }
    else
    {
        bst_node_BattingT20 * nn = new bst_node_BattingT20();

        root = nn;
        root->name = value;
        root->Runs = p.Runs;
        root->Mat = p.Mat;
        root->Inns = p.Inns;
        root->No = p.No;
        root->Runs = p.Runs;
        root->HS = p.HS;
        root->Ave = p.Ave;
        root->BF = p.BF;
        root->SR = p.SR;
        root->Centuries = p.Centuries;
        root->Fifties = p.Fifties;
        root->Zero = p.Zero;
        root->Four = p.Four;
        root->Six = p.Six;
        root->end = p.end;
        root->start = p.start;





        return nn;
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

        delete root;
    }
    else{
        this->root = nullptr;
    }
}

//bst :: ~bst()
//{
//    std::cout<<"destroyed ";
//    destroy(this->root);
//}
