#pragma once

struct Node
{
    int val;
    Node* next;
    Node* prev;

    Node(int val);
    ~Node();
};

class DoublyLinkedList
{
    protected:
        Node* head;
        Node* tail;
        int numItems;
    public:
        // Constructor
        DoublyLinkedList();

        //Destructor
        ~DoublyLinkedList();

        //DLL operations
        void append(int);
        void listForward();
        void listBackward();
        Node* find(int);
        void deleteNode(int);
        void insert(int);
};
