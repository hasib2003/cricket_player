//
// Created by Ahmad on 12/28/2022.
//

#pragma once
#include <iostream>
#include "FieldingProfile.h"
#include "avl_FieldingProfile.h"
#include <cmath>
using namespace std;
class FieldingProfile_hashTable{
public:

    FieldingProfile * base;


    int hashSize;
    int collision;


    FieldingProfile_hashTable()
    {
        hashSize = 2300;
        collision = 0;


        base = new FieldingProfile[hashSize];

    }

    // inserting the value inside the table
    FieldingProfile *  insert(FieldingProfile p, int index)
    {

        index = index % hashSize;


//        int index = hashFunction(p.name);


        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
            if (p.FieldingT20)
            {
                base[index].FieldingT20 = p.FieldingT20;
            }
            if (p.FieldingODI)
            {
                base[index].FieldingODI = p.FieldingODI;

            }
            if(p.FieldingTest)
            {
                base[index].FieldingTest = p.FieldingTest;
            }
            return &base[index];
        }
        else
        {

            collision ++;
            return (chaining(index,p));


        }

    }
    // for chaining, helpful when collision
    FieldingProfile * chaining(int index,FieldingProfile p)
    {

        index = index % hashSize;


        if(base[index].chain)
        {
            avl_FieldingProfile tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {

            intermediate_FieldingProfile *inter = new intermediate_FieldingProfile();

            base[index].chain = inter;

            avl_FieldingProfile *tree = new avl_FieldingProfile();
            FieldingProfile * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return (temp);
        }
    }

    ~FieldingProfile_hashTable()
    {

        delete [] base;
    }


};



