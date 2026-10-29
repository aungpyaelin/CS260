// DynQueue.h
#pragma once

#include <string>

struct Job {
    int rank {};            // rank 0 = active, 1 = 1st, 2 = 2nd calc by q 
    std::string owner;      // job owner specified by client
    int jobnum {};          // job number assigned by queue
    std::string filename;   // name of file to be printed 
    int size {};            // size of file to be printed
};

class DynQueue {
    protected:
        struct Node {
            Job job;            // job to be printed
            Node* next {};      // pointer to next node in queue
        };
        int serial;     // sequential serial number used to assign job #'s
        Node* front;    // pointer to the front of the queue
        Node* rear;     // pointer to the rear of the queue 
        int numItems;   // Number of items in the queue 
        
    public:
        // Constuctor 
        DynQueue();
        
        // Destructor 
        ~DynQueue();
        
        // Queue operations 
        void enqueue(Job);
        Job dequeue();
        void list() const;
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};