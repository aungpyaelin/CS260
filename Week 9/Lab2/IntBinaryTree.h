// IntBinaryTree.h 

#pragma once

#include <string>

std::string uppercase(const std::string& s);

class IntBinaryTree {
protected:
    struct TreeNode {
        // int value {};
        std::string value; // Composite key
        std::string first; 
        std::string last;
        TreeNode* left {};
        TreeNode* right {};

        TreeNode(std::string a_last, std::string a_first) : 
            first{a_first}, last{a_last}, value{uppercase(a_last + ' ' + a_first)} {}; 
    };

    TreeNode* root;
    void insert(TreeNode*& nodePtr, TreeNode* newNode);
    void displayInOrder(TreeNode* nodePtr);

public:
    IntBinaryTree();
    void insertNode(std::string a_last, std::string a_first);
    void displayInOrder();
    bool searchNode(std::string num);
};