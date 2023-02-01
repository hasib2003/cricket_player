//
// Created by hasib on 12/30/22.
//

#pragma once

#include "coutry_intermediate.h"
#include <iostream>
//#include "../linkedList/linked_list.h"

class linked_list;
class country {
public:
    country_intermediate * next;

    linked_list * targetPlayers;


    std::string name;
    int collisions;


    country();
};


