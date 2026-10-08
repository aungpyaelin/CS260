/******************************************************************************

Week 2 Lab 2
Multisets_implemented_using_maps.cpp
Aung Pyae Lin
CS260 Fall 2026 Priestley

Purpose: Implement multisets using maps instad of arrays.

Specification: A multiset or bag is implemented. The bag can contain any 
quantity of each of a half dozen different items. The contents of the multisets
or bag can be displayed in an inventory report or using roster notation. 

Technical Specification: A multiset or bag is implemented using a map from item 
name to quantity. The interface is unchanged from the array version. 

*******************************************************************************/
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

//List of item names used in the bag, in order
const string ITEM_NAMES[] = 
{"Apple", "Banana", "Cookie", "Donut", "Egg", "Fish"};

const int MAX = sizeof(ITEM_NAMES) / sizeof(ITEM_NAMES[0]);


void DisplayInventory(map<string, int> );
void DisplayRoster(map<string, int> );
int main()
{
    // map<string, int> myBag1;  //strings to int. it map the string to int

    // myBag1["apple"] = 7;

    // cout << "The quantity of apples in the bag is " << myBag1["apple"] << endl;

    // Map replaces the array: item name → quantity
    map<string, int> myBag1 {
        {"Apple", 2},
        {"Banana", 0},
        {"Cookie", 1},
        {"Donut", 4},
        {"Egg", 0},
        {"Fish", 2}
    };

    // Announce program
    cout << "Multiset Calculator \n\n";

    //Add one banana to the bag
    ++myBag1["Banana"];

    //Display the multiset's contents (inventory and roster)
    cout << "Your bag's contents: \n";
    DisplayInventory(myBag1);
    cout << endl;
    cout << "myBag1 = ";
    DisplayRoster(myBag1);

    //Purge all data 
    for (string str: ITEM_NAMES)
        myBag1[str] = 0;

    for (auto& [item, qty]: myBag1)
        qty = 0;


    return 0;
}
// Purpose: Displays inventory list for a multiset
// Argument: Pass the map that you want displayed
// No return value
// Side effect: Displays to console monitor
void DisplayInventory(map<string, int> bag){
    cout << "Item qty" << endl;
    for(const string& item: ITEM_NAMES){
        cout << setw(10) << left << item << " " << setw(3) << (bag)[item]
        << endl;
    }
}

// Purpose: Displays roster of a multiset
// Argument: Pass map to be rosterized
// No return value
// Side effect: Displays to console monitor
void DisplayRoster(map<string, int> bag){
	bool first = true; // internally tracks first item to suppress pre comma
	cout << '{';
	for (string item : ITEM_NAMES) {
		for (int count = 0; count < bag[item]; ++count) {
			if (!first)
				cout << ", ";
			else
				first = false;
			cout << item;
		}
	}
	cout << '}' << endl;
}