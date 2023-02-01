#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include "intermediate_FieldingProfile.h"
#include "../Fielding/Fielding.h"
using namespace std;
class FieldingProfile
{
public:
    string name;
    Fielding* FieldingODI;
    Fielding* FieldingT20;
    Fielding* FieldingTest;
    intermediate_FieldingProfile* chain;

    FieldingProfile()
    {
        name="\n";
        FieldingODI = nullptr;
        FieldingT20 = nullptr;
        FieldingTest = nullptr;
        chain=nullptr;
    }
};