/******************************************************************************

Week3Program.cpp

Aung Pyae Lin

CS250 Fall Term - Inst: Mitch Priestley

Purpose: 

Specification:

Sources: CS162 Week 3 Program, CS250 Week 3 Program Hints, 

Ok to share

******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"

using namespace std;

void SetUpGame(LinkedList&);
string GreetUser();

int main(){

    LinkedList spaces;      // The list of spaces in the game, harded-coded
    
    string playerName;      // Name of the player, entered by user
    int choice, health = 0;  // The choice the user made and the score 

    playerName = GreetUser();



    return 0;
}

void SetUpGame(LinkedList& list){
    
}

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
    cout << "Try to beat the Enderdragon to win the game." << endl;
    
    return name;
}