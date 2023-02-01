//
// Created by hasib on 12/30/22.
//

#include "parser.h"
#include <iostream>

#include <fstream>
#include <vector>
#include <sstream>
#include "../linkedList/linked_list.h"
// all hash tables
#include "../player//hashTable.h"
#include "../country/countryHashTable.h"
#include "../Batting/Batting_hashTable.h"
#include "../BattingT20/BattingT20_hashTable.h"


#include "../Batting/Batting.h"
#include "../BattingT20/BattingT20.h"
#include "../BattingODI/BattingODI.h"

parser :: parser()
{

    // when ever we shall start to parse the hashTables shall
    //be instanciated automatically and the address of them stored in the
    //respective pointers


    // for players
    playerTable = new hashTable();

    // for country
    countryTable = new countryHashTable();

    // for batting profiles
    battingTable = new Batting_hashTable();
    t20Table = new BattingT20_hashTable();
    odiBatTable = new BattingODI_hashTable();
    testBatTable = new BattingTest_hashTable();

    // for bowling profiles
    bowlingHashTable = new Bowling_hashTable();
    t20BowlTable = new BowlingT20_hashTable();
    odiBowlTable = new BowlingODI_hashTable();
    testBowlTable = new BowlingTest_hashTable();

    // for fielding profiles
    fieldTable = new FieldingProfile_hashTable();
    field20 = new Fielding_hashTable();
    fieldOdi = new Fielding_hashTable();
    fieldTest = new Fielding_hashTable();



}




void parser::parse()

{
    // the order of calls is very important
    // program will not work if change
    // batting -> bowling ->fielding


    // to parse all files related to batting
    parseBatting();

    // to parse all files related to bowling
    parseBowling();

    // to parse all files related to fielding
    parseFielding();

    playerTable->maintainGraphLinks();
    // main menu for navigation and functions
    this->mainMenu();

}


void parser ::parseFielding() {

    // parse t20 fielding
    parseField("../data/Fielding/Fielding_t20.csv","20");
    parseField("../data/Fielding/Fielding_ODI.csv","50");
    parseField("../data/Fielding/Fielding_test.csv","test");
}

void parser ::parseField(std::string path,std::string mod)
{


    std::string fname;

    fname = path;


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file (fname,std::ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        std::cout<<"Could not open the file\n";


    int columns = content[0].size();
    country * currentCountry = nullptr;

    for(int i=1;i<content.size();i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 3);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        Fielding field;
        field.Mat = std::stoi(content[i][1]);
        field.Inns = std::stoi(content[i][2]);
        field.Dis = std::stoi(content[i][3]);
        field.Ct = std::stoi(content[i][5]);
        field.ST = std::stoi(content[i][6]);
        field.CT_WK= std::stoi(content[i][6]);
        field.CT_Fi =std::stoi(content[i][7]);
        field.MD = content[i][8];
        field.DI = std::stof(content[i][9]);

        field.start = std::stoi(start);
        field.end = std::stoi(end);
        field.name = name;



        this->insertPlayer(name, countryName, field, mod);

    }




}

void parser ::parseBowling()
{
    // the order of calls is very important
    // program will not work if change
    // 20 -> odi -> test
    this->parseBowl20();
    this->parseBowlOdi();
    this->parseBowlTest();
}

void parser ::parseBowl20()
{


    std::string fname;

    fname = "../data/Bowling/Bowling_t20.csv";


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file (fname,std::ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ';'))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        std::cout<<"Could not open the file\n";


    int columns = content[0].size();
    country * currentCountry = nullptr;

    for(int i=1;i<content.size();i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 3);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        BowlingT20 bowl20;
        bowl20.Mat = std::stoi(content[i][1]);
        bowl20.Inns = std::stoi(content[i][2]);
        bowl20.Overs = std::stof(content[i][3]);
        bowl20.Mdns = std::stoi(content[i][5]);
        bowl20.Runs = content[i][6];
        bowl20.Wkts = std::stoi(content[i][6]);
        bowl20.BBI =content[i][7];
        bowl20.Ave = std::stof(content[i][8]);
        bowl20.Econ = std::stof(content[i][9]);
        bowl20.SR = std::stof(content[i][10]);
        bowl20.Four = std::stoi(content[i][11]);
        bowl20.Five = std::stoi(content[i][12]);

        bowl20.start = std::stoi(start);
        bowl20.end = std::stoi(end);
        bowl20.name = name;



        this->insertPlayer(name, countryName, bowl20);

    }



}

void parser ::parseBowlOdi()
{

    std::string fname;

    fname = "../data/Bowling/Bowling_ODI.csv";


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file (fname,std::ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        std::cout<<"Could not open the file\n";


    int columns = content[0].size();
    country * currentCountry = nullptr;

    for(int i=1;i<content.size();i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 3);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        BowlingODI bowl50;
        bowl50.Mat = std::stoi(content[i][1]);
        bowl50.Inns = std::stoi(content[i][2]);
        bowl50.Balls = std::stof(content[i][3]);
        bowl50.Runs = content[i][4];
        bowl50.Wkts = std::stoi(content[i][5]);
        bowl50.BBI =content[i][6];
        bowl50.Ave = std::stof(content[i][7]);
        bowl50.Econ = std::stof(content[i][8]);
        bowl50.SR = std::stof(content[i][9]);
        bowl50.Four = std::stoi(content[i][10]);
        bowl50.Five = std::stoi(content[i][11]);

        bowl50.start = std::stoi(end);
        bowl50.end = std::stoi(start);
        bowl50.name = name;




        player *temp = this->insertPlayer(name, countryName, bowl50);
//        std::cout<<"on the last step from player table bowling averge "<<temp->bowlingProfiles->BowlT20->Ave<<std::endl;
    }



}


void parser ::parseBowlTest()
{

    std::string fname;

    fname = "../data/Bowling/Bowling_test.csv";


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file (fname,std::ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        std::cout<<"Could not open the file\n";


    int columns = content[0].size();
    country * currentCountry = nullptr;

    for(int i=1;i<content.size();i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 3);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        BowlingTest bowlTest;
        bowlTest.Mat = std::stoi(content[i][1]);
        bowlTest.Inns = std::stoi(content[i][2]);
        bowlTest.Balls = std::stof(content[i][3]);
        bowlTest.Runs = content[i][4];
        bowlTest.Wkts = std::stoi(content[i][5]);
        bowlTest.BBI =content[i][6];
        bowlTest.BBM =content[i][7];
        bowlTest.Ave = std::stof(content[i][8]);
        bowlTest.Econ = std::stof(content[i][9]);
        bowlTest.SR = std::stof(content[i][10]);
        bowlTest.Five = std::stoi(content[i][11]);
        bowlTest.Ten = std::stoi(content[i][12]);

        bowlTest.start = std::stoi(end);
        bowlTest.end = std::stoi(start);
        bowlTest.name = name;




        this->insertPlayer(name, countryName, bowlTest);
    }



}

void parser :: parseBat20()
{

    std::string fname;

    fname = "../data/Batting/t20.csv";


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file (fname,std::ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        std::cout<<"Could not open the file\n";


    int columns = content[0].size();
    country * currentCountry = nullptr;

    for(int i=1;i<content.size();i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 2);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        BattingT20 bt20;
        bt20.Mat = std::stoi(content[i][1]);
        bt20.No = std::stoi(content[i][3]);
        bt20.Inns = std::stoi(content[i][2]);
        bt20.Runs = std::stoi(content[i][4]);
        bt20.HS = content[i][5];
        bt20.Ave = std::stof(content[i][6]);
        bt20.BF = std::stoi(content[i][7]);
        bt20.SR = std::stof(content[i][8]);
        bt20.Centuries = std::stoi(content[i][9]);
        bt20.Fifties = std::stoi(content[i][10]);
        bt20.Zero = std::stoi(content[i][11]);
        bt20.Four = std::stoi(content[i][12]);
        bt20.Six = std::stoi(content[i][13]);
        bt20.start = std::stoi(start);
        bt20.end = std::stoi(end);
        bt20.name = name;

        this->insertPlayer(name, countryName, bt20);

    }




}


void parser ::parseBatOdi() {


    std::string fname;

    fname = "../data/Batting/odi.csv";


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file(fname, std::ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            std::stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    } else
        std::cout << "Could not open the file\n";


    int columns = content[0].size();
    country *currentCountry = nullptr;

    for (int i = 1; i < content.size(); i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 3);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        BattingODI bt50;
        bt50.Mat = std::stoi(content[i][1]);
        bt50.NO = std::stoi(content[i][3]);
        bt50.Inns = std::stoi(content[i][2]);
        bt50.Runs = std::stoi(content[i][4]);
        bt50.HS = content[i][5];
        bt50.Ave = std::stof(content[i][6]);
        bt50.BF = std::stoi(content[i][7]);
        bt50.SR = std::stof(content[i][8]);
        bt50.Centuries = std::stoi(content[i][9]);
        bt50.Fifties = std::stoi(content[i][10]);
        bt50.Zero = std::stoi(content[i][11]);
        bt50.start = std::stoi(start);
        bt50.end = std::stoi(end);
        bt50.name = name;


        this->insertPlayer(name, countryName, bt50);


    }
}


void parser ::parseBatTest()  {


    std::string fname;

    fname = "../data/Batting/test.csv";


    std::vector<std::vector<std::string>> content;

    std::vector<std::string> row;
    std::string line, word;

    std::fstream file(fname, std::ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            std::stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    } else
        std::cout << "Could not open the file\n";


    int columns = content[0].size();
    country *currentCountry = nullptr;

    for (int i = 1; i < content.size(); i++) {

        std::string name = content[i][columns - 2];
        name = name.substr(1, name.length() - 2);

        std::string countryName = content[i][columns - 1];
        countryName = countryName.substr(1, countryName.length() - 3);

        std::string start = content[i][columns - 3];
        std::string end = content[i][columns - 4];


        // encapsulating the attributes in the required object format


        BattingTest btTest;
        btTest.Mat = std::stoi(content[i][1]);

        btTest.Inns = std::stoi(content[i][2]);

        btTest.NO = std::stoi(content[i][3]);

        btTest.Runs = std::stoi(content[i][4]);
        btTest.HS = content[i][5];
        btTest.Ave = std::stof(content[i][6]);
        btTest.Centuries = std::stoi(content[i][7]);
        btTest.Fifties = std::stoi(content[i][8]);
        btTest.Zero = std::stoi(content[i][9]);
        btTest.end = std::stoi(start);
        btTest.start = std::stoi(end);
        btTest.name = name;


        this->insertPlayer(name, countryName, btTest);


    }
}

void parser ::parseBatting() {

    // the order of calls is very important
    // program will not work if change
    // 20 -> odi -> test

    parseBat20();
    parseBatOdi();
    parseBatTest();
}


// for inserting the t20 bat players
player * parser :: insertPlayer(std::string pname,
                                std::string country,
                                BattingT20 bt20 )
{
    // will help on multiple files if player name is already

    player * currentPlayer = playerTable->search(pname);

    if(!currentPlayer)
    {
        player p;

        Batting battingProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);

        // next all three batting profile shall be inserted into their respective table
        // the return values will be bound to the profile object

        battingProfiles.BaT20 = t20Table->insert(bt20,index);


        battingProfiles.name = pname;

        // profile object will be inserted into the Batting Table

        p.battingProfiles = battingTable->insert(battingProfiles,index);


//
        // finally the player object with links to all profiles will be inserted into player table;

//        p.Country->addPlayer(temp);

//        std::cout<<"after all insertions "<<temp->battingProfiles->BaT20->Runs<<std::endl;


        return (playerTable->insert(p));
    }
    else
    {
        return currentPlayer;

    }
}

// for inserting the Odi bat players overloaded
player * parser :: insertPlayer(std::string pname,
                                std::string country,
                                BattingODI bt50 )
{
    // will help on multiple files if player name is already



    player * currentPlayer = playerTable->search(pname);

    if(!currentPlayer)
    {
        player p;

        Batting battingProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);

        // next all three batting profile shall be inserted into their respective table
        // the return values will be bound to the profile object

        battingProfiles.BatODI = odiBatTable->insert(bt50,index);
        battingProfiles.name = pname;

        // profile object will be inserted into the Batting Table

        p.battingProfiles = battingTable->insert(battingProfiles,index);
//
        // finally the player object with links to all profiles will be inserted into player table;

//        p.Country->addPlayer(temp);

//        std::cout<<"after all insertions "<<temp->battingProfiles->BaT20->Runs<<std::endl;


        return (playerTable->insert(p));
    }
    else
    {
        if(currentPlayer->battingProfiles)
        {
            if(!currentPlayer->battingProfiles->BatODI)
//            if(battingTable->)
            {
                // means that profile exists but the ODI is not linked to profiles table

                // getting index from player table
                int index = playerTable->hashFunction(pname);

                BattingODI * odiProfile = odiBatTable->insert(bt50,index);

                // linking the odi profile to main profiles

                currentPlayer->battingProfiles->BatODI = odiProfile;



            }
        }


    }
}


// for inserting the Test bat players overloaded
player * parser :: insertPlayer(std::string pname,
                                std::string country,
                                BattingTest btTest )
{
    // will help on multiple files if player name is already

    player * currentPlayer = playerTable->search(pname);

    if(!currentPlayer)
    {

        player p;

        Batting battingProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);

        // next all three batting profile shall be inserted into their respective table
        // the return values will be bound to the profile object

        battingProfiles.BatTest = testBatTable->insert(btTest,index);
        battingProfiles.name = pname;

        // profile object will be inserted into the Batting Table

        p.battingProfiles = battingTable->insert(battingProfiles,index);



        return (playerTable->insert(p));
    }
    else
    {

        if(currentPlayer->battingProfiles)
        {

            if(!currentPlayer->battingProfiles->BatTest)
            {
                // means that profile exists but the Test is not linked to profiles table

                // getting index from player table
                int index = playerTable->hashFunction(pname);

                BattingTest* testProfile = testBatTable->insert(btTest,index);


                // linking the test profile to main profiles

                currentPlayer->battingProfiles->BatTest = testProfile;




                return currentPlayer;



            }

        }


    }
}




// insert functions for bowlings

player * parser ::insertPlayer(std::string pname, std::string country,
                               BowlingT20 bowl20)
{

    // will help on multiple files if player name is already

    player * currentPlayer = playerTable->search(pname);



    if(!currentPlayer)
    {
        player p;

        Bowling bowlingProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);

        // next all three bowling profile shall be inserted into their respective table
        // the return values will be bound to the profile object

        bowlingProfiles.BowlT20 = t20BowlTable->insert(bowl20,index);


        bowlingProfiles.name = pname;

        // profile object will be inserted into the bowling Table

        p.bowlingProfiles = bowlingHashTable->insert(bowlingProfiles,index);


//
        // finally the player object with links to all profiles will be inserted into player table;

//        p.Country->addPlayer(temp);

        player * temp = playerTable->insert(p);


        return (temp);
    }
    else
    {

        //the player exists but the bowling profile has to be attached
        // by the order in which we call the parsers, it will happen only
        // if the batting profile has been successfully attached


        // create bowling profile
        Bowling bowlingProfiles;


        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // insert t20bowl in its hashtable
        bowlingProfiles.BowlT20= t20BowlTable->insert(bowl20,index);

        bowlingProfiles.name = pname;


        // inserting the profile object that contains only the t20 bowling
        // into the hashtable and storing the result
        // into the existing player

        currentPlayer->bowlingProfiles = bowlingHashTable->insert(bowlingProfiles,index);


        return currentPlayer;






    }

}


player * parser ::insertPlayer(std::string pname, std::string country,
                               BowlingODI bowl50)
{

    // will help on multiple files if player name is already

    player * currentPlayer = playerTable->search(pname);

    if(!currentPlayer)
    {
        player p;

        Bowling bowlingProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);

        // next all three bowling profile shall be inserted into their respective table
        // the return values will be bound to the profile object

        bowlingProfiles.BowlODI = odiBowlTable->insert(bowl50,index);

        bowlingProfiles.name = pname;

        // profile object will be inserted into the bowling Table

        p.bowlingProfiles = bowlingHashTable->insert(bowlingProfiles,index);

//        std::cout<<"after the insertion of the bowling profile econ: "<<p.bowlingProfiles->BowlT20->Econ<<std::endl;

//
        // finally the player object with links to all profiles will be inserted into player table;

//        p.Country->addPlayer(temp);

//        std::cout<<"after all insertions "<<temp->battingProfiles->BaT20->Runs<<std::endl;


        return (playerTable->insert(p));
    }
    else
    {
        if(currentPlayer->bowlingProfiles)
        {

            // bowling profile exists

            // by the order in which we call the parsers it is
            // possible only if the batting profile has been attached
            // and the t2o bowling has also been attached

            // got index from hashfunction
            int index = playerTable->hashFunction(pname);

            // insert the odi bowl profile in its table and attach it
            // to the existing bowling profile of current player

            currentPlayer->bowlingProfiles->BowlODI;
            BowlingODI * temp = odiBowlTable->insert(bowl50,index);

            currentPlayer->bowlingProfiles->BowlODI = temp;
//            std::cout<<"temp "<<temp->Ave<<;
            return currentPlayer;

        }
        else
        {
            //the player exists and the bowling profile does not exist

            // by the order in which we call the parsers, it will happen only
            // if the batting profile has been successfully attached
            // and current player has no bowling record in t20.csv


            // create bowling profile
            Bowling bowlingProfiles;


            // getting index of the current player to save computation for each hashTable
            int index = playerTable->hashFunction(pname);




            bowlingProfiles.BowlODI = odiBowlTable->insert(bowl50,index);

            bowlingProfiles.name = pname;


            // inserting the profile object into the hashtable and storing the result
            // into the existing player

            currentPlayer->bowlingProfiles = bowlingHashTable->insert(bowlingProfiles,index);


        }

        return currentPlayer;

    }

}


player * parser ::insertPlayer(std::string pname, std::string country,
                               BowlingTest bowlTest)
{

    // will help on multiple files if player name is already

    player * currentPlayer = playerTable->search(pname);

    if(!currentPlayer)
    {
        player p;

        Bowling bowlingProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);

        // next all three bowling profile shall be inserted into their respective table
        // the return values will be bound to the profile object

        bowlingProfiles.BoTest = testBowlTable->insert(bowlTest,index);

        bowlingProfiles.name = pname;

        // profile object will be inserted into the bowling Table

        p.bowlingProfiles = bowlingHashTable->insert(bowlingProfiles,index);



        return (playerTable->insert(p));
    }
    else
    {
        if(currentPlayer->bowlingProfiles)
        {

            // bowling profile exists

            // by the order in which we call the parsers it is
            // possible only if the batting profile has been attached
            // and one among the t2o bowling or odi bowling  has also been attached
            // or both or them, but remaining shall be test only

            // got index from hashfunction
            int index = playerTable->hashFunction(pname);

            // insert the test bowl profile in its table and attach it
            // to the existing bowling profile of current player

            BowlingTest * temp = testBowlTable->insert(bowlTest,index);

            currentPlayer->bowlingProfiles->BoTest = temp;
            return currentPlayer;

        }
        else
        {
            //the player exists and the bowling profile does not exist

            // by the order in which we call the parsers, it will happen only
            // if the batting profile has been successfully attached
            // and current player has no bowling record in bowling_t20.csv and bowling_odi.csv


            // create bowling profile
            Bowling bowlingProfiles;


            // getting index of the current player to save computation for each hashTable
            int index = playerTable->hashFunction(pname);




            bowlingProfiles.BoTest = testBowlTable->insert(bowlTest,index);

            bowlingProfiles.name = pname;


            // inserting the profile object into the hashtable and storing the result
            // into the existing player

            currentPlayer->bowlingProfiles = bowlingHashTable->insert(bowlingProfiles,index);


        }

        return currentPlayer;

    }

}



// insert function for fielding

player * parser ::insertPlayer(std::string pname, std::string country,
                               Fielding field, std::string mod)
{

    // will help on multiple files if player name is already


    player * currentPlayer = playerTable->search(pname);

    if(!currentPlayer)
    {
        player p;

        FieldingProfile fieldProfiles;



        p.name = pname;

        // getting index of the current player to save computation for each hashTable
        int index = playerTable->hashFunction(pname);


        // first insert the country
        p.Country = this->insertCountry(country);



        // next all three fielding profile shall be inserted into their respective table
        // the return values will be bound to the profile object


        if (mod == "20") {

            fieldProfiles.FieldingT20 = field20->insert(field, index);

        }
        else if (mod == "50") {

            fieldProfiles.FieldingT20 = fieldOdi->insert(field, index);

        }
        else if (mod == "test") {

            fieldProfiles.FieldingT20 = fieldTest->insert(field, index);

        }

        fieldProfiles.name = pname;

        // profile object will be inserted into the fielding Table

        p.fieldingProfile = fieldTable->insert(fieldProfiles, index);

        return (playerTable->insert(p));
    }
    else
    {
        if(currentPlayer->fieldingProfile)
        {

            // bowling profile exists

            // by the order in which we call the parsers it is
            // possible only if the batting profile has been attached
            // and fieldind profile for one format has also been attached

            // got index from hashfunction
            int index = playerTable->hashFunction(pname);

            // insert the test bowl profile in its table and attach it
            // to the existing bowling profile of current player

            if (mod =="20")
            {
                Fielding * temp = field20->insert(field,index);


                currentPlayer->fieldingProfile->FieldingT20= temp;

            }


            else if (mod == "50") {

                Fielding * temp = fieldOdi->insert(field,index);


                currentPlayer->fieldingProfile->FieldingODI= temp;

            }
            else if (mod == "test") {

                Fielding * temp = fieldTest->insert(field,index);

                currentPlayer->fieldingProfile->FieldingTest= temp;

            }





            return currentPlayer;

        }
        else
        {
            //the player exists and the bowling profile does not exist

            // by the order in which we call the parsers, it will happen only
            // if the batting profile has been successfully attached
            // and bowling profile has also been attached


            // create bowling profile
            FieldingProfile fieldingProfile;


            // getting index of the current player to save computation for each hashTable
            int index = playerTable->hashFunction(pname);




            if (mod == "20")
            {
                fieldingProfile.FieldingT20 = field20->insert(field, index);
            }

            fieldingProfile.name = pname;


            // inserting the profile object into the hashtable and storing the result
            // into the existing player

            currentPlayer->fieldingProfile = fieldTable->insert(fieldingProfile,index);


        }

        return currentPlayer;

    }

}


country * parser:: insertCountry (std::string name)
{
    country * countryAddress =  countryTable->search(name);
    if(!countryAddress)
    {

        country temp;
        temp.name = name;
        countryAddress = countryTable->insert(temp);
    }

    return countryAddress;
}

void parser ::mainMenu() {
    int choice = 0;
    while (choice != -1) {
        std::cout<<std::endl;
        std::cout<<"-----------"<<std::endl<<std::endl;
        std::cout << "Press 1 to search player by name " << std::endl;
        std::cout << "Press 2 to get players by country " << std::endl;

        std::cout << "Press 3 to get players with centuries in t20 " << std::endl;
        std::cout << "Press 4 to get players with centuries in test " << std::endl;
        std::cout << "Press 5 to get players with centuries in ODI " << std::endl;
        std::cout << "Press 6 to get players with 5 wicket haul t20" << std::endl;
        std::cout << "Press 7 to get players with 10 wicket haul in test" << std::endl;
        std::cout << "Press 8 to get players with 5 wicket haul odi" << std::endl;




        std::cout << "Press 3 to get players with centuries in t20 " << std::endl;
        std::cout << "Press 10 to get players who scored centuries in same span as then entered player" << std::endl;
        std::cout << "Press 11 to get players who scored more centuries in test then entered player and are in same span " << std::endl;
        std::cout << "Press -1 to exit" << std::endl;
        std::cout<<"-----------"<<std::endl<<std::endl;
        std::cout<<"Enter : ";
        std::cin >> choice;

        if (choice == 1) {
            int choice2 = 0;
            std::string name;
            std::cout << "Enter the player name: " << std::endl;
            std::getline(std::cin >> std::ws, name);
            player *target = playerTable->search(name);
            if (target) {


                std::cout << "----------------" << std::endl;
                std::cout << "Name : " << target->name << std::endl;
                std::cout << "Country : " << target->Country->name << std::endl;
                std::cout << "----------------" << std::endl;


                std::cout << "Press 1 to see batting profiles" << std::endl;
                std::cout << "press 2 to see bowling profiles" << std::endl;
                std::cout << "press 3 to see Fielding profiles" << std::endl;
                std::cout << "press : ";

                std::cin >> choice2;


                if (choice2 == 1) {
                    std::cout << "Press 1 to see t20 profile" << std::endl;
                    std::cout << "Press 2 to see odi profile" << std::endl;
                    std::cout << "Press 3 to see test profile" << std::endl;
                    int choice3;
                    std::cin >> choice3;
                    if (choice3 == 1) {
                        if (target->battingProfiles->BaT20) {
                            std::cout << "----------------" << std::endl;


                            std::cout << "Start: " << target->battingProfiles->BaT20->start << std::endl;
                            std::cout << "End: " << target->battingProfiles->BaT20->end << std::endl;
                            std::cout << "Runs : " << target->battingProfiles->BaT20->Runs << std::endl;
                            std::cout << "Matches : " << target->battingProfiles->BaT20->Mat << std::endl;
                            std::cout << "Innings : " << target->battingProfiles->BaT20->Inns << std::endl;
                            std::cout << "Average : " << target->battingProfiles->BaT20->Ave << std::endl;
                            std::cout << "Centuries : " << target->battingProfiles->BaT20->Centuries << std::endl;
                            std::cout << "Fifties : " << target->battingProfiles->BaT20->Fifties << std::endl;
                            std::cout << "Average : " << target->battingProfiles->BaT20->Ave << std::endl;

                            std::cout << "Highest Run : " << target->battingProfiles->BaT20->HS << std::endl;
                            std::cout << "BF : " << target->battingProfiles->BaT20->BF << std::endl;
                            std::cout << "Strike Rate : " << target->battingProfiles->BaT20->SR << std::endl;
                            std::cout << "Zeros : " << target->battingProfiles->BaT20->Zero << std::endl;
                            std::cout << "Sixes : " << target->battingProfiles->BaT20->Six << std::endl;
                            std::cout << "Four : " << target->battingProfiles->BaT20->Four << std::endl;

                            std::cout << "----------------" << std::endl;
                        }


                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }

                    } else if (choice3 == 2) {

                        if (target->battingProfiles->BatODI) {
                            std::cout << "----------------" << std::endl;


                            std::cout << "Start: " << target->battingProfiles->BatODI->start << std::endl;
                            std::cout << "End: " << target->battingProfiles->BatODI->end << std::endl;
                            std::cout << "Runs : " << target->battingProfiles->BatODI->Runs << std::endl;
                            std::cout << "Matches : " << target->battingProfiles->BatODI->Mat << std::endl;
                            std::cout << "Innings : " << target->battingProfiles->BatODI->Inns << std::endl;
                            std::cout << "Average : " << target->battingProfiles->BatODI->Ave << std::endl;
                            std::cout << "Centuries : " << target->battingProfiles->BatODI->Centuries << std::endl;
                            std::cout << "Fifties : " << target->battingProfiles->BatODI->Fifties << std::endl;
                            std::cout << "Average : " << target->battingProfiles->BatODI->Ave << std::endl;

                            std::cout << "Highest Run : " << target->battingProfiles->BatODI->HS << std::endl;
                            std::cout << "BF : " << target->battingProfiles->BatODI->BF << std::endl;
                            std::cout << "Strike Rate : " << target->battingProfiles->BatODI->SR << std::endl;
                            std::cout << "Zeros : " << target->battingProfiles->BatODI->Zero << std::endl;

                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }

                    } else if (choice3 == 3) {
                        if (target->battingProfiles->BatTest) {

                            std::cout << "----------------" << std::endl;
                            std::cout << "Start: " << target->battingProfiles->BatTest->start << std::endl;
                            std::cout << "End: " << target->battingProfiles->BatTest->end << std::endl;
                            std::cout << "Runs : " << target->battingProfiles->BatTest->Runs << std::endl;
                            std::cout << "Matches : " << target->battingProfiles->BatTest->Mat << std::endl;
                            std::cout << "Innings : " << target->battingProfiles->BatTest->Inns << std::endl;
                            std::cout << "Average : " << target->battingProfiles->BatTest->Ave << std::endl;
                            std::cout << "Centuries : " << target->battingProfiles->BatTest->Centuries << std::endl;
                            std::cout << "Fifties : " << target->battingProfiles->BatTest->Fifties << std::endl;
                            std::cout << "Average : " << target->battingProfiles->BatTest->Ave << std::endl;

                            std::cout << "Highest Run : " << target->battingProfiles->BatTest->HS << std::endl;
                            std::cout << "Zeros : " << target->battingProfiles->BatTest->Zero << std::endl;

                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }



                    }
                } else if (choice2 == 2) {
                    std::cout << "Press 1 to see t20 profile" << std::endl;
                    std::cout << "Press 2 to see odi profile" << std::endl;
                    std::cout << "Press 3 to see test profile" << std::endl;
                    int choice3;
                    std::cin >> choice3;
                    if (choice3 == 1) {

                        if (target->bowlingProfiles->BowlT20) {
                            std::cout << "----------------" << std::endl;

                            std::cout << "Start: " << target->bowlingProfiles->BowlT20->start << std::endl;
                            std::cout << "End: " << target->bowlingProfiles->BowlT20->end << std::endl;
                            std::cout << "Runs : " << target->bowlingProfiles->BowlT20->Runs << std::endl;
                            std::cout << "Matches : " << target->bowlingProfiles->BowlT20->Mat << std::endl;
                            std::cout << "Innings : " << target->bowlingProfiles->BowlT20->Inns << std::endl;
                            std::cout << "Maidens : " << target->bowlingProfiles->BowlT20->Mdns << std::endl;
                            std::cout << "Wickets : " << target->bowlingProfiles->BowlT20->Wkts << std::endl;
                            std::cout << "Best : " << target->bowlingProfiles->BowlT20->BBI << std::endl;
                            std::cout << "Average : " << target->bowlingProfiles->BowlT20->Ave << std::endl;

                            std::cout << "Economy : " << target->bowlingProfiles->BowlT20->Econ << std::endl;
                            std::cout << "Fivers : " << target->bowlingProfiles->BowlT20->Five << std::endl;
                            std::cout << "Fours : " << target->bowlingProfiles->BowlT20->Four << std::endl;
                            std::cout << "Strike Rate : " << target->bowlingProfiles->BowlT20->SR << std::endl;


                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }


                    } else if (choice3 == 2) {

                        if (target->bowlingProfiles->BowlODI) {
                            std::cout << "----------------" << std::endl;
                            std::cout << "Start: " << target->bowlingProfiles->BowlODI->start << std::endl;
                            std::cout << "End: " << target->bowlingProfiles->BowlODI->end << std::endl;
                            std::cout << "Runs : " << target->bowlingProfiles->BowlODI->Runs << std::endl;
                            std::cout << "Matches : " << target->bowlingProfiles->BowlODI->Mat << std::endl;
                            std::cout << "Innings : " << target->bowlingProfiles->BowlODI->Inns << std::endl;
                            std::cout << "Average : " << target->bowlingProfiles->BowlODI->Ave << std::endl;
                            std::cout << "Economy : " << target->bowlingProfiles->BowlODI->Econ << std::endl;
                            std::cout << "Fivers  : " << target->bowlingProfiles->BowlODI->Five << std::endl;
                            std::cout << "Fours  : " << target->bowlingProfiles->BowlODI->Four << std::endl;

                            std::cout << "Wickets : " << target->bowlingProfiles->BowlODI->Wkts << std::endl;
                            std::cout << "Best : " << target->bowlingProfiles->BowlODI->BBI << std::endl;
                            std::cout << "Strike Rate : " << target->bowlingProfiles->BowlODI->SR << std::endl;

                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }


                    }
                    else if (choice3 == 3) {

                        if (target->bowlingProfiles->BoTest) {
                            std::cout << "----------------" << std::endl;
                            std::cout << "Start: " << target->bowlingProfiles->BoTest->start << std::endl;
                            std::cout << "End: " << target->bowlingProfiles->BoTest->end << std::endl;
                            std::cout << "Runs : " << target->bowlingProfiles->BoTest->Runs << std::endl;
                            std::cout << "Matches : " << target->bowlingProfiles->BoTest->Mat << std::endl;
                            std::cout << "Innings : " << target->bowlingProfiles->BoTest->Inns << std::endl;
                            std::cout << "Best Figures in Match : " << target->bowlingProfiles->BoTest->BBM
                                      << std::endl;
                            std::cout << "Wickets : " << target->bowlingProfiles->BoTest->Wkts << std::endl;
                            std::cout << "Best Figures in Innings : " << target->bowlingProfiles->BoTest->BBI
                                      << std::endl;
                            std::cout << "Average : " << target->bowlingProfiles->BoTest->Ave << std::endl;

                            std::cout << "Economy : " << target->bowlingProfiles->BoTest->Econ << std::endl;
                            std::cout << "Fivers : " << target->bowlingProfiles->BoTest->Five << std::endl;
                            std::cout << "Fours : " << target->bowlingProfiles->BoTest->Ten << std::endl;
                            std::cout << "Strike Rate : " << target->bowlingProfiles->BoTest->SR << std::endl;


                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }

                    }


                }
                else if (choice2 == 3) {
                    std::cout << "Press 1 to see t20 profile" << std::endl;
                    std::cout << "Press 2 to see odi profile" << std::endl;
                    std::cout << "Press 3 to see test profile" << std::endl;
                    int choice3;
                    std::cin >> choice3;
                    if (choice3 == 1) {
                        std::cout << "----------------" << std::endl;

                        if (target->fieldingProfile->FieldingT20) {

                            std::cout << "Start: " << target->fieldingProfile->FieldingT20->start << std::endl;
                            std::cout << "End: " << target->fieldingProfile->FieldingT20->end << std::endl;
                            std::cout << "Matches : " << target->fieldingProfile->FieldingT20->Mat << std::endl;
                            std::cout << "Innings : " << target->fieldingProfile->FieldingT20->Inns << std::endl;
                            std::cout << "D/I : " << target->fieldingProfile->FieldingT20->DI << std::endl;
                            std::cout << "MD : " << target->fieldingProfile->FieldingT20->MD << std::endl;
                            std::cout << "CT FI : " << target->fieldingProfile->FieldingT20->CT_Fi << std::endl;
                            std::cout << "CT WK : " << target->fieldingProfile->FieldingT20->CT_WK << std::endl;
                            std::cout << "ST : " << target->fieldingProfile->FieldingT20->ST << std::endl;
                            std::cout << "CT : " << target->fieldingProfile->FieldingT20->Ct << std::endl;
                            std::cout << "DIS : " << target->fieldingProfile->FieldingT20->Dis << std::endl;

                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }


                    }
                    else if (choice3 == 2) {

                        if (target->fieldingProfile->FieldingODI) {
                            std::cout << "----------------" << std::endl;

                            std::cout << "Start: " << target->fieldingProfile->FieldingODI->start << std::endl;
                            std::cout << "End: " << target->fieldingProfile->FieldingODI->end << std::endl;
                            std::cout << "Matches : " << target->fieldingProfile->FieldingODI->Mat << std::endl;
                            std::cout << "Innings : " << target->fieldingProfile->FieldingODI->Inns << std::endl;
                            std::cout << "D/I : " << target->fieldingProfile->FieldingODI->DI << std::endl;
                            std::cout << "MD : " << target->fieldingProfile->FieldingODI->MD << std::endl;
                            std::cout << "CT FI : " << target->fieldingProfile->FieldingODI->CT_Fi << std::endl;
                            std::cout << "CT WK : " << target->fieldingProfile->FieldingODI->CT_WK << std::endl;
                            std::cout << "ST : " << target->fieldingProfile->FieldingODI->ST << std::endl;
                            std::cout << "CT : " << target->fieldingProfile->FieldingODI->Ct << std::endl;
                            std::cout << "DIS : " << target->fieldingProfile->FieldingODI->Dis << std::endl;

                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }

                    }
                    else if (choice3 == 3) {
                        if (target->fieldingProfile->FieldingTest) {

                            std::cout << "Start: " << target->fieldingProfile->FieldingTest->start << std::endl;
                            std::cout << "End: " << target->fieldingProfile->FieldingTest->end << std::endl;
                            std::cout << "Matches : " << target->fieldingProfile->FieldingTest->Mat << std::endl;
                            std::cout << "Innings : " << target->fieldingProfile->FieldingTest->Inns << std::endl;
                            std::cout << "D/I : " << target->fieldingProfile->FieldingTest->DI << std::endl;
                            std::cout << "MD : " << target->fieldingProfile->FieldingTest->MD << std::endl;
                            std::cout << "CT FI : " << target->fieldingProfile->FieldingTest->CT_Fi << std::endl;
                            std::cout << "CT WK : " << target->fieldingProfile->FieldingTest->CT_WK << std::endl;
                            std::cout << "ST : " << target->fieldingProfile->FieldingTest->ST << std::endl;
                            std::cout << "CT : " << target->fieldingProfile->FieldingTest->Ct << std::endl;
                            std::cout << "DIS : " << target->fieldingProfile->FieldingTest->Dis << std::endl;

                            std::cout << "----------------" << std::endl;
                        }
                        else {
                            std::cout << "profile does not exist" << std::endl;
                        }
                    }

                }
                else if (choice2 == -1) {
                    break;
                }
            } else {
                std::cout << "Player does not exists" << std::endl;
                continue;
            }

        }
        else if (choice == 2) {
            playerByCountry();
        }

        else if (choice == 3)
        {
            t20CenturyPlayers();
        }

        else if (choice==4)
        {
            testCenturyPlayers();
        }

        else if (choice==5)
        {
            ODICenturyPlayers();
        }
        else if (choice==6)
        {
            T20WicPlayers();
        }

        else if(choice==7)
        {

            TestWicPlayers();

        }

        else if (choice==8)
        {
            ODIWicPlayers();

        }

        else if (choice == 10)
        {
            this->getCenturyHolderBySpan();
        }        else if (choice == 11)
        {
            this->getStrongTestCompetitors();
        }

    }

}








int parser ::profilesMenu()
{
    int choice = 0;
    std::cout << "Press 1 to see Batting Profile: " << std::endl;
    std::cout << "Press 2 to see Bowling Profile: " << std::endl;
    std::cout << "Press 3 to see Fielding Profile: " << std::endl;
    std::cout << "Press -1 to exit" << std::endl;

    std::cin>>choice;

    if (choice == -1)
    {
        return -1;
    }
    else if (choice == 1)
    {

    }

}

parser :: ~parser()
{
    delete playerTable;
    delete countryTable;
    delete battingTable;
    delete t20Table;
}



// project functions

// get all players of a country
void parser ::playerByCountry()
{
    std::string target = " ";
    std::cout<<"Enter the country Name :";
    std::cin>>target;

    country * result= countryTable->search(target);
    if(result)
    {
        result->targetPlayers->printList();
    }
    else
    {
        std::cout<<" No such country in our records"<<std::endl;
    }

}

void parser ::t20CenturyPlayers() {

    // itereating through the hashTable
for (int i=0;i<playerTable->hashSize; i++)
{
    // checking if the index is used


    if (playerTable->base[i].name !="\n")
    {
        // we dont have default value

        if(playerTable->base[i].battingProfiles && playerTable->base[i].battingProfiles->BaT20){
        checkCenturies(playerTable->base[i].battingProfiles->BaT20);
            }

        // checking if we have any collsions at that index

        if (playerTable->base[i].next)
        {
            // there exists a chain

            bst_node * avlNode = playerTable->base[i].next->chain;

            checkAVL(avlNode);




        }



    }
    }
}



void parser :: checkAVL(bst_node * root)

{
    if(root)
    {
        if(root->battingProfiles && root->battingProfiles->BaT20) {
            checkCenturies(root->battingProfiles->BaT20);
        }

        checkAVL(root->leftChild);
        checkAVL(root->rightChild);
    }
}
void parser :: checkCenturies(BattingT20 * bat20)
{
    if (bat20) {
        int centuries = bat20->Centuries;
        if (centuries > 0) {
            std::cout << bat20->name << ": " << centuries <<" || ";
        }
    }
}


void parser ::getCenturyHolderBySpan() {
    std::string target = " ";
    std::cout<<"Enter the player name: ";
    getline(std::cin>>std::ws,target);


    player * tar = playerTable->search(target);
    if(tar )
    {
        if(tar->battingProfiles->BatTest) {
            std::cout << "following is the list of all players who scored centuries in test and have overlapping span"
                      << std::endl;
            tar->inSpanPlayers->printListTestCentury();
        }
    }
    else
    {
        std::cout<<"player doest not exist is our record "<<std::endl;
    }
}

void parser ::getStrongTestCompetitors() {
    std::string target = " ";
    std::cout<<"Enter the player name: ";
    getline(std::cin>>std::ws,target);


    player * tar = playerTable->search(target);
    if(tar )
    {
        if(tar->battingProfiles->BatTest) {
            std::cout << "following is the list of all players who scored more centuries in test than "<< tar->name<<" and have overlapping span"
                      << std::endl;
            std::cout<<"-> "<<tar->battingProfiles->BatTest->Centuries<<std::endl;
            tar->inSpanPlayers->printListTestCenturyGreater(tar->battingProfiles->BatTest->Centuries);
        }
    }
    else
    {
        std::cout<<"player doest not exist is our record "<<std::endl;
    }
}




void parser :: checkCenturies(BattingTest * batTest)
{
    if (batTest) {
        int centuries = batTest->Centuries;
        if (centuries > 0) {
            std::cout << batTest->name << ": " << centuries <<" || ";
        }
    }
}







void parser::testCenturyPlayers() {
    for (int i = 0; i < playerTable->hashSize; i++) {
        if (playerTable->base[i].name != "\n") {
            // we dont have default value

            if (playerTable->base[i].battingProfiles && playerTable->base[i].battingProfiles->BatTest) {
                checkCenturies(playerTable->base[i].battingProfiles->BatTest);
            }


            if (playerTable->base[i].next)
            {
                // there exists a chain

                bst_node * avlNode = playerTable->base[i].next->chain;

                checkAVL(avlNode);

            }


        }
    }

}



void parser::ODICenturyPlayers()  {
    for (int i = 0; i < playerTable->hashSize; i++) {
        if (playerTable->base[i].name != "\n") {
            // we dont have default value

            if (playerTable->base[i].battingProfiles && playerTable->base[i].battingProfiles->BatODI) {
                checkCenturies(playerTable->base[i].battingProfiles->BatODI);
            }


            if (playerTable->base[i].next)
            {
                // there exists a chain

                bst_node * avlNode = playerTable->base[i].next->chain;

                checkAVL(avlNode);

            }


        }
    }

}


void parser :: checkCenturies(BattingODI * BatODI)
{
    if (BatODI) {
        int centuries = BatODI->Centuries;
        if (centuries > 0) {
            std::cout << BatODI->name << ": " << centuries <<" || ";
        }
    }
}

void parser ::CheckT20Wickets( BowlingT20 * BowlT20) {
    if (BowlT20) {
        if (BowlT20->Five>0) {
            std::cout << BowlT20->name << ": " << BowlT20->Five <<" || ";
        }
    }
}



void parser ::CheckTestWickets(BowlingTest * BoTest) {
    if (BoTest) {
        if (BoTest->Ten>0) {
            std::cout << BoTest->name << ": " << BoTest->Ten <<" || ";
        }
    }
}


void parser ::CheckODIWickets(BowlingODI * BowlODI)  {
    if (BowlODI) {
        if (BowlODI->Five>0) {
            std::cout << BowlODI->name << ": " << BowlODI->Five <<" || ";
        }
    }
}




void parser::T20WicPlayers()   {
    for (int i = 0; i < playerTable->hashSize; i++) {
        if (playerTable->base[i].name != "\n") {
            // we dont have default value

            if (playerTable->base[i].bowlingProfiles && playerTable->base[i].bowlingProfiles->BowlT20) {
                CheckT20Wickets(playerTable->base[i].bowlingProfiles->BowlT20);
            }


            if (playerTable->base[i].next)
            {
                // there exists a chain

                bst_node * avlNode = playerTable->base[i].next->chain;

                checkAVL(avlNode);

            }


        }
    }

}




void parser::TestWicPlayers()    {
    for (int i = 0; i < playerTable->hashSize; i++) {
        if (playerTable->base[i].name != "\n") {
            // we dont have default value

            if (playerTable->base[i].bowlingProfiles && playerTable->base[i].bowlingProfiles->BoTest) {
                CheckTestWickets(playerTable->base[i].bowlingProfiles->BoTest);
            }


            if (playerTable->base[i].next)
            {
                // there exists a chain

                bst_node * avlNode = playerTable->base[i].next->chain;

                checkAVL(avlNode);

            }


        }
    }

}



void parser::ODIWicPlayers()      {
    for (int i = 0; i < playerTable->hashSize; i++) {
        if (playerTable->base[i].name != "\n") {
            // we dont have default value

            if (playerTable->base[i].bowlingProfiles && playerTable->base[i].bowlingProfiles->BowlODI) {
                CheckODIWickets(playerTable->base[i].bowlingProfiles->BowlODI);
            }


            if (playerTable->base[i].next)
            {
                // there exists a chain

                bst_node * avlNode = playerTable->base[i].next->chain;

                checkAVL(avlNode);

            }


        }
    }

}