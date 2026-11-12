/******************************************************************************
Binary Search Tree (BST) Demo

CS260 Week 8 Lab - 2

Aung Pyae Lin

Purpose: This program specifies, implement, and demonstrates a basic binary
search tree (BST).  

Specification: A basic BST is implemented using member functions to recursively
insert, recursively display, and iteratively search. 

Sources: Gaddis, from Starter Code Provided

Time Complexity: 
    Insert-
    Display-
    Search-
*******************************************************************************/
#include <iostream>
#include <cstdlib>   // rand()
#include <ctime>     // time()

#include "IntBinaryTree.h"

#define rnd(min, max) min + rand() % max

using namespace std;

int main() {
    IntBinaryTree tree;
    int r {};

    // Greet user
    cout << "Binary Search Tree Program \n\n";
    
    // Initialize (seed) random number generator 
    srand(time(0)); 
    
    // Insert 10 random values into the tree
    cout << "Inserting: " << endl;
    for (int count = 1; count <= 10; ++count) {
        r = rnd(1, 99); // Random number from 1 to 99
        cout << r << ' ' << flush;
        tree.insertNode(r);
    }

    // Display tree contents in order
    cout << "\n\nTree contents in order:\n";
    tree.displayInOrder();
    
    // Display some successful search results
    // Search for some nodes until 100 are tried or 10 are found
    cout << "\nFound: \n";
    for (int tries = 1, count = 0; tries <=100 && count < 10; ++tries) {
        r = rnd(1, 99);
        if (tree.searchNode(r)) {
            cout << r << ' ' << flush;
            ++count;
        }
    }

    // Display some unsuccessful search results
    // Search for some nodes until 100 are tried or 10 are not found
    cout << "\n\nNot Found: \n";
    for (int tries = 1, count = 0; tries <= 100 && count < 20; ++tries) {
        r = rnd(1, 99);
        if (!tree.searchNode(r))
            cout << r << ' ' << flush;
            ++count;
    }

    // Sign off
    cout << "\n\nProgram complete.\n";

    // End normally
    return 0;
}