#include <iostream>
#include <fstream>
#include "intermediate_BattingODI.h"
using namespace std;
class BattingODI
{
public:
    string name="\n";
    string span="\n";
    int Mat=0;
    int Inns=0;
    int NO=0;
    int Runs=0;
    int HS=0;
    float Ave=0;
    int BF=0;
    float SR=0;
    int Centuries=0;
    int Fifties=0;
    int Zero=0;
    intermediate_BattingODI* chain=NULL;
};