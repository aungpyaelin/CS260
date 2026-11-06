#include "DLL.h"
#include <iostream>
#include <iomanip>

using namespace std;

Node::Node(int num) : val{num}, next{nullptr}, prev{nullptr} {}; 

Node::~Node(){
    val = 0;
    next = prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList(): head{}, tail{}, numItems{} {};

DoublyLinkedList::~DoublyLinkedList(){
    Node 
        *curr = head,
        *temp = nullptr;

    // Loop untill curr is nullptr
    while(curr){
        temp = curr;
        curr = curr->next;
        delete temp;
        temp = nullptr;
    }
    // Set to nullptr
    head = tail = curr = nullptr;
    numItems = 0;
}

void DoublyLinkedList::append(int num){
    Node* newNode = new Node(num);
    Node* curr = head;

    // If the list is empty, set the new node as head and tail.
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        //Traverse to the end of the list and append the new node..
        while(curr->next){
            curr = curr->next;
        }
        newNode->prev = curr;
        curr->next = newNode;
        tail = newNode;
    }
    // Upate the number of items in the list
    ++numItems;
}

//Function to display the list forward
void DoublyLinkedList::listForward(){
    Node* curr = head;

    while(curr){
        cout << setw(5) << right << curr->val << ' ';
        curr = curr->next;
    }
    cout << endl;
}

//Function to display the list backward
void DoublyLinkedList::listBackward(){
    Node* curr = tail;

    while(curr){
        cout << setw(5) << right<< curr->val << ' ';
        curr = curr->prev;
    }
    cout << endl;
}

//Find the first specific node from the DLL
Node* DoublyLinkedList::find(int num){
    Node* curr = head;

    while(curr && curr->val != num){
        curr = curr->next;
    }

    return curr;
}

//Delete the first specific node from the DLL
void DoublyLinkedList::deleteNode(int num){
    Node* target = find(num);

    // if the target is the last node
    if(target == tail){
        target->prev->next = nullptr;
        tail = target->prev;
    }else if(target == head){ // if the target is the first node
        target->next->prev = nullptr;
        head = target->next;
    }else{
        //If target is in the middle
        target->next->prev = target->prev;
        target->prev->next = target->next;
    }

    delete target;
    target = nullptr;

    // Update the number of items in the list.
    --numItems;
}

// Function to insert num is ascending order
void DoublyLinkedList::insert(int num){
    Node* newNode = new Node(num);
    Node* curr = head;
    
    // Check if the list is empty and if empty set it as head
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }else{
        // Traverse through the list, make sure curr is not nullptr, curr vale is less than equal to num, curr next isn't null
        while(curr && curr->val <= num && curr->next != nullptr){
            curr = curr->next;
        }
        //Case 1: If the num is before the first node
        if(curr->prev == nullptr && num < curr->val){
            newNode->next = curr;
            curr->prev = newNode;
            head = newNode;
        }
        //Case 2: If the num is the last node
        else if(curr->next == nullptr && num >= curr->val){
            newNode->prev = curr;
            curr->next = newNode;
            tail = newNode;
        }
        //Case 3: If the num is in the middle
        else{
            
            if(curr->val <= num){
                curr = curr->next;
            }
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
    }
}