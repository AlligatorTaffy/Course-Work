//	Week 5 -- Let's Play the Name Changing Game!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int select = 0;
	string tempName = "null";
	string newName = "null";
	vector<string> names;
	vector<string>::iterator changeIter;
	names.push_back("Mario");
	names.push_back("Mallow");
	names.push_back("Geno");
	names.push_back("Bowser");
	names.push_back("Toadstool");
	cout << "\n\n\nWelcome to the Name Changing Game!";

	do {
		int list = 0;
		cout << endl;
		cout << endl;
		for(changeIter = names.begin(); changeIter != names.end(); ++changeIter) {
			cout << ++list << ". " << *changeIter << endl;
		}
		cout << "\n\nMain Menu:\n";
		cout << "1. Add a Name\n";
		cout << "2. Edit a Name\n";
		cout << "3. Delete a Name\n";
		cout << "4. List All Names\n";
		cout << "5. Exit\n\n";
		cout << "Select an Option::";
		cin >> select;
		if(select == 1) {
			cout << "\n\nAdd a name to the list::";
			cin.ignore();
			getline(cin, tempName);
			names.push_back(tempName);
			cout << "\n\nName successfully added!";
		}
		else if(select == 2) {	
			cout << "\n\nEdit a name in the list::";
			cin.ignore();
			getline(cin, tempName);
			changeIter = find(names.begin(), names.end(), tempName);
			if(changeIter == names.end()) {
				cout << "\nName not found in the list!";
			}
			else {
				cout << "\nReplace name with::";
				getline(cin, newName);
				*changeIter = newName;
				cout << "\nName successfully changed!";
			}
		}
		else if(select == 3) {	
			cout << "\n\nDelete a name in the list::";
			cin.ignore();
			getline(cin, tempName);
			changeIter = find(names.begin(), names.end(), tempName);
			if(changeIter == names.end()) {
				cout << "\nName not found in the list!";
			}
			else {
				names.erase(changeIter);
				cout << "\nName successfully deleted!";
			}
		}
		else if(select == 4) {
			cout << "\n\nList of Names:";
		}
		else if(select == 5) {
			cout << "\nThanks for playing!\n\n";
			break;
		}
		else {
			cout << "Please enter a number between 1-5!\n";
		}
	}
	while(select != 5);	


	return 0;
}
