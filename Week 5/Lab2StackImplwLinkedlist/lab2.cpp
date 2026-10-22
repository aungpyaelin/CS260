/*******************************************************
stack_as_linked_list.cpp
CS260 Week 5 Lab 2
Implement a stack as a linked list - Extended

Extension: Range-based for-loop to push; include .peek();
overload << for push with chaining; overload >> for pop and return data value

Aung Pyae Lin
********************************************************/
#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack stack; // Stack to experiment pushing, seeing top value, popping
    int dummy {}; // Cathes values popped off the stack

    cout << "Stack proram using linked list \n\n";

    //Test pushes (include << and range-based for-loop)
    cout << "Pushing item onto the stack \n";
    stack << 1 << 2 << 3 << 4;

    for (int value: {4,5,6,7,8,9,10,11,12,32,23,43}){
        cout << "Pushing " << value << " onto the stack...\n"; 
        stack << value;
    }

    // Test size/count
    cout << "The size of the stack is now " << stack.size() << endl;

    //Test top item by peeking
    cout << "Top item: " << stack.peek() << endl; //Expect 43

    // Pop and check to again
    cout << "(Popping it...)" << endl;
    stack.pop();

    cout << "Top item: " << stack.peek() << endl; //Expect 23

    while(!stack.empty()){
        cout << "Popped: " << (stack >> dummy, dummy) << endl;
    }

    // cout << (3,5) comma operator returns the second operand. it will cout 5.. Second values will return after evaluating the first operand
    // x  = 3, 5 x will be 5

    // Confrim that the stack is empty
    cout << "Stack empty as expected? " << (stack.empty() ? "Yes" : "No") << endl;

    //Sign off
    cout << "\nProgram Completed" << endl;
    return 0;
}