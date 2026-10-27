/*


DynamicQueueDemo.cpp
CS260 Week 6 Lab 1 Fall 2026 Priestley

Aung Pyae Lin

Proficiency Demo planned for Friday 30/10/2026

Purpose: This program specifies, implements, and demonstrates a queue.

Specification: A dynamic queue is created to store integers. Intergers are
enqueued and dequeued. A count is maintained, and a method is provided to check
whether the queue is empty. 

Source: Gaddis, Priestley Class/lab

*/
#include <iostream>
#include <string>
#include "DynIntQueue.h"

using namespace std;

int main(){
    
    //Declare constants
    const int MAX_VALUES = 5; // Max size of demo queue

    string  
        greeting("Welcome to the Queue Program v1.0\n"), // Use at start
        signoff("\n\nProgram Complete.\n"); // Use at end
    
    int catchVar{};
    // Create queue object for demonstration
    DynIntQueue iQueue; // holds demonstration values, demonstrates behaviors

    //Greet User
    cout << greeting;

    // Confirm Queue existence/status
    if (iQueue.isEmpty()) //Accessing member function of an obj proves obj exists
    {
        cout << "A queue exists and is empty.\n";
    }
    
    //Enqueu a series of data values
    cout << "Enqueuing " << MAX_VALUES << " items...\n" ;
    for(int data_value : {5,7,11,13,17}){
        cout << data_value << ' ';
        iQueue.enqueue(data_value);
    }  

    // Dequeue and retrieve all values stored in the queue
    cout << "\nDequeuing... \n";
    cout << "The values that were in the queue: \n";
    while(!iQueue.isEmpty()){
        iQueue.dequeue(catchVar);
        cout << catchVar << endl;
    }

    // Confirm queue status
    cout << "Queue status: " << (iQueue.isEmpty() ? "Empty": "Not Empty") << endl;

    //Zeroize
    catchVar = 0;
    
    //Overwrite
    greeting = string(greeting.length(), 32);
    signoff = string(signoff.length(), 32);

    //clear 
    greeting = string(greeting.length(), 0);
    signoff = string(signoff.length(), 0);

    // Sign off;
    cout << signoff;

    return 0;
}