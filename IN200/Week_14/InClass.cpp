/**
 * 	In class work 11-8-17
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int randRange(int min, int max);

//	Angry Mutant Chicken
class Chicken {
private:
	string m_Mutation;	// Declaring Data Member - variable
	string m_Name;
	int m_Age;
public:
	Chicken(string gName = "Chick", string gMutation = "an extra wing"):
	m_Name(gName), m_Mutation(gMutation) {}
	void Squawk();		// Declaring Member function - function
	int GetAge() const {return m_Age;}	//	read-only
	void SetAge(int gAge) {
		if(gAge < 0) { 
			cout << "User is trying to set " << m_Name << "'s age to ";
			cout << gAge << "...\n";
			cout << "How would that even work?\n"; }
		else { m_Age = gAge; }
	}

};

//	create a new class ship
class Ship {
private:
	int m_ShipSpeed;
	

public:
	string m_ShipName;
	int m_Health;
	Ship(string gName = "USS Netscape", int gSpeed = 10):
	m_ShipName(gName), m_ShipSpeed(gSpeed), m_Health(100) {}
	void Parley() {
	cout << "The ship's name is " << m_ShipName << endl;
	cout << "The current speed is factor " << m_ShipSpeed << endl;
	}
	void Attack(Ship& givenShip) {
		givenShip.m_Health -= randRange(15,25);
		cout << m_ShipName << "'s health = " << m_Health << "   ";
		cout << givenShip.m_ShipName << "'s health = " << givenShip.m_Health << endl;
	}
};

int main() {
/*	cout << "Welcome to the Thunderdome, friend.\n";
	Chicken sanders;
	sanders.Squawk();

	Chicken little("Chicken Little", "I lay miniatrure adult chickens");
	little.Squawk();

	Chicken bert, ernie;
	bert.SetAge(412);
	cout << "Bert is " << bert.GetAge() << " years old.\n";
	cout << "Don't tell him - he's forgetten.\n";
	ernie.SetAge(-22);
	cout << "Ernie is " << ernie.GetAge() << " years old.\n";
	cout << endl;
	cout << endl;

	Ship shippy;
	shippy.Parley();


	make two ships fight.
	need what?
	while(ship1.health > 0 && ship2.health > 0) {
		ship1.attack(&ship2);
			ship2.health -= randRange(5,12);
			ship2.health -= randRange(5,12);
			cout ship1 health and ships health
		ship2.attack(&ship1);
			ship1.health -= randrange(15,25);
			cout ship1 health and ship2 health
		}
*/
	srand(time(0));
	Ship nautilus("Nautilus"), enterprise("Enterprise");
	do(nautilus.m_Health > 0 && enterprise.m_Health > 0) {
		if(nautilus.m_Health > 0) nautilus.Attack(enterprise);
		if(enterprise.m_Health > 0) {enterprise.Attack(nautilus);
	
	} while(nautilus.m_Health > 0 && enterprise.m_Health > 0);


	return 0;
}

/**
 * Functions
 */

void Chicken::Squawk() {
	cout << "Dar! My naem is " << m_Name << endl;
	cout << "I am horribly deformed!\n";
	cout << "My mutation is " << m_Mutation << endl;
}

int randRange(int min, int max) {
	return (rand() % (max - min)) + min;
}
