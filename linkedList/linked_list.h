//
// Created by hasib on 9/23/22.
//

#pragma once
#include "node.h"
#include "string"
//class player;
#include "../player/player.h"
class linked_list {
public:
    node *start;
    node *last;
    node *loc;
    node *ploc;
    linked_list();



    bool isEmpty();

    void SwapNodes();

    void  Search(std::string );

    player * insert(player * );

    void InsertSorted(player *);

    void InsertAtLast(player *);
    void InsertAtStart(player *);

    void printList();

    void printListTestCentury();
    void printListTestCenturyGreater(int);


    ~linked_list();
};


