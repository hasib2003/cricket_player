//
// Created by hasib on 12/30/22.
//

#include "bst_country.h"

#include "country.h"
//
// Created by hasib on 11/22/22.
//
#include <iostream>
using namespace  std;
#include "bst_country.h"
#include "string.h"
bst_country ::bst_country() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}


bool bst_country::isEmpty() {

    return this->root == nullptr;

}


country * bst_country::search(string value)
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


    return loc;





}


country * bst_country::InsertWithoutDuplication(country p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_country_node * nn = new bst_country_node();
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
            return  loc;
        }
    }
    else
    {
        bst_country_node * nn = new bst_country_node();

        root = nn;
        root->name = value;
        return nn;
    }

}


void bst_country ::preOrder(bst_country_node * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bst_country ::postOrder(bst_country_node * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bst_country ::inOrder(bst_country_node * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}

int bst_country :: height(bst_country_node * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bst_country ::destroy(bst_country_node * root)
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


