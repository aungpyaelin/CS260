/******************************************************************************
CS260 WeeK 4 Lab 1

Purpose: This program implements and demonstrates recursive functions.

Specification: This program implements recursive functions to (1) multiply by
repeated addition; (2) sum array elements; (3) calculate a factorial;
(4) calculate a Fibonacci number in sequence { 1, 1, 2, 3, 5, ... }.
*******************************************************************************/
#include <iostream>

using namespace std;

int Fibonacci(int);
int Multiply(int , int);
int SumArray(int[], int);
int Factorial(int);

int main(){
    const int FIB = 3;     //Maximum Max Seq Number

    int numlist[] {3,5,1,2,33};
    int size = sizeof(numlist)/sizeof(numlist[0]);
    
    cout << "Recursion Demonstration \n\n";

    cout << "1. 6 times 8 = " << Multiply(6,8) << endl;

    cout << "2. Sum of {3, 5, 1, 2, 33} is " << SumArray(numlist, size) << endl;

    cout << "3. 6 factorial (6!) is " << Factorial(6) << endl;

    cout << "4. Fibonacci #" << FIB << " in the sequence is " << flush << Fibonacci(FIB) << endl; // use flush when the function may take a while to return
    
    return 0;
}

// Multiply recursive function will calculate a product by repeated addition
// Arguments are value to be added and number times to add it (second >= 0) 
// Return sum,
int Multiply(int value, int times){
    //Base case
    if (times == 0)
        return 0;
    else 
        return value + Multiply(value, times - 1); // Make sure rescursive call to be reduced to base case. 

}

// SumArray recusive function sums elements of an int array
// Arguments are an int array and its size
// Return the sum of the array elements
int SumArray(int arr[], int size){
    //base case
    if (size == 1)
        return arr[0];

    //Recursive case
    else 
        return arr[size - 1] + SumArray(arr, size - 1);
}

// Factorial recursive function calculates the factorial of the argument
// Argument is the number of which the factorial will be calculated
// Return the factorial of the argument
int Factorial(int n){
    // Base Case
    if (n == 0)
        return 1;
    //Recursive Case
    else
        return n * Factorial(n-1);

}

// Fibonacci Resurcive funtion, f(n), calculate the nth fib number
// Arguement is the ordinal value of the desired fib number (beginning with 0)
// Return the Fibonacci number whose ordinal value is the argument
int Fibonacci(int n){
    int result = 0;

    // Base cases
    if (n == 0){
        result = 0;
    }
    else if (n == 1)
        result = 1;
    // Recursive case
    else 
        result = Fibonacci(n-2) + Fibonacci(n-1);

    return result;

}