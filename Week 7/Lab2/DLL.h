// DLL.h 

#pragma once 

// Node structure for the doubly linked list
struct Node {
    int value;      // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    Node(int val);  // Constructor
    ~Node();        // Destructor to zeroize data members
};

// Class for the doubly linked list
class DoublyLinkedList {
protected:
    Node* head;     // Pointer to the first node
    Node* tail;     // Pointer to the last node
    int numItems;   // Number of items in the list

public:
    DoublyLinkedList();      // Constructor
    ~DoublyLinkedList();     // Destructor

    void listForward();           // Print list from head to tail
    void listBackward();          // Print list from tail to head
    Node* find(int val);          // Find node with given value
    void deleteNode(int val);     // Delete node with given value
    void insert(int val);        // Insert before first node with value >= val
};


