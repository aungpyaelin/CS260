// Specification file for StirngBinaryTree
#pragma once

#include <string>

class StringBinaryTree{
    protected:
        struct TreeNode{
            string name;
            TreeNode* left {};
            TreeNode* right {};
        };
        TreeNode* root;
        void insert(TreeNode*& nodePtr, string name);
        void display(TreeNode* nodePtr, int order = 0); //order, 0 for inorder, 1 for pre, 2 for post

    public:
        StringBinaryTree();
        ~StringBinaryTree();
        void insertNode(string name);
        void displayInOrder();
        void displayPreOrder();
        void displayPostOrder();
    
};