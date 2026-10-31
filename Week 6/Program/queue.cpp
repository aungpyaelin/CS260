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

    if(numItems > MAX_QUEUE){
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

bool PrintQueue::isEmpty() const{
    return (numItems == 0);
}

void PrintQueue::clear() {
    Job dummy {};

    while(!isEmpty()){
        dummy = dequeue();
    }
}