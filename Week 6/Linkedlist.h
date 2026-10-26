#pragma once

struct Node{
    int value;
    Node* next; 

    Node():value{0}, next{nullptr}{};
};

class LinkedList{
    protected:
    Node* head;
    int size = 0; 

    public:
    LinkedList() : head{nullptr} {};
    void append(int);
    void remove();
    void display();
};