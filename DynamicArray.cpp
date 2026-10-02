/*






*/

#include <iostream>

using namespace std;

int main(){
    int a[100] {}; //uses 400 bytes, 100 x 4
    int* b  = new int[100] {}; //new return a memory address of the 100 int values, uses 408 bytes
    
    a[7] = 6;
    b[7] = 9;

    return 0;
}