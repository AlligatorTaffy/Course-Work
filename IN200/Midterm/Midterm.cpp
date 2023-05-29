#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

string input;
vector<string> locations;
vector<string>::iterator iter;

string NumberFour(string place) {
	locations.push_back(place);

	return place;
}


int main() {


	// Number 1
	string name = "AlligatorTaffy";
	cout << name << endl;
	cout << name.size() << endl;
	

	// Number 2
	float nums[5];
	nums[0] = 3.1415;
	nums[1] = 7.777;
	nums[2] = 55;
	nums[3] = 9999.99;
	nums[4] = 1;
	for(int i = 0; i < 5; i++) {
		cout << nums[i] << endl;
	}
	

	// Number 3
	int playerNumber;
	cout << "Hey there, please insert a number between 1 - 100" << endl;
	cin >> playerNumber;
	if(playerNumber > 100) {
		cout << "You need to try again." << endl;
	}
	else if(playerNumber > 66) {
		cout << "Sweet number, it's bigger than 66.  Woo! The top 1/3 of all possible numbers" << endl;
	}
	else if(playerNumber == 33) {
		cout << "That is exactly 33!  That is the number I was looking for!" << endl;
	}
	else {
		cout << "Weak number.  How unremarkable!" << endl;
	}


	// Number 4
	do {
		cout << "Please enter a location you'd like to go? (type 'quit' to quit)" << endl;
		getline(cin, input);
		NumberFour(input);
		cout << endl;
		cout << "Names List:";
		for(iter = locations.begin(); iter < locations.end(); iter++) {
			cout << *iter << endl;
		}
	}
	while(input != "quit");


	// Number 5
	srand(time(0));
	int hell[100];
	for(int i = 0; i < 100; i++) {
		hell[i] = (rand() % 1000) + 1 ;
	}
	
	for(int i = 0; i < 100; i++) {
		if(hell[i] == 666) {
			cout << i + 1 << ". " << hell[i] << endl;
			cout << "You need to create a salt circle fast!" << endl;
			break;
		} else { 
			cout << i + 1 << ". " << hell[i] << endl;
		}
	}
	

	// Number 6
	int choice = (rand() % 4);
	switch(choice) {
		case 0:
			cout << "The quick brown dog.. or was it fox?" << endl;
			break;
		case 1:
			cout << "So, uh, have you ever seen 'Clash of the Titans'?" << endl;
			break;
		case 2:
			cout << "I think unicorns are kickass!!" << endl;
			break;
		case 3:
			cout << "Sorry, sorry dude, Got a little excited." << endl;
			break;
		case 4:
			cout << "He fixes the cable?" << endl;
			break;
	}


	return 0 ;
}

