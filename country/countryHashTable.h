//
// Created by hasib on 12/30/22.
//

#ifndef CRICKET_PLAYER_COUNTRYHASHTABLE_H
#define CRICKET_PLAYER_COUNTRYHASHTABLE_H




#include <iostream>
//template <typename T>
#include "avl_country.h"
#include "coutry_intermediate.h"
#include <cmath>

#include "country.h"

class countryHashTable{
public:

    country * base;


    int hashSize;
    int collision;

    int max;


    countryHashTable();
    int hashFunction(std::string);
    country * insert(country p);
    country *  chaining(int index, country p);
    country *  search(std::string);
    ~countryHashTable();





};












#endif //CRICKET_PLAYER_COUNTRYHASHTABLE_H
