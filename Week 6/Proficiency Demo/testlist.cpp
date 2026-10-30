#include "testlist.h"
#include <iostream>

using namespace std;

void Bag::addItem(string name, int num){
    items[name] += num;
}

Bag Bag::operator+(const Bag& other){
    Bag result = *this;

    for(auto item: other.items){
        result.items[item.first] += item.second;
    }

    return result;
}

void Bag::display(){
    for(auto item: items){
        cout << item.first << " " << item.second << endl;
    }
}