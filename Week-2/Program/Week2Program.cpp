/******************************************************************************

Week2Program.cpp

Aung Pyae Lin

CS260 Fall 2026 - Inst: Mitch Priestley

Purpose: This program does a thing (state purpose briefly in 1-2 lines)

Specification: Elaborate on what the program does and how it does it, detailing I/O (2-4 lines)

Sources: (list the textbook, websites, and other sources consulted; cite liberally)

Ok to share

******************************************************************************/
#include <iostream>
#include <random>
#include "bag.h"

using namespace std;

//Function Declaration
void CreateBag();
int GenerateRandomInt(int);

int main(){
    cout << "Welcome to bag program" << endl;

    CreateBag();

    return 0;
}

int GenerateRandomInt(int NUM_RANGE) {
    static bool initialized {false};

    static mt19937 generator;  // Mersenne Twister

    // Initialize the random engine if not already done
    if (!initialized) {
        // Use a random device to seed the generator
        random_device rd;
        generator.seed(rd());

        initialized = true;
    }
    uniform_int_distribution<int> distribution(0, NUM_RANGE - 1);
    return distribution(generator);
}
