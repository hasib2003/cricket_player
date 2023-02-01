#pragma once
#include <iostream>
#include <fstream>
#include "intermediate_BattingTest.h"
using namespace std;
class BattingTest
{
public:
    string name;
    int start;
    int end;
    int Mat;
    int Inns;
    int NO;
    int Runs;
    string HS;
    float Ave;
    int Centuries;
    int Fifties;
    int Zero;





    intermediate_BattingTest* chain;

    BattingTest()
    {
        name="\n";
        start = 0;
        end = 0;
        Mat=0;
        Inns=0;
        NO=0;
        Runs=0;
        HS="0";
        Ave=0;
        Centuries=0;
        Fifties=0;
        Zero = 0;
        chain  = nullptr;
    }

    ~BattingTest(){
        delete chain;
    }
};