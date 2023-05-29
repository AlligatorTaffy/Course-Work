/**
 * Chapter 9 - Adv. Classes and the HEAP
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Build a class with two private data member, m_Name and m_Strength
 * Build a constructor with default values for name and strength
 * Build a Talk() member function that sends those two values to cout
 */

class Player {
	friend void Display(const Player& givenPlayer);
	friend ostream& operator<<(ostream& os, const Player& givenPlayer);
private:
	string m_Name;
	int m_Strength;
public:
	Player(string gName = "Ryu", int gStrength = 9001): m_Name(gName), m_Strength(gStrength) {}
	void Talk() {
		cout << "Fighter's name is " << m_Name << ", with a strength of " << m_Strength << ".\n";
	}
	string GetName() const { return m_Name; }
};

class Car {
private:
	vector<Player> m_pass;		// a vector of passengers
public:
	Car(int seats = 1){ m_pass.reserve(seats); }		// setting vector size to 1 (save RAM)
	void Add( const Player givenPlayer) { m_pass.push_back(givenPlayer); }
	void FireDrill() const {		// const is read only
		for(int i = 0; i < m_pass.size(); i++) {
			cout << m_pass[i].GetName() << endl;
		}
	}
};

void Display(const Player& givenPlayer) {
	cout << "Hey! I can see all of givenPlayer's private stuff!\n";
	cout << "m_Name = " << givenPlayer.m_Name << endl;
	cout << "m_Strength = " << givenPlayer.m_Strength << endl;
	cout << "I'm not weird, you're weird!\n";
}

ostream& operator<<(ostream& os, const Player& givenPlayer) {
	os << "[Debug]\n";
	os << "Player's name = " << givenPlayer.m_Name << ".\n";
	os << "Player's strength = " << givenPlayer.m_Strength << ".\n";
	os << "[/Debug]\n";
	return os;
}

int main() {
	cout << "QWERTY\n";
	Player street;
	street.Talk();
	/*	
	string user;
	int strength;
	cout << "Create a player::";
	getline(cin, user);
	cout << "Input a strength::";
	cin >> strength;
	Player player(user, strength);
	player.Talk();
	Car Clown;
	Clown.Add(Player("Steve", 10));
	Clown.Add(Player("Frank", 20));
	Clown.Add(Player("Dave", 666));
	Clown.FireDrill();
	*/
	Display(street);
	Player pam("Paaaaaaaameeeeelllla", 25);
	cout << pam << endl;

	return 0;
}
