//
// Created by hasib on 9/23/22.
//

#include "linked_list.h"
#include "node.h"
#include <iostream>
bool linked_list::isEmpty() {
    return start == nullptr;
}
linked_list::linked_list() {
    start = nullptr;
    last = nullptr;
}

player *linked_list::insert(player * tar)
{

    Search(tar->name);

    if(!loc) {
        node *temp = new node();
        temp->target = tar;
        temp->next = nullptr;
        if (last) {
            last->next = temp;
        } else {
            last = temp;
        }
        if (!start) {
            start = temp;
        }
    }




}

void linked_list ::InsertAtStart(player * value) {
    node * nn = new node();
    nn->target = value;
    if(isEmpty()){
        start = nn;
        last = nn;
        nn->next = nullptr;
    }
    else{
        nn->next = start;
        start = nn;
    }
}
void linked_list::InsertAtLast(player *value) {
    node * nn = new node();
    nn->target = value;
    if (isEmpty()){
        start = nn;
        last = nn;
        nn->next = nullptr;

    }
    else{
        last->next = nn;
        last = nn;
    }



}

void linked_list ::InsertSorted(player *  value) {
    if (!isEmpty()) {
        Search(value->name);
        if (loc == nullptr) {
            if (ploc != nullptr) {
                if (ploc == last) {
                    InsertAtLast(value);
                }
                else {
                    node *nn = new node();
                    nn->target = value;
                    nn->next = ploc->next;
                    ploc->next = nn;
                }


            } else {
                InsertAtStart(value);
            }


        }
    }
    else {
        InsertAtStart(value);
    }

}


void linked_list ::Search(std::string value) {

    if (!isEmpty()) {
        loc = start;
        ploc = nullptr;
        while (loc != nullptr && loc->target->name < value) {
            ploc = loc;
            loc = loc->next;
        }

        if(ploc!=last)
        {
            if (loc->target->name != value)
            {
                loc = nullptr;

            }


        }



    }
    else{
        std::cout<<"error:the list is empty"<<std::endl;
    }
}





linked_list:: ~linked_list(){
    std::cout<<"dynamically deleted: ";
    while (start!=nullptr){
        node *loc = start;
        start = start->next;
        std::cout<<loc->target<<" ";
        delete loc;

    }
    last = nullptr;

}


// project functions
void linked_list ::printList() {

    if (!start)
    {
        std::cout<<"no player of this country"<<std::endl;
    }
    else
    {
        std::cout<<"players: "<<std::endl;

    }

    loc = start;
    while (loc)
    {

        std::cout<<loc->target->name<<" || ";
        loc = loc->next;
    }

    std::cout<<endl;


}// project functions
void linked_list ::printListTestCentury()  {

    if (!start)
    {
        std::cout<<"no player for this request"<<std::endl;
    }
    else {

        std::cout<<"-----------"<<std::endl<<std::endl;
        loc = start;
        while (loc) {

            int cent = loc->target->battingProfiles->BatTest->Centuries;
            if (cent > 2) {
                std::cout << loc->target->name << " " << cent<<" || ";
            }
            loc = loc->next;
        }
        std::cout<<"-----------"<<std::endl<<std::endl;
        std::cout << endl;
    }


}
void linked_list :: printListTestCenturyGreater(int val){
    if (!start)
    {
        std::cout<<"no player for this request"<<std::endl;
    }
    else {


        int odd = 0;
        loc = start;
        std::cout<<"-----------"<<std::endl<<std::endl;
        while (loc) {

            int cent = loc->target->battingProfiles->BatTest->Centuries;
            if (cent > val) {
                std::cout << loc->target->name << " " << cent << " || ";
            }
            loc = loc->next;
            odd ++;
        }
        std::cout << endl;

        std::cout<<"-----------"<<std::endl<<std::endl;
    }

}