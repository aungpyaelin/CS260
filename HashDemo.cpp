/******************************************************************************
Hash Table

CS260 Week 1 

Purpose: Demonstrate a hash table with chaining.

Specification: Establish a separate chaining hash table, sometimes called
closed addressing, with a vector chain at each array position to store strings. 
Hash, Insert, and Display are implemented first. Optional: Also implement
Lookup, and finally Remove.

Words inserted: dog, cat, fox, cow

Technical specification: Each string is hashed by the sum of its characters'
ASCII values, modulo the size of the array.

Lessons/Reference Info:
Separate chaining: collisions go into a list/vector/chain at the bucket.
Open addressing: collisions stay inside the main array by probing.
A ragged or jagged data structure is a 2D structure, a table, where each row 
has its own length (number of columns per row can vary).

Assignment:
Read/study this program. Review the video if desired. Re-create this program
on your own strictly from the output and header comments. Once you have 
successfully reproduced this program, specify (.h) and implement (.cpp) a 
HashTable object with these features and behaviors, again using an array of 
vectors. Submit your object with a driver program.

Optional Extra Credits:
(1) After submitting the assigned object program (.h, .cpp, and main.cpp), modify
your program to use a Linked List instead of a vector to chain elements. Submit 
this version (.h, .cpp, and main.cpp) to Extra Credit submissions.
(2) Write a one-page summary of "21 Year Old Disproves 4 Decades Old Belief in
Computing" (YouTube)
(3) Write a one-page summary after watching "AlphaGo - The Movie | Full award-
winning documentary" (free on YouTube)
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 5;

const string
    INPUTS[] { "dog", "cat", "fox", "cow" },
    TEST_LOOKUPS[] { "dog", "barker", "cat", "meower", "fox", "sly one", "cow", "mooer" },
    TEST_REMOVALS[] { "flea", "dog", "wolf" },
    LOOKUP_STATUS[] { "Not found", "Found" },
    REMOVAL_STATUS[] { "Not found", "Removed" };

int Hash(const string&);
void Insert(vector<string>[], const string&);
void Display(const vector<string>[]);
bool Lookup(const vector<string>[], const string&); // Optional
bool Remove(vector<string> table[], const string& target); // Extra

int main()
{
	vector<string> table[TABLE_SIZE];   // An array to store vectors of names

	cout << "Hash Demo \n\n";

	for (const string& s : INPUTS) {
		cout << "Inserting " << s << " (hash value: " << Hash(s) << ")... \n";
		Insert(table, s);
	}

	Display(table);
	
	// Test optional additional features
    // Use flush to reveal which function call was attempted if program crashes

    // If Lookup is implemented:
	for (const string& s : TEST_LOOKUPS) {
		cout << "Looking up " << s << "... " << flush;
		cout << LOOKUP_STATUS[Lookup(table, s)] << "!\n";
	}
	
	cout << endl;
	
	// If Remove is implemented:
	for (const string& s : TEST_REMOVALS) {
        cout << "Attempting to remove " << s << "... " << flush;
        cout << REMOVAL_STATUS[Remove(table, s)] << "!\n";
	}

    Display(table);
    
    cout << "\nProgram complete.\n";

	return 0;
}

// Simple hash function
int Hash(const string& key) {
	int hash_value = 0;

	for (char c : key)
		hash_value += c;

	hash_value %= TABLE_SIZE;

	return hash_value;
}

// Insert a string into the hash table
void Insert(vector<string> table[], const string& key) {
	table[Hash(key)].push_back(key);
}

// Display the hash table
void Display(const vector<string> table[]) {
	cout << "\nHash Table Contents:\n";
	for (int idx = 0; idx < TABLE_SIZE; idx++) {
		cout << "Index " << idx << ": ";
		for (const string& s : table[idx])
			cout << s << " -> ";
		cout << "nullptr\n";
	}
	cout << endl;
}

// Determine whether the hash table contains a target string
bool Lookup(const vector<string> table[], const string& target) {
	bool found = false;
	int idx_i = Hash(target);

	for (size_t idx_j = 0; !found && idx_j < table[idx_i].size(); ++idx_j) {
		found = ( table[idx_i][idx_j] == target );
		if (found) // special output reveals loc
			cout << "[bucket " << idx_i << ", position " << idx_j << "] ";
	}

	return found;
}

// Remove a string from its vector chain; erase() collapses the vector
bool Remove(vector<string> table[], const string& target) {
    bool success = false;
    int idx_i = Hash(target);

    for (size_t idx_j = 0; !success && idx_j < table[idx_i].size(); ++idx_j) {
        if (table[idx_i][idx_j] == target) {
            table[idx_i].erase(table[idx_i].begin() + idx_j);
            success = true;
        }
    }

    return success;
}