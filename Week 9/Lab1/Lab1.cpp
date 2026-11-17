/******************************************************************************

CS260 Week 9 Lab 1: Templates & Composite primary key 

Templates are shortcut to overloading

Write the function once for all the data type

4 Process in compilation
1. Preprocessor Diractive 
2. Compiler add source code and compiled to Assembly Language
3. Assembler translate one for one Assembly language to machine languae in binary
4. Linker link.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

// Side note FYI
// How to alphabetize full names in a binary search tree (BST)
struct Node {
    string first;
    string last;
    
    Node *right {}, *left {};
};

// last + " " + first   "WILLIAM JERRY"
//                      "WILLIAMS ALAN" 
//                      "WILLIAMS BILL"
//                      "WILLIAMS STEVEN"
//                      "WILLIAMS TERRY"

// How to use a template for a struct
template <class T> // Equivalent to template typename T
struct Info {
    T id {};      // Brace init is type indepedent
};

// Provide compiler a function template for triple functions
template <typename T>   // equiv: template <class T>
T triple(T arg);

// Provide compiler a function template for an array allowing range-based loop
template <typename T, int N>
void printArray(T (&arr)[N] );

int main()
{
    char ch = '!'; // '!' ASCII 33 will triple to 'c' ASCII 99
    double p = 3.14, q = 24.50; // doubles to get tripled
    int x = 21, y = 100;        // ints to get tripled
    string s1 = "Maria", s2 = "Bianca";  // strings to be tripled
    int nums[] = {1, 2, 3, 4, 5}; // int arry to be displayed
    double vals[] = {1.1, 3.3, 5.5, 7.7, 9.9, 11.11}; // double array to display

    Info<int> a {21};        // struct to hold an int 
    Info<string> b {"Mario"};   // struct to hold a string
    Info<double> c {}; // double
    
    c.id = 2.781828;
    
    cout << "Template Demonstration\n";
    operator<<(cout, "Welcome\n\n");

    // Triple the ints 
    cout << "Tripling ints...\n";
    cout << "Triple " << x << " is " << triple(x) << endl;
    cout << "Triple " << y << " is " << triple(y) << endl;
    cout << "Size of that triple is " << sizeof(triple(x)) << " bytes \n\n";

    // Triple the doubles 
    cout << "Tripling double-precision floating point values...\n";
    cout << "Triple " << p << " is " << triple(p) << endl;
    cout << "Triple " << q << " is " << triple(q) << endl << endl;
    cout << "Size of that triple is " << sizeof(triple(x)) << " bytes \n\n";

    // Triple the strings
    cout << "Tripling strings...\n";
    cout << "Triple " << s1 << " is " << triple(s1) << endl;
    cout << "Triple " << s2 << " is " << triple(s2) << endl;
    cout << "Triple " << "Reggie" << " is " << triple(string("Reggie")) << endl; // tricky
    cout << "Size of that triple is " << sizeof(triple(x)) << " bytes \n\n";

    // Display arrays of varying types/sizes (tricky)
    cout << "\nDisplaying arrays: \n";
    printArray(nums);
    printArray(vals);
    
    // Output structs with data member id of varying types
    cout << "\nDisplaying struct IDs:\n";
    cout << a.id << ", " << b.id << " & " << c.id << endl;    

    // Sign off
    cout << "\nProgram complete.\n";

    // End normally
    return 0;
}



// Provide compiler a function template for triple functions
template <typename T>
T triple(T arg){
    T result;
    result = arg + arg + arg;
    return result;
}

// Provide compiler a function template for triple functions
template <typename T, int N>
void printArray(T (&arr)[N]){
    for (const T & element: arr)
        cout << element << " ";
    for (int i = 0; i < N; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
