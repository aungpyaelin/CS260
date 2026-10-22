#include <iostream>
#include <stdexcept>
#include "Stack.h"

using namespace std;

Stack::Stack(): top{nullptr}, count{0}{}

Stack::~Stack(){
    //empty out the list
    while(!empty())
        pop();
}

void Stack::push(int value){
    Node* baby = new Node{value, top};
    top = baby; 
    ++count;
}

Stack& Stack::operator<<(int value){// pushes; permits chaining
    push(value);
    return *this;
}

int Stack::pop(){
    if(empty()){
        throw runtime_error("Attempted Illegal operation: stack underflow");
    }
    Node* temp = top;
    int result = top->data;
    top = top->next;
    delete temp;
    temp = nullptr;
    --count;
    return result;
}
Stack& Stack::operator>>(int& var){
    var = pop();
    return *this;
} // pops; permits channing

int Stack::peek() const{
    if(empty()){
        throw runtime_error("Attempted Illegal operation: empty stack has no 'top'");
    }
    return top->data;
}// getter for data

bool Stack::empty() const{
    return !top;// top == nullptr
}
int Stack::size() const{
    return count;
} // getter for count 