//
// Created by Ahmad on 12/28/2022.
//

#pragma once
#include <iostream>
#include "BowlingT20.h"
#include "avl_BowlingT20.h"
#include <cmath>
using namespace std;
class BowlingT20_hashTable{
public:

    BowlingT20 * base;


    int hashSize;
    int collision;


    BowlingT20_hashTable()
    {
        hashSize = 0;
        collision = 0;
        hashSize = 2300;

        base = new BowlingT20[hashSize];

    }

    // inserting the value inside the table
    BowlingT20 *  insert(BowlingT20 p, int index)
    {

        index = index % hashSize;





        if(base[index].name=="\n" )
        {
            base[index].name = p.name;

            base[index].Mat = p.Mat;
            base[index].Inns =p.Inns;
            base[index].Overs = p.Overs;
            base[index].Mdns =p.Mdns;
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

            BowlingT20 * temp = chaining(index,p);

            return (temp);


        }

    }
    // for chaining, helpful when collision
    BowlingT20 * chaining(int index,BowlingT20 p)
    {
        index = index % hashSize;




        if(base[index].chain)
        {
            avl_BowlingT20 tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {

            intermediate_BowlingT20 *inter = new intermediate_BowlingT20();

            base[index].chain = inter;

            avl_BowlingT20 *tree = new avl_BowlingT20();
            BowlingT20 * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);

            inter->root = tree->root;


            return temp;
        }
    }

    ~BowlingT20_hashTable()
    {

        delete [] base;
    }


};


