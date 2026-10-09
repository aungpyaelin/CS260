/******************************************************************************
Implement a Linked List completed
CS260
Week 3 Lab 2 includes destructor/delete; reverse order

This program implements and demonstrates a linked list in heap memory.
*******************************************************************************/
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedList list, list2;
    
    cout << "Linked List Program" << endl << endl;
    
    list.append(5);
    list.append(7);
    list.append(11);
    list.display();
    cout << endl;
    list.display_new();
    list.display_new(2);  // Display in reverse order
    
    // Extra credit:
    list2 << 5;
    list2 << 7;
    list2 << 11;
    
    cout << endl;
    cout << list2;
    
    cout << "\nProgram complete.\n";
    return 0;
}