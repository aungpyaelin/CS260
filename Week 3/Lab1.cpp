/**************************************************************************
Implement a Linked List
Linked List.cpp
CS260 Week 3 Lab 1

This program 

**************************************************************************/

#include <iostream>
#include "LinkedList.h"


using namespace std;

int main() {
    //Declare Variable
    LinkedList list;

    //Welcome user
    cout << "Linked List Program" << endl << endl;

    list.append(5);
    list.append(7);
    list.append(11);

    list.display();

    cout << endl;

    list.display_new(); //Call recursive version
    
    cout << endl;

    cout << "Program Completed";

    return 0;
}