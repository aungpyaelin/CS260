/******************************************************************************

DLL Demo
Week 7 Lab 2 to 2 starter Spring '26 - Doubly Linked list

Aung Pyae Lin

CS260-H1 FALL'26 Priestley

Purpose: This program implements a doubly linked list and demonstrates its
functionality.

Specification: Create a doubly linked list, then perform various operations on 
it, displaying the list after each operation to visually verify proper 
functionality. Operations include insert, list (forward and backward), and 
deleting a node.

*******************************************************************************/
#include <iomanip>
#include <iostream>
#include "DLL.h"

using namespace std;

int main() {
    DoublyLinkedList dll;
    
    // Greet user
    cout << "Doubly Linked List Demo Program \n\n";

    // Append values to the list
    cout << "Let's insert 1, 10, and 25 into the DLL...\n";
    //dll.insert(1);
    //dll.insert(10);
    //dll.insert(25);
    for (int value : {1, 10, 25}) {
        dll.insert(value);
        dll.listForward();
    }

    // Display list forward
    cout << setw(25) << left << "Current list (forward): ";
    dll.listForward(); // Expected: 1 10 25

    // Insert before a value >= 5
    dll.insert(5);
    cout << setw(25) << left << "After insert(5):  ";
    dll.listForward(); // Expected: 1 5 10 25 

    // Display list in reverse
    cout << setw(25) << left << "List backward:     ";
    dll.listBackward(); // Expected: 25 10 5 1

    // Delete a node by value
    dll.deleteNode(10);
    cout << setw(25) << left << "After deleting 10: ";
    dll.listForward(); // Expected: 1 5 25
    cout << setw(25) << left << "List backward:     ";
    dll.listBackward(); 
    // Sign off
    cout << "\nProgram complete \n";

    // End normally
    return 0;
}