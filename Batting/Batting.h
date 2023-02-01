#pragma once
#include <iostream>
#include <fstream>
#include "../BattingODI/BattingODI.h"
#include "../BattingTest/BattingTest.h"
#include "../BattingT20/BattingT20.h"
#include "intermediate_Batting.h"
using namespace std;
class Batting
{
public:


    string name ;

    BattingODI* BatODI;

    BattingTest* BatTest;

    BattingT20 * BaT20 ;

    intermediate_Batting* next;

    Batting(){
        BatTest = nullptr;
        BatODI = nullptr;
        BaT20 = nullptr;
        name = "\n";

        next =nullptr;


    }
    ~Batting()
    {
        delete next;
    }
};