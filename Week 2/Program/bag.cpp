//Implementation file for the bag class
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "bag.h"

using namespace std;

//Default constructor
Bag::Bag() : counts(new int[MAX]()) {}

//Destructor
Bag::~Bag() {
    delete[] counts;
    counts = nullptr;
}

//Copy constructor
Bag::Bag(const Bag& other) : counts(new int[MAX]()) {
    for (int i = 0; i < MAX; i++) {
        counts[i] = other.counts[i];
    }
}

void Bag::insertItem(ItemType item, int count) {
    counts[item] += count;
}

void Bag::removeItem(ItemType item, int count) {
    counts[item] -= count;
    if (counts[item] < 0) {
        counts[item] = 0;
    }
}

int Bag::getCount(ItemType item) {
    return counts[item];
}

int Bag::getSize() {
    int size = 0;
    for (int i = 0; i < MAX; i++) {
        size += counts[i];
    }
    return size;
}

void Bag::displayInventory() {
    cout << "Item Qty" << endl;

    for (int item = 0; item < MAX; item++)
    {
        cout << setw(4) << ITEM_NAMES[item]
             << " " << setw(3) << counts[item] << endl;
    }
}

void Bag::displayRoster() {
    bool first = true; // first item to be displayed
    cout << '{';
    for (int item = 0; item < MAX; item++)
    {
        for (int count = 0; count < counts[item]; count++)
        {
            if (!first)
                cout << ", ";
            else 
                first = false;
            cout << ITEM_NAMES[item];
        }
    }
    cout << '}';
}

bool Bag::isEmpty() {
    return getSize() == 0;
}

bool Bag::isFull() {
    return getSize() == MAX;
}

// Return a new bag with an additional item
Bag Bag::operator+(ItemType item) const {
    Bag newBag = *this;
    newBag.counts[item]++;
    return newBag;
}

Bag Bag::operator+(const Bag& other) const {
    Bag newBag = *this;
    for (int i = 0; i < MAX; i++) {
        newBag.counts[i] += other.counts[i];
    }
    return newBag;
}

Bag Bag::operator-(ItemType item) const {
    Bag newBag = *this;
    if (newBag.counts[item] > 0) {
        newBag.counts[item]--;
    }
    return newBag;
}

Bag Bag::operator-(const Bag& other) const {
    Bag newBag = *this;
    for (int i = 0; i < MAX; i++) {
        newBag.counts[i] -= other.counts[i];
        if (newBag.counts[i] < 0) {
            newBag.counts[i] = 0;
        }
    }
    return newBag;
}

Bag Bag::operator*(const Bag& other) const {
    Bag newBag = *this;
    for(int i = 0; i < MAX; i++){
        newBag.counts[i] = std::min(newBag.counts[i], other.counts[i]);
    }
    return newBag;
}

Bag Bag::operator/(const Bag& other) const {
    Bag newBag = *this;
    for (int i = 0; i < MAX; i++) {
        newBag.counts[i] = std::max(newBag.counts[i], other.counts[i]);
    }
    return newBag;
}
