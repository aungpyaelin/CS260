/*******************************
Stack Demonstration
CS260 Week 5 : Stacks
Lab 1 : Array Implementation

Aung Pyae Lin

Attendance: Attended live; on time. 

Purpose: This driver (main) demonstrates basic funcitonality of a stack object,
an abstract data type. 

Specification: The driver (main) declares a stack and its maximum size, pushes elements (ints) 
onto the stack, and pops elements off of the stack. 

Test regimen or test plan = planned routine or structured sequence of tests
********************************/
#include <iostream>
#include "IntStack.h"

using namespace std;

int main(){
    int catchVar {};    //To capture values popped off stack 

    //Define a stack object to hold 5 values
    IntStack stack(5);

    //Welcome
    cout << "Stack Demonstration v1.0\n\n";

    //Push values 5,10,15,20,25 onto stack
    // for (int value = 5; value <= 25; value += 5)
    // {
    for(int value : {2,3,5,6,7,7})
    {
        if(!stack.isFull()){

            cout << "Pushing " << value << " onto stack... \n";
            stack.push(value);
    
        }else{
            cout << "The stack is full.\n";
        }
    }
    
    // Pop valus off the stack
    while (!stack.isEmpty())
    {
        cout << "Popping... ";
        stack.pop(catchVar); // catchVar = stack.pop();
        cout << "Popped " << catchVar << endl;
    }
    
    cout << "The stack is now empty. \n";
    
    // Zeroize
    catchVar = 0;

    // Sign off
    cout << "\nProgram Completed\n";

    //End Normally
    return 0;
}