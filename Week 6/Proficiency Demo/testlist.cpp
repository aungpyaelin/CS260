#include "testlist.h"
#include <iostream>

using namespace std;

LinkedList::~LinkedList(){
    Node* curr = head;
    Node* temp;

    while(curr){
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedList::append(int num){
    Node* curr = head;
    Node* baby = new Node{num, nullptr};

    if(!head){
        head = baby;
    }else{
        while(curr->next){
            curr = curr->next;
        }
        curr->next = baby;
    }
}

void LinkedList::display(){
    Node* curr = head;
    while(curr){
        cout << curr->value << endl;
        curr = curr->next;
    }
}