#pragma once
#include <iostream>
#include <fstream>
#include "intermediate_BowlingODI.h"
using namespace std;
class BowlingODI
{
public:
    string name="\n";
    int start;
    int end;
    int Mat=0;
    int Inns=0;
    float Balls=0;
    string Runs="0";
    int Wkts=0;
    string BBI="\n";
    float Ave=0;
    float Econ=0;
    float SR=0;
    int Four=0;
    int Five=0;
    intermediate_BowlingODI* chain=NULL;


    ~BowlingODI(){
        delete chain;
    }
};