/******************************************************************************
Byte_Examiner.cpp
CS260 Fall 2026 Mitch Priestley
Week 1 Lab 2
Purpose: This program reveals the content of each byte of a four-byte int.

Specification: 
    The program does the following:
    1. Declares an int variable and populates it with an integer value. 
    2. Displays the int as an integer.
    3. Displays the int as a character string (C-string).
    4. Displays each individual byte of the int as 
           a. 8 bits 
           b. a decimal value (an integer 0-255) 
           c. a char 
           d. a hex value (0-FF)

Technical Specification: The program declares a five-byte struct consisting of 
a 4-byte int and a 5-byte C-string overlapping in a union. A value is assigned
to the int. We then use the C-string to individually examine the four bytes of 
the int, viewing them in binary, as integers, as chars, and in hex. Finally, as 
a bonus, we demonstrate overflowing a one-byte variable, an unsigned char.
*******************************************************************************/
#define byte(x) (var1.item.ch[x])
#define bits(x) bitset<8>(byte(x))

#include <bitset>
#include <iostream>


using namespace std;

struct four_bytes {
    union {
        int value;
        char ch[5] {};
    } item;
};

int main()
{
   
    four_bytes var1 {65 + 66 * 256 + 67 * 256 * 256 + 68 * 256 * 256 * 256};

    cout << var1.item.value << endl;
    cout << var1.item.ch << endl;
    
    cout << bits(0) << " " << bits(1) << " "
         << bits(2) << " " << bits(3) << endl;
 
    cout << (int) byte(0) << "\t " << (int) byte(1) << "\t  "
         << (int) byte(2) << "\t   " << (int) byte(3) << endl;
         
    cout <<  var1.item.ch[0] << "\t " <<  var1.item.ch[1] << "\t  "
         <<  var1.item.ch[2] << "\t   " <<  var1.item.ch[3] << endl;
         
    cout << hex;
    
    cout << (int) byte(0) << "\t " << (int) byte(1) << "\t  "
         << (int) byte(2) << "\t   " << (int) byte(3) << endl;

    // Bonus: Demonstrate overflow (wrap-around) of a one-byte unsigned char 
    cout << endl;
    unsigned char a = 255;
    a += 1;
    cout << (int) a << endl; 
    
    return 0;
}