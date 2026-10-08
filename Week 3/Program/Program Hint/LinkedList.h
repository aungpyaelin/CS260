// LinkedList_game.h
// CS260 Week 3 Game Programming Ideas

#include <string>

struct Node {
        std::string desc;
        std::string conseq[2];
        int change[2];
        Node* next = nullptr;
};

class LinkedList {
    public:
        Node* head;
        void listRecursively(Node*);
    
    public: 
        LinkedList(): head {nullptr} {}
        void append(Node*);
        void display_old();
        void display_new();
};