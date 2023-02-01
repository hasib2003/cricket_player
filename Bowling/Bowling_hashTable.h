//
// Created by Ahmad on 12/28/2022.
//

#pragma once

#include <iostream>
#include "Bowling.h"
#include "avl_Bowling.h"
#include <cmath>

using namespace std;
class Bowling_hashTable {
public:
    Bowling* base;
    int hashSize;
    int collision;
    Bowling_hashTable()
    {
        hashSize = 0;
        collision = 0;
        hashSize = 2300;

        base = new Bowling[hashSize];

    }




    Bowling *  insert(Bowling p, int index)
    {

        index = index % hashSize;



        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            if (p.BowlT20)
            {
                base[index].BowlT20 = p.BowlT20;
            }
            if (p.BowlODI)
            {
                base[index].BowlODI = p.BowlODI;

            }
            if(p.BoTest)
            {
                base[index].BoTest = p.BoTest;
            }





            return &base[index];



        }
        else
        {

            collision ++;
            return (chaining(index,p));

        }

    }


    Bowling * chaining(int index,Bowling p)
    {
        index = index % hashSize;

        if(base[index].chain)
        {
            avl_Bowling tree;
            tree.root = base[index].chain->root;


            return(tree.InsertWithoutDuplication(p));

        }
        else
        {
            intermediate_Bowling *inter = new intermediate_Bowling();
            base[index].chain = inter;

            avl_Bowling *tree = new avl_Bowling();

            Bowling * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return  temp;
        }
    }


    ~Bowling_hashTable()
    {
        delete base;
    }
};


