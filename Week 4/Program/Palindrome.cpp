/******************************************************************************

Palindrome.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley

Purpose: The program takes an array of string and check whether the strings are
Palindrome or not 

Specification: The program uses hard-coded array of strings, clean it so that the
string don't have any punctuations. Then uses recurive function to check if the 
string is Palindrome or not. Then zeroize the string arry, release dynamic memory,
and set to null ptr.

Technical Specification: The program uses dynamically allocated string array to store
the sentences and make sure the memory is freed up after the program. The program cleans
the array by using a built-in function of string library. It uses a for loop and 
compares the sentences with an array of punctuations. It then delete the punctuation 
to pass it to the IsPalindrome() function. The function uses a very similar function used
in the lab 2.  Checking the first and last char and passing the middle chars of the string
to the recursive function. With the base case being the center char.

Sources: Lab1Extended.cpp, Lab2.cpp, StackOverFlow

Ok to share

******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Global Constant
const int SIZE = 4;     //Numbers of sentences to check
const char PUNCTUATIONS[] {'.', '!', '?', ',', ':', ';', '\'', '\"', '-', '(', ')', '[', ']', ' '}; // List of punctuations to remove

//Function Prototype
bool IsPalindrome(string, int, int);

int main(){
    // Declare Variables    
    string* strArr = new string[SIZE] {"Able was I, ere I saw Elba",
        "A man, a plan, a canal, Panama",
        "Desserts, I stressed",
        "Kayak"
    };
    
    string cleanStr;    // Palindrome sentences after removing punctuations

    //Greet User
    cout << "Palindrome Checker\n\n";

    //Loop through all the palindromes
    for (int i = 0; i < SIZE; i++)
    {
        cleanStr = strArr[i];

        for (int j = 0; j < sizeof(PUNCTUATIONS); j++)
        {
            if (cleanStr.find(PUNCTUATIONS[j]) != string::npos)
            {
                cleanStr.erase(remove_if(cleanStr.begin(), cleanStr.end(), [j](char c) {
                    return c== PUNCTUATIONS[j];
                }), cleanStr.end());
            }
        }
        // if (strArr[i].find(',') != string::npos || strArr[i].find(' ') != string::npos || strArr[i].find('!') != string::npos)
        // {
        //     strArr[i].erase(remove_if(strArr[i].begin(), strArr[i].end(), [](char c) {
        //         return c== ',' || c == ' ' || c == '!';
        //     }), strArr[i].end());
        // }
        
        cout << strArr[i] << (IsPalindrome(cleanStr, 0, cleanStr.length() - 1) ? " is " : " is not ") 
             << "a palindrome." << endl;
    }

    cout << "\nProgram Completed\n";

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


// Recursive function to determine if a string is palindrome or not
// The function takes the string, the starting char index and the last char index
// Return true if the stirng is Palindrome and False if it's not
bool IsPalindrome(string str, int left, int right){
    // Base Case
    if (left >= right)
    {
        return true;
    }   
    // Recursive Case
    return tolower(str[left]) == tolower(str[right]) && IsPalindrome(str, left + 1, right - 1);
}