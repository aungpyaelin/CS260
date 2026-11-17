/******************************************************************************

StringBinaryTreeProgram

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley 

Purpose: The program demonstrates the use of a binary search tree to store and manipulate strings. 
It allows for insertion, deletion, and traversal of the tree in various orders.

Specification: The program defines a StringBinaryTree class that encapsulates the functionality of a binary search tree.
The class provides methods for inserting nodes, displaying the tree in different traversal orders (in-order, pre-order, post-order), 
and deleting nodes or subtrees based on specified criteria.

Technical Specifications: The program use Hardcoded strings to insert into the BST.
The program uses a vector to store the strings and iterates through them to insert into the tree.
Insertion uses a recursive approach to find the correct position for each string based on LEXICAL order.
For the display funciton, the program uses enum to determine the order of traversal and recursively prints the nodes in the specified order.
It also specifies two deletion modes: node deletion and subtree deletion, allowing for flexible removal of nodes from the tree.
Node deletion handles cases where the node has zero, one, or two childre, while subtree deletion removes the entire subtree rooted at the specified node.


Sources: Gaddis, Week 8 Lab 2, 

Ok to share
******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "StringBinaryTree.h"

using namespace std;

int main(){
    // Initailize Variables
    vector<string> names = {"Bob", "Lin", "Mitch", "Claire", "Steven", "Aung"};
    StringBinaryTree Tree;

    // Greet user
    cout << "Welcome to String Binary Search Tree Program\n\n";

    cout << "Inserting Nodes to the Tree\n";
    
    // Demonstrate Insertion
    for(string entries : names){
        Tree.insertNode(entries);
    }
    cout << endl;
    
    // Demonstrate Display
    cout << "Displaying the Tree in Order\n";
    Tree.displayInOrder();
    cout << endl << endl;

    cout << "Displaying the Tree in Post Order\n";
    Tree.displayPostOrder();
    cout << endl << endl;

    cout << "Displaying the Tree in Pre Order\n";
    Tree.displayPreOrder();
    cout << endl << endl;
    
    // Demonstrate Deletion
    cout << "Deleting Lin from the BST" << endl;
    Tree.remove("Lin");
    Tree.displayInOrder();
    cout << endl;

    // Demonstrate Sub Tree Deletion
    cout << "\nDeleting Sub Tree with root Lin\n";
    Tree.deleteSubTree("Lin");
    Tree.displayInOrder();

    //Sign Off
    cout << "\n\nProgram Completed\n"; 
    
    // Return 0 to indicate successful completion
    return 0;
}
