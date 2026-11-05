// DLL.cpp

#include <iomanip>
#include <iostream>
#include "DLL.h"

using namespace std;

// Node constructor
Node :: Node(int val) : value{val}, next{nullptr}, prev{nullptr} {}
// Destructor to zeroize data members
Node :: ~Node() {
    value = 0;
    next = prev = nullptr;
}

// Constructor
DoublyLinkedList :: DoublyLinkedList() : head {}, tail {}, numItems {} {}
// Destructor: clean up all nodes
DoublyLinkedList :: ~DoublyLinkedList() {
    Node
        *curr = head,
        *temp = nullptr;
    
    while (curr) { // (curr != nullptr)
        temp = curr;
        curr = curr->next;
        delete temp;
        temp = nullptr;
    }
    curr = head = tail = nullptr; // zeroize to avoid dangling pointers 
    numItems = 0;
}

// Print list from head to tail 
void DoublyLinkedList :: listForward() {
    Node* curr = head;
    while (curr) {
        cout << setw(4) << right << curr->value << ' ';
        curr = curr->next;
    }
    cout << endl;
}

 // Print list from tail to head
void DoublyLinkedList :: listBackward() {
   Node* curr = tail;
    while (curr) {
        cout << setw(4) << right << curr->value << ' ';
        curr = curr->prev;
    }
    cout << endl;
} 

//Find first node with given value
Node* DoublyLinkedList :: find(int val) {
    Node* curr = head;
    Node* found = nullptr;

    while (curr && !found)
    {
        if(curr->value == val){
            found = curr;
        }else
            curr = curr->next;
    }
    
    return found;
}
    
void DoublyLinkedList::deleteNode(int val){
    Node* target = find(val);

    if(target == nullptr)
        return;

    // If target is not the head
    if(target->prev){
        target->prev->next = target->next;
    }
    else{
        head = target->next;
    }
    
    //If target is not the tail
    if(target->next)
        target->next->prev = target->prev;
    else
        tail = target->prev;

    //Detach target before deleting
    target->next = target->prev = nullptr;

    delete target;
    target = nullptr;

    --numItems;
}

// Insert before first node with value >= val
void DoublyLinkedList :: insert(int val) {
    Node* newNode = new Node(val);
    Node* curr {};
    
    // If list is empty or val is less than first node's value, insert at front 
    if (!head || val < head->value) {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        if (!tail)
            tail = newNode;
    } else {
        // Traverse to find first node >= value
        curr = head;
        while (curr && curr->value < val) 
            curr = curr->next;
        // If reached end, insert at tail 
        if (!curr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            // Insert before curr
            newNode->next = curr;
            newNode->prev = curr->prev;
            if (curr->prev)
                curr->prev->next = newNode;
            curr->prev = newNode;   
            // Fix head if needed
            if (curr == head)
                head = newNode;
        }
    }
    ++numItems;
}






