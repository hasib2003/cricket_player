//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTINGODI_HASHTABLE_H
#define DSA_PROJECT_BATTINGODI_HASHTABLE_H
#include "avl_BattingODI.h"
#include <math.h>
#include "BattingODI.h"
#include <iostream>

using namespace std;

class BattingODI_hashTable {
public:
    BattingODI * base;


    int hashSize;
    int collision;


    BattingODI_hashTable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new BattingODI[hashSize];

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

    void insert(BattingODI p)
    {


        int index = hashFunction(p.name);


        if(base[index].name=="\n" )
        {
            base[index].name = p.name;

            std::cout<<"inserted successfully"<<std::endl;


        }
        else
        {

            chaining(index,p);


        }

    }


    void chaining(int index,BattingODI p)
    {
        if(base[index].chain)
        {
            avl_BattingODI tree;
            tree.root = base[index].chain->root;

            tree.InsertWithoutDuplication(p);


        }
        else
        {
            intermediate_BattingODI *inter = new intermediate_BattingODI();
            base[index].chain = inter;

            avl_BattingODI *tree = new avl_BattingODI();

            inter->root = tree->root;

            tree->InsertWithoutDuplication(p);
        }
    }

    void search(std::string name)
    {
        int index = hashFunction(name);

        if(base[index].name == name)
        {
            std::cout<<base[index].name<<" "<<std::endl;
        }
        else
        {
            avl_BattingODI tree;
            tree.root = base[index].chain->root;

            tree.search(name);
        }
    }

    ~BattingODI_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }
};


#endif //DSA_PROJECT_BATTINGODI_HASHTABLE_H
