/******************************************************************************

Week7Program.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley

Purpose: Demonstrate the use of a doubly linked list by creating a DLL,
inserting values, deleting values, and displaying the list in both forward and backward order.

Specification: The program will create a doubly linked list and perform the following operations:
1. Append values 1, 3, 6, and 8 to the list
2. Display the list in forward order
3. Insert the value 5 into the list in ascending order
4. Display the list in forward order
5. Display the list in backward order
6. Append values 10, 13, 14, 16, 18, and 19 to the list using the insert function
7. Display the list in forward order after each insertion
8. Delete the node with the value 10 from the list
9. Display the list in forward order after deletion

Technical Specification: The program will use a DoublyLinkedList class that contains 
a head and tail pointer, as well as a count of the number of items in the list. 
The class will have methods to append values, insert values in ascending order, 
delete nodes, and display the list in both forward and backward order.
The Node struct will contain an integer value and pointers to the next and 
previous nodes in the list.

Sources: Gaddis, Week 7 Lab 1, 2

Ok to share

******************************************************************************/
#include <iomanip>
#include <iostream>
#include "DLL.h"

using namespace std;

int main(){
    // Init Variables
    DoublyLinkedList dll;

    // Greet User
    cout << "Doubly Linked List Program\n\n";

    //Append Values to the List
    cout << "Inserting 1,3,6,8 to the DLL...\n";
    for(int value : {1,3,6,8}){
        dll.append(value);
        dll.listForward();
    }

    // Display list forward
    cout << setw(25) << left << "Current list (forward): ";
    dll.listForward(); 

    //Insert(5)
    dll.insert(5);
    cout << setw(25) << left << "After inserting 5: ";
    dll.listForward();

    //Display list in reverse
    cout << setw(25) << left << "List backward:     ";
    dll.listBackward();

    //Add using insert()
    cout << "Appending 10, 13, 14, 16, 18, 19 to the DLL...\n";
    for(int values : {10,13,14,16,18,19}){
        dll.insert(values);
        dll.listForward();
    }
    
    //Demonstrate deleting node
    dll.deleteNode(10);
    cout << setw(25) << left << "After deleting 10: ";
    dll.listForward();
    cout << setw(25) << left << "List backward:     ";
    dll.listBackward(); 

    //Sign off
    cout << "\nProgram Completed.\n";
    
    // End normally
    return 0;
}