// Bag.cpp - Implementation of the Bag class.
#include "Bag.h"

Bag::Bag(int capacity) : items(nullptr), used(0), cap(capacity > 0 ? capacity : 1) {
    items = new char[cap];
}

Bag::Bag(const Bag& other) : items(new char[other.cap]), used(other.used), cap(other.cap) {
    for (int i = 0; i < used; i++) items[i] = other.items[i];
}

Bag::~Bag() {
    delete[] items;
}

Bag& Bag::operator=(const Bag& other) {
    if (this != &other) {
        char* fresh = new char[other.cap];
        for (int i = 0; i < other.used; i++) fresh[i] = other.items[i];
        delete[] items;
        items = fresh;
        used = other.used;
        cap = other.cap;
    }
    return *this;
}

int  Bag::size() const     { return used; }
int  Bag::capacity() const { return cap; }
bool Bag::isFull() const   { return used == cap; }

int Bag::count(char item) const {
    int n = 0;
    for (int i = 0; i < used; i++)
        if (items[i] == item) n++;
    return n;
}

std::string Bag::list() const {
    std::string s = "{";
    for (int i = 0; i < used; i++) {
        if (i > 0) s += ", ";
        s += items[i];
    }
    return s + "}";
}

bool Bag::insertItem(char item) {
    if (isFull()) return false;
    int pos = used;
    while (pos > 0 && items[pos - 1] > item) {   // shift larger items right
        items[pos] = items[pos - 1];
        pos--;
    }
    items[pos] = item;
    used++;
    return true;
}

bool Bag::removeItem(char item) {
    for (int i = 0; i < used; i++) {
        if (items[i] == item) {
            for (int j = i; j < used - 1; j++) items[j] = items[j + 1];
            used--;
            return true;
        }
    }
    return false;
}

// bag + item
Bag Bag::operator+(char item) const {
    Bag result(*this);
    result.insertItem(item);
    return result;
}

// bag - item
Bag Bag::operator-(char item) const {
    Bag result(*this);
    result.removeItem(item);
    return result;
}

// bag1 - bag2
Bag Bag::operator-(const Bag& other) const {
    Bag result(*this);
    for (int i = 0; i < other.used; i++) result.removeItem(other.items[i]);
    return result;
}

// bag1 * bag2 : intersection (each item appears min(count1, count2) times)
Bag Bag::operator*(const Bag& other) const {
    Bag result(cap);
    for (int i = 0; i < used; i++)
        if (result.count(items[i]) < other.count(items[i]))
            result.insertItem(items[i]);
    return result;
}

// bag1 / bag2 : union (combination of all items from both bags)
Bag Bag::operator/(const Bag& other) const {
    Bag result(cap + other.cap);   // big enough that nothing is lost
    for (int i = 0; i < used; i++)       result.insertItem(items[i]);
    for (int i = 0; i < other.used; i++) result.insertItem(other.items[i]);
    return result;
}