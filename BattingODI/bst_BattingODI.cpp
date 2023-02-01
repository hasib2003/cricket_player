//
// Created by Ahmad on 12/28/2022.
//

#include "bst_BattingODI.h"
#include "bst_node_BattingODI.h"
#include <iostream>

using namespace std;
#include "string.h"
bst_BattingODI ::bst_BattingODI()  {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}
bool bst_BattingODI::isEmpty() {

    return this->root == nullptr;

}


BattingODI * bst_BattingODI::search(string value)
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


BattingODI * bst_BattingODI::InsertWithoutDuplication(BattingODI p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_BattingODI * nn = new bst_node_BattingODI();
            nn->name = value;

            nn->Mat = p.Mat;
            nn->NO =p.NO;
            nn->Inns = p.Inns ;
            nn->Runs =  p.Runs ;
            nn->HS =  p.HS;
            nn->Ave =  p.Ave;
            nn->BF =   p.BF;
            nn->SR =  p.SR ;
            nn->Centuries =  p.Centuries;
            nn->Fifties =p.Fifties;
            nn->Zero =   p.Zero;
            nn->start =  p.start;
            nn->end =   p.end;

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
            return  loc;
        }
    }
    else
    {
        bst_node_BattingODI * nn = new bst_node_BattingODI();

        root = nn;
        nn->name = value;
        nn->name = p.name;
        nn->Mat = p.Mat;
        nn->NO =p.NO;
        nn->Inns = p.Inns ;
        nn->Runs =  p.Runs ;
        nn->HS =  p.HS;
        nn->Ave =  p.Ave;
        nn->BF =   p.BF;
        nn->SR =  p.SR ;
        nn->Centuries =  p.Centuries;
        nn->Fifties =p.Fifties;
        nn->Zero =   p.Zero;
        nn->start =  p.start;
        nn->end =      p.end;
        return nn;


    }

}


void bst_BattingODI ::preOrder(bst_node_BattingODI * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_BattingODI ::postOrder(bst_node_BattingODI * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_BattingODI ::inOrder(bst_node_BattingODI * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}



int bst_BattingODI :: height(bst_node_BattingODI * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_BattingODI ::destroy(bst_node_BattingODI * root)
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