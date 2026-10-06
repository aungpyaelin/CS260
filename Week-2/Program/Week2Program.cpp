/******************************************************************************

Week2Program.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley

Purpose: This program demonstrates the creating multisets and performing operations on them.

Specification: This program demonstrates the creation of multisets and the performance of 
various operations on them. The program first creates a random number of bags and fill/remove
various item types from the bag. Then the program display the contents of each bag. The 
program then perform the bag operations such as Union, Intersection, and Difference, Addition.
The program zerioze data and clean up resources before exiting.

Technical Specification: The program use dynamic memory allocation to create and manage the bags.
Implement favored coin flips to determine the operation (add or remove). The addition is carried 
out by incrementing the item count in the corresponding index. for example index 1 = a, index 2 = b, etc.
By incrementing the count of index 1, we will have another a in the set. Similarly removing
an item by decrementing the item count in the corresponding index. If the bag is empty, the operation will fail.
Bag condition is checked by isEmpty() function, which check the size of the bag. Then the contents
are displayed using displayRoster() function. Union operation is performed using the / operator and uses the 
max() function. Intersection operation by min() function. Bag subtraction by removing other bag items from 
this bag item. 

Sources: Computer Lab 1451, Gaddis, Week 2 Labs, Mitch Priestley, StackOverflow, GeeksforGeeks

Ok to share

******************************************************************************/
#include <iostream>
#include <random>
#include "bag.h"

using namespace std;

//Function Declaration
int GenerateRandomInt(int, int);    //Generate Random Integer
bool FavoredFlip(int);              //Simulate Biased Coin Flip

int main(){
    //Variable Declarations
    int numBags = GenerateRandomInt(3,5);   //Generate Random Number of Bags
    
    Bag* bags = new Bag[numBags];

    //Greet User
    cout << "Welcome to bag program" << endl;
    cout << "We are creating " << numBags << " empty bags." << endl << endl;

    //Fill the bags with items
    for (int i = 0; i < 25; i++) {
        bool flip = FavoredFlip(0.60);          // 60% chance of getting "adding"
        int num = GenerateRandomInt(1, 4);      // Generate random number of items
        int bag = GenerateRandomInt(1, numBags);// generate random bag number
        ItemType item = static_cast<ItemType>(GenerateRandomInt(0, MAX - 1));//Generate random item type

        cout << "We will now attempt to " << (flip ? "add " : "remove ") << num 
             << " of item " << ITEM_NAMES[item] << (flip ? " to bag " : " from bag ") << bag << endl;

        if (flip) {                             // If the flip is in favor of adding
            bags[bag - 1].insertItem(item, num);
        } else {                                // If the flip is in favor of removing
            if (bags[bag - 1].isEmpty()){       // If the bag is empty
                cout << "This operation failed: Bag is empty." << endl << endl;
                continue;
            }
            bags[bag - 1].removeItem(item, num);// Remove items from the bag
        }

        //Display the contents of the bag
        cout << "The contents of the bag are now as follows:";
        bags[bag - 1].displayRoster();
        cout << endl << endl;
    }

    // Display the contents of all bags
    for (int i = 0; i < numBags; i++) {
        cout << "Bag " << (i + 1) << ": ";
        bags[i].displayRoster();
        cout << endl;
    }
    cout << endl;

    //Demonstrate bag operations
    cout << "We will now subtract Bag 2 from Bag 1" << endl;
    (bags[1] - bags[0]).displayRoster();
    cout << endl;

    cout << "We will now add Bag 2 to Bag 3" << endl;
    (bags[1] + bags[2]).displayRoster();
    cout << endl;

    cout << "We will now demonstrate union of Bag 1 and Bag 2" << endl;
    (bags[0] / bags[1]).displayRoster();
    cout << endl;

    cout << "We will now demonstrate intersection of Bag 2 and Bag 3" << endl;
    (bags[1] * bags[2]).displayRoster();
    cout << endl;

    cout << "The program has completed successfully." << endl;

    //Zeroize data
    numBags = 0;

    delete[] bags;
    bags = nullptr;

    //End normally
    return 0;
}

// Function to generate a random integer within a specified range
// Arguments: NUM_RANGE
// Returns: a random integer within a specified range
int GenerateRandomInt(int min, int max) {
    static bool initialized {false};

    static mt19937 generator;  // Mersenne Twister

    // Initialize the random engine if not already done
    if (!initialized) {
        // Use a random device to seed the generator
        random_device rd;
        generator.seed(rd());

        initialized = true;
    }
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

// Function to simulate a biased coin flip
// Arguments: favored (probability of getting "true")
// Returns: true with the specified probability
bool FavoredFlip(int favored) {
    return GenerateRandomInt(0, 1) <= favored;
}