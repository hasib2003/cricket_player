//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTING_HASHTABLE_H
#define DSA_PROJECT_BATTING_HASHTABLE_H
#include <iostream>
#include "Bowling.h"
#include "avl_Bowling.h"
#include <cmath>

using namespace std;
class Batting_hashTable {
public:
    Bowling* base;
    int hashSize;
    int collision;
    Batting_hashTable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your Batting table: ";
        std::cin>>hashSize;

        base = new Bowling[hashSize];

    }




    Bowling *  insert(Bowling p, int index)
    {


//        int index = hashFunction(p.name);


        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            base[index].BowlT20 = p.BowlT20;


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


    Bowling * chaining(int index,Bowling p)
    {
        if(base[index].chain)
        {
            avlBatting tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));

        }
        else
        {
            intermediate_Bowling *inter = new intermediate_Bowling();
            base[index].chain = inter;

            avlBatting *tree = new avlBatting();

            Bowling * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return  temp;
        }
    }


    ~Batting_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }
};


#endif //DSA_PROJECT_BATTING_HASHTABLE_H
