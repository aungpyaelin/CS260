/******************************************************************************

StringBinaryTreeProgram

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley 

Purpose: 

Specification:

Sources: 

Ok to share
******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "StringBinaryTree.h"

using namespace std;

int main(){
    // Initailize Variables
    vector<string> names = {"Bob", "Lin", "Mitch", "Claire", "Steven"};
    StringBinaryTree Tree;

    // Greet user
    cout << "Welcome to String Binary Search Tree Program\n\n";

    cout << "Inserting Nodes to the Tree\n";
    
    // Demonstrate Insertion
    for(string entries : names){
        Tree.insertNode(entries);
        Tree.displayInOrder();
    }

    

    
    
    return 0;
}