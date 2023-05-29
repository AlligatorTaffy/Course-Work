//	Week 5 -- Vectors, iterators, and algorithms

#include <iostream>
#include <string>
#include <vector>				// for using vectors
using namespace std;

int main() {
	vector<string> inv;
	cout << "You've dried your clothes by the campfire\n";
	cout << "but you hear zombies crawling in the shadows.\n";
	
	cout << "You grab a stick from the fire...\n";
	inv.push_back("Torch");
	cout << "a rock from the river...\n";
	inv.push_back("Rock");
	cout << "and a Swiss army knife from a nearby cadaver.\n";
	inv.push_back("Pocketknife");

	// A NEW CHALLENGER APPROACHES
	vector<string>::iterator changeIter;
	vector<string>::const_iterator readIter;
	cout << "Your items:\n";
	for(readIter = inv.begin(); readIter != inv.end(); ++readIter) {
		cout << *readIter << endl;		// * = dereference operator
	}

	cout << "Your torch has gone out.  It's DARK!\n";
	changeIter = inv.begin();		// iterator = iterator pointing to start of vector
	*changeIter = "Charred Club";	// value that changeIter is pointing at = "string"
	cout << "Your items:\n";
	for(readIter = inv.begin(); readIter != inv.end(); ++readIter) {
		cout << *readIter << endl;
	}

	cout << "You club another survivor to death!  She looked mean.\n";
	cout << "You monster.\n";
	cout << "She had a crossbow!! Totally worth it.  It's a horrible world.\n";
	inv.insert(inv.begin(), "Crossbow");

	cout << "Your items:\n";
	for(readIter = inv.begin(); readIter != inv.end(); ++readIter) {
		cout << *readIter << endl;
	}

	cout << "You find a grenade!\n";
	cout << "it should go in your belt, the 3rd slot of our vector.\n";
	inv.insert(inv.begin() + 2, "Grenade!!!");

	cout << "Your items:\n";
	for(readIter = inv.begin(); readIter != inv.end(); ++readIter) {
		cout << *readIter << endl;
	}

	cout << "You yell at the top of your lungs to attract the Zs.\n";
	cout << "You pull the pin on your grenade. . .\n\n";
	cout << "You drop the grenade at your feet and run as fast as you can.\n";
	inv.erase(inv.begin() + 2); 

	cout << "Your items:\n";
	for(readIter = inv.begin(); readIter != inv.end(); ++readIter) {
		cout << *readIter << endl;
	}

	// scenario - you can't remember where an item is.  Let's search for it.
	cout << "The blast knocked you off your feet and your items fall out of your pack.\n";
	cout << "you're searching for your rock.\n";
	
	for(readIter = inv.begin(); readIter != inv.end(); ++readIter) {
		if(*readIter == "Rock") {
			cout << "You've found your rock!\n";
			break;
		} else if(readIter == inv.end() - 1) {
			cout << "You've looked everywhere and you can't find it.\n Damn.\n";
		}
	}

	return 0;
}
