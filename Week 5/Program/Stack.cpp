// Implementation File for Stack.h
#include <stdexcept>
#include "Stack.h"

using namespace std;

Stack::Stack() : top{nullptr}, count{0} {}

Stack::~Stack() {
        while(!empty())
                pop();
}

void Stack::push(int value){
        Node* head = new Node(value, top); // Create a new node with the value and next node pointing to the top node
        top = head;                        // Make the top node be the new node                     
        ++count;                           //Increment the size
}

void Stack::pop(){
        if(empty()){
                throw runtime_error("Attempted Illegal Operation: Stack is Empty");
        }

        Node* temp = top; //Create a temp pointer to the top node
        top = top->next;  //Make the top node equal to the next node, if top node is 25, the top node will become 15
        delete temp;      //Remove the temp node, which was the top node in the first place
        temp = nullptr;         
        --count;

}

Node* Stack::topItem() const{
        if(empty()){
                throw runtime_error("Attempted Illegal Operation: Cannot access empty stack");
        }else{
                return top; 
        }
}

bool Stack::empty() const{
        return (top == nullptr);
}

int Stack::size() const{
        return count;
} // returns count (like get_count())