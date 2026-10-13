//Header file for the game engine
#pragma once

struct Node{
    std::string desc; // Description of the space
    std::string conseq[2]; //Consequences related to your choice
    int change[2]; // Changes to the stat

    Node* next = nullptr;
};

class LinkedList{
    protected:
        Node* head;
        void listRecursively(Node*);
    
    public:
        LinkedList(): head{nullptr} {};
        void append(Node*);
        void display();
        void display_new();
};
