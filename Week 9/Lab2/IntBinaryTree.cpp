// IntBinaryTree.cpp

#include <iostream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

// Protected
// Helper functions
void IntBinaryTree :: insert(TreeNode*& nodePtr, TreeNode* newNode) {
    string value = newNode->value;

    if (!nodePtr)                       // alt: nodePtr == nullptr
        nodePtr = newNode; // alt: (value, nullptr, nullptr)
    else if (value < nodePtr->value) 
        insert(nodePtr->left, newNode);
    else 
        insert(nodePtr->right, newNode);
}

void IntBinaryTree :: displayInOrder(TreeNode* nodePtr) {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->first << ' ' << nodePtr->last << 
            " (" << nodePtr->last << ", " << nodePtr->first << ')' << endl;
        displayInOrder(nodePtr->right);
    }
}

// Public
IntBinaryTree :: IntBinaryTree(): root {} {}

void IntBinaryTree :: insertNode(string a_last, string a_first) {
    TreeNode* newNode = new TreeNode(a_last, a_first);
    insert(root, newNode);
}

void IntBinaryTree :: displayInOrder() {
    displayInOrder(root);
    cout << endl;
}

bool IntBinaryTree :: searchNode(string num) {
    bool found = false;
    TreeNode *nodePtr = root;
    
    while (!found && nodePtr) {
        if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else if (num > nodePtr->value)
            nodePtr = nodePtr->right;
        else
            found = true;
    }
    return found;
}

string uppercase(const string& s){
    string result = s;

    for (int idx = 0; idx < s.length(); ++idx)
    {
        result[idx] = toupper(result[idx]);
    }
    
    return result;
    
}