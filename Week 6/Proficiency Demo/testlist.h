#pragma once
#include <string>
#include <map>

class Bag{
    protected:
        std::map<std::string, int> items;
    public:
        void addItem(std::string, int);
        Bag operator+(const Bag&);
        void display();
};
