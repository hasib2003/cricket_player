//
// Created by hasib on 12/25/22.
//
#include "hashTable.h"
#include "../linkedList/linked_list.h"
hashTable::hashTable()
{
    max =0;
    hashSize = 0;
    Pcollision = 0;
    hashSize = 4600;

    base = new player[hashSize];


}



int hashTable::hashFunction(std::string name)
{

    char * arr = &name[0];

    unsigned long long int initialKey = 0;

    int t1 = 0;
    unsigned long long int t2 = 0;
    for (int ind=0;ind<name.length();ind++)
    {
//            std::cout<<"i->"<<ind<<std::endl;
        t2 = pow(2,ind);

        if(arr[ind] == ' ')
        {
            continue;
        }

        t1 = int(arr[ind]);
        initialKey +=   t1 * t2 ;
    }



//        long double inter =3-logl (1 + logl(0.5 +  logl(  logl(initialKey))));
    long double inter =3-logl (1 + logl(0.5 +  logl(  logl(initialKey))));
    initialKey = abs(int(pow(hashSize,inter) - hashSize) % hashSize);
    return  initialKey;



}


player * hashTable::insert(player p)
{


    int index = hashFunction(p.name);



    // we shall insert into the table only if the name value is default value or
    if(base[index].name=="\n")
    {
        base[index].name = p.name;
        base[index].Country = p.Country;
        base[index].battingProfiles = p.battingProfiles;


        if(p.Country->targetPlayers)
        {
            p.Country->targetPlayers->InsertSorted(&base[index]);
        }
        else {

            linked_list *currentList = new linked_list();
            p.Country->targetPlayers = currentList;
            currentList->InsertSorted(&base[index]);
        }

        return &base[index];


    }
    else
    {
//            std::cout<<"current collision "<<Pcollision<<std::endl;
        Pcollision ++;

        return (chaining(index,p));



    }

}


player *  hashTable::chaining(int index,player p)
{
    if(base[index].next)
    {
//            std::cout<<"inserting at leave"<<std::endl;
        avl tree;
        tree.root = base[index].next->chain;

        return (tree.InsertWithoutDuplication(p)) ;


    }
    else
    {
//            std::cout<<"inserting at root"<<std::endl;

        intermediate *inter = new intermediate();
        base[index].next = inter;

        avl *tree = new avl();

        player*  temp = nullptr;
        temp =tree->InsertWithoutDuplication(p);


        inter->chain = tree->root;
        return(temp);

    }
}

player *  hashTable::search(std::string name,std::string Country)
{

//        std::cout<<"searching "<<name<<std::endl;
    int index = hashFunction(name);
    // additional check based on country

//    std::cout<<"Currently at base index "<<base[index].name<<std::endl;
    // will return true only if name is same and country is also same
    if(base[index].name == name && Country == base[index].Country->name)
    {
        return &base[index];
    }
    else
    {
//            std::cout<<"searching in avl"<<name<<std::endl;

        avl tree;
        if(base[index].next)
        {
//                std::cout<<"searching in avl with root "<<base[index].next->chain->name<<std::endl;

            tree.root = base[index].next->chain;
            player * temp = tree.search(name);

            // if both the country name and the name is matched
            if (temp->Country->name == Country)
            {
                return temp;
            }
            else
            {
                // name is matched and country name is not
                return nullptr;
            }

        }
        else
        {
//                std::cout<<"not in avl"<<name<<std::endl;

            return nullptr;
        }
    }
}

player * hashTable::search(std::string name)
{
    int index = hashFunction(name);
    // additional check based on strike rate


    // will return true only if name is same and country is also same
    if(base[index].name == name)
    {
        return &base[index];
    }
    else
    {
        avl tree;
        if(base[index].next)
        {
            tree.root = base[index].next->chain;
            player * temp = tree.search(name);

            // if both the country name and the name is matched
            return  temp;

        }
        else
        {

            return nullptr;
        }
    }
}











void hashTable ::maintainGraphLinks()

// will create a linked list in front of every player , containing nodes that
// point to all those players who have overlapping span of playing (in this dataset)

{

iterator();

}

void hashTable :: checkAVL(bst_node * root,player * target)

{
    // calling linker on required nodes recursively
    if(root)
    {
        if(root->battingProfiles && root->battingProfiles->BatTest) {


            if (root->name =="Majid Khan")
            {
                std::cout<<"hit"<<std::endl;
            }
            linker(root);
        }

        checkAVL(root->leftChild,root);
        checkAVL(root->rightChild,root);
    }
}


void hashTable :: iterator()
{

    // iterate over all values in the player hashTable


    for (int i=0;i<this->hashSize; i++)
    {
        // checking if the index is used
//


        if (this->base[i].name !="\n")
        {

            // we dont have default value so a player exists here

            // checking weather a player has test profile or not

            if(this->base[i].battingProfiles && this->base[i].battingProfiles->BatTest)
            {
//                BattingTest * target = this->base[i].battingProfiles->BatTest;

                // calling linker to find related players
                linker(&base[i]);
            }

            // checking if we have any collisions at that index

            if (this->base[i].next)
            {

                // there exists a chain
//                if(this->base[i].battingProfiles && this->base[i].battingProfiles->BatTest) {

                    bst_node *avlNode = this->base[i].next->chain;
                    checkAVL(avlNode, &base[i]);



                                                            //                }





            }



        }
    }


}

void hashTable ::linker(player * target) {

    for (int i = 0; i < this->hashSize; i++) {
        // checking if the index is used

        if (this->base[i].name != "\n") {
            // we dont have default value so a player exists here
            if(target->name == "Majid Khan")
            {
                std::cout<<"hit 2";
            }

            // checking weather a player has test profile or not

            if (this->base[i].battingProfiles && this->base[i].battingProfiles->BatTest)
                // this player has to linked with target if matches condition
            {

                linkerHelper(&base[i], target);


                // checking if there are any collisions at this place

                if (this->base[i].next) {
                    // if we have any chain

                    // search in the whole avl tree and make linkings
                    checkAVLlinker(base[i].next->chain, target);

                }


            }
        }
    }
}

void hashTable ::checkAVLlinker(bst_node * root, player * target)
{
    // make links
    // recursively

if(root)
{
    // find objective nodes and call linkerHelper recursively
    if (root->battingProfiles && root->battingProfiles->BatTest)
    {
        // if current root has to be linked
        linkerHelper(root,target);

        checkAVLlinker(root->rightChild,target);
        checkAVLlinker(root->leftChild,target);

    }

}
}

void hashTable:: linkerHelper(player * objective, player * target) {
    BattingTest *obj = objective->battingProfiles->BatTest;
    BattingTest *tar = target->battingProfiles->BatTest;

    if (tar && obj) {
        if (obj != tar && (obj->start < tar->end && obj->end > tar->start)
            || (tar->start < obj->end && tar->end > obj->start)) {
            // overlapping in this case

            // now we have to add a link in target's list
            if (target->inSpanPlayers) {
                // the list already exists no need to recreate it

                target->inSpanPlayers->InsertSorted(objective);

                // also filling the list for objective at the
                // same time
            } else {
                // the list is empty and we have to create a new one
                linked_list *temp = new linked_list();
                // inserting objective to target's list
                temp->InsertSorted(objective);

                target->inSpanPlayers = temp;

            }


        }

    }
}




hashTable :: ~hashTable()
{

    delete[] base;
}