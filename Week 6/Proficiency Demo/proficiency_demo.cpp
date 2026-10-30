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


int main(){

    Bag bag1;
    Bag bag2;

    bag1.addItem("A", 2);
    bag1.addItem("B", 1);
    bag1.addItem("C", 4);
    bag1.addItem("D", 1);
    bag1.addItem("E", 1);

    bag2.addItem("A", 2);
    bag2.addItem("B", 1);
    bag2.addItem("C", 4);
    bag2.addItem("D", 1);
    bag2.addItem("E", 1);

    
    cout << "Sum of two bags" << endl;

    (bag1 + bag2).display();

    return 0;
}
