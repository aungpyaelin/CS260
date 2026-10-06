//Header file for the bag
#pragma once

#include <string>

enum ItemType {
    A, B, C, D, E, F
};

const int MAX = 6;
const std::string ITEM_NAMES[MAX] = {"a", "b", "c", "d", "e", "f"};

class Bag{
    private:
        int* counts;
    public: 
        //Constructor and Destructor
        Bag();
        ~Bag();
        Bag(const Bag& other);

        //Getters and Setters
        void insertItem(ItemType item, int count);  //Adding an item
        void removeItem(ItemType item, int count);  //Removing an item
        int getCount(ItemType item);
        int getSize();
        bool isEmpty();
        bool isFull();
        void displayInventory();
        void displayRoster();

        //Bag operations
        Bag operator+(ItemType item) const;     //Adding One element
        Bag operator+(const Bag& other) const;  //Adding Another Bag
        Bag operator-(const Bag& other) const;  //Subtracting Another Bag
        Bag operator-(ItemType item) const;     //Subtracting One element
        Bag operator*(const Bag& other) const;  //Intersection Operation
        Bag operator/(const Bag& other) const;  //Union Operation
};