//
// Created by Ahmad on 12/31/2022.
//

#pragma once
#include "../Fielding/Fielding.h"
#include "../Fielding//avl_Fielding.h"
#include <cmath>
class Fielding_hashTable {
public:

    Fielding * base;


    int hashSize;
    int collision;


    Fielding_hashTable()
    {
        collision = 0;
        hashSize = 2300;


        base = new Fielding[hashSize];

    }






    Fielding *  insert(Fielding p, int index)
    {

        index = index % hashSize;



        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            base[index].Mat = p.Mat;
            base[index].Inns = p.Inns;
            base[index].Dis = p.Dis;
            base[index].Ct = p.Ct;
            base[index].ST = p.ST;
            base[index].CT_WK= p.CT_WK;
            base[index].CT_Fi = p.CT_Fi;
            base[index].MD = p.MD;
            base[index].DI = p.DI;

            base[index].start = p.start;
            base[index].end = p.end;


            return &base[index];
        }
        else
        {

            collision ++;
            return (chaining(index,p));


        }

    }
    // for chaining, helpful when collision
    Fielding * chaining(int index,Fielding p)
    {

        index = index % hashSize;



        if(base[index].chain)
        {
            avl_Fielding tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {

            intermediate_Fielding *inter = new intermediate_Fielding();

            base[index].chain = inter;

            avl_Fielding *tree = new avl_Fielding();
            Fielding * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return (temp);
        }
    }

    ~Fielding_hashTable()
    {

        delete[] base;
    }
};


