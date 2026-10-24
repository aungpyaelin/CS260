/******************************************************************************

StackImplementainwithLinkedList.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley 

Purpose: Demonstrate stack operation with linked list

Specification: The program pushes, pop and check the size of the stack.
The program also determine if the stack is empty or not. 

Technical Specification: The program uses linkedlist to implement the stack.
Push() function creates a new node with value and pointer to the nextnode. set the 
top to the new node and increment the size. 
Pop() funciton copy a temp pointer to the top, make the top point to the next node,
and delete the temp pointer. 

Sources: Week 5 Program Starter Code

Ok to share

******************************************************************************/
#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack s;

    // Greeting
    cout << "Stack implementation using Linked List\n\n";
    
    //Pushes item to the stack
    s.push(5);
    s.push(15);
    s.push(25);
    
    cout << "Top item: " << s.topItem()->data << endl; // 25
    
    s.pop();
    
    cout << "Top item: " << s.topItem()->data << endl; // 15

    cout << "Size of the stack is " << s.size() << endl;

    while (!s.empty()) {
        cout << "Popping: " << s.topItem()->data << endl;
        s.pop();
    }

    cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    //Sign off
    cout << "Program Completed\n";

    //End normally
    return 0;
}
