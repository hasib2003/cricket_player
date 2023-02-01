//
// Created by hasib on 12/26/22.
//

#ifndef HASHTABLES_PLAYER_H
#define HASHTABLES_PLAYER_H
#include <iostream>
#include "intermediate.h"
class player {
public:
    intermediate * next;

    std::string name;
    std::string span;
    int collisions;


    player(){
        next = nullptr;
        collisions = 0;
    }
};


#endif //HASHTABLES_PLAYER_H
