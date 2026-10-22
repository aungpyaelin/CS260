/************************************************************************
Stack.h
CS260 Week 5 Lab 2  
Define a stack as a linked list
*******************************************************************************/

#ifndef STACK_H
#define STACK_H

class Stack {
    protected:
        struct Node { 
            int data;
            Node* next;
            Node(int value, Node* arg_next = nullptr)
                : data {value}, next {arg_next} {}
            ~Node() { data = 0; next = nullptr; };
        };
    
        Node* top;
        int count; // Maintain a count of how many items are on our stack
    
    public:
        Stack();
        ~Stack();
        void push(int value);
        Stack& operator<<(int value); // pushes; permits chaining
        int pop();
        Stack& operator>>(int& var); // pops; permits channing
        int peek() const; // getter for data
        bool empty() const;
        int size() const; // getter for count 
};

#endif