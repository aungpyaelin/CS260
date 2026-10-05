// Bag.h - Interface for an array-based Bag (multiset) ADT of chars.
// Operators: +  add an item        (bag + item)
//            -  remove an item     (bag - item)
//            -  subtract two bags  (bag1 - bag2)
//            *  intersection       (bag1 * bag2)
//            /  union              (bag1 / bag2)
#ifndef BAG_H
#define BAG_H

#include <string>

class Bag {
public:
    static const int DEFAULT_CAPACITY = 15;

    // Constructor / big three (the bag owns a dynamic array)
    explicit Bag(int capacity = DEFAULT_CAPACITY);
    Bag(const Bag& other);
    ~Bag();
    Bag& operator=(const Bag& other);

    // Accessors
    int  size() const;              // number of items currently in the bag
    int  capacity() const;          // maximum items the bag can hold
    bool isFull() const;
    int  count(char item) const;    // occurrences of item in the bag
    std::string list() const;       // e.g. "{a, a, b, c}"

    // Operators (each returns a NEW bag; operands are not modified)
    Bag operator+(char item) const;         // add one item (unchanged if bag is full)
    Bag operator-(char item) const;         // remove one item (unchanged if absent)
    Bag operator-(const Bag& other) const;  // remove each of other's items once
    Bag operator*(const Bag& other) const;  // items common to both (min counts)
    Bag operator/(const Bag& other) const;  // all items of both bags combined

private:
    char* items;   // dynamic array, kept in sorted order
    int   used;    // items in use
    int   cap;     // array capacity

    bool insertItem(char item);   // sorted insert; false if full
    bool removeItem(char item);   // remove one occurrence; false if absent
};

#endif