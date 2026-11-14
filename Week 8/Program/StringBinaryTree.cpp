// Implementation file for StringBinaryTree
#include "StringBinaryTree.h"

using namespace std;

StringBinaryTree::StringBinaryTree(){};

StringBinaryTree::~StringBinaryTree(){};

void StringBinaryTree::insertNode(string name){
    insert(root, name);
}

void StringBinaryTree::displayInOrder(){
    display(root);
}

void StringBinaryTree::displayPreOrder(){
    display(root, 1);
}

void StringBinaryTree::displayPostOrder(){
    display(root, 2);
}


// Protected Functions
void StringBinaryTree::display(TreeNode* nodePtr, int order){
    
}