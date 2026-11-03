/******************************************************************************
main.cpp aka DynQueueEnhDemo.cpp
A print queue program using a dynamic queue, enhanced with more features
CS260 Week 6 Program Example to produce sample transcript of output

Aung Pyae Lin

CS260-H1 Spring 2025 Priestley 

Purpose: Manage a print queue, enabling enqueue, dequeue, list, cancel,
and VIPEnqueue.

Specification: Define a Job struct, and a Node struct holding a Job and next 
pointer; Enqueue jobs assigning a job # and a rank and a files ize; Dequeue jobs 
announcing job was printed and updating ranks of remaining jobs; list all jobs
in queue; cancel a job from the queue by job number; permit VIPEnqueue to place 
a queue near the front of the queue after the currently printing job, ahead of 
the job with priority 1, reranking all other jobs (job with rank 0 is currently 
printing and is unaffected by VIPEnqueue). 

Sources: Gaddis, Priestley class/labs, Stackoverflow, Computer Lab 1451

Ok to share

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
#include "queue.h"

using namespace std;

void Print(PrintQueue&);

int main(){
    // Init Variables
    string 
        greeting("Welcome to the Print Queue Program\n\nA new queue is now operational. You may queue up to 3 jobs in this queue.\n\n");

    PrintQueue queue;

    // Greet user
    cout << greeting;

    Print(queue);

    // Sign Off
    cout << "\nProgram Completed."  << endl;

    // End normanlly
    return 0;
}

void Print(PrintQueue& queue){
    Job catch_job; 
    
    for(Job job: {
        Job{0, "alice", 0, "main.cpp", 0},
        Job{0, "bob", 0, "resume.docx", 0},
        Job{0, "carol", 0, "invoice.xlsx", 0},
        Job{0, "dave", 0, "poster.ps", 0},
    }) {
        queue.enqueue(job);
        queue.list();
    }
    
    // VIP enqueue
    queue.VIPEnqueue({0, "erin" , 0, "thesis.dvi", 0});
    queue.list();

    queue.cancelJob(5);
    queue.list();

    queue.cancelJob(2);
    queue.list();

    // Simulate completion of a job 
    catch_job = queue.dequeue();
    queue.list();
    
    queue.enqueue({0, "dave", 0, "poster.ps", 0});
    queue.list();

    queue.VIPEnqueue({0, "erin" , 0, "thesis.dvi", 0});
    queue.list();
    
    // Dequeue all remaining jobs in the queue ;
    while (!queue.isEmpty()) {
        catch_job = queue.dequeue();
        queue.list();
    }
}