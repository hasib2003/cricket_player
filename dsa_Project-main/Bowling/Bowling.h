#include <iostream>
#include <fstream>
#include "C:\Users\Ahmad\Desktop\DSA Project\BowlingODI\BowlingODI.h"
#include "C:\Users\Ahmad\Desktop\DSA Project\BowlingT20\BowlingT20.h"
#include "C:\Users\Ahmad\Desktop\DSA Project\BowlingTest\BowlingTest.h"
#include "intermediate_Bowling.h"
using namespace std;
class Bowling
{
public:

    string name="\n";
    BowlingODI* BowlODI=NULL;
    BowlingT20* BowlT20=NULL;
    BowlingTest* BoTest=NULL;
    intermediate_Bowling * chain=NULL;
};