#include "bag.h"
#include <iostream>


using namespace std;

void Bag::insert(ITEM_TYPE item, int num){
    count[item] += num;
}

void Bag::display(){
    cout << "list" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << ITEM_NAMES[i] << " " << count[i] << endl;
    }
    
}

Bag Bag::operator+(const Bag& other){
    Bag newBag = *this;
    for (int i = 0; i < 6; i++)
    {
        newBag.count[i] += other.count[i];
    }
    return newBag;
    
}