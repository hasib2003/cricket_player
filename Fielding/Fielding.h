#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include "intermediate_Fielding.h"
using namespace std;
class Fielding
{
public:
    string name;
    int start;
    int end;
    int Mat;
    int Inns;
    int Dis;
    int Ct;
    int ST;
    int CT_WK;
    int CT_Fi;
    string MD;
    float DI;
    intermediate_Fielding* chain;

    Fielding()
    {
        name="\n";
        start=0;
        end=0;
        Mat=0;
         Inns=0;
         Dis=0;
         Ct=0;
         ST=0;
         CT_WK=0;
         CT_Fi=0;
        MD="\n";
         DI=0;
        chain= nullptr;
    }
};