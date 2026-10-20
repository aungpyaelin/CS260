// IntStack.h Integer Stack Implementation as an array

#pragma once

class IntStack{
    protected: // May be made public for early debugging
        int *stackArray;
        int stackSize; // keep track of max items that can be held
        int top; // keep track of top position used on stack 

    public:
    //Constructor
    IntStack(int); 

    //Copy Constructor
    IntStack(const IntStack&);

    //Destructor
    ~IntStack();

    //Stack operations
    void push(int);
    void pop(int&);
    bool isEmpty() const;
    bool isFull() const;

};

