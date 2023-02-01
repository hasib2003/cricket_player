//
// Created by Ahmad on 12/30/2022.
//

#ifndef DSA_PROJECT_BOWLINGODI_HASHTABLE_H
#define DSA_PROJECT_BOWLINGODI_HASHTABLE_H
#include "BowlingODI.h"
#include "avl_BowlingODI.h"

using namespace std;

class BowlingODI_hashTable {
    BowlingODI * base;


    int hashSize;
    int collision;


    BowlingODI_hashTable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new BowlingODI[hashSize];

    }





    BowlingODI* insert(BowlingODI p , int index)
    {





        if(base[index].name=="\n" )
        {
            base[index].name = p.name;

            std::cout<<"inserted successfully"<<std::endl;
            return &base[index];

        }
        else
        {

            collision ++;
            std::cout<<"insertion after collsion at index"<<index
                     <<std::endl;
            return (chaining(index,p));

        }

    }


    BowlingODI* chaining(int index,BowlingODI p)
    {
        if(base[index].chain)
        {
            avl_BowlingODI tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {
            intermediate_BowlingODI *inter = new intermediate_BowlingODI();
            base[index].chain = inter;

            avl_BowlingODI *tree = new avl_BowlingODI();



            BowlingODI * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;
            return  temp;
        }
    }



    ~BowlingODI_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete[] base;
    }
};


#endif //DSA_PROJECT_BOWLINGODI_HASHTABLE_H
