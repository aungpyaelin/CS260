#include <iomanip>
#include <iostream>
#include "DLL.h"

using namespace std;

// Constructor
DoublyLinkedList::DoublyLinkedList() : head{}, tail {}, numItems{0} {};

//Destructor: clean up all nodes
// Note: wrtie iteratively & recursively
DoublyLinkedList::~DoublyLinkedList() {
    Node
        *curr = head,
        *temp = nullptr;
    
    while (curr != nullptr)
    {
        temp = curr;
        curr = curr->next;
        delete temp;
        temp = nullptr;
    }

    curr = head = tail = nullptr; //zeroize to avoid dangling pointer
    
}

// Print list from head to tail
// Note: EXTRA CREDIT for recursive verison
void DoublyLinkedList:: listForward(){
    Node* curr = head;

    while (curr)
    {
        cout << setw(4) << right << curr->value << ' ';
        curr = curr->next;
    }
    cout << endl;
    
}

// Print list from tail to head
void DoublyLinkedList::listBackward() {cout << endl;}

// Find node with given value
// Node* DoublyLinkedList::find(int val){}

void DoublyLinkedList::deleteNode(int val){}; // Delete node with given value

// Insert *before* first node with value >= val
// If no such node exists, add to end
void DoublyLinkedList::insert(int val){
    Node* newNode = new Node(val);
    Node* curr{};

    // If list is empty or val is less than first node's value, insert at front
    if (!head || val < head->value)
    {
        newNode->next = head;
        if (head)
        {
            head->prev = newNode;
        }
        head = newNode;
        if(!tail){
            tail = newNode;
        }
    } else{
        //Traverse to find first node >= val
        curr = head;
        while (curr && curr->value < val)
        {
            curr = curr->next;
        }
        // If reached end, insert at tail
        if(!curr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }else{
            // Insert before curr
            newNode->next = curr;
            newNode->prev = curr->prev;
            if(curr->prev){
                curr->prev->next = newNode;
            }
            curr->prev = newNode;

            // Fix head if needed
            if(curr == head)
                head = newNode;
            curr->prev = newNode;

        }
        
    }
    ++numItems;
    
}

