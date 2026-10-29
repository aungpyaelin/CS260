/******************************************************************************
DynQueueDemo.cpp
CS260 Week 6 Lab 2 

Aung Pyae Lin

planned for Friday

Purpose: Manage a print queue, enabling jobs to be queued, then dequeued 
when printed.

Specification: Define a Job struct, and a Node struct holding a Job and next 
pointer; Enqueue jobs assigning a job # and a rank; Dequeue jobs updating ranks.
Note file size as jobs are enqueued.

Sources: Gaddis, Priestley class/lab 

Shared (weekly program: Private or OK to share)

$ lpq
Rank    Owner   Job  Files                  Total Size
active  alice   1    main.cpp               2020 bytes
2nd     bob     2    resume.docx            20480 bytes
3rd     carol   3    invoice.xlsx           30720 bytes
4th     dave    4    poster.ps              512000 bytes
5th     erin    5    thesis.dvi             1500000 bytes
6th     frank   6    resume.doc             9145 bytes

*******************************************************************************/
#include <iostream>
#include <string>
#include "DynQueue.h"

using namespace std;

void Test(DynQueue&);

int main()
{
    // Declare constant(s) 

    // Declare variables
    string 
        greeting("Welcome to the Print Queue Program \n\n"), //Use at start
        signoff("\n\nProgram complete.\n"); // Use at end

    // Greet User
    cout << greeting;

    // Create a queue object
    DynQueue printQueue;

    // Call a driver function to test and demonstrate queue features
    Test(printQueue);

    // Sign off
    cout << signoff;
    
    // End normally
    return 0;
}

void Test(DynQueue& queue) {
    Job catch_job;  // capture jobs returned by dequeue
    // Enqueue a series of print jobs  
    for (Job job : {
            Job{0, "alice", 0, "PrintQueue.cpp", 0},
            Job{0, "bob", 0, "resume.docx", 0},
            Job{0, "carol", 0, "invoice.xlsx", 0},
         })  {
        cout << job.owner << " is enqueuing " << job.filename << "...\n";
        queue.enqueue(job);
        queue.list();
    }
    
    // Simulate completion of a job 
    catch_job = queue.dequeue();
    queue.list();
    catch_job = queue.dequeue();
    queue.list();
    
    // Enqueue more jobs
    cout << "dave is enqueuing post.ps...\n";
    queue.enqueue({0, "dave", 0, "poster.ps", 0});
    queue.list();
    cout << "erin is enqueuing thesis.dvi...\n";
    queue.enqueue({0, "erin", 0, "thesis.dvi", 0});
    queue.list();
    
    // Dequeue all remaining jobs in the queue ;
    while (!queue.isEmpty()) {
        catch_job = queue.dequeue();
        queue.list();
    }
}