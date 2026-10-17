/******************************************************************************

Palindrome.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley

Purpose: 

Specification: 

Sources: 

Ok to share

******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Global Constant
const int SIZE = 4;
//Function Prototype
bool IsPalindrome(string, int);

int main(){
    
    string* strArr = new string[SIZE] {"Able was I, ere I saw Elba",
        "A man, a plan, a canal, Panama",
        "Desserts, I stressed",
        "Kayak"
    };

    for (int i = 0; i < SIZE; i++)
    {
        cout << strArr[i] << (IsPalindrome(strArr[i], strArr[i].length()) ? " is " : " is not ") 
             << "a palindrome." << endl;
    }

    //zeroize
    for (int i = 0; i < SIZE; i++)
    {
        strArr[i].clear();
    }
    
    //release memory
    delete[] strArr;

    strArr = nullptr;

    return 0;
}

// Recursive function to determine if a string is palindrome or not
// The function takes a string as an argument
// Return true if its a palindrome and false if it's not
bool IsPalindrome(string str, int size){
    //Base Case
    if(size <= str.length()/2 )
        return true;

    // if (str.find(',') != string::npos && str.find(' ') != string::npos)
    // {
    //     str.erase(remove_if(str.begin(), str.end(), [](char c) {
    //         return c== ',' || c == ' ' || c == '!';
    //     }), str.end());
    // }
    
    return str[str.length() - size] == str[size - 1] && IsPalindrome(str, size - 1);
}