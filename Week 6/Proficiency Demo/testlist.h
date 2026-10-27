#pragma once

struct Node{
    int value;
    Node* next;

    ~Node(){value = 0; next = nullptr;}
};

class LinkedList{
    protected:
        Node* head;
    public:
        ~LinkedList();
        LinkedList(): head{nullptr}{};
        void append(int);
        void display();
};