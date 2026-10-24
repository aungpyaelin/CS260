#ifndef STACK_H
#define STACK_H

class Stack {
    protected:
        struct Node {
            int data;
            Node* next;
            Node(int value, Node* nextNode = nullptr): data{value}, next{nextNode} {}
        };
        Node* top;
        int count; // tracks the number of nodes on the stack
    public:
        Stack();
        ~Stack();
        void push(int value);
        void pop();
        Node* topItem() const;
        bool empty() const;
        int size() const; // returns count (like get_count())
};
#endif