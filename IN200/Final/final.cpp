/**
 * Coding Final for IN200
 * Let's Make the Magic Happen, it has been a blast!
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Declarations
void AddGame(vector<string>& givenVec, string givenGame);
void DisplayFavs(vector<string> *givenVec);

// Global Definitions

//Number 1
string Names[] = {"Frank", "Mike", "Brice", "Brian", "Sally", "Erin", "Sheila", "Fred", "Ashley", "Betty"};

//Number7
class Bot {
private:
	string m_Name;
	int m_Health;
	int m_Damage;
public:
	Bot(string name = "Starscream", int health = 100, int damage = 0) {
		m_Name = name;
		m_Health = health;
		m_Damage = damage;
	}
	void Battlecry() {
		cout << "I am " << m_Name << "! I have " << m_Health << " health and I have " << m_Damage << " damage!\n";
	}
	void Attack(Bot& givenBot, int givenDamage) {
		givenBot.TakeDamage(givenDamage);
	}
	void TakeDamage(int givenDamage) {
		m_Health -= givenDamage;
	}
};


int main() {

//Number 2
	int numNames = 10;
	for(int i = 0; i < numNames; i++) {
		cout << Names[i] << endl;
	}

//Number 3
	vector<string> favs;

//Number 4B
	AddGame(favs, "Super Mario RPG");
	AddGame(favs, "Phantasy Star Online");
	AddGame(favs, "Sonic the Hedgehog 2");
	AddGame(favs, "Legend of Zelda: A Link to the Past");
	AddGame(favs, "Legend of Zelda: Link's Awakening");

//Number5B
	DisplayFavs(&favs);

//Number6
	string input = "null";
	vector<string>::iterator iter;
	cout << "Search for a Game Title::";
	getline(cin, input);
	iter = find(favs.begin(), favs.end(), input);
	if(*iter == input) {
		cout << "Yes!  That's a favorite!\n";
	} else {
		cout << "Sorry!  Didn't see that game in the list!\n\nNow it is in the list!\n";
		favs.push_back(input);
	}
	DisplayFavs(&favs);

//Number7
	Bot starscream;
	Bot megatron("Megatron", 10000, 0);
	starscream.Battlecry();
	megatron.Battlecry();
	starscream.Attack(megatron, 100);
	megatron.Battlecry();
	starscream.Battlecry();

	return 0;
}

/**
 * Functions
 */


//Number 4A
void AddGame(vector<string>& givenVec, string givenGame) {
	givenVec.push_back(givenGame);
}

//Number5A
void DisplayFavs(vector<string> *givenVec) {
	sort((*givenVec).begin(), (*givenVec).end());
		for(int i = 0; i < (*givenVec).size(); i++) {
			cout << (*givenVec)[i] << endl;
	}
}
