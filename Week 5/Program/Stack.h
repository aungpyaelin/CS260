//Header file for Stack.h

#ifndef STACK_H
#define STACK_H

struct Node {
            int data;
            Node* next;
            Node(int value, Node* nextNode = nullptr): data{value}, next{nextNode} {}
        };

class Stack {
    protected:
        Node* top;  //Pointer to the top of the stack
        int count; // tracks the number of nodes on the stack

    public:
        Stack(); //Constructor for Stack Obj
        ~Stack();//Destructor for Stack Obj
        void push(int value);   //Add values to the stack
        void pop();             //Remove values from the stack (from top)
        Node* topItem() const;  //Return the pointer of the top node
        bool empty() const;     //Check if the stack is empty or not
        int size() const; // returns count (like get_count())
};
#endif