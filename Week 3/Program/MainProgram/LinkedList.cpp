//Implementation file for the game engine
#include "LinkedList.h"
#include <iostream>

using namespace std;

void LinkedList::append(Node* baby){
    Node* curr = head; // used for traversing the list to the end

    if(!head) {
        head = baby;
    }else{
        while(curr->next){
            curr = curr->next;
        }
        curr->next = baby;
    }
}

void LinkedList::display(){
    Node* curr = head; // used for traversing the list

    std::cout << "List:" << std::endl;

    while(curr){
        std::cout << curr->desc << std::endl;
        curr = curr->next;
    }
}

void LinkedList::display_new(){
    std::cout << "Recursive List:" << std::endl;
    listRecursively(head);
}

void LinkedList::listRecursively(Node* node){
    if(node){
        std::cout << node->desc << std::endl;
        listRecursively(node->next);
    }
}