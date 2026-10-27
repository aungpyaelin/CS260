#pragma once
#include <string>

enum ITEM_TYPE{
    A,B,C,D,E,F
};

const std::string ITEM_NAMES[6] = {"a", "b", "c", "d", "e", "f"};


class Bag{
    protected:
        int* count;
    public:
        void insert(ITEM_TYPE, int);
        void display();

        Bag operator+(const Bag&);
};