// Homework Week 2.

#include <iostream>
#include <string>
using namespace std ; 

//  Variables
int manaCount = 30 ;
string playerName = "null" ;
string horseName = "null" ;
int healthIRONSIDES = 100 ;
int healthPlayer = 60 ;
int healthHorse = 50 ;
int playerGold = 10 ;
int paralysis = 0 ;
int playerLevel = 1 ; 

// Constant Int
const int timeAlysiumPerDay = 29 ;

// Int
int main () {

//  String
    cout << "Welcome to the world of Alysium!\n" ;
    cout << "This world is filled with a mystic energy, called MANA, that can be harnessed for good or evil.\n" ;
    cout << "Before we embark on our quest...\nWhat is your name? :: " ;

//  Getline / Input from Player (1)
    getline (cin, playerName) ;
    cout << "Ah yes, " << playerName << ", we have heard of your previous accomplishments in other lands!  We are grateful to have you here!\n" ;
    cout << "And who is your equestrian companion?\nPlease enter your horse's name :: " ;

// Input from Player (2)
    getline(cin, horseName) ; 
    cout << horseName << ", such a fitting name.\n" ;
    cout << "Get some rest, " << playerName << ". There are only " << timeAlysiumPerDay << " hours left before the planet dies.  We embark in the morning.\n" ;
    cout << "\n\n\n[Dawn of the First Day]\n\n\n\n" ;
    cout << playerName << "!!!  Wake up!  We are under attack!  Franklin Delano Roosevelt is rolling through our front lines!\nThe terror of IRONSIDES is here!!\n" ;
    cout << "\n\n\n[BATTLE WITH IRONSIDES BEGINS]\n\n\n" ;
    cout << "----------\n[IRONSIDES HP-" << healthIRONSIDES << " : MANA-100]\n[" << playerName << " HP-" << healthPlayer << " : MANA-" << manaCount << "]\n[" << horseName << " HP-" << healthHorse << " : MANA-" << manaCount << "]\n----------\n\n" ;
    

// Enumerator    
    enum attacksIRONSIDES {SCREECH = 5, CRUTCHES = 10, ROLLOUT = 40, MANHATTANPROJECT = 80} ;    
    enum spellsPlayer {JUBILEE = 0, RESTA = 20, INTIMIDATINGSHOUT = 25, GIZONDA = 75} ;
    enum itemsPlayer {BERRY = 25, ELIXER = 30} ;
    cout << "IRONSIDES HP-" << healthIRONSIDES << ":  \"I'll crush all of you.  Prepare for a NEW DEAL!\"\n" ; 
    cout << "(IRONSIDES uses ROLL OUT)\n" ;
    cout << "(" << playerName << " receives 40 Damage!)\n" ;
    cout << "(" << horseName << " receives 40 Damage!)\n\n" ;
    
//  -=
    healthPlayer -= ROLLOUT ;
    healthHorse -= ROLLOUT ;
    cout << "----------\n[IRONSIDES HP-" << healthIRONSIDES << " : MANA-100]\n[" << playerName << " HP-" << healthPlayer << " : MANA-" << manaCount << "]\n[" << horseName << " HP-" << healthHorse << " : MANA-" << manaCount << "]\n----------\n\n" ;
    cout << "(" << playerName << " uses INTIMIDATING SHOUT)\n" ;
    healthIRONSIDES -= INTIMIDATINGSHOUT ; 
    paralysis = 3 ;
    cout << "(IRONSIDES receives 25 Damage! and now PARALYZED for the next " << paralysis << " turns)\n" ;
    cout << "(IRONSIDES is PARALYZED for the next " << paralysis << " moves)\n\n" ;
    cout << "----------\n[IRONSIDES HP-" << healthIRONSIDES << " : MANA-100]\n[" << playerName << " HP-" << healthPlayer << " : MANA-" << manaCount << "]\n[" << horseName << " HP-" << healthHorse << " : MANA-" << manaCount << "]\n----------\n\n" ;
    cout << "(" << playerName << " uses item BERRY on " << horseName << ")\n" ;

//  +=
    paralysis-- ;
    healthHorse += BERRY ; 
    cout << "(" << horseName << " regained 25 HP!)\n(IRONSIDES is PARALYZED for the next " << paralysis << " turns)\n\n" ;
    cout << "----------\n[IRONSIDES HP-" << healthIRONSIDES << " : MANA-100]\n[" << playerName << " HP-" << healthPlayer << " : MANA-" << manaCount << "]\n[" << horseName << " HP-" << healthHorse << " : MANA-" << manaCount << "]\n----------\n\n" ;
    
//  Decrement Operator
    paralysis-- ;
    cout << "(IRONSIDES is PARALYZED for the next " << paralysis << " turns)\n\n" ;
    cout << "----------\n[IRONSIDES HP-" << healthIRONSIDES << " : MANA-100]\n[" << playerName << " HP-" << healthPlayer << " : MANA-" << manaCount << "]\n[" << horseName << " HP-" << healthHorse << " : MANA-" << manaCount << "]\n----------\n\n" ;
    cout << "(" << playerName << " uses GIZONDA)\n" ;
    cout << "(" << playerName << " must roll an EVEN number from a 32-sided die to complete attack!)\n" ; 

// Modulus Operator
    cout << "(" << playerName << " rolls a " << 79678694 % 32 << "!)\n" ; 
    cout << "(IRONSIDES receives 75 Damage!)\n\n" ;
    healthIRONSIDES -= GIZONDA ;
    cout << "----------\n[IRONSIDES HP-" << healthIRONSIDES << " : MANA-100]\n[" << playerName << " HP-" << healthPlayer << " : MANA-" << manaCount << "]\n[" << horseName << " HP-" << healthHorse << " : MANA-" << manaCount << "]\n----------\n\n" ;
    cout << "(IRONSIDES is DEFEATED)\n\n" ;

//  Increment Operator
    cout << playerName << " Level-" << playerLevel << ".\n" ;
    playerLevel++ ;
    cout << playerName << " is now at Level-" << playerLevel << "!\n\n\n" ;
    cout << "END OF LINE\n\n" ;

    return 0 ;
}


