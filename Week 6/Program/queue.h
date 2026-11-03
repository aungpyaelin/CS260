// Header file for Print Queue
#pragma once

#include <string>

const int MAX_QUEUE = 3;

struct Job{
    int rank{};             // rank 0 = active, 1 = 1st, 2 = 2nd calc by q
    std::string owner;      // job owner specified by client
    int jobID{};            // Job number assigned by queue
    std::string filename;   // name of file to be printed
    int size{};             // size of file to be printed
};

class PrintQueue{
    protected:
        struct Node{
            Job job;
            Node* next {};
        };
    int serial;
    Node* front;
    Node* rear;
    int numItems;

    public:
        //Constructor
        PrintQueue();

        //Destructor
        ~PrintQueue();

        //Queue Operations
        void enqueue(Job);
        Job dequeue();
        void VIPEnqueue(Job);
        void cancelJob(int);
        void list() const;
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};