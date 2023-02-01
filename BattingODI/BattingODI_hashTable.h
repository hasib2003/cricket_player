//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTINGODI_HASHTABLE_H
#define DSA_PROJECT_BATTINGODI_HASHTABLE_H
#include "avl_BattingODI.h"
#include <math.h>
#include "BattingODI.h"
#include <iostream>

using namespace std;

class BattingODI_hashTable {
public:
    BattingODI * base;


    int hashSize;
    int collision;


    BattingODI_hashTable()
    {
        hashSize = 0;
        collision = 0;
        hashSize = 2300;

        base = new BattingODI[hashSize];

    }


    BattingODI * insert(BattingODI p,int index)
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
            base[index].BF =   p.BF;
            base[index].SR =  p.SR ;
            base[index].Centuries =  p.Centuries;
            base[index].Fifties =p.Fifties;
            base[index].Zero =   p.Zero;
            base[index].start =  p.start;
            base[index].end =      p.end;



            return &base[index];

        }
        else
        {


            collision ++;
            return (chaining(index,p));


        }

    }


    BattingODI * chaining(int index,BattingODI p)
    {
        index = index % hashSize;

        if(base[index].chain)
        {
            avl_BattingODI tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));



        }
        else
        {
            intermediate_BattingODI *inter = new intermediate_BattingODI();
            base[index].chain = inter;

            avl_BattingODI *tree = new avl_BattingODI();



            BattingODI * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);

            inter->root = tree->root;
            return (temp);
        }
    }


    ~BattingODI_hashTable()
    {

        delete [] base;
    }
};


#endif //DSA_PROJECT_BATTINGODI_HASHTABLE_H
