/******************************************************************************

Week3Program.cpp

Aung Pyae Lin

CS250 Fall Term - Inst: Mitch Priestley

Purpose: The program set up a game board and prompt user for their choice to make in different locations. 
The program will give the user different outcomes based on their choices and display the status of the user after every location. 
The program will also give the final summary of the game if the game ended.

Specification: The program greet the user first, then laod the game board from a function with hardcoded data 
and set the player position to the head of the list. The program uses while-loop to go through different spaces 
and prompt the user for different input and giving them different outcomes. If the health get below or equal to 0,
the game will terminate and display the final summary of the game. 

Technical Specifications: The program uses a linked list to store the game board spaces and their consequences.
The head of the linked list is public for the game to access. The while-loop will continue as long as
the player is alive or the head of the linked list is not null. The program will use a function to get the user's choice and validate it.
The program also uses chrono library to add time delay after every location to make the game more interactive.

Sources: CS162 Week 3 Program, CS250 Week 3 Program Hints, Week 3 Lab 2, 

Ok to share

******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include "LinkedList.h"

using namespace std;

// Function Prototypes
void SetUpGame(LinkedList&);       // Function to set up the game board
void LoadingText(string, int);     //Display animation used for various cases
int GetUserChoice(); 
string GreetUser();

int main(){
    // Declare variables, stating purpose and how they get populated
    LinkedList spaces;      // The list of spaces in the game, harded-coded
    Node* player_position {}; // Player's position on the board, tracked by game
    
    string playerName;      // Name of the player, entered by user
    int choice = 0;  // The choice the user made and the score 
    int health = 100; // The health of the player, programmed, can be changed by player interactions
    bool gamestatus = false; // The game status, programmed

    // Greeting
    playerName = GreetUser();

    SetUpGame(spaces);

    //Set the player position to the head of the list
    player_position = spaces.head;
    
    LoadingText("\rStarting the game", 1500);

    while(!gamestatus && player_position){
        cout << setfill('-') << setw(42)<< "-" << endl;
        cout << "         Location: " << player_position->name << endl;
        cout << setfill('-') << setw(42)<< "-" << endl;
        cout << player_position->desc << endl; //Display the discription of the location to user
        cout << "1. " << player_position->conseq[0] << endl; //Display the choice two to user
        cout << "2. " << player_position->conseq[1] << endl; //Display The choice one to user

        //Prompt user for choice
        choice = GetUserChoice();

        health += player_position->change[choice];

        if (health <= 0)
        {
            health = 0;
            gamestatus = true;
            cout << "Game Over. You died.\n";
        }

        //Display the status of the user after every locations
        cout << endl;
        cout << setfill('.') << setw(42)<< "."<< endl;
        cout << left << setw(14)<< setfill(' ') << "Health: " << health << endl;
        cout << setfill('.') << setw(42)<< "."<< endl;
        cout << endl;

        //Add time delay 2 seconds
        this_thread::sleep_for(chrono::seconds(2));

        player_position = player_position->next; // Move to the next space
    }

    //Sign off
    if(!gamestatus){
        cout << "Congratulations, " << playerName << "! You have completed the adventure with " << health << " health remaining." << endl;
    }
    else{
        cout << "Sorry, " << playerName << ". You have lost the game with " << health << " health remaining." << endl;
    }

    //Zerioze
    choice = health = 0;
    player_position = nullptr;
    playerName = string(playerName.length(), '\0');

    //Wrap up (delete dyanamically allocated nodes)
    while (spaces.head) {
        Node* temp = spaces.head;
        spaces.head = spaces.head->next;
        delete temp;
    }
    spaces.head = nullptr;
    
    //End normally
    return 0;
}

// Purpose: Set up the game board with spaces and their consequences
// Arguments: A reference to a LinkedList object
// Return: The list is populated with game spaces and their consequences
void SetUpGame(LinkedList &list){
    list.append(new Node{
        "Village\n", 
        "You arrive at a village. There may be useful tools inside the chests.\n", 
        {"You looted the chests and found some health potions." , "You decided to skip the village and move on."}, 
        {25, 0}});

    list.append(new Node{
        "Cave\n",
        "You enter a dark cave. You hear growls and see shadows moving.\n",
        {"You decided to fight the zombies.", "You took a safer path."},
        {-25, 0}});
    list.append(new Node{
        "Nether World\n",
        "You entered the Nether World. this is where you will be searching for blaze rod to creft Eyes of Enders\nYou can fight the blazes to get the blaze rods quickly.\n",
        {"You decided to fight the blazes.", "You took a safer path."},
        {-50, 0}});
    list.append(new Node{
        "Real World\n",
        "You have made it out of Nether, now you will have to find the end portal to get to the end.\n",
        {"You Searched for the end portal right away.", "You took a short break and gained some health."},
        {0, 25}});
    list.append(new Node{
        "The End Wordl\n",
        "You have made it to the End World. This is where you will fight the ender dragon and win the game.\n",
        {"You fought the dragon directly.", "You fought strategically."},
        {-70, -40}});
}

// Purpose: Get the user's name and validate it
// Arguments: None
// Return: The name of the user is stored in a string and returned
string GreetUser(){
    string name; 

    //Title of the game
    cout << setfill('-') << setw(42)<< "-"<< endl;
    cout <<"           Minecraft Adventure\n";
    cout << setfill('-') << setw(42)<< "-"<< endl << endl;

    cout << "Enter Your Name: " ; 
    getline(cin, name);

    //Default name to Player if user doesn't enter name
    if (name.length() == 0)
    {
        name = "Player"; 
    }

    //Greet the user.
    cout << "Welcome to Minecraft based adventure game, " << name << '.' << endl << endl;
    cout << "Try to beat the Enderdragon to win the game." << endl << endl;
    
    return name;
}

// Purpose: Display a loading animation for a given name and duration
// Arguments: A string name to display and an integer msec for the duration of each dot
// Return: No return value
void LoadingText(string name, int msec){
    //Display animation for to make time
    cout << name << flush;
    for (int dots = 0; dots < 3; dots++)
    {
        this_thread::sleep_for(chrono::milliseconds(msec));
        cout << "." << flush;
    }
    cout << endl;
}

// Purpose: Get the user's choice and validate it
// Arguments: None
// Return: An integer representing the user's choice (0 for choice 1, 1 for choice 2)
int GetUserChoice(){
    int choice;
    do {
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        if (choice != 1 && choice != 2)
            cout << "Invalid choice. Please enter 1 or 2." << endl;
    } while (choice != 1 && choice != 2);
    
    return (choice == 1) ? 0 : 1; // Return 0 for 1, 1 for 2
}