// DynIntQueue.cpp
// Implementation file for the DynIntQueue Obj

#include <iostream>
#include "DynIntQueue.h"

using namespace std;

// Constructor to create an empty queue 
DynIntQueue :: DynIntQueue() : front {}, rear {}, numItems{} 
{}

// Destructor
DynIntQueue :: ~DynIntQueue() {
    clear();
}

// function enqueue inserts the value of sum at the end of the queue
void DynIntQueue::enqueue(int num){
    QueueNode *newNode {};
    
    //Create a new node and store num therein 
    newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;

    //Adjust front and rear as necessary
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    ++numItems;
}

// Function dequeue removes the value at the front of the queue, and
// copies it to the argument. 
// Side effect: Display message if there is nothing to dequeue 
void DynIntQueue :: dequeue(int &num) {
    QueueNode *temp {};
    
    if (isEmpty())
        cout << "Error dequeuing The queue is empty. \n";
    else {
        // Save the front node value in num 
        num = front->value;
        
        // Remove the front node and delete it 
        temp = front;
        front = front->next;
        if (rear == temp)
            rear = nullptr;
        temp->value = 0;
        temp->next = nullptr;
        
        delete temp;
        temp = nullptr;
        
        // Update numItems 
        --numItems;
    }
        
}

// Function isEmpty returns true if the queue is empty; false otherwise
bool DynIntQueue :: isEmpty() const {
    return (numItems == 0);
}

// Function clear dequeues all elements in queue 
void DynIntQueue :: clear() {
    int dummy {};       // dummy var for dequeued values
    
    while (!isEmpty())
        dequeue(dummy);
}