#pragma once
#include <iostream>
#include <fstream>
#include "../BowlingODI/BowlingODI.h"
#include "../BowlingT20/BowlingT20.h"
#include "../BowlingTest/BowlingTest.h"
//#include "C:\Users\Ahmad\Desktop\DSA Project\BowlingT20\BowlingT20.h"
//#include "C:\Users\Ahmad\Desktop\DSA Project\BowlingTest\BowlingTest.h"
#include "intermediate_Bowling.h"
using namespace std;
class Bowling
{
public:

    string name="\n";
    BowlingODI* BowlODI;
    BowlingT20* BowlT20;
    BowlingTest* BoTest;
    intermediate_Bowling * chain;

    Bowling()
    {
        BowlODI = nullptr;
        BowlT20 = nullptr;
        BoTest = nullptr;
        chain = nullptr;
    }

    ~Bowling(){
        delete chain;
    }
};