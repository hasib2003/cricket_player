#include <iostream>
#include <fstream>
#include "C:\Users\Ahmad\Desktop\DSA Project\Batting\Batting.h"
#include "C:\Users\Ahmad\Desktop\DSA Project\Bowling\Bowling.h"
#include "C:\Users\Ahmad\Desktop\DSA Project\Fielding\Fielding.h"
using namespace std;

#include "player_intermediate.h"

class Player
{
public:
    string name;
    Batting* batting;
    Bowling* bowling;
    Fielding* fielding;

    intermediate_player * chain;

    Player(){
        chain = nullptr;
        batting = nullptr;
        bowling = nullptr;
        fielding = nullptr;
        name = "\n";

    }
    


};