//	IN200 In-Class Week 10

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string>& rVec) {
	cout << "Your list:\n";
	for(int i = 0; i < rVec.size(); i++) {
		cout << rVec[i] << endl;
	}
}

string& refToIndex(vector<string>& rVec, int i) {
	return rVec[i];
}

int main() {
	cout << "More stuffs\n";
	vector<string> loadout;
	loadout.push_back("Egg Blaster");		//rifle
	loadout.push_back("VARUNA");			//pistol
	loadout.push_back("DelSaber's Claw");	//Knife
	loadout.push_back("ScapeDoll");			//Thrown
	loadout.push_back("Moon Atomizer");		//Item

	string favPistol = refToIndex(loadout, 1);
	cout << "My fav pistol is " << favPistol << endl;
	string favKnife = refToIndex(loadout, 2);
	cout << "My fav knife is " << favKnife << endl;


	display(loadout);

	string& rifle = loadout[0];
	string& pistol = loadout[1];
	string& knife = loadout[2];
	string& thrown = loadout[3];
	string& iten = loadout[4];

/*

What is the point of a constant reference?
When you need to assign a constant value to a constant reference. a non-constant reference

How do I return a reference?
You define the function how you would want it to be returned.  Such as string& MyFunction(stuff in here)

What can i do with a returned reference?
You can have it display specified slots of a list without having to redefine functions.

*/
	return 0;
}
