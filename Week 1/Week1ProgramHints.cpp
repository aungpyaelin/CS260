/******************************************************************************
Four_Arrays_Mini.cpp

The purpose of this mini-program is to demonstrate a static array, dynamic array, and 
two arrays of pointers.

Specification: This program fills array A with values, then copies them to array 
B, then to C, then to D. When copying to D, the values in A are used as the 
indices (subscripts) for placement into D. For this to work, the original set of 
values must span the array indices, in any order.

*******************************************************************************/
#include <iostream>

using namespace std;

const int MAX = 6;

int main()
{
    // Declare four arrays
    int A[MAX] { 5, 2, 1, 0, 3, 4 };
    int* B = new int[MAX];
    int* C[MAX] {nullptr}, *D[MAX] {nullptr};
    
    // Demonstate copying as specified
    for (int idx = 0; idx < MAX; ++idx) {
        B[idx] = A[idx];
        C[idx] = new int(B[idx]);
        D[A[idx]] = new int(A[idx]);
    }
    
    // Output all four arrays side-by-side
    cout << "A B C D" << endl;
    for (int idx = 0; idx < MAX; ++idx) {
        cerr << A[idx] << ' ' << B[idx] << ' ' << *C[idx] << ' ' << *D[idx] << endl;
    }

    // Free dynamic memory for B, C, and D
    delete[] B;
    B = nullptr;
    
    for (int idx = 0; idx < MAX; ++idx) {
        delete C[idx];
        C[idx] = nullptr;
        delete D[idx];
        D[idx] = nullptr;
    }
    
    return 0;
}