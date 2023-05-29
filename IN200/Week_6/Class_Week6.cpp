//	Week 6 -- In Class Work
//	Function, Function, what's your Function?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//global variable
vector<string> inv; 

char AskYesNo() {
	char response1;
	do {
		cout << "Please enter 'y' or 'n' : ";
		cin >> response1; 
	} while(response1 != 'y' && response1 != 'n');

	return response1;
}

float AddTwoNumber(float number1, float number2) {
	return number1 + number2;
}

string AddTwoNumber(string number1, string number2) {
	return number1 + " + " + number2;
}

string Bananas(string givenString) {
	return givenString + " Banana!\n";
}

int Birthday(int givenAge) {
	return ++givenAge;
}

void InvSetup() {
	inv.push_back("Candy");
	inv.push_back("Funyuns");
	inv.push_back("Poop");
}

void ShowInv() {
	cout << "Your List:\n";
	for(int i = 0; i < inv.size(); i++) {
		cout << i + 1 << ". " << inv[i] << endl;
	}
}

inline void SayHello() {
	cout << "\nWelcome to Functions!\n";
}

string Super() {
	return "I'm having a SUPER day!\n";
}

int AddTwoNumber(int number1, int number2) {
	int sum = number1 + number2;
	return sum;
}

int main() {
	SayHello();
	cout << Super();
	cout << "The sum of 55 and 67 = " << AddTwoNumber(55, 67) << endl;
	cout << "The sum of 5.5 and 67.3 = " << AddTwoNumber(5.5f, 67.3f) << endl;
	cout << "Tell me dem numbas! " << AddTwoNumber("Five", "Seven") << endl;
	InvSetup();
	cout << endl;
	ShowInv();

	int myAge = 28;
	myAge = Birthday(myAge);
	cout << "It's my birthday!  I am " << myAge << " years old!\n" ;
	
	string testString;
	//getline(cin, testString);
	//cout << Bananas(testString) ;

	// in line function
	cout << "You have to type 'y' or 'n'!\n";
	cout << "See how i made you type '" << AskYesNo() << "' I am Evil!\n";

	return 0;
}
