//
// Created by Ahmad on 12/28/2022.
//

#include "bst_BattingTest.h"

#include "BattingTest.h"
#include <iostream>
using namespace  std;

bst_BattingTest ::bst_BattingTest()  {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst_BattingTest::isEmpty() {

    return this->root == nullptr;

}


BattingTest * bst_BattingTest::search(string value)
{
    ploc= nullptr;
    loc = root;

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


BattingTest * bst_BattingTest::InsertWithoutDuplication(BattingTest p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_BattingTest * nn = new bst_node_BattingTest();
            nn->name = value;
            nn->name = p.name;
            nn->Mat = p.Mat;
            nn->NO =p.NO;
            nn->Inns = p.Inns ;
            nn->Runs =  p.Runs ;
            nn->HS =  p.HS;
            nn->Ave =  p.Ave;
            nn->Centuries =  p.Centuries;
            nn->Fifties =p.Fifties;
            nn->Zero =   p.Zero;
            nn->start =  p.start;
            nn->end =      p.end;


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
        bst_node_BattingTest * nn = new bst_node_BattingTest();

        root = nn;
        nn->name = value;
        nn->name = p.name;
        nn->Mat = p.Mat;
        nn->NO =p.NO;
        nn->Inns = p.Inns ;
        nn->Runs =  p.Runs ;
        nn->HS =  p.HS;
        nn->Ave =  p.Ave;
        nn->Centuries =  p.Centuries;
        nn->Fifties =p.Fifties;
        nn->Zero =   p.Zero;
        nn->start =  p.start;
        nn->end =  p.end;
        return nn;
    }

}


void bst_BattingTest ::preOrder(bst_node_BattingTest * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_BattingTest ::postOrder(bst_node_BattingTest * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_BattingTest ::inOrder(bst_node_BattingTest * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}

int bst_BattingTest :: height(bst_node_BattingTest * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_BattingTest ::destroy(bst_node_BattingTest * root)
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

