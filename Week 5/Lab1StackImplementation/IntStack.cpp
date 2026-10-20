// IntStack.cpp Integer Stack Implementation file using array

#include "IntStack.h"
#include <iostream>

using namespace std;

//Parameterized contructor
IntStack::IntStack(int size){
    stackArray = new int[size] {};
    stackSize = size; 
    top = -1;
}

//Copy Constructor * stub * 
IntStack::IntStack(const IntStack& obj){

}

// Destructor
IntStack::~IntStack(){
    // Zeroize
    // Relase memory
    delete[] stackArray;
    stackArray = nullptr;
}

void IntStack::push(int num){
    if(isFull()){
        cerr << "Push Error: The stack is already full. \n\n";
    }
    else{
        ++top; 
        stackArray[top] = num; // can use stackArray[++top] = num
    }
}

void IntStack::pop(int& num ){
    if(isEmpty()){
        cerr << "Pop Error: The stack is empty. \n";    
    }
    else{
        num = stackArray[top];
        stackArray[top] = 0;
        top--;
    }  
}

bool IntStack::isFull() const{
    bool status {};
    if(top == stackSize - 1) 
        status = true;
    else    
        status = false;
    return status; //return (top == stackSize - 1)
}

bool IntStack::isEmpty() const{
    return (top == -1);
}