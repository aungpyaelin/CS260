//DynIntQueue.h

#pragma once

class DynIntQueue{
    protected:
        struct QueueNode{
            int value = 0;      // value held in node 
            QueueNode* next{}; //pointer to the next node in queue
        };

        QueueNode* front; // pointer to the front of the queue
        QueueNode* rear; // pointer to the rear of the queue
        int numItems;   // Number of items in the queue

    public:
        //Contructor
        DynIntQueue();

        //Destructor
        ~DynIntQueue();

        //Queue Operations
        void enqueue(int);
        void dequeue(int&);
        bool isEmpty() const; // Doesn't change any value so its is const funciton
        void clear();
};

