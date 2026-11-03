// Implementation file for the queue class
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <stdexcept>
#include "queue.h"

namespace fs = std::filesystem;

using namespace std;

// Constructor to create an empty queue
PrintQueue::PrintQueue() : serial {1} , front{} , rear {} , numItems {} {};

//Destructor
PrintQueue::~PrintQueue() {
    clear();
}

// Function enqueue inserts a job at the rear of the queue
// Take a job as an argument
// Return nothing
void PrintQueue::enqueue(Job arg_job){

    cout << arg_job.owner << " is enqueuing " << arg_job.filename << "...\n";

    if(numItems >= MAX_QUEUE){
        cout << "The queue is full! The new job is rejected from " << arg_job.owner << "; cannot queue "
             << arg_job.filename << " to be printed.";  
        return;
    } 
    
    Node* newNode = {};

    arg_job.jobID = serial++;
    arg_job.rank = numItems;

    try{
        arg_job.size = fs::file_size(arg_job.filename);
    }catch(const fs::filesystem_error& e){
        cout << "Warning: could not get size of " << arg_job.filename << endl;
        arg_job.size = -1;
    }

    // Create a new node and store arg_job therein
    newNode = new Node;
    newNode->job = arg_job;
    newNode->next = nullptr;

    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }

    ++numItems;
}

Job PrintQueue::dequeue(){
    Job result;
    Node* curr{};
    Node* temp{};

    if(isEmpty()){
        cerr << "Dequeue Error: The queue is empty.\n";
    }
    else{
        //Save the fron node in result
        result = front->job;

        //Announce dequeuing
        cout << "Finished priting " << result.filename << ". "
             << "Job " << result.jobID << " complete.\n" ;
        
        // Remove the front node and delete it
        temp = front;
        front = front->next;
        
        if(rear == temp){
            rear = nullptr;
        }
        delete temp;
        temp = nullptr;

        // Update numItems
        --numItems;

        //Update remaining ranks
        curr = front;
        while (curr)
        {
            curr->job.rank -= 1;
            curr = curr->next;
        }
        
    }
    return result;
}


// Function list all jobs in queue
// No arguments
// No return vlaue
void PrintQueue::list() const{
    Node* curr = front;

    cout << endl << left;
    cout << "Rank    Owner   Job  Files                  Total Size" << endl;

    while (curr)
    {
        if(curr->job.rank == 0)
            cout << setw(8) << "active" ;
        else   
            cout << setw(8) << curr->job.rank;
        
        cout << setw(8) << curr->job.owner;
        cout << setw(5) << curr->job.jobID;
        cout << setw(23)<< curr->job.filename;
        cout << curr->job.size;
        cout << endl;
        curr = curr->next;
    }
    
    cout << endl;

}

void PrintQueue::VIPEnqueue(Job arg_job){
    // Check if its an empty queue. True: use regular enqueue
    if(isEmpty()){
        enqueue(arg_job);
        return;
    }

    Node* newNode = {}; // Contain the new node
    Node* curr = front->next; // current node 
    Node* temp{}; // Temporary node
    int rank = 0; // To update the rank of the queue

    cout << arg_job.owner << " is a VIP enquing " << arg_job.filename << "...\n";

    // Check for the size of the queue if exceed, return the function
    if (numItems >= MAX_QUEUE)
    {
        cout << "The queue is full! The new job is rejected from " << arg_job.owner << "; cannot queue "
             << arg_job.filename << " to be printed.\n";  
        return;
    }
    
    // Assign the jobID for the newNode
    arg_job.jobID = serial++;

    try{
        arg_job.size = fs::file_size(arg_job.filename);
    }catch(const fs::filesystem_error& e){
        cout << "Warning: could not get size of " << arg_job.filename << endl;
        arg_job.size = -1;
    }

    // Set up the newNode
    newNode = new Node;
    newNode->job = arg_job;
    newNode->next = curr;   //Link to the current node in the chain
    front->next = newNode; // Link the next pointer of the front node to newNode 

    if(curr == nullptr){
        rear = newNode;
    }

    // For an empty queue
    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }

    // Update the ranking of the queue
    temp = front;
    while(temp){
        temp->job.rank = rank;
        rank++;
        temp = temp->next;
    }

    // Update the size of queue
    ++numItems;
}

void PrintQueue::cancelJob(int jobNum){
    Node* curr = front; // Current pointer 
    Node* prev = nullptr; // Previous pointer to keep track before deleting the current pointer
    Node* temp{}; // Temporary pointer
    int rank = 0; // to update the rank after canceling a job

    cout << "Requesting that Job #" << jobNum << " be canceled...\n";

    // Check if the queue is empty or not
    if(front == nullptr){
        cerr << "Error cannot cancel from empty queue\n";
        return;
    }

    // If the requested # is the front node, delete the front node
    if(front->job.jobID == jobNum){
        temp = front;
        front = front->next;
        delete temp;
        temp = nullptr;
        return;
    }

    // Traverse through the list until it find the target jobId
    while(curr != nullptr && curr->job.jobID != jobNum){
        prev = curr;
        curr = curr->next;
    }

    // If jobId cannot be found
    if(curr == nullptr){
        cout << "Cancellation request rejected: Job " << jobNum << " could not be found!\n";
        return;
    }

    // save the previous node to the next node of current to maintain link.
    prev->next = curr->next;

    // If the cancel Node is the last node. update the rear node
    if(curr == rear){
        rear = prev;
    }

    //Delete the curr node that maintain the jobID
    delete curr;
    curr = nullptr;

    //Update the size of the queue
    --numItems;

    // Update the rank of the queue
    temp = front;

    while(temp != nullptr){
        temp->job.rank = rank;
        rank++;
        temp = temp->next;
    }

    cout << "Job " << jobNum << " is canceled.\n";
}

bool PrintQueue::isEmpty() const{
    return (numItems == 0);
}

void PrintQueue::clear() {
    Job dummy {};

    while(!isEmpty()){
        dummy = dequeue();
    }
}