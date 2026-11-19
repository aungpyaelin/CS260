/******************************************************************************
Conversion of Int BST to String Name BST

CS260 Week 9 Lab - 2

Aung Pyae Lin

Purpose: This program specifies, implements, and demonsrates a basic binary 
search tree (BST) to store names alphabetically. 

Specification: A basic BST is implemented using member functions to
recursively insert, recursively display, and iteratively search. Last name and 
first name are stored. For alphabetizing, a formula
uppercase(last +  ' ' + first) is used. We observe that the delimiter chosen 
(we choose a space character) must hvae an ASCII les the 65 (and 97)
in order to work properly (e.g., using '|' places Willam|Terry incorrectly 
after Williams|Vivian).

Notes: We focus on priortizing essential changes to meet to compiler's 
requirements, and leave details such as the name of the class to be dealt
with at a later time. 

Time Complexity: 
    Insert- O(lg n)
    Display- O(n)
    Search- O(lg n)
*******************************************************************************/
#include <iostream>
#include <cstdlib>   // rand()
#include <ctime>     // time()
#include <string>

#include "IntBinaryTree.h"

#define rnd(min, max) min + rand() % max

using namespace std;

int main() {
    IntBinaryTree tree;
    int r {};
    string s;

    // Greet user
    cout << "Binary Search Tree Program \n\n";
    
    // Initialize (seed) random number generator 
    srand(time(0)); 
    
    // Insert 10 random values into the tree
    // cout << "Inserting: " << endl;
    // for (int count = 1; count <= 10; ++count) {
    //     r = rnd(1, 99); // Random number from 1 to 99
    //     cout << r << ' ' << flush;
    //     tree.insertNode(r);
    // }

    tree.insertNode("Jones", "Mitchell");
    tree.insertNode("Martinez", "Jose");
    tree.insertNode("Lincoln", "Abraham");
    tree.insertNode("Johnson", "Louis");
    tree.insertNode("Borell", "Layne");
    tree.insertNode("Williams", "Mona");
    tree.insertNode("William", "Terry"); 
    tree.insertNode("William", "Jerry");
    tree.insertNode("De La Cruz", "Joseph");
    tree.insertNode("de la Cruz", "Geraldo");

    // Display tree contents in order
    cout << "\n\nTree contents in order:\n";
    tree.displayInOrder();
    
    // Display some successful search results
    // Search for some nodes until 100 are tried or 10 are found
    cout << "\nFound: \n";

    // for (int tries = 1, count = 0; tries <=100 && count < 10; ++tries) {
    //     r = rnd(1, 99);
    //     if (tree.searchNode(r)) {
    //         cout << r << ' ' << flush;
    //         ++count;
    //     }
    // }

    s = "JONES MITCHELL";
    if(tree.searchNode(s)){
        cout << s << ' ' << flush;
    }

    // Display some unsuccessful search results
    // Search for some nodes until 100 are tried or 10 are not found
    cout << "\n\nNot Found: \n";

    s = "Aung Lin";
    if(!tree.searchNode(s)){
        cout << s << ' ' << flush;
    }

    // for (int tries = 1, count = 0; tries <= 100 && count < 20; ++tries) {
    //     r = rnd(1, 99);
    //     if (!tree.searchNode(r))
    //         cout << r << ' ' << flush;
    //         ++count;
    // }

    // Sign off
    cout << "\n\nProgram complete.\n";

    // End normally
    return 0;
}