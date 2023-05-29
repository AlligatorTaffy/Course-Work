//	Week 5 -- Vectors, iterators, and algorithms

#include <iostream>
#include <string>
#include <vector>				// for using vectors
using namespace std;

int main() {
	cout << "Hello.\n";
	cout << "Creating inventory and adding zombie survival tools!\n";
	vector<string> inv;			//	Inventory
	inv.push_back("Machete");		//	Adds an item to the inventory array
	inv.push_back("Sawed-off");
	inv.push_back("Chainsaw");

	for(int i = 0; i < inv.size(); i++) {
		cout << inv[i] << endl;
	}
	cout << "Chainsaw is out of gas, you thow it away.\n";
	cout << "You won't live long enough to find more gas for it anyway.\n";
	inv.pop_back();			// Deletes last item in your vector

	cout << "Your items:\n";
	for(int i = 0; i < inv.size(); i++) {
		cout << inv[i] << endl;
	}

	cout << "When crossing the river you lost all of your items.\n";
	cout << "Tough luck, but at least you're still alive.\n";
	inv.clear();

	if(inv.empty()) {
		cout << "You have nothing but wet clothes.\n";
	} else {
		cout << "Your items:\n";
		for(int i = 0; i < inv.size(); i++) {
			cout << inv[i] << endl;
		}
	}

	return 0;
}
