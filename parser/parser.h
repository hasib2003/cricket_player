//
// Created by hasib on 12/30/22.
//

#ifndef IMPLEMENTATION_PARSER_H
#define IMPLEMENTATION_PARSER_H
#pragma once
#include "../player/player.h"
#include "../country/country.h"

#include "../player/hashTable.h"
#include "../country/countryHashTable.h"

#include "../BattingT20/BattingT20.h"

#include "../Batting/Batting_hashTable.h"
#include "../BattingT20/BattingT20_hashTable.h"
#include "../BattingODI/BattingODI_hashTable.h"
#include "../BattingTest/BattingTest_hashTable.h"
#include "../Bowling/Bowling_hashTable.h"
#include "../BowlingTest/BowlingTest_hashTable.h"
#include "../BowlingODI/BowlingODI_hashTable.h"
#include "../BowlingT20/BowlingT20_hashTable.h"
#include "../FieldingProfile/Fielding_hashTableProfile.h"
#include "../Fielding/Fielding_hashTable.h"

class parser {

public:
    std::string PATH;


    hashTable * playerTable;
    countryHashTable * countryTable;

    BattingT20_hashTable * t20Table;
    Batting_hashTable* battingTable;
    BattingODI_hashTable * odiBatTable;
    BattingTest_hashTable * testBatTable;

    Bowling_hashTable * bowlingHashTable;
    BowlingT20_hashTable * t20BowlTable;
    BowlingODI_hashTable * odiBowlTable;
    BowlingTest_hashTable * testBowlTable;


    FieldingProfile_hashTable * fieldTable;
    Fielding_hashTable * field20;
    Fielding_hashTable * fieldOdi;
    Fielding_hashTable * fieldTest;








    parser();
    void parse(); // to store data in hash tables

    country * insertCountry(std::string);


// three overloaded functions for each batting type
    player * insertPlayer(std::string,std::string,BattingT20);
    player * insertPlayer(std::string,std::string,BattingODI);
    player * insertPlayer(std::string,std::string,BattingTest);


// three overloaded functions for each bowling type
    player * insertPlayer(std::string,std::string,BowlingT20);
    player * insertPlayer(std::string,std::string,BowlingODI);
    player * insertPlayer(std::string,std::string,BowlingTest);

// three overloaded functions for each bowling type
    player * insertPlayer(std::string,std::string,Fielding,std::string);








    void mainMenu();

    // works for test only
    void getCenturyHolderBySpan();

    void getStrongTestCompetitors();

    void playerByCountry();

    void t20CenturyPlayers();

    void checkCenturies(BattingT20 *);
    void checkAVL(bst_node *);


    void testCenturyPlayers();
    void ODICenturyPlayers();
    void T20WicPlayers();
    void TestWicPlayers();
    void ODIWicPlayers();

    void checkCenturies(BattingTest*);
    void checkCenturies(BattingODI*);
    void CheckT20Wickets(BowlingT20*);
    void CheckTestWickets(BowlingTest*);
    void CheckODIWickets(BowlingODI*);







    int profilesMenu();
    int BattingMenu();

    void parseBatting();
    void parseFielding();
    void parseBowling();

    void parseBat20();
    void parseBatOdi();
    void parseBatTest();

    void parseField(std::string,std::string);


    void parseBowl20();
    void parseBowlOdi();
    void parseBowlTest();

    ~parser();






};


#endif //IMPLEMENTATION_PARSER_H













