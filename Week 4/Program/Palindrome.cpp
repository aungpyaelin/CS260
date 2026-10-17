/******************************************************************************

Palindrome.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley

Purpose: 

Specification: 

Sources: 

Ok to share


Lambda Capture

******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Global Constant
const int SIZE = 4;
const char PUNCTUATIONS[] {'.', '!', '?', ',', ':', ';', '\'', '\"', '-', '(', ')', '[', ']'};
//Function Prototype
bool IsPalindrome(string, int, int);

int main(){
    
    string* strArr = new string[SIZE] {"Able was I, ere I saw Elba",
        "A man, a plan, a canal, Panama",
        "Desserts, I stressed",
        "Kayak"
    };

    //Greet User
    cout << "Palindrome Checker\n\n";

    //Loop through all the palindromes
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < sizeof(PUNCTUATIONS); j++)
        {
            if (strArr[i].find(PUNCTUATIONS[j]) != string::npos)
            {
                strArr[i].erase(remove_if(strArr[i].begin(), strArr[i].end(), [](char c) {
                    return c== PUNCTUATIONS[j];
                }), strArr[i].end());
            }
        }
        // if (strArr[i].find(',') != string::npos || strArr[i].find(' ') != string::npos || strArr[i].find('!') != string::npos)
        // {
        //     strArr[i].erase(remove_if(strArr[i].begin(), strArr[i].end(), [](char c) {
        //         return c== ',' || c == ' ' || c == '!';
        //     }), strArr[i].end());
        // }
        
        cout << strArr[i] << (IsPalindrome(strArr[i], 0, strArr[i].length() - 1) ? " is " : " is not ") 
             << "a palindrome." << endl;
    }

    //zeroize
    for (int i = 0; i < SIZE; i++)
    {
        strArr[i].clear();
    }
    
    //release memory
    delete[] strArr;

    //set to null pointer
    strArr = nullptr;

    //End normally
    return 0;
}

// Recursive function to determine if a string is palindrome or not
// The function takes a string as an argument
// Return true if its a palindrome and false if it's not
// bool IsPalindrome(string str, int size){
//     //Base Case
//     // if(size <= str.length()/2 )
//     //     return true;

//     if((str.length() - size) > (size - 1))
//         return true;

//     if (str.find(',') != string::npos || str.find(' ') != string::npos || str.find('!') != string::npos)
//     {
//         str.erase(remove_if(str.begin(), str.end(), [](char c) {
//             return c== ',' || c == ' ' || c == '!';
//         }), str.end());
//     }
    
//     cout << str << endl;

//     return tolower(str[str.length() - size]) == tolower(str[size - 1]) && IsPalindrome(str, size - 1);
// }


bool IsPalindrome(string str, int left, int right){

    if (left >= right)
    {
        return true;
    }
    
    return tolower(str[left]) == tolower(str[right]) && IsPalindrome(str, left + 1, right - 1);
}