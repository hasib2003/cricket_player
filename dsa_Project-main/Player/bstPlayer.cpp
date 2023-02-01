//
// Created by Ahmad on 12/28/2022.
//

#include "bstPlayer.h"
#include "bst_node_player.h"


#include <iostream>
using namespace  std;
#include "string.h"
bstPlayer ::bstPlayer() {
    ploc= nullptr;
    loc = ploc;
    root = ploc;
}










bool bstPlayer::isEmpty() {

    return this->root == nullptr;

}


void bstPlayer::search(string value)
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


void bstPlayer::InsertWithoutDuplication(Player p )
{

    std::string value = p.name;
    if(!isEmpty()) {

        search(p.name);

        if (!loc)  // value is not present in the tree
        {
            bst_node_player * nn = new bst_node_player();
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
        }

        else
        {
            std::cout << "value already present" << std::endl;
        }
    }
    else
    {
        bst_node_player * nn = new bst_node_player();

        root = nn;
        root->name = value;

    }

}


void bstPlayer ::preOrder(bst_node_player * root)
{


    if (root->leftChild){
        preOrder(root->leftChild);}
    std::cout<<root->name<<std::endl;
    if(root->rightChild){
        preOrder(root->rightChild);

    }
}
void bstPlayer ::postOrder(bst_node_player * root)
{


    if (root->leftChild){
        postOrder(root->leftChild);}

    if(root->rightChild){
        postOrder(root->rightChild);

    }
    std::cout<<root->name<<std::endl;
}
void bstPlayer ::inOrder(bst_node_player * node)
{
    if (node) {
        std::cout << node->name << std::endl;

        inOrder(node->leftChild);

        inOrder(node->rightChild);

    }
}



int bstPlayer :: height(bst_node_player * root) {

    if (root) {
        return (max(height(root->leftChild), height(root->rightChild)) + 1);
    } else {
        return -1;
    }
}


void bstPlayer ::destroy(bst_node_player * root)
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



