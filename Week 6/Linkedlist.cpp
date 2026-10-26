#include "Linkedlist.h"
#include <iostream>

using namespace std;

void LinkedList::append(int num){
    Node* curr = head;
    Node* baby = new Node{num};

    if (!head)
    {
        head = baby;
    }else
        while(curr->next){
            curr = curr->next;
        }
        curr->next = baby;
}

void LinkedList::display(){
    Node* curr = head;
    while (curr->next)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
    
}