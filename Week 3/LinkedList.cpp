// LinkedList.cpp
// CS260 Week 3 Lab 1

#include "LinkedList.h"
#include <iostream>

using namespace std;

void LinkedList::append(int a_value){
    Node* curr = head; //Used for traversing the list to the end
    Node* baby = new Node(a_value); // Address of newly created node to append

    if(!head)
        head = baby;
    else{
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = baby;

        
    }
}


void LinkedList::display(){
    Node* curr = head; // Used for tranversing the list

    cout << "List: " << endl;

    while (curr)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
    
}

void LinkedList::display_new(){
    cout << "Recursive List: " << endl;
    listRecursively(head);
}

void LinkedList::listRecursively(Node* node){
    if (node) {
        cout << node->value << endl;
        listRecursively(node->next);
    }
}