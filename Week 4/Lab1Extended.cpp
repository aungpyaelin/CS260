/******************************************************************************
Aung Pyae Lin

CS260 WeeK 4 Lab 1E - Palindrome 

Purpose: This program implements and demonstrates recursive functions.

Specification: This program implements recursive functions to (1) multiply by
repeated addition; (2) sum array elements; (3) calculate a factorial; 
(4) calculate a number in sequence { 1, 1, 2, 3, 5, ... }; (5) determine whether
an int array is symmetric (6) determine whether a string is a perfect 
palindrome; (7) determine whether a string is a palindrome, ignoring 
capitalizatation, spaces, and punctuation.
*******************************************************************************/
#include <iostream>

using namespace std;

int Multiply(int, int);
int SumArray(int[], int);
int Factorial(int);
int Fibonacci(int);
bool isSymmetric(int[], int, int);
bool isPerfectPalindrome(string sentence, int size);
bool isPalindrome(string sentence, int size);
// Examples of perfect palindromes: noon, kayak, racecar, straw warts, part trap
// Examples of palindromes: Dennis sinned, Edam made (note cases)
// Examples of palindromes: bird rib, Dennis and Edna sinned (note spaces)
// Examples of palindromes: A man, a plan, a canal -- Panama (note punctuation)
// I saw desserts; I'd no lemons, alas no melon. Distressed was I. 


int main()
{

    const int FIB = 20;    // limit: 46
    int numList[] {3, 5, 7, 11, 13, 11, 7, 5, 3};
    int size = sizeof(numList) / sizeof(numList[0]);
    int count = 0;
    string phrases[] {"abc-cba", "part trap", "abcd---dcba", "baddabit"};
    string sentences[] 
        {"A man, a plan, a canal -- Panama.",
         "Doc, note: I dissent. A fast never prevents a fatness. I diet on cod.",
         "A Toyota's a Toyota.",
         "Do nine men Interpret? Nine men, I nod.",
         "Eve is even steven with Stephen."};
    

    cout << "Recursion Demonstration \n\n";
    
    cout << "1. 6 times 8 = " << Multiply(6, 8) << endl;

    cout << "2. Sum of the array is " << SumArray(numList, size) << endl;

    cout << "3. 6 factorial is " << Factorial(6) << endl; // 6! = 6 * 5!
    
    cout << "4. Fibonacci #" << FIB << " in the sequence is " << flush << Fibonacci(FIB) << endl; 
    
    cout << "5. The array" << flush;
    cout << (isSymmetric(numList, size, size) ? " is " : " is not ") << "symmetric.\n";
    
    for (string str : phrases) {
        cout << "6." << ++count << " The string " << str << flush;
        cout << 
            (isPerfectPalindrome(str, str.length()) ? " is " : " is not ")
             << "a perfect palindrome.\n";
    }
    
    count = 0;
    for (string str : sentences) {
    cout << "7." << ++count << " The string \"" << str << "\"" << flush;
    cout << (isPalindrome(str, str.length()) ? " IS " : " is NOT ") 
         << "a palindrome.\n";
    }


    cout << "\nProgram Complete.\n";
    return 0;
}


// Multiply recursive function will calculate a product by repeated addition
// Arguments are value to be added and number of times to add it (second >= 0)
// Returns sum, which is product of arguments (value + value + value... )
int Multiply(int value, int times) {
    // Base case
    if (times == 0)
        return 0;
    
    else { // Recursive case 
        return value + Multiply(value, times - 1);
    
    }
}

// SumArray recursive function sums elements of the array 
// Arguments are array and size 
// Returns sum of array elements 
int SumArray(int arr[], int size) {
    // Base case
    if (size == 1)
        return arr[0];
    else     // Recursive case
        return arr[size - 1] + SumArray(arr, size - 1);
    
}

// Factorial recursive function calculates the factorial of the argument 
// Argument is the number of which the factorial will be calculated 
// Returns the factorial of the argument 
int Factorial(int factorial) {
    // Base cases: 0! = 1, 1! = 1 
    if (factorial == 0 || factorial == 1)
        return 1;
    else // Recursive case 
        return factorial * Factorial(factorial - 1);
}

// Fibonacci recursive function, f(n), calculates the nth Fib. number 
// Argument is the ordinal value of the desired Fib. number 
// Returns the Fibonacci number whose ordinal value is the argument 
int Fibonacci(int base) {
    // Base cases 
    if (base == 1 || base == 2)
        return 1;
    else // Recursive case 
        return Fibonacci(base - 2) + Fibonacci(base - 1);
}

// isSymmetric determines whether an int subarray is symmetric
// Takes three arguments: int array, array size, subarray size 
// Returns true if the subarray is symmetric; false otherwise
bool isSymmetric(int arr[], int size, int n){
    if (n <= size / 2) 
        return true;
    
    return arr[size - n] == arr[n - 1] && isSymmetric(arr, size, n - 1);
    
}


//Determines whether a string is a perfect palindrome
// Comments UNFINISHED and left for students
bool isPerfectPalindrome(string sentence, int size) {
    if (size <= sentence.length() / 2)
        return true;
    
    return sentence[sentence.length() - size] == sentence[size - 1] &&
            isPalindrome(sentence, size - 1);
}

// Determines whether a string is a palindrome, ignoring capitalizatation, 
// spaces, and punctuation.
// Comments AND function are UNFINISHED and left for students 
bool isPalindrome(string sentence, int size) {
    if (size <= sentence.length() / 2)
        return true;
        
    // Fix this function to achieve its stated purpose.
    
    return sentence[sentence.length() - size] == sentence[size - 1] &&
            isPalindrome(sentence, size - 1);
}
