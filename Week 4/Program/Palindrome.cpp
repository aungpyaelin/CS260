/******************************************************************************

ProgName.cpp

Student Name

CSxxx Term Year - Inst: Mitch Priestley <-- please spell my name including the 'e' ending l-e-y

Purpose: This program does a thing (state purpose briefly in 1-2 lines)

Specification: Elaborate on what the program does and hw it does it, detailing I/O (2-4 lines)

Sources: (list the textbook, websites, and other sources consulted; cite liberally)

Type your choice of "OK to share" or "Private"

******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//Gloal Constant
const int SIZE = 4;
//Function Prototype
bool IsPalindrome(string);

int main(){
    
    string* strArr = new string[SIZE] {"Able was I, ere I saw Elba",
        "A man, a plan, a canal, Panama",
        "Desserts, I stressed",
        "Kayak"
    };

    for (int i = 0; i < SIZE; i++)
    {
        cout << strArr[i] << (IsPalindrome(strArr[i]) ? " is " : " is not ") 
             << "a palindrome." << endl;
    }

    //zeroize

    
    //release memory
    delete[] strArr;

    return 0;
}

// Determine if a string is palindrome or not
// The function takes a string as an argument
// Return true if its a palindrome and false if it's not
bool IsPalindrome(string str){

    return true;

}