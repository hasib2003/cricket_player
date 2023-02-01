#pragma once
#include <iostream>
#include <fstream>
#include "intermediate_BowlingTest.h"
#include <string.h>
using namespace std;
class BowlingTest
{
public:
    string name;
    int start;
    int end;
    int Mat;
    int Inns;
    float Balls;
    string Runs;
    int Wkts;
    string BBI;
    string BBM;
    float Ave;
    float Econ;
    float SR;
    int Ten;
    int Five;
    intermediate_BowlingTest* chain;


    BowlingTest()
    {
       name="\n";
        start = 0;
        end = 0;
        Mat=0;
        Inns=0;
         Balls=0;
         Runs="0";
         Wkts=0;
         BBI="\n";
         BBM="\n";
         Ave=0;
         Econ=0;
         SR=0;
        Ten=0;
         Five=0;
        chain= nullptr;
    }

    ~BowlingTest()
    {
        delete chain;
    }
};