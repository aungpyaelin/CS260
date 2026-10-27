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
#include "testlist.h"

using namespace std;

// int Fibonacci(int);

int main(){
    // for (int count = 0; count < 46; count++)
    // {
        //     cout << "The " << count << " Fib number is " << Fibonacci(count);
        // }
        
    LinkedList list;

    list.append(1);
    list.append(3);
    list.append(5);
    list.display();
    
    return 0;
}

// int Fibonacci(int num){
//     if (num == 0)
//     {
//         return 0; 
//     }else if (num == 1)
//         return 1;
//     else   
//         return Fibonacci(num - 1) + Fibonacci(num - 2);
// }