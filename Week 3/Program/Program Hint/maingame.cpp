/******************************************************************************

CS260 Game Programming Ideas

*******************************************************************************/
#include "LinkedList.h"
#include <iostream>

using namespace std;

// Declare Constants
const bool DEBUG = true; // DEBUG shows verbose output until completion
const int MAX = 5; // Number of spaces on gameboard

// Function Prototypes
void SetUpBoard(LinkedList&);

int main()
{
    // Declare variables, stating purpose and how they get populated
    LinkedList list;    // List of game space nodes, hard-coded in SetUpBoard
    Node* player_position {}; // Player's position on the board, tracked by game
    int 
        score = 0,      // Amt of money player has, determined by program
        choice = 0;     // Player's choice of action, entered each turn
    
    // Welcome Player
    cout << "Welcome to Mini-Monopoly!" << endl << endl;
    
    // Initialize gameboard
    SetUpBoard(list);
 
    // Display descriptions of all board spaces to confirm that board is set up
    if (DEBUG)
        list.display_new();
        
    // Start Play 
    cout << endl << endl << "Game begins..." << endl << endl;
        
    // Execute game proceeding space-by-space until last game space 
    player_position = list.head;
    
    while (player_position) {
        // Show description of current space and present choice
        cout << (player_position->desc) << endl;
        
        // Input choice and validate as numeric and as 0 or 1
        do {
            while (!(cin >> choice)) { // validate input as numeric
                cout << "Choice must be numeric! Please re-enter: ";
                cin.clear();
                cin.ignore(1024, '\n');
            }
            if (choice != 0 && choice != 1)
                cout << "Invalid choice. You must choose 0 or 1: ";
            } while (choice != 0 && choice != 1);
            
            
        // Ouput the consequence of the choice 
        
        // Modify score according to the choice
        
        // Report the current score as of the end of the turn
        
        // Advance the player to the next gameboard position
        player_position = player_position->next;
    }
    
    // Wrap up (delete dynamic memory)
    
    
    
    // Sign off
    cout << endl << "The game is over" << endl;

    // End normally
    return 0;
}

void SetUpBoard(LinkedList &list) {
        // Define first space as 'Go'
        list.append(new Node(
            "You are on 'Go'. \n"
            "You can start with 0) $1500 or 1) nothing. Choose 0 or 1.", 
            {"You receive $1500", "You get nothing!"}, 
            {1500, 0} ));
        
        // Define second space as Mediterranean Ave.
        list.append(new Node(
            "You are on 'Mediterranean Ave'. \n"
            "You can 0) buy it for $60 or 1) decline. Choose 0 or 1.", 
            {"You pay $60 and buy Mediterranean Ave.", "You proceed."}, 
            {-60, 0} ));
        
        // Define third space as Community Chest 
        list.append(new Node(
            "You are on 'Community Chest'. \n"
            "You can draw a card from 0) the top of the deck or "
            "1) bottom. \nChoose 0 or 1.", 
            {"You must pay a fine of $50!", "You win a $20 prize!"}, 
            {-50, 20} ));           
 
}