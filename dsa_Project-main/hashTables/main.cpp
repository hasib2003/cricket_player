#include <iostream>
#include "hashTable.h"

#include <fstream>
#include <vector>
#include <sstream>

#include "player.h"
using namespace std;
int main() {

    hashTable h;
    player p;

    string fname;
//    cout<<"Enter the file name: ";
//    cin>>fname;
    fname = "t20.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";

    for(int i=0;i<content.size();i++)
    {

        p.name = content[i][1];
        p.span= content[i][2];

        h.insert(p);

    }

    string s;
    while (s!="-1")
    {
        std::cout<<"Enter the player name to search";
        getline(cin >> ws,s);
        h.search(s);
    std::cin>>s;

    }




//player p;



    return 0;
}

