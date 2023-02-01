//
// Created by Ahmad on 12/28/2022.
//

#ifndef DSA_PROJECT_BATTINGT20_HASHTABLE_H
#define DSA_PROJECT_BATTINGT20_HASHTABLE_H
#include <iostream>
#include "BattingT20.h"
#include "avl_BattingT20.h"
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
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new BattingT20[hashSize];

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

    void insert(BattingT20 p)
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


    void chaining(int index,BattingT20 p)
    {
        if(base[index].chain)
        {
            avl_BattingT20 tree;
            tree.root = base[index].chain->root;

            tree.InsertWithoutDuplication(p);


        }
        else
        {
            intermediate_BattingT20 *inter = new intermediate_BattingT20();
            base[index].chain = inter;

            avl_BattingT20 *tree = new avl_BattingT20();

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
            avl_BattingT20 tree;
            tree.root = base[index].chain->root;

            tree.search(name);
        }
    }

    ~BattingT20_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }


};


#endif //DSA_PROJECT_BATTINGT20_HASHTABLE_H
