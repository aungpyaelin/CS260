/*************************************************************************
Aung Pyae Lin

CS260 Week 4 Lab 2 - Preparing for Palindromes
Classify an Array as Symmetric or Non-Symmetric
 
Purpose: This program classifies an array as symmetric or non-symmetric.

Specification: This program determines a recursive function to determine
whether an int array is symmetric.

Extra Credit: In many applications, it can be important to have symmetric
matrices or to know whether matrices are symmetric. Write a program that sets 
up a square 2D array and determines whether nor not it is symmetric. Symmetry
for a matrix  is defined across its main diagonal. What is in the diagonal is 
of no concern. For all cells A[i, j] in the n x n 2D array A, the following 
must hold: A[i][j] == A[j][i]. Submit your function, isSymmetricMatrix, and 
the main that drives and demonstrates it to Extra Credit Submissions. Note 
whether your algorithm is iterative or recursive. If it is iterative, try 
to write it as a recursive algorithm and submit that for more XCR!
*************************************************************************/
#include <iostream>

using namespace std;

bool IsSymmetric(int[], int, int);
bool IsSymmetricMatrix(int[][3], int);

int main(){
    int numList[] {3,5,7,11,99,99,11,7,5,3};
    int size = sizeof(numList)/sizeof(numList[0]);

    int matrix[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    cout << "Array Symmetry Classifier \n\n";

    cout << "The array" << flush;
    cout << (IsSymmetric(numList, 0, size - 1) ? " is " : " is not " )
         << "symmetric.\n";

    cout << "The matrix" << flush;
    cout << (IsSymmetricMatrix(matrix, 3) ? " is " : " is not " )
         << "symmetric.\n";

    cout << "\nProgram Completed.";

    return 0;
}

// bool IsSymmetric(int arr[], int left, int right){
//     // Base Case
//     if (arr[left] != arr[right])
//     {
//         return false;
//     }
//     else if (left >= right)
//     {
//         return true;
//     }
//     // Recursive Case
//     else {
//         return IsSymmetric(arr, left + 1, right - 1);  
//     }
// }

bool IsSymmetric(int arr[], int left, int right){
    // Base Case
    if (left >= right)
        return true;
    // Recursive case   
    return arr[left] == arr[right] && IsSymmetric(arr, left + 1, right - 1);
}

bool IsSymmetricMatrix(int arr[][3], int size){
    // Base Case
    
}