#include <iostream>
#include <fstream>
#include <cmath>
#include "intermediate_Fielding.h"
using namespace std;
class Fielding
{
public:
    string name="\n";
    string span="\n";
    int Mat=0;
    int Inns=0;
    int Dis=0;
    int Ct=0;
    int ST=0;
    int CT_WK=0;
    int CT_Fi=0;
    string MD="\n";
    float DI=0;
    Fielding* FieldingODI = NULL;
    Fielding* FieldingT20 = NULL;
    Fielding* FieldingTest = NULL;
    intermediate_Fielding* chain=NULL;
};