// Specification file for StirngBinaryTree
#pragma once

#include <string>

enum class TraversalOrder{
    inOrder,
    preOrder,
    postOrder
};

enum class DeletionMode{
    nodeDeletion,
    subTreeDeletion
};

struct TreeNode{
    std::string name;
    TreeNode* left {};
    TreeNode* right {};

    ~TreeNode(){
        delete left;
        delete right;
    }
};

class StringBinaryTree{
    protected:
        TreeNode* root;
        void insert(TreeNode*& nodePtr, std::string name); //Insert the node to the tree
        void display(TreeNode* nodePtr, TraversalOrder order = TraversalOrder::inOrder); //order, 0 for inorder, 1 for pre, 2 for post
        bool deleteNode(TreeNode *&nodePtr, std::string name, DeletionMode mode = DeletionMode::nodeDeletion); // Find the node to delete and call the makeDeletion function, mode 0 for node, 1 or subtree
        void makeDeletion(TreeNode *&nodePtr); // Delete the node
        void makeSubTreeDeletion(TreeNode *&nodePtr);

    public:
        //Constructor
        StringBinaryTree();
        //Destructor
        ~StringBinaryTree();

        //BST operations
        void insertNode(std::string name); // Find the right place and call insert function
        void displayInOrder();             // Display the tree in order
        void displayPreOrder();            // Display the tree pre order
        void displayPostOrder();           // Display the tree post order
        void remove(std::string name);     // Delete the node with the given name 
        void deleteSubTree(std::string name); // Delete the entire subtree including the node
};
