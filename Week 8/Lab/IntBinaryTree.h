// IntBinaryTree.h 

class IntBinaryTree {
    protected:
        struct TreeNode {
            int value {};
            TreeNode* left {};
            TreeNode* right {};
        };
    
        TreeNode* root;
        void insert(TreeNode*& nodePtr, int value); // Helper funciton for recursive
        void displayInOrder(TreeNode* nodePtr);
    
    public:
        IntBinaryTree();
        void insertNode(int value); // Wrapper function for recursion
        void displayInOrder(); // function overloading
        bool searchNode(int num);
};