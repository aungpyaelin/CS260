//Header file for the game engine
#pragma once

#include <string>

struct Node{
    std::string name; // Name of the space
    std::string desc; // Description of the space
    std::string conseq[2]; //Consequences related to your choice
    int change[2]; // Changes to the stat

    Node* next = nullptr;
    ~Node() {name = ""; desc = ""; conseq[0] = ""; conseq[1] = ""; change[0] = 0; change[1] = 0; next = nullptr;}
};

class LinkedList{
    public:
        Node* head;
        void listRecursively(Node*);
    
    public:
        LinkedList(): head{nullptr} {};
        void append(Node*);
        void display();
        void display_new();
};
