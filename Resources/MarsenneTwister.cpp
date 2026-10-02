// Week 1 Lab 1 starter
// CS162

// Program to fill an array with random numbers, echoing to screen
// This program employs Modern C++ to generate pseudo-random numbers

#include <iostream>
#include <random>       // Mersenne Twister

using namespace std;

int generateRandomInt(int max);

int main() {
    const int 
        MAX_RANGE{100},     // Set constant to the desired maximum range
        QUANTITY {10};          // Specify how many random numbers to generate
     int randomValue[QUANTITY];    // Establish array to store random numbers
    
    // Display header

    cout << "Random integer(s) between 0 and " << MAX_RANGE - 1 << ": " << endl;
    
    // Generate random numbers and echo to console
    for (int count = 0; count < QUANTITY; ++count) {
        randomValue[count] = generateRandomInt(MAX_RANGE);
        cout << randomValue[count] << " ";
    }

    cout << endl;

    // End program normally

    return 0;
}

// Function to generate a random integer in the range [0, max - 1]

// Accepts integer parameter to determine maximum value
// Returns an integer from 0 to max â€“ 1, inclusive 

int generateRandomInt(int max) {
    static bool initialized {false};

    static mt19937 generator;  // Mersenne Twister

    // Initialize the random engine if not already done
    if (!initialized) {
        // Use a random device to seed the generator
        random_device rd;
        generator.seed(rd());

        initialized = true;
    }
    uniform_int_distribution<int> distribution(0, max - 1);
    return distribution(generator);
}