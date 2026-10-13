/******************************************************************************
Week_3_Program.cpp

Aung Pyae Lin 

Purpose: The program is a text-based Minecraft Adventure game, where player 
go through different location in quest to slay the final Ender Dragon.Trying to
stay alive by making wise decisions with unpredictable outcomes.

Specification: The program greet the user first, then load the whole board from
a function and start the game. The program uses for-loop and switch cases to go 
through different locations, prompting user for differnt input and giving them
random outcomes. The program display stats after every location and give the 
user the final stats if the game ended.

MAX GRADE: Meets requirements and specifications, 60%
           Has five-fully functional gameboard spaces, +5%
           Has consequential user interaction, +5% per spaces, total = 25%

CS162 Spring 2026 - Inst: Mitch Priestley

Sources: CS162 Week 1 Lab 1, Gaddis, Minecraft, cplusplus.com, Mitch Priestley,
        Friends and Families.

Ok to share
******************************************************************************/
#include <iostream>
#include <cstring>
#include <random> //For Marsenne Twister
#include <iomanip> //For Output formatting
#include <cctype>
#include <string>
#include <thread> //For time delay
#include <chrono> //To add time delay after every location
#include <limits> //to remove unwanted char input

using namespace std;

//Global Constants
const int SPACES = 5; //Number of spaces in the game

//Datatype to store all the information for the game required
struct Place{
    string name;
    string description;
    string choiceA;
    string choiceB;
};

//Function Prototypes
string GreetUser();
void LoadData(Place board[], int);
int GenerateRandomInt(int, int);   //For randomness outcomes
char UserChoiceInput();
void LoadingText(string, int);     //Display animation used for various cases
void Stats(int, int);              //Player stats after every space
void FinalSummary(int, int, bool ,bool, string);
void ApplyDamage(int&, int&, int); //Function to apply damage if dealt to the player
void ClearBoard(Place board[], int);// Purge data of struct

int main(){
    //Declare Variables
    string playerName; //Name of the player, entered by the user 
    Place board[SPACES]; //Gameboard, hardcoded by program
    
    int health = 100, //The health of the player, programmed, can be changed by player interactions
        armor = 0,    //The armor of the player, programmed
        probability = 0,// Probability for randomness, Programmed
        damage_dealt = 0;// Damage dealt to the player in different locations, Programmed

    char userChoice = '\0';// For determining what user chose, entered by user

    bool dragonDefeated = false, //Dragon status, programmed
         gameover = false; // Game status, programmed
    
    //Greeting
    playerName = GreetUser();
    
    //Load the game files, Hardcoded
    LoadData(board, SPACES);

    cout << "You will adventure through different places in your journey to beat the Ender Dragon.\n";
    cout << "Keep in mind of your health and armor when deciding what to do.\n";
    cout << "Good Luck Adventurer.\n\n";

    //Add a loading screen for user to read the instructions
    LoadingText("\rStarting the game", 1500);

    //Start the game
    for (int space = 0; !gameover && space < SPACES; space++)
    {
        // Title of the locations
        cout << endl << setfill('-') << setw(42) << '-' << endl;
        cout << "         Location #" << space+1 << ": " << board[space].name << endl;
        cout << setfill('-') << setw(42)<< "-" << endl;
        cout << board[space].description << endl; //Display the discription of the location to user
        cout << "A. " << board[space].choiceA << endl; //Display The choice one to user
        cout << "B. " << board[space].choiceB << endl; //Display the choice two to user

        //Prompt user for choice
        userChoice = UserChoiceInput();
        //Switch case based on different locations.
        switch (space)
        {
        case 0: //At the village
            if (userChoice == 'A')
            {
                probability = GenerateRandomInt(1,100);
                if (probability >= 50)
                {
                    cout << "You found armors in the chest.\n"
                            "+25 armors.\n";
                    armor += 25;
                }else if(probability < 50 && probability >= 25){
                    cout << "You found some potions to boost your health.\n";
                    health += 25;
                    if (health >= 100)
                    {
                        health = 100;
                    }
                }else{
                    cout << "You found nothing and carried on.\n";
                }
                
            }else{
                cout << "You skipped the village and carried on.\n";
            }
            break;
        case 1://At the Cave
            if (userChoice == 'A')
            {
                cout << "You decided to fight the zombies" << endl;
                probability = GenerateRandomInt(0,100);
                if (probability <= 20)
                {
                    cout << "You lost all of your health while fighting the zombies.\n";
                    health = 0;
                    gameover = true;
                }else if(probability > 20 && probability <= 60){
                    cout << "You bravely fought off all the zombies, however, you suffered some damages.\n";
                    ApplyDamage(health, armor, 25);
                }else{
                    cout << "You fought off the zombies unharmed.\n";
                }
                cout << "You found the diamonds.\n";
            }else{
                cout << "You took a safer path ";
                probability = GenerateRandomInt(0,100);
                if (probability <= 10)
                {
                    cout << "and you lost some health due to hanger.\n";
                    health = health - 10;
                }else{
                    LoadingText("\rMining through the cave", 300);
                }
                
            }
            cout << "You successfully mined the diamonds and finally built the nether portal to go to the Nether.\n";
            break;
        case 2: // At the Nether
            if (userChoice == 'A')
            {
                cout << "You decided to fight the blazes" << endl;
                probability = GenerateRandomInt(0,100);
                if (probability <= 10)
                {
                    cout << "You lost all of your health while fighting the blazes.\n";
                    health = 0;
                    gameover = true;
                }else if(probability > 10 && probability <= 50){
                    cout << "You fought all the blazes and got the blaze rods you needed, however, you suffered minor damages.\n";
                    ApplyDamage(health, armor, 25);
                    cout << "You found the blaze rods you needed and started to craft Eyes of Ender to search for The End Portal.\n";

                }else{
                    cout << "You fought off the blazes and go the blaze rods you needed.\n";
                }
            }else{
                cout << "You took the safer route and tried to find the chest, which took some time.\n\n";
                LoadingText("\rVenturing the Nether", 300);
                cout << "You found the blaze rods you needed and started to craft Eyes of Ender to search for The End Portal.\n";
            }
            break;
        case 3: //Back to real world
            if (userChoice == 'A')
            {
                probability = GenerateRandomInt(0,100);

                if (probability <= 75)
                {
                    cout << "You found the End Portal without any difficulties.\n";

                }else{
                    cout << "You encountered some enderman and fought them off, howeverm, you suffered some minor injuries.\n";
                    health = health - 10;
                }
                
            }else{
                cout << "You decided to take a short break and gained some health.\n"
                        "+20 Health\n"; 
                health += 20;
                if (health > 100)
                {
                    health = 100;
                }
                      
            }   
            cout << "You reached the End Portal and went to it.\n";
            break;
        case 4: //At the End World
            if (userChoice == 'A')
            {
                probability = GenerateRandomInt(0,100);
                if (probability <= 40)
                {
                    cout << "The Ender Dragon has defeated you.\n";
                    health = 0;
                    gameover = true;
                }else if(probability > 40 && probability <= 80){
                    cout << "You defeated the Ender Dragon, but took heavy damage.\n";
                    health = health - 30;
                    dragonDefeated = true;
                }else{
                    cout << "You defeated the Ender Dragon without any struggle.\n";
                    dragonDefeated = true;
                }
                
            }else{
                probability = GenerateRandomInt(0,100);
                if (probability <= 70)
                {
                    cout << "You strategically defeated the Ender Dragon and won.\n";
                    dragonDefeated = true;
                }else{
                    cout << "You did some strategic attacks but the Ender Dragon countered them and killed you.\n";
                    health = 0;
                    gameover = true;
                }
            }
            break;
        }
        //Check if the user died while playing
        if (health <= 0)
        {
            health = 0;
            gameover = true;
            cout << "You have died during your adventure.\n";
        }

        //Display the status of the user after every locations
        Stats(health, armor);
        
        //Add time delay 2 seconds
        this_thread::sleep_for(chrono::seconds(2));
    }

    //Summary of the game:
    FinalSummary(health, armor, gameover, dragonDefeated, playerName);
    
    //Purge Data
    health = armor = probability = damage_dealt = 0;
    userChoice = '\0';
    dragonDefeated = gameover = false;
    playerName = string(playerName.length(), '\0');
    ClearBoard(board, SPACES);

    //End normally
    return 0; 
}

//Purpose: Greet the user and welcomes them
//Arguments: No arguments
//Return value: The name of the Player is returned
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

//Purpose: Load the board into the array 
//Argument: The array to put data into and the size of the board
//Return value: no return
void LoadData(Place board[], int size){
    board[0].name = "Village";
    board[0].description = "You arrive at a village. There may be useful tools inside the chests,\n"
                            "or you can skip it and continue with your journey.";
    board[0].choiceA = "Loot the chests.";
    board[0].choiceB = "Skip the village.";

    board[1].name = "Cave";
    board[1].description = "You have now reached the cave, this is where you will need to find diamonds to prepare for Nether.\n"
                            "Zombies are nearby, and the cave is dangerous.";
    board[1].choiceA = "Fight the zombies for a faster path.";
    board[1].choiceB = "Avoid fighting and take a safer path.";

    board[2].name = "Nether World";
    board[2].description = "You have now reached the nether world, this is where you will be searching for blaze rod to creft Eyes of Enders\n"
                            "You can fight the blazes to get the blaze rods quickly.";
    board[2].choiceA = "Fight blazes.";
    board[2].choiceB = "Avoid fighting and Try to find chest containing blaze rods.";

    board[3].name = "Real World";
    board[3].description = "Congrat, you made it ouf of Nether, now you will have to find the end portal to get to the end.";
    board[3].choiceA = "Search now.";
    board[3].choiceB = "Take a short break and search.";

    board[4].name = "The End World";
    board[4].description = "You have made it to the End, this is where you will fight the ender dragona and win the game.\n"
                            "Becareful the dragon is very hostile.";
    board[4].choiceA = "Attack the dragon directly.";
    board[4].choiceB = "Fight strategically.";
}


//Purpose: Generate random number from range
//Argument: minimun value and maximun value for range
//Return: a random int is returned
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

//Purpose: The function prompts user for the choice to make in different places and validate them
//Arguments: No arguments
//Return: The choice of the user is reutrned
char UserChoiceInput(){
    char choice;
    //User input validation
    do
    {
        cout << "Choose A or B: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// Only use the first char and ignore the rest, to avoid typing AB
        choice = toupper(choice);
        
        //To make sure it is a letter
        if (!isalpha(choice))
        {
            cout << "Error: Please enter a letter.\n";
        }else if (choice != 'A' && choice != 'B') //To make sure it is A OR B
        {
            cout << "Error: Please enter either A or B.\n";
        }
        
    } while (!isalpha(choice) || (choice != 'A' && choice != 'B'));
    cout << endl;
    return choice;
}

//Purpose: Display the loading text for various uses
//Argument: The string text to display
//Return: No Return
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

//Purpose: Provide the stats to the player after every space
//Arguments: Two ints, Health and armor
//Return: No return
void Stats(int health, int armor){

    cout << endl;
    cout << setfill('.') << setw(42)<< "."<< endl;
    cout << left << setw(14)<< setfill(' ') << "Health: " << health << endl;
    cout << left << setw(14)<< setfill(' ') << "Armor: " << armor << endl;
    cout << setfill('.') << setw(42)<< "."<< endl << endl;
}

//Purpose: Give the user finaly summary of the game
//Arguments: Health, armor, game status, dragon status and name
//No return values
void FinalSummary(int health, int armor, bool gamestatus, bool dragonstatus, string name){
    cout << setfill('-') << setw(42)<< "-"<< endl;
    cout << "             Final Summary\n";
    cout << setfill('-') << setw(42)<< "-"<< endl << endl;
    
    if (gamestatus)
    {
        cout << "Sorry " << name << ", you have lost the game.\n"
                "The Dragon still remain undefeated.\n";
    }else{
        cout << "Congratulations... YOU WON!!!\n\n";
    }
    cout << boolalpha;
    cout << left << setw(14)<< setfill(' ') << "DragonDefeated: " << dragonstatus << endl;
    cout << left << setw(14)<< setfill(' ') << "Gameover: " << gamestatus << endl;
    cout << left << setw(14)<< setfill(' ') << "Health: " << health << endl;
    cout << left << setw(14)<< setfill(' ') << "Armor: " << armor << endl;
    cout << "\nGAME END.\n";
}

//Purpose: Apply damage taken by the user
//Arguments: Health and armor of the player and damage_dealt
//No return value
void ApplyDamage(int &health, int &armor, int damage)
{
    int remainingDamage = 0;
    if (armor >= damage)
    {
        armor -= damage;
    }
    else
    {
        remainingDamage = damage - armor;
        armor = 0;
        health -= remainingDamage;
    }

    if (health < 0)
    {
        health = 0;
    }
}

//Purpose: Purge data from the struct
//Arguements: The sturct and the size of the struct
//No return value
void ClearBoard(Place board[], int size){
    Place empty; //Create a new variable which is all empty

    for (int i = 0; i < size - 1; i++)
    {
        board[i] = empty;
    }
    
}