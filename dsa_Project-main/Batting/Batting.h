#include <iostream>
#include <fstream>
#include "C:\Users\Ahmad\Desktop\DSA Project\BattingODI\BattingODI.h"
#include "C:\Users\Ahmad\Desktop\DSA Project\BattingTest\BattingTest.h"
#include "C:\Users\Ahmad\Desktop\DSA Project\BattingT20\BattingT20.h"
#include "intermediate_Batting.h"
using namespace std;
class Batting
{
public:
    string name = "\n";
    BattingODI* BaODI =NULL;
    BattingT20* BaT20 =NULL;
    BattingTest* BaTest =NULL;
    intermediate_Batting* chain =NULL;
};