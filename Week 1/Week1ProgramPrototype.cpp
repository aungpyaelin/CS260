/******************************************************************************

Week1ProgramPrototype.cpp

Aung Pyae Lin

CS260 Fall 20206 - Inst: Mitch Priestley

Purpose: This (prototype) program will establish three arrays and copy values from the first to
the second, and from the second to the third.

Specification: This (prototype) program declares a static array, A, fills the 
array with values, and displays the array's values. The program then uses pointer arithmetic 
to demonstrate that values in this array are stored in contiguous memory. Next, a dynamic 
array, B, is declared, and a for- loop is used to copy the values from array A to array B. 
Then B is displayed and shown to be contiguous. Finally, an array of int pointers, C, 
is declared, and the values are copied from B to various places in dynamically allocated 
memory, with each memory location being stored in array C. Then we loop through C to 
display the original list of values.

Sources: Gaddis, Mitch Priestley, CS260 Week 1 Program Starter

Ok to share

******************************************************************************/
#include <iostream>
#include <random>       // Marsenne Twister random number generator

using namespace std;

const int SIZE = 5;

//Function Prototypes
void DisplayArray(int []);
void CopyArray(int [], int []);

int main()
{
    // Declare variables
    int arr_a[SIZE] {3, 2, 4, 0, 1}; // Stores a list of values
    int* arr_b = new int[SIZE] {}; // Stores values copied from array a
    int* arr_c[SIZE] {nullptr};	// Stores heap addresses where ints are stored
    // Can be made dynamic using int** arr_c = new int*[SIZE] {nullptr};
    
    // Greet user
    
    // Fill array with random values
    // (only implemented in later version)
    
    // Display array a 
    cout << "A: ";
    DisplayArray(arr_a);
    cout << "A: " << *arr_a << ' ' << *(arr_a + 1) << " (demonstrates contiguity) \n";
    
    // Copy array a to array b 
    CopyArray(arr_a, arr_b);


    // Display array b
    cout << "B: ";
    DisplayArray(arr_b);
    cout << "B: " << *arr_b << ' ' << *(arr_b + 1) << " (demonstrates contiguity) \n";

    

    // Copy array b to c 
    for (int count = 0; count < SIZE; count++)
    {
        arr_c[count] = &arr_b[count];
    }
    
    // Display array c 
    for (int count = 0; count < SIZE; count++)
    {
        cout << *arr_c[count] << " ";
    }
    cout << endl;
    
    // Zeroize all 400 ints to 0 



    // Deallocate dyamic memory
    delete arr_b;
    arr_b = nullptr;
    // more for c
    
    // Sign off
    cout << "Program complete. \n";
    // End normally
    return 0;
}

void DisplayArray(int arr[]){
    for (int size = 0; size < SIZE; size++)
    {
        cout << arr[size] << " ";
    }
    cout << endl;
}

void CopyArray(int arr1[], int arr2[]){
    for (int count = 0; count < SIZE; count++)
    {
        arr2[count] = arr1[count];
    }
    
}