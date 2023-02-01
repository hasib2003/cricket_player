//
// Created by Ahmad on 12/28/2022.
//

#include <iostream>
#pragma once
#include "BattingTest.h"
#include "avl_BattingTest.h"
#include <cmath>
using namespace std;
class BattingTest_hashTable{
public:

    BattingTest * base;


    int hashSize;
    int collision;


    BattingTest_hashTable()
    {
        hashSize = 0;
        collision = 0;
        hashSize = 2300;

        base = new BattingTest[hashSize];

    }

    // inserting the value inside the table
    BattingTest *  insert(BattingTest p, int index)
    {

        index = index % hashSize;





        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            base[index].Mat = p.Mat;
            base[index].NO =p.NO;
            base[index].Inns = p.Inns ;
            base[index].Runs =  p.Runs ;
            base[index].HS =  p.HS;
            base[index].Ave =  p.Ave;
            base[index].Centuries =  p.Centuries;
            base[index].Fifties =p.Fifties;
            base[index].Zero =   p.Zero;
            base[index].start =  p.start;
            base[index].end =    p.end;

            return &base[index];
        }
        else
        {

            collision ++;
            return (chaining(index,p));


        }

    }
    // for chaining, helpful when collision
    BattingTest * chaining(int index,BattingTest p)
    {
        index = index % hashSize;

        if(base[index].chain)
        {
            avl_BattingTest tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {

            intermediate_BattingTest *inter = new intermediate_BattingTest();

            base[index].chain = inter;

            avl_BattingTest *tree = new avl_BattingTest();
            BattingTest * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return (temp);
        }
    }

    ~BattingTest_hashTable()
    {

        delete [] base;
    }


};


