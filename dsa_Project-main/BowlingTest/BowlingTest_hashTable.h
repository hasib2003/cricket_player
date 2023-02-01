//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTINGT20_HASHTABLE_H
#define DSA_PROJECT_BATTINGT20_HASHTABLE_H
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
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your Batting T20 hash table: ";
        std::cin>>hashSize;

        base = new BowlingTest[hashSize];

    }

    // inserting the value inside the table
    BowlingTest *  insert(BowlingTest p, int index)
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
//
//            std::cout<<"inserted successfully"<<std::endl;
//
//            return &base[index];
        }
        else
        {

            collision ++;
            std::cout<<"insertion after collsion at index "<<index<<std::endl;
            return (chaining(index,p));


        }

    }
    // for chaining, helpful when collision
    BowlingTest * chaining(int index,BowlingTest p)
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
            avl_BowlingTest tree;
            tree.root = base[index].chain->root;

            return(tree.InsertWithoutDuplication(p));


        }
        else
        {
            std::cout<<"inserting at root"<<std::endl;

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
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete [] base;
    }


};


#endif //DSA_PROJECT_BATTINGT20_HASHTABLE_H
