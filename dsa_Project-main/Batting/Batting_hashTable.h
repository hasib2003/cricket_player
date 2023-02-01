//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTING_HASHTABLE_H
#define DSA_PROJECT_BATTING_HASHTABLE_H
#include <iostream>
#include "Batting.h"
#include "avlBatting.h"
using namespace std;
class Batting_hashTable {
public:
    Batting* base;
    int hashSize;
    int collision;
    Batting_hashTable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new Batting[hashSize];

    }



    int hashFunction(std::string name)
    {




        char * arr = &name[0];

        int initialKey = 0;



        for (int i=0;i<name.length();i++)
        {
            initialKey += int(arr[i])+i;
        }


        initialKey = abs((initialKey- (initialKey/name.length() )) % hashSize );



        std::cout<<"the key is "<<initialKey<<std::endl;
        return  initialKey;



    }

    void insert(Batting p)
    {


        int index = hashFunction(p.name);


        if(base[index].name=="\n" )
        {
            base[index].name = p.name;

            std::cout<<"inserted successfully"<<std::endl;


        }
        else
        {

            chaining(index,p);


        }

    }


    void chaining(int index,Batting p)
    {
        if(base[index].chain)
        {
            avlBatting tree;
            tree.root = base[index].chain->root;

            tree.InsertWithoutDuplication(p);


        }
        else
        {
            intermediate_Batting *inter = new intermediate_Batting();
            base[index].chain = inter;

            avlBatting *tree = new avlBatting();

            inter->root = tree->root;

            tree->InsertWithoutDuplication(p);
        }
    }

    void search(std::string name)
    {
        int index = hashFunction(name);

        if(base[index].name == name)
        {
            std::cout<<base[index].name<<" "<<std::endl;
        }
        else
        {
            avlBatting tree;
            tree.root = base[index].chain->root;

            tree.search(name);
        }
    }

    ~Batting_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }
};


#endif //DSA_PROJECT_BATTING_HASHTABLE_H
