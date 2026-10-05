// main.cpp - Test driver for the Bag class.
#include <iostream>
#include <random>
#include "Bag.h"
using namespace std;

const int NUM_ITERATIONS = 25;
const int MAX_BAGS = 5;
const int ADD_PERCENT = 70;     // favor adding over removing

// Mersenne Twister engine (32-bit), seeded once from the system's entropy source
mt19937 rng{random_device{}()};

// Uniformly distributed integer in [lo, hi]
int randomInRange(int lo, int hi) {
    uniform_int_distribution<int> dist(lo, hi);
    return dist(rng);
}

// Adds qty of item to bag; all-or-nothing. Returns true on success.
bool addItems(Bag& bag, char item, int qty) {
    if (bag.size() + qty > bag.capacity()) return false;
    for (int i = 0; i < qty; i++) bag = bag + item;
    return true;
}

// Removes qty of item from bag; all-or-nothing. Returns true on success.
bool removeItems(Bag& bag, char item, int qty) {
    if (bag.count(item) < qty) return false;
    for (int i = 0; i < qty; i++) bag = bag - item;
    return true;
}

int main() {
    cout << "Welcome to the bag program.\n";
    int numBags = randomInRange(3, 5);
    cout << "We are creating " << numBags << " empty bags.\n\n";

    Bag bags[MAX_BAGS];   // only the first numBags are used

    for (int turn = 1; turn <= NUM_ITERATIONS; turn++) {
        bool adding = randomInRange(1, 100) <= ADD_PERCENT;
        int  qty    = randomInRange(1, 4);
        char item   = static_cast<char>('a' + randomInRange(0, 5));
        int  b      = randomInRange(1, numBags);

        cout << "Now we will attempt to " << (adding ? "add " : "remove ")
             << qty << " of item " << item
             << (adding ? " to" : " from") << " bag " << b << "\n";

        bool ok = adding ? addItems(bags[b - 1], item, qty)
                         : removeItems(bags[b - 1], item, qty);

        cout << "This operation " << (ok ? "succeeded." : "failed.") << "\n";
        cout << "Bag " << b << ": The contents of the bag are now as follows: "
             << bags[b - 1].list() << "\n\n";
    }

    cout << "----- Final contents -----\n";
    for (int i = 0; i < numBags; i++)
        cout << "Bag " << (i + 1) << ": " << bags[i].list() << "\n";

    // Demonstrate bag-bag operators using two randomly chosen distinct bags
    int x = randomInRange(1, numBags);
    int y;
    do { y = randomInRange(1, numBags); } while (y == x);

    cout << "\n----- Bag operators demonstration (Bag " << x << " and Bag " << y << ") -----\n";
    cout << "We will now subtract Bag " << y << " from Bag " << x << "\n";
    cout << "Resulting bag: The contents of the bag are as follows: "
         << (bags[x - 1] - bags[y - 1]).list() << "\n\n";

    cout << "We will now find the intersection of Bag " << x << " and Bag " << y << "\n";
    cout << "Resulting bag: The contents of the bag are as follows: "
         << (bags[x - 1] * bags[y - 1]).list() << "\n\n";

    cout << "We will now find the union of Bag " << x << " and Bag " << y << "\n";
    Bag u = bags[x - 1] / bags[y - 1];
    cout << "Resulting bag: The contents of the bag are as follows: " << u.list() << "\n";

    return 0;
}