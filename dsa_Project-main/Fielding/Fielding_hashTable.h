//
// Created by Ahmad on 12/31/2022.
//

#ifndef DSA_PROJECT_FIELDING_HASHTABLE_H
#define DSA_PROJECT_FIELDING_HASHTABLE_H
#include "Fielding.h"
#include "avl_Fielding.h"

class Fielding_hashTable {
public:

    Fielding * base;


    int hashSize;
    int collision;


    Fielding_hashTable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new Fielding[hashSize];

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

    void insert(Fielding p)
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


    void chaining(int index,Fielding p)
    {
        if(base[index].chain)
        {
            avl_Fielding tree;
            tree.root = base[index].chain->root;

            tree.InsertWithoutDuplication(p);


        }
        else
        {
            intermediate_Fielding *inter = new intermediate_Fielding();
            base[index].chain = inter;

            avl_Fielding *tree = new avl_Fielding();

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
            avl_Fielding tree;
            tree.root = base[index].chain->root;

            tree.search(name);
        }
    }

    ~Fielding_hashTable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }
};


#endif //DSA_PROJECT_FIELDING_HASHTABLE_H
