#include <iostream>
#include <fstream>
#include "intermediate_BowlingTest.h"
using namespace std;
class BowlingTest
{
public:
    string name="\n";
    string span="\n";
    int Mat=0;
    int Inns=0;
    int Balls=0;
    int Runs=0;
    int Wkts=0;
    string BBI="\n";
    string BBM="\n";
    float Ave=0;
    float Econ=0;
    float SR=0;
    int Four=0;
    int Five=0;
    intermediate_BowlingTest* chain=NULL;
};