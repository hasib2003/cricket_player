//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTING_HASHTABLE_H
#define DSA_PROJECT_BATTING_HASHTABLE_H
#include <iostream>
#include "Batting.h"
#include "avlBatting.h"
#include <cmath>

using namespace std;
class Batting_hashTable {
public:
    Batting* base;
    int hashSize;
    int collision;

    Batting_hashTable()
    {
        hashSize = 0;
        collision = 0;
//        std::cout<<"What should be the size of your Batting table: ";
//        std::cin>>hashSize;
        hashSize = 2300;
        base = new Batting[hashSize];

    }




    Batting *  insert(Batting p, int index)
    {


        index = index % hashSize;


        if(base[index].name=="\n")
        {
            base[index].name = p.name;
            if(p.BaT20)
            {
                base[index].BaT20 = p.BaT20;
            }
            if (p.BatODI)
            {
                base[index].BatODI = p.BatODI;

            }

            if (p.BatTest)
            {
                base[index].BatTest = p.BatTest;

            }




            return &base[index];



        }
        else
        {

            collision ++;
            return (chaining(index,p));

        }

    }


    Batting * chaining(int index,Batting p)
    {
        index = index % hashSize;

        if(base[index].next)
        {
            avlBatting tree;
            tree.root = base[index].next->root;

            return(tree.InsertWithoutDuplication(p));

        }
        else
        {
            intermediate_Batting *inter = new intermediate_Batting();

            base[index].next = inter;

            avlBatting *tree = new avlBatting();

            Batting * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;


            return  temp;
        }
    }


    ~Batting_hashTable()
    {

        delete [] base;
    }
};


#endif //DSA_PROJECT_BATTING_HASHTABLE_H
