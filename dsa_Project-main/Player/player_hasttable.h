//
// Created by hasib on 12/25/22.
//


#include <iostream>
#include "Player.h"
#include "avlPlayer.h"
//#include "player_intermediate.h"

class player_hashtable{
public:

    Player * base;


    int hashSize;
    int collision;


    player_hashtable()
    {
        hashSize = 0;
        collision = 0;
        std::cout<<"What should be the size of your hash table: ";
        std::cin>>hashSize;

        base = new Player[hashSize];

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

    void insert(Player p)
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


    void chaining(int index,Player p)
    {
        if(base[index].chain)
        {
            avlPlayer tree;
            tree.root = base[index].chain->root;

            tree.InsertWithoutDuplication(p);


        }
        else
        {
            intermediate_player *inter = new intermediate_player();
            base[index].chain = inter;

            avlPlayer *tree = new avlPlayer();

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
            avlPlayer tree;
            tree.root = base[index].chain->root;

            tree.search(name);
        }
    }

    ~player_hashtable()
    {
        std::cout<<"destructor is called"<<std::endl;
        std::cout<<"total "<<collision<<std::endl;
        delete base;
    }


};


