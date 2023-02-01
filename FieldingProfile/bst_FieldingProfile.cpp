//
// Created by Ahmad on 12/28/2022.
//

#include "bst_FieldingProfile.h"

#include "FieldingProfile.h"
#include <iostream>
using namespace  std;

bst_FieldingProfile ::bst_FieldingProfile() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}

bool bst_FieldingProfile::isEmpty() {

    return this->root == nullptr;

}


FieldingProfile * bst_FieldingProfile::search(string value)
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


FieldingProfile * bst_FieldingProfile::InsertWithoutDuplication(FieldingProfile p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_FieldingProfile * nn = new bst_node_FieldingProfile();
            nn->name = value;

            if (p.FieldingT20)
            {
                nn->FieldingT20 = p.FieldingT20;
            }
            if (p.FieldingODI)
            {
                nn->FieldingODI = p.FieldingODI;

            }
            if(p.FieldingTest)
            {
                nn->FieldingTest = p.FieldingTest;
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
            return  loc;
        }
    }
    else
    {
        bst_node_FieldingProfile * nn = new bst_node_FieldingProfile();

        root = nn;
        root->name = value;
        if (p.FieldingT20)
        {
            nn->FieldingT20 = p.FieldingT20;
        }
        if (p.FieldingODI)
        {
            nn->FieldingODI = p.FieldingODI;

        }
        if(p.FieldingTest)
        {
            nn->FieldingTest = p.FieldingTest;
        }
        return nn;
    }

}


void bst_FieldingProfile ::preOrder(bst_node_FieldingProfile * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_FieldingProfile ::postOrder(bst_node_FieldingProfile * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_FieldingProfile ::inOrder(bst_node_FieldingProfile * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}

int bst_FieldingProfile :: height(bst_node_FieldingProfile * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_FieldingProfile ::destroy(bst_node_FieldingProfile * root)
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
