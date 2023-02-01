#pragma once
#include <iostream>
#include <fstream>
#include "intermediate_BattingODI.h"
//#include "../player/player.h"
class player;
using namespace std;
class BattingODI
{
public:


    player * target;
    string name;
    int start;
    int end;
    string span;
    int Mat;
    int Inns;
    int NO;
    int Runs;
    string HS;
    float Ave;
    int BF;
    float SR;
    int Centuries;
    int Fifties;
    int Zero;
    intermediate_BattingODI* chain;

    BattingODI()
    {
        target = nullptr;
        name="\n";
        start = 0;
        end = 0;
        Mat=0;
        Inns=0;
        NO=0;
        Runs=0;
        HS="0";
        Ave=0;
        BF=0;
        SR=0;
        Centuries=0;
        Fifties=0;
        Zero = 0;
        chain  = nullptr;
    }
    ~BattingODI(){
        delete chain;
    }


};