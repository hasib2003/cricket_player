//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTINGT20_HASHTABLE_H
#define DSA_PROJECT_BATTINGT20_HASHTABLE_H
#include <iostream>
#include "BattingT20.h"
#include "avl_BattingT20.h"
#include <cmath>
using namespace std;
class BattingT20_hashTable{
public:

    BattingT20 * base;


    int hashSize;
    int collision;


    BattingT20_hashTable()
    {
        hashSize = 0;
        collision = 0;
        hashSize = 2300;

        base = new BattingT20[hashSize];

    }

    // inserting the value inside the table
    BattingT20 *  insert(BattingT20 p, int index)
    {

        index = index % hashSize;




        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            base[index].Runs = p.Runs;
            base[index].Mat = p.Mat;
            base[index].Inns = p.Inns;
            base[index].No = p.No;
            base[index].Runs = p.Runs;
            base[index].HS = p.HS;
            base[index].Ave = p.Ave;
            base[index].BF = p.BF;
            base[index].SR = p.SR;
            base[index].Centuries = p.Centuries;
            base[index].Fifties = p.Fifties;
            base[index].Zero = p.Zero;
            base[index].Four = p.Four;
            base[index].Six = p.Six;
            base[index].end = p.end;
            base[index].start = p.start;


            return &base[index];
        }
        else
        {

            collision ++;
            BattingT20 * temp = chaining(index,p);
            return (temp);


        }

    }
    // for chaining, helpful when collision
    BattingT20 * chaining(int index,BattingT20 p)
    {
        index = index % hashSize;




        if(base[index].next)
        {
            avl_BattingT20 tree;
            tree.root = base[index].next->chain;

            return (tree.InsertWithoutDuplication(p));


        }
        else
        {

            intermediate_BattingT20 *inter = new intermediate_BattingT20();

            base[index].next = inter;

            avl_BattingT20 *tree = new avl_BattingT20();
            BattingT20 * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->chain = tree->root;

            return (temp);
        }
    }

    ~BattingT20_hashTable()
    {

        delete [] base;
    }


};


#endif //DSA_PROJECT_BATTINGT20_HASHTABLE_H
