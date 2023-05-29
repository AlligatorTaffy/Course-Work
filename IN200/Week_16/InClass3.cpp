/**
 * Chapter 9 - Adv. Classes and the HEAP
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
	string* m_pName;
public:
	//constructor is called when player is created
	Player(const string& name = "Bobalob") {
		cout << "[Constructor has been called]\n";
		m_pName = new string(name);		//allocate - type - value
	}
	//destructor is called when a player is destroyed
	~Player() {
		cout << "[Destructor has been called]\n";
		delete m_pName;
	}
	//Copy Constructor
	Player(const Player& copy) {
		cout << "[Copy Constructor has been called]\n";
		m_pName = new string;
		*m_pName = copy.GetName();
	}
	string GetName() const { return *m_pName; }
	void SetName(const string& name = "") { *m_pName = name; }
	void SayHi() const { cout << "Hello, my name is " << GetName() << ".\n"; }
};

void TestDestructor() {
	Player bob("bobalob");
	bob.SayHi();
}

void TestCopyConstructor(Player givenPlayer) {
	givenPlayer.SayHi();
}

int main() {
	cout << "ASDF\n";
	TestDestructor();
	cout << "\n\nCreating new Player named Meredith";
	Player meredith("Meredith");
	cout << "Testing Copy Constructor\n";
	TestCopyConstructor(meredith);
	cout << "Ending program now...\n";

	return 0;
}
