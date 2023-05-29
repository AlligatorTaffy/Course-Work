/**
 * Coding Final for IN200
 * So this is supposed to be easy?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
//Number 1
	int input;
	cout << "Select a Door 1, 2, or 3::";
	cin >> input;
	switch(input) {
		case 0: cout << "Shh!  This is the SECRET door ;)\n";
			break;
		case 1: cout << "You've picked DOOR #1 -- FANTASTIC!\n";
			break;
		case 2: cout << "You've picked DOOR #2 -- CONGRATS!\n";
			break;
		case 3: cout << "You've picked DOOR #3 -- REGRETS!\n";
			break;
		default: cout << "That's not a door!\n";
	}

//Number2
	string input2;
	cout << "Out of these, which is your favorite? (DOG, CAT, BUNNY)::";
	cin.ignore();
	getline(cin, input2);
	if(input2 == "DOG") {
		cout << "Look's like we have ourselves a dog person.\n";
	} else if(input2 == "CAT") {
		cout << "Are you Bubbles?  How's Sunnyvale?\n";
	} else if(input2 == "BUNNY") {
		cout << "Hip.  Hip Hop.\n";
	} else {
		cout << "You chose wrongly.\n";
	}

//Number3
	srand(time(0));
	cout << "\nEnjoy this random number::" << (rand() % 100) << endl;

	return 0;
}
