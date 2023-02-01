//
// Created by Ahmad on 12/28/2022.
//

#pragma once
#include <iostream>
#include "BowlingTest.h"
#include "avl_BowlingTest.h"
#include <cmath>
using namespace std;
class BowlingTest_hashTable{
public:

    BowlingTest * base;


    int hashSize;
    int collision;


    BowlingTest_hashTable()
    {
        this->collision = 0;
        this->hashSize = 2300;

        base = new BowlingTest[hashSize];




    }

    // inserting the value inside the table
    BowlingTest *  insert(BowlingTest p, int index)
    {
        index = index % hashSize;




        if("\n" == base[index].name)
        {
            base[index].name = p.name;
            base[index].name = p.name;

            base[index].Mat = p.Mat;
            base[index].Inns =p.Inns;

            base[index].Runs = p.Runs;
            base[index].Wkts = p.Wkts;
            base[index].BBI =p.BBI;
            base[index].Ave = p.Ave;
            base[index].Econ = p.Econ;
            base[index].SR =p.SR;
            base[index].Ten =p.Ten;

            base[index].Five = p.Five;
            base[index].BBM = p.BBM;

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
    // for chaining, helpful when collision
    BowlingTest * chaining(int index,BowlingTest p)
    {
        index = index % hashSize;



        if(base[index].chain)
        {
            avl_BowlingTest tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {

            intermediate_BowlingTest *inter = new intermediate_BowlingTest();

            base[index].chain = inter;

            avl_BowlingTest *tree = new avl_BowlingTest();
            BowlingTest * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return (temp);
        }
    }

    ~BowlingTest_hashTable()
    {

        delete [] base;
    }


};


