// #pragma once

// enum ItemType{
//     A,B,C,D,E
// };

// const int MAX = 5;
// const std::string ITEM_NAMES[MAX] = {"a", "b", "c", "d", "e"};

// class Bag {
//     protected:
//     int* counts;

//     public:
//         Bag();
//         ~Bag();

//         void insertItem(ItemType, int);
//         Bag operator+(const Bag&) const;
// };


#pragma once

#include <string>
#include <map>

class Bag {
    protected:
        std::map<std::string, int> items;
    public:
        void addItem(std::string, int);
        Bag operator+(const Bag&);
        void display();

};