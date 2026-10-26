/*******************
 * 
 * Lists Fibonacci numbers from the 1st to the 46th, using recursive function calls, where fib(i) 
 * returns the ith Fibonacci number, starting with fib(1) = 1 and fib(2) = 1.
 * 
 * 
 * 
 * 
 * 
 * *****************/
#include <iostream>
#include "Linkedlist.h"

using namespace std;

int Fibonacci(int);

int main(){
    cout << "The 20th Fib number is " << Fibonacci(4) << endl;

    return 0;
}

int Fibonacci(int num){
    if (num == 0)
    {
        return 0; 
    }else if (num == 1)
        return 1;
    else   
        return Fibonacci(num - 1) + Fibonacci(num - 2);
}