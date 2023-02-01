//
// Created by Ahmad on 12/30/2022.
//
#pragma once
#ifndef DSA_PROJECT_BOWLINGODI_HASHTABLE_H
#define DSA_PROJECT_BOWLINGODI_HASHTABLE_H
#include "BowlingODI.h"
#include "avl_BowlingODI.h"

using namespace std;

class BowlingODI_hashTable {
public:
    BowlingODI * base;


    int hashSize;
    int collision;


    BowlingODI_hashTable()
    {
        collision = 0;
        hashSize = 2300;

        base = new BowlingODI[hashSize];

    }





    BowlingODI* insert(BowlingODI p , int index)
    {

index = index % hashSize;



        if(base[index].name=="\n" )
        {
            base[index].name = p.name;

            base[index].Mat = p.Mat;
            base[index].Inns =p.Inns;

            base[index].Runs = p.Runs;
            base[index].Wkts = p.Wkts;
            base[index].BBI =p.BBI;
            base[index].Ave = p.Ave;
            base[index].Econ = p.Econ;
            base[index].SR =p.SR;
            base[index].Four =p.Four;
            base[index].Five = p.Five;

            base[index].start = p.end;
            base[index].end = p.start;

            return &base[index];

        }
        else
        {

            collision ++;
            return (chaining(index,p));

        }

    }


    BowlingODI* chaining(int index,BowlingODI p)
    {
        index = index % hashSize;

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

        delete[] base;
    }
};


#endif //DSA_PROJECT_BOWLINGODI_HASHTABLE_H
