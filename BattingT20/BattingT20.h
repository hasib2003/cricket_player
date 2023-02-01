
#pragma once
#include <iostream>
#include "intermediate_BattingT20.h"
using namespace std;
class BattingT20
{
public:
    string name;
    int start;
    int end;
    int Mat;
    int Inns;
    int No;
    int Runs;
    string HS;
    float Ave;
    int BF;
    float SR;
    int Centuries;
    int Fifties;
    int Zero;
    int Four;
    int Six;
    intermediate_BattingT20* next;

    BattingT20()
    {
         name="\n";
        start=0;
         end=0;
         Mat=0;
        Inns=0;
        No=0;
         Runs=0;
         HS=" ";
        Ave=0;
        BF=0;
        SR=0;
       Centuries=0;
      Fifties=0;
        Zero=0;
        Four=0;
        Six=0;



        next = nullptr;
    }
    ~BattingT20(){
        delete next;
    }
};