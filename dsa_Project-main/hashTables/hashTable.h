//
// Created by hasib on 12/25/22.
//

#ifndef HASHTABLES_HASHTABLE_H
#define HASHTABLES_HASHTABLE_H
#include <iostream>
//template <typename T>
#include "player.h"
#include "avl.h"
#include "intermediate.h"
class hashTable{
public:

    player * base;


    int hashSize;
    int collision;


    hashTable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new player[hashSize];


        for (int i=0;i<hashSize;i++)
        {
            base[i].name = "\n";
            base[i].span = "\n";
        }
    }



    int hashFunction(std::string name)
    {




        char * arr = &name[0];

        int initialKey = 0;



        for (int i=0;i<name.length();i++)
        {
            initialKey += int(arr[i])+i;
        }


        initialKey = abs((initialKey- (initialKey/name.length() )) % hashSize );



        std::cout<<"the key is "<<initialKey<<std::endl;
        return  initialKey;



    }

    void insert(player p)
    {


        int index = hashFunction(p.name);


        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            base[index].span = p.span;

            std::cout<<"inserted successfully"<<std::endl;


        }
        else
        {

            chaining(index,p);


        }

    }


    void chaining(int index,player p)
    {
        if(base[index].next)
        {
            avl tree;
            tree.root = base[index].next->chain;

            tree.InsertWithoutDuplication(p);


        }
        else
        {
            intermediate *inter = new intermediate();
            
            base[index].next = inter;

            avl *tree = new avl();

            inter->chain = tree->root;

            tree->InsertWithoutDuplication(p);
        }
    }

    void search(std::string name)
    {
        int index = hashFunction(name);

        if(base[index].name == name)
        {
            std::cout<<base[index].name<<" "<<base[index].span<<std::endl;
        }
        else
        {
            avl tree;
            tree.root = base[index].next->chain;

            tree.search(name);
        }
    }

    ~hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }


};


#endif //HASHTABLES_HASHTABLE_H
