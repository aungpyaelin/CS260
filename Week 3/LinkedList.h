// LinkedList.h
// CS260 Week 3 Lab 1

#pragma once

struct Node{
    int value = 0;
    Node* next = nullptr;

};

class LinkedList{
    protected:
        Node* head;
        void listRecursively(Node*);
    
    public:
        LinkedList(): head{nullptr} {};
        void append(int);
        void display();
        void display_new();

};

