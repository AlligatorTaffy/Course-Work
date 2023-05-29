//	Homework Week 6
//  Function, Function, what's your Function?

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

int health = 100;			//If below zero, game is over
int baseDmg;				// base damage between 1 and 12
int dmgMod;					// multiplied by baseDmg - between 1 and 4
int totalEnemiesKilled;		// how many times you've adventured without dying
char input = 'y';

char AskYesNo() {
	char response1;
	do {
		cout << "Would you like to continue?\n Please enter 'y' or 'n' : ";
		cin >> response1; 
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} while(response1 != 'y' && response1 != 'n');

	return response1;
}

int RollDie(int sides) {
	srand(time(0));
	return (rand() % sides) + 1;
}

void Say(string givenString) {
	cout << givenString << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Adventure() {
	Say("\nAn enemy attacks!");
	baseDmg = RollDie(12);
	cout << "Enemy attacks with " << baseDmg << endl;
	dmgMod = RollDie(4);
	cout << "It's a Fire Demon with a damage mod of " << dmgMod << "!!!\n";
	health -= baseDmg * dmgMod;
	cout << "My health is " << health << ".\n";
	totalEnemiesKilled++;
}

void Summary() {
	cout << "\n\nYou managed to survive against " << totalEnemiesKilled << " enemies.";
	cout << "\nThanks for playing!\n\n";
}

int main () {
	Say("Beginning Epic Story!");
	Say("Setting up variables...");
	Say("Reticulating Splines...");
	Say("\nStarting out on my adventure! The weather is beautiful!");
	do {
		if(input == 'y' && health >= 0) {
			Adventure();
			input = AskYesNo();
		} else {
			totalEnemiesKilled--;
			cout << "\nWAIT!  How can you continue?  Your Health is " << health << " YOU'RE DEAD!";
			break;
		}
	} while(input != 'n');
	Summary();

	return 0;
}
