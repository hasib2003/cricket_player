//
// Created by hasib on 12/26/22.
//

#pragma once
#include "../Bowling/Bowling.h"
#include <iostream>
#include "intermediate.h"
#include "../country/country.h"
#include "../Batting/Batting.h"
#include "../FieldingProfile/FieldingProfile.h"
#include "../linkedList/linked_list.h"

//class  country;
class player {
public:





    // pointer to the country
    country * Country;

    // pointers to three profiles of the player
    Batting* battingProfiles;
    Bowling * bowlingProfiles;
    FieldingProfile * fieldingProfile;




    // pointer to the collision detector
    intermediate * next;

    // players name
    std::string name;


    // pointer to maintain the graph based on the span of players
    linked_list * inSpanPlayers;






    int collisions;

    player();

};


