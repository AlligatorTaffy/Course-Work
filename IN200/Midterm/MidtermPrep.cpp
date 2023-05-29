#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

string compType;
	int compGamble;
		string playdmgType;
	int playgamble;

string PoopBananas() {
	srand(time(0));
	switch(rand() % 3) {
		case 0:
			return "Brice";
		case 1:
			return "Erika";
		case 2:
			return "John";
	}
	return "Brian";
}

void fight(string dmgType, int gamble) {
	cout << "Player's DmgType = " << dmgType << endl;
	cout << "Player's Gamble = " << gamble << endl;
	string types[4] = {"Fire" , "Water" , "Earth" , "Air"};
	compType = types[rand() % 4];
	compGamble = ((rand() % 50) + 25);
	cout << "Computer's DmgType = " << compType << endl;
	cout << "Computer's Gamble = " << compGamble << endl;
	if(playdmgType == compType) {
		playgamble = playgamble / 2;
		cout << "That's the same type!  Player Damage cut in HALF!";
	} else if(playgamble > compGamble) {
		cout << "You WIN!\n";
	} else {
		cout << "You LOSE!\n";
	} 
}

int main() {
	srand(time(0));
	cout << PoopBananas() << endl;
	
	cout << "What damage type will you choose?\n";
	getline(cin, playdmgType);
	cout << "what would you like to wager?\n";
	cin >> playgamble;
	fight(playdmgType, playgamble);
	return 0;
}