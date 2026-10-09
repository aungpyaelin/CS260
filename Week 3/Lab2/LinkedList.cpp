// LinkedList.cpp
// CS260 Week 3 Lab 2 

#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::~LinkedList(){
    Node* curr = head;  // used to traverse the list
    Node* target; // The node we are deleting
    while (curr){
        target = curr;
        curr = curr->next;

        cout << "destroying node with value: " << target->value << endl;

        delete target;
    }

    head = nullptr;
}
    
void LinkedList::append(int a_value){
    Node* curr = head; // used for traversing the list to the end 
    Node* baby = new Node{a_value, nullptr}; // address of newly-created node to append
    
    if (!head) {
        head = baby;
    }
    else {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = baby;
    }
}
 
        
void LinkedList::display() {
    Node* curr = head; // used for traversing the list 
    
    cout << "List:" << endl;
    
    while (curr) {
        cout << curr->value << endl;
        curr = curr->next;
    }
}

void LinkedList::display_new(int order) {
    cout << "Recursive List:" << endl;
    listRecursively(head, order);
}


void LinkedList::listRecursively(Node* node, int order){
    if (node) {
        if (order == 1) {
            cout << node->value << endl;
            listRecursively(node->next, order);
        } else {
            listRecursively(node->next, order);
            cout << node->value << endl;
        }
    }
}

void LinkedList::operator<<(int new_value) {
    append(new_value);
}

std::ostream& operator<<(std::ostream& os, LinkedList& list){
    Node* curr = list.head; // used for traversing the list 
    
    os << "List:" << endl;
    
    while (curr) {
        os << curr->value << endl;
        curr = curr->next;
    }
    return os;
}