// IntBinaryTree.cpp

#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

// Protected
// Helper functions
void IntBinaryTree :: insert(TreeNode*& nodePtr, int value) {
    if(!nodePtr)
        nodePtr = new TreeNode{value};
    else if (value < nodePtr->value)
        insert(nodePtr->left, value);
    else   
        insert(nodePtr->right, value);
}

void IntBinaryTree :: displayInOrder(TreeNode* nodePtr) {
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << ' ';
        displayInOrder(nodePtr->right);
    }   
}

// Public
IntBinaryTree :: IntBinaryTree(): root {} {}

void IntBinaryTree :: insertNode(int value) {
    insert(root, value);
}

void IntBinaryTree :: displayInOrder() {
    displayInOrder(root);
    cout << endl;
}

bool IntBinaryTree :: searchNode(int num) {
    bool found = false;
    TreeNode *nodePtr = root;
    
    while(!found && nodePtr){
        if(num < nodePtr->value)
            nodePtr = nodePtr->left;
        else if(num > nodePtr->value)  
            nodePtr = nodePtr->right;
        else 
            found = true; 
    }
    return found;
}
