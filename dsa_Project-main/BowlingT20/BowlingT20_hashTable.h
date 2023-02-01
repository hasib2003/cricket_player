//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTINGT20_HASHTABLE_H
#define DSA_PROJECT_BATTINGT20_HASHTABLE_H
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
        std::cout<<"What should be the size of your Batting T20 hash table: ";
        std::cin>>hashSize;

        base = new BowlingT20[hashSize];

    }

    // inserting the value inside the table
    BowlingT20 *  insert(BowlingT20 p, int index)
    {


        std::cout<<"------"<<std::endl;
        std::cout<<"inserting the t20 profile"<<std::endl;
        std::cout<<"recieved name as "<<p.name<<std::endl;
        std::cout<<"------"<<std::endl;
//        int index = hashFunction(p.name);


        if(base[index].name=="\n" )
        {
            base[index].name = p.name;
//            base[index].Runs = p.Runs;
//            base[index].Mat = p.Mat;
//            base[index].Inns = p.Inns;
//            base[index].No = p.No;

            std::cout<<"inserted successfully"<<std::endl;

            return &base[index];
        }
        else
        {

            collision ++;
            std::cout<<"insertion after collsion at index "<<index<<std::endl;
            return (chaining(index,p));


        }

    }
    // for chaining, helpful when collision
    BowlingT20 * chaining(int index,BowlingT20 p)
    {
        std::cout<<"inside the chaining"<<std::endl;
        std::cout<<"with index"<<index<<std::endl;
        std::cout<<"with player"<<p.name<<std::endl;

        if (p.name == "N Nipiko")
        {
            std::cout<<"hit"<<std::endl;

        }
        if(base[index].chain)
        {
            std::cout<<"inserting at leave with root"<<base[index].chain->root->name<<std::endl;
            avl_BowlingT20 tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {
            std::cout<<"inserting at root"<<std::endl;

            intermediate_BowlingT20 *inter = new intermediate_BowlingT20();

            base[index].chain = inter;

            avl_BowlingT20 *tree = new avl_BowlingT20();
            BowlingT20 * temp = nullptr;


            temp = tree->InsertWithoutDuplication(p);
            inter->root = tree->root;

            return (temp);
        }
    }

    ~BowlingT20_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete [] base;
    }


};


#endif //DSA_PROJECT_BATTINGT20_HASHTABLE_H
