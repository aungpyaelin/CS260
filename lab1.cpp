/*******************************
 * 
 * CS260 Week 1 Lab 1A Static Arrays, Dynamic Arrays 
 * 
 * Purpose: Define a class for employees, some of whom are supervisors. 
 * 
 * Specification: Each employee has a name, a supervisor, and a list of subordinates.
 * The list will be a vector of employee pointers. 
 * 
 *******************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    public: 
        string name;
        Employee* supervisor = nullptr; // supervisor's name is supervisor->name or (*supervisor).name
        vector<Employee*>* subordinates = nullptr; 

};


int main() {
    cout << "Hello World!" << endl;
    return 0;
}