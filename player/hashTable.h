//
// Created by hasib on 12/25/22.
//

#pragma once
#include <iostream>
#include "player.h"
#include "avl.h"
#include "intermediate.h"
#include <cmath>

#include "helper.h"
class hashTable{
public:

    player * base;


    int hashSize;
    int Pcollision;

    int max;



    hashTable();


    int hashFunction(std::string );


    player * insert(player );

    player *  chaining(int ,player );

    player *  search(std::string ,std::string );

    player * search(std::string );



    // function to maintain links to others players

    void maintainGraphLinks();
    void checkAVL(bst_node*,player *);

    // to iterate over the whole data set and find players with test
    // profile
    void iterator();



    // will link the nodes in avl if we have any collisions
    void checkAVLlinker(bst_node *, player *);


    // given a specific player it will find and link all
    // those players who have overlapping span

    void linker(player *);

    void linkerHelper(player * ,player * );



    ~hashTable();


};


