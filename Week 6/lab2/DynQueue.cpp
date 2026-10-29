// DynQueue.cpp 
#include <iomanip>
#include <iostream>
#include <filesystem>  // C++17, std::filesystem
#include "DynQueue.h"

namespace fs = std::filesystem;

using namespace std;

// Constructor to create an empty queue 
DynQueue :: DynQueue() : serial {1}, front {}, rear {}, numItems{} {}

// Destructor
DynQueue :: ~DynQueue() {
    clear();
}

// Function enqueue inserts a job at the rear of the queue
// Takes a Job as an argument
// Returns nothing
void DynQueue :: enqueue(Job arg_job) {
    Node *newNode = {};

    // Fill in some job values
    arg_job.jobnum = serial++;
    arg_job.rank = numItems;
    try
    {
        arg_job.size = fs::file_size(arg_job.filename);
    }
    catch(const fs::filesystem_error& e)
    {
        cout << "Warning: could not get size of " << arg_job.filename << endl;
        arg_job.size = -1;
    }

    // Create a new node and store arg_job therein
    newNode = new Node;
    newNode->job = arg_job;
    newNode->next = nullptr;

    // Adjust front and rear as necessary
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }

    // Update item count
    ++numItems;
}

// Function dequeue removes the value at the front of the queue
// No arguments
// Returns the Job that was dequeued.
// Side effect: Display message if there is nothing to dequeue 
Job DynQueue :: dequeue() {
    Job result; // Function returns first job in queue
    Node *temp {}; // points to object being dequeue
    Node *curr {}; //use to traverse queue to update ranks

    if(isEmpty())
        cerr << "Dequeue Error: The queue is empty. \n";
    else{
        // Save the front node in result
        result = front->job;

        //Announce dequeuing
        cout << "Finished printing " << result.filename << ". "
             << "Job " << result.jobnum << " complete.\n";
    
        // Remove the front node and delete it
        temp = front;
        front = front->next;
        if (rear == temp){
            rear = nullptr;
        }
        delete temp;
        temp = nullptr;

        // Update numItems 
        --numItems;
        
        // Update remaining ranks
        curr = front; 
        while (curr) {
            curr->job.rank -=1;
            curr = curr->next;
        }   
    }
    return result;
}// Function list to list all jobs in queue 
// No arguments
// No return value
void DynQueue :: list() const {
    Node* curr = front;
 
    cout << endl << left;
    cout << "Rank    Owner   Job  Files                  Total Size" << endl;
   
    while (curr) {
        if (curr->job.rank == 0)
            cout << setw(8) << "active";        // display "active" for rank 0
        else
            cout << setw(8) << curr->job.rank;
            
        cout << setw(8) << curr->job.owner;
        cout << setw(5) << curr->job.jobnum;
        cout << setw(23) << curr->job.filename;
        cout << curr->job.size;
        cout << endl;
        curr = curr->next;
    }
    
    cout << endl;
}

// Function isEmpty determines whether the queue is empty
// No arguments
// Returns true if the queue is empty; false otherwise
bool DynQueue :: isEmpty() const {
    return (numItems == 0);
}

// Function clear dequeues all elements in queue
// No arguments
// No return value
void DynQueue :: clear() {
    Job dummy {};       // dummy var for dequeued values (not needed)
    
    while (!isEmpty())
        dummy = dequeue(); 
        
    // Note that while dummy is not needed to capture a return value, a 
    // dummy variable would be required if an argument were needed.
}

