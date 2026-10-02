/******************************************************************************
Week 2 Lab 1 
Multisets_implemented_using_arrays.cpp
Aung Pyae Lin 
CS260 Fall 2026 Priestley

Purpose: Implement multisets using arrays.

Specification: A multisets or bag is implemented. The bag can contain any 
quantity of each of a half dozen different items. The contents of the multisets
or bag can be displayed in an inventory report or using roster notation. 

Technical Specification: A constant, MAX, specifies the maximum number of differing
items in a multiset,6. Each item has quantity. An array of int is used to represent
the multiset, with the values of the array elements being the quantities of the 
corresponding multiset elements.

Reminders: varName or var_name, CONST_NAME, FunctionNameVerb, TypeNameNoun, 
memberFunctionActionPhrase
*******************************************************************************/
#include <iomanip>
#include <iostream>
#include <string> // ## addition

using namespace std;

enum ItemType {A,B,C,D,E,F}; // ## addition

const int MAX = 6; // maximum number of different elements (U = {0,1,..., MAX - 1})
const string ITEM_NAMES[MAX] = {"a", "b", "c", "d", "e", "f"};

void DisplayInventory(int []);
void DisplayRoster(int []);

int main()
{
    int* myBag1 = new int[MAX] {2, 1, 2, 4, 0, 2}; //Sample bag, hard-coded

    //Announce Program
    cout << "Multiset Calculator\n\n";

    //  Display the multiset's contents as inventory and using roster notation
    cout << "Your bag's contents: " << endl;
    DisplayInventory(myBag1);
    cout << endl;

    cout << "myBag1 = ";
    DisplayRoster(myBag1);

    //Purge all data

    //free dynamic memory
    delete[] myBag1;
    myBag1 = nullptr;
    //End Normally
    return 0;
}

void DisplayInventory(int arr[]){
    cout << "Item Qty" << endl;

    for (int item = 0; item < MAX; item++)
    {
        cout << setw(4) << ITEM_NAMES[item]
             << " " << setw(3) << arr[item] << endl;
    }
    
}

void DisplayRoster(int arr[]){
    bool first = true; // first item to be displayed
    cout << '{';
    for (int item = 0; item < MAX; item++)
    {
        for (int count = 0; count < arr[item]; count++)
        {
            if (!first)
                cout << ", ";
            else 
                first = false;
            cout << ITEM_NAMES[item];
        }
        
    }
    cout << '}';
}

