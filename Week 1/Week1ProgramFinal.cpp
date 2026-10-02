/******************************************************************************

Week1ProgramFinal.cpp

Aung Pyae Lin

CS260 Fall 20206 - Inst: Mitch Priestley

Purpose: This program will establish four arrays, fill up the first array with
unique random numbers and copy values from the first to the second, to the third, 
and to the fourth array.

Specification: This program declares a static array, A, fill the array with 
random numbers, and make sure it is unique by checking each number against the 
existing elements in the array. The program then uses pointer arithmetic to 
demostrate that values in this array are stored in contiguous memory. Next, the 
program create a dynamic array, B and copies the values from the first array to 
the second array by using for loops. Then B is displayed, and the shown to be 
contiguous. Next, the program creates an array of pointers, C, and copies the 
values from the second array to the third array by using for loops. Then C is 
displayed, and the shown to be contiguous. Finally, the program creates an array
of pointers, D, and copies the values from the first array to the fourth array 
by using the indices of the fourth array to store the value. Then D is displayed, 
and the shown to be contiguous.

Technical Specification: This program populate the first array with unique random
numbers by adding a value and then checking the array if the value to be added is 
unique. If the value is not unique, it generates a new random number and the process
is repeated. The reason for not using an if statment to check the array is that we 
don't know how many time the loop is going to run.That is why we resort to using 
a do while loop, which ran the loop aleast once before checking the condition. 
When the condition is checked, the loop will determine if it need to be repeated 
or not. The program check if the value is unique by passing the number to 
IsUniqueNumber function. The function returns true if the number is unique and 
false otherwise. The first array is copied to the second array using for loop.
Then the second array is copid to the third, and the fourth array is populated
from the first array using the indices of the fourth array to store the value.

Sources: Gaddis, Mitch Priestley, CS260 Week 1 Program Starter, Program Hints,
Computer Tutor

Ok to share

******************************************************************************/
#include <iostream>
#include <random>       // Marsenne Twister random number generator
#include <iomanip>      // For display formatting

using namespace std;

const int SIZE = 100, NUM_RANGE = 100;

//Function Declarations
void DisplayArray(int []); // Display a regular array
void DisplayArray(int*[]); // Display an array of pointers to integers
void CopyArray(int [], int []); // Copy a regular array to another regular array
void CopyIntArray(int [], int*[]); // Copy a regular array to an array of pointers to integers
void CopyArrayToD(int [], int*[]); // Copy a regular array to an array of pointers to integers (for sorting)
void ArrayFillUp(int []); // Fill an array with unique random numbers
bool IsUniqueNumber(int [], int, int); // Check if a number is unique in an array
int generateRandomInt(int); // Generate a random integer within a range

int main()
{
    // Declare variables
    int arr_a[SIZE] {}; // Stores a list of values
    int* arr_b = new int[SIZE] {}; // Stores values copied from array a
    int* arr_c[SIZE] {nullptr};	// Stores heap addresses where ints are stored
    int* arr_d[SIZE] {nullptr}; // Sorted array of int pointers
    
    // Greet user
    cout << "Welcome to the 4 array program!\n";
    cout << "Generating random values for Array A...\n\n";

    // Fill array with random values
    ArrayFillUp(arr_a);
    
    // Copy array a to array b 
    CopyArray(arr_a, arr_b);
    // Copy array b to c 
    CopyIntArray(arr_b, arr_c);
    //Copy array A to D
    CopyArrayToD(arr_a, arr_d);

    // Display array A
    cout << "Array A\n";
    DisplayArray(arr_a);
    cout << "A: " << *arr_a << ' ' << *(arr_a + 1) << " (demonstrates contiguity) \n\n";
    
    // Display array b
    cout << "Array B\n";
    DisplayArray(arr_b);
    cout << "B: " << *arr_b << ' ' << *(arr_b + 1) << " (demonstrates contiguity) \n\n";

    // Display array c 
    cout << "Array C\n";
    DisplayArray(arr_c);
    cout << "C: " << **arr_c << ' ' << **(arr_c + 1) << " (demonstrates contiguity) \n\n";

    // Display array d
    cout << "Array D\n";
    DisplayArray(arr_d);
    cout << "D: " << **arr_d << ' ' << **(arr_d + 1) << " (demonstrates contiguity) \n\n";

    // Zeroize all 400 ints to 0 
    for (int count = 0; count < SIZE; count++)
    {
        arr_a[count] = 0;
        arr_b[count] = 0;
        if (arr_c[count]) {
            *arr_c[count] = 0;
        }
        if (arr_d[count]) {
            *arr_d[count] = 0;
        }
    }

    // Deallocate dyamic memory
    delete[] arr_b;
    arr_b = nullptr;

    // more for c
    for (int count = 0; count < SIZE; count++)
    {
        delete arr_c[count];
        arr_c[count] = nullptr;
        delete arr_d[count];
        arr_d[count] = nullptr;
    }
    
    // Sign off
    cout << "Program complete. \n";
    // End normally
    return 0;
}

// Function to fill an array with unique random numbers
// Arguments: array to be filled with unique random numbers
// No return value
void ArrayFillUp(int arr[]){
    for (int count = 0; count < SIZE; ++count)
    {
        int randomNumber = 0;
        do
        {
            randomNumber = generateRandomInt(NUM_RANGE);
        } while (!IsUniqueNumber(arr, count, randomNumber));
        arr[count] = randomNumber;
    }
}

// Function to check if a number is unique in an array
// Arguments: array, current count of elements, number to check
// Returns: true if the number is unique, false otherwise   
bool IsUniqueNumber(int arr[], int count, int num){
    for (int idx = 0; idx < count; idx++)
    {
        if (arr[idx] == num)
        {
            return false; // Number already exists, not unique
        }
    }
    return true; // Number is unique
}

// Function to generate a random integer within a specified range
// Arguments: NUM_RANGE
// Returns: a random integer within a specified range
int generateRandomInt(int NUM_RANGE) {
    static bool initialized {false};

    static mt19937 generator;  // Mersenne Twister

    // Initialize the random engine if not already done
    if (!initialized) {
        // Use a random device to seed the generator
        random_device rd;
        generator.seed(rd());

        initialized = true;
    }
    uniform_int_distribution<int> distribution(0, NUM_RANGE - 1);
    return distribution(generator);
}

// Function to copy an array of integers to another array of pointers to integers
// Arguments: arr1 - source array, arr2 - destination array of pointers
// No return value
void CopyIntArray(int arr1[], int* arr2[]){
    for (int count = 0; count < SIZE; count++)
    {
        arr2[count] = new int(arr1[count]); 
    }
}

// Function to display an array of integers
// Arguments: array to be displayed
// No return value 
void DisplayArray(int arr[]){
    for (int idx = 0; idx < SIZE; idx++)
    {
        cout << setw(4) << left << arr[idx] << " ";
        if((idx + 1) % 10 == 0){
            cout << endl;
        }
    }
    cout << endl;
}

// Function to display an array of pointers to integers
// Arguments: array of pointers to be displayed
// No return value
void DisplayArray(int* arr[]){
    for (int idx = 0; idx < SIZE; idx++)
    {
        cout << setw(4) << left << *arr[idx] << " ";
        if((idx + 1) % 10 == 0){
            cout << endl;
        }
    }
    cout << endl;
}

// Function to copy an array of integers to another array of integers
// Arguments: arr1 - source array, arr2 - destination array
// No return value
void CopyArray(int arr1[], int arr2[]){
    for (int count = 0; count < SIZE; count++)
    {
        arr2[count] = arr1[count];
    }
}

// Function to copy an array of integers to an array of pointers to integers using the values as indices
// Arguments: arr1 - source array, arr2 - destination array of pointers
// No return value
void CopyArrayToD(int arr1[], int* arr2[]){
    for (int count = 0; count < SIZE; count++)
    {
        arr2[arr1[count]] = new int(arr1[count]); 
    }
}