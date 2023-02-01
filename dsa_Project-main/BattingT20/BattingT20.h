#include <iostream>
#include <fstream>
#include "intermediate_BattingT20.h"
using namespace std;
class BattingT20
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
    int Four=0;
    int Six=0;
    intermediate_BattingT20* chain=NULL;
};