//
// Created by hasib on 12/30/22.
//

#include "countryHashTable.h"


countryHashTable::countryHashTable()
{
    max =0;
    hashSize = 0;
    collision = 0;
    hashSize = 250;

    base = new country[hashSize];


    for (int i=0;i<hashSize;i++)
    {
        base[i].name = "\n";

    }
}



int countryHashTable::hashFunction(std::string name)
{




    char * arr = &name[0];

    unsigned long long int initialKey = 0;

    int t1 = 0;
    unsigned long long int t2 = 0;
    for (int ind=0;ind<name.length();ind++)
    {
        t2 = pow(2,ind);

        if(arr[ind] == ' ')
        {
            continue;
        }

        t1 = int(arr[ind]);
        initialKey +=   t1 * t2 ;
    }


    if (initialKey > max){
        max = initialKey;
    }


    long double inter =3-logl (1 + logl(0.5 +  logl(  logl(initialKey))));
    initialKey = abs(int(pow(hashSize,inter) - hashSize) % hashSize);
    return  initialKey;


}


country * countryHashTable::insert(country p)
{


    int index = hashFunction(p.name);


    if(base[index].name=="\n" )
    {
        base[index].name = p.name;


        return &base[index];


    }
    else
    {
        collision ++;
        return (chaining(index,p));



    }

}


country *  countryHashTable::chaining(int index,country p)
{
    if(base[index].next)
    {
        avl_country tree;
        tree.root = base[index].next->chain;

        return(tree.InsertWithoutDuplication(p));


    }
    else
    {
        country_intermediate *inter = new country_intermediate();
        base[index].next = inter;

        avl_country *tree = new avl_country();

        country * temp = nullptr;
        temp = tree->InsertWithoutDuplication(p);
        inter->chain = tree->root;

        return (temp);

    }
}

country *  countryHashTable::search(std::string name)
{
    int index = hashFunction(name);

    if(base[index].name == name)
    {
        return  &base[index];
    }

    else
    {
        avl_country tree;
        if(base[index].next) {
            tree.root = base[index].next->chain;
            return (tree.search(name));
        }

    }

    return nullptr;

}

countryHashTable::~countryHashTable()
{

    delete[] base;
}