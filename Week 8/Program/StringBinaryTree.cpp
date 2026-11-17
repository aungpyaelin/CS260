// Implementation file for StringBinaryTree
#include "StringBinaryTree.h"
#include <iostream>

using namespace std;

// Public Functions
// Constructor
StringBinaryTree::StringBinaryTree() : root{} {};

// Destructor
StringBinaryTree::~StringBinaryTree(){
	delete root;
	root = nullptr;
};

// Wrapper functions for public access
// Function to insert a node into the tree
void StringBinaryTree::insertNode(string name){
	if(name.empty()){
		cerr << "Cannot insert an empty name.\n";
		return;
	}
	insert(root, name);
}

// Display the tree in order
void StringBinaryTree::displayInOrder(){
	display(root);
}

// Display the tree in pre order
void StringBinaryTree::displayPreOrder(){
	display(root, TraversalOrder::preOrder);
}

// Display the tree in post order
void StringBinaryTree::displayPostOrder(){
	
	display(root, TraversalOrder::postOrder);
}

// Delete the node with the given name
void StringBinaryTree::remove(string name){
	if(name.empty()){
		cerr << "Cannot remove an empty name.\n";
		return;
	}
	if(!deleteNode(root, name))
		cerr << "Name not found: " << name << '\n';
}

// Delete the entire subtree including the node
void StringBinaryTree::deleteSubTree(string name){
	if(name.empty()){
		cerr << "Cannot remove an empty sub tree.\n";
		return;
	}
	if(!deleteNode(root, name, DeletionMode::subTreeDeletion))
		cerr << "Name not found: " << name << '\n';
}

// Protected Functions
void StringBinaryTree::display(TreeNode* nodePtr, TraversalOrder order){
	if(!nodePtr) return;
	
	if(order == TraversalOrder::inOrder){
		display(nodePtr->left);
		cout << nodePtr->name << ' ';
		display(nodePtr->right);
	}else if(order == TraversalOrder::preOrder){
		cout << nodePtr->name << ' ';
		display(nodePtr->left, TraversalOrder::preOrder);
		display(nodePtr->right, TraversalOrder::preOrder);
	}else{
		display(nodePtr->left, TraversalOrder::postOrder);
		display(nodePtr->right, TraversalOrder::postOrder);
		cout << nodePtr->name << ' ';
	}
}

void StringBinaryTree::insert(TreeNode*& nodePtr, string name){
	if(!nodePtr) // If the current node is null, create a new node with the given name
		nodePtr = new TreeNode{name};
	else if (name < nodePtr->name) // If the name is less than the current node's name, insert into the left subtree
		insert(nodePtr->left, name);
	else // If the name is greater than or equal to the current node's name, insert into the right subtree
		insert(nodePtr->right, name);
}

bool StringBinaryTree::deleteNode(TreeNode*& nodePtr, string name, DeletionMode mode){
	if (!nodePtr) return false;
	
	if(name < nodePtr->name) // If the name is less than the current node's name, search in the left subtree
		return deleteNode(nodePtr->left, name, mode);
	else if(name > nodePtr->name) // If the name is greater than the current node's name, search in the right subtree
		return deleteNode(nodePtr->right, name, mode);
	else{
		if (mode == DeletionMode::subTreeDeletion) // If the mode is subtree deletion, call the makeSubTreeDeletion function
			makeSubTreeDeletion(nodePtr);
		else // If the mode is node deletion, call the makeDeletion function
			makeDeletion(nodePtr);
		return true;
	}	
}

void StringBinaryTree::makeDeletion(TreeNode*& nodePtr){
	if(!nodePtr) return;
	// Handle the case where the node has zero, one, or two children
	TreeNode* tempNode = nodePtr;
	if(!nodePtr->left){ // If the node has no left child, replace it with its right child
		nodePtr = nodePtr->right;
		tempNode->right = nullptr;
	}else if(!nodePtr->right){ // If the node has no right child, replace it with its left child
		nodePtr = nodePtr->left;
		tempNode->left = nullptr;
	}else{ // If the node has two children, find the leftmost node in the right subtree and replace the current node with it
		TreeNode* rightSubtree = nodePtr->right;
		TreeNode* leftmost = rightSubtree;
		while(leftmost->left)
			leftmost = leftmost->left;
		leftmost->left = nodePtr->left;
		nodePtr = rightSubtree;
		tempNode->left = nullptr;
		tempNode->right = nullptr;
	}
	delete tempNode;
}

void StringBinaryTree::makeSubTreeDeletion(TreeNode *&nodePtr){
	delete nodePtr;
	nodePtr = nullptr;
}