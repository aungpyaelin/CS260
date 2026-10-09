// LinkedList.h
// CS260 Week 3 Lab 2 

#pragma once    // replaces ifndef; 
#include <iostream>

// Note: using namespace std; is not allowed in .h files by convention

struct Node {
    int value = 0;
    Node* next = nullptr;

    ~Node() {value = 0; next = nullptr; }
};

class LinkedList {
    protected:
        Node* head;
        void listRecursively(Node*, int);
    
    public: 
        LinkedList(): head {nullptr} {}
        ~LinkedList();
        void append(int);
        void display();
        void display_new(int order = 1);
        void operator<<(int);
        friend std::ostream& operator<<(std::ostream&, LinkedList&);
};