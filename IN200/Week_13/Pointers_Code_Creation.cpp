/*
Week 13
Pointers Code Creation
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int PassValue(int x, int y);
string PassValue(string x, string y);
string *Add(vector<string> *inputVec, string word);
void *Display(vector<string> *inputVec);
float answer(float *x, float *y);

int main () {
	//	Passing an int by value
	int passint1 = 3;
	int passint2 = 5;
	cout << "We are now passing an int by value by adding 3 and 5\n";
	cout << "That value is = " << PassValue(passint1, passint2) << endl;
	cout << endl;

	//	Passing a string by value
	string word1 = "Chicken";
	string word2 = "McNuggets";
	cout << "We are now passing a string by value by combining the words 'Chicken' and 'McNuggets'\n";
	cout << PassValue(word1, word2) << endl;
	cout << endl;

	//	Passing a vector and string by pointer
	cout << "We are now going to pass vectors and strings by pointer.\n";
	vector<string> spells;
	vector<string>::iterator changeIter;
	string userInput = "null";
	do {
		cout << "Please add something to the list (type 'quit' to exit')::";
		getline(cin, userInput);
		*Add(&spells, userInput);
	} while(userInput != "quit");
	*Display(&spells);
	cout << endl;

	//	Constant Pointer
	cout << "Here's a Constant Pointer.\n";
	string favConsole = "Sega Dreamcast";
	string *const pFaveConsole = &favConsole;
	cout << *pFaveConsole << endl;
	cout << endl;

	//	Pointer to a Constant
	cout << "Here's a Pointer to a Constant!\n";
	string beer = "Coors Banquet";
	const string *favBeer = &beer;
	cout << "My favorite beer = " << *favBeer << endl;
	cout << endl;

	//	Constant Pointer to a Constant
	cout << "Here's a Constant Pointer to a Constant\n";
	cout << "It's read-only and you can't change what it points to.\n";
	string chips = "Lay's Sour Cream & Onion";
	const string *const pChips = &chips;
	cout << "My favorite chips are: " << *pChips << endl;
	cout << endl;

	//	Returning a Pointer to a Float
	float num1;
	float num2;
	float sum;
	cout << "Let's add some floats!\nWhat is the first number?::";
	cin >> num1;
	cout << "And the second number?::";
	cin >> num2;
	sum = answer(&num1, &num2);
	cout << "This should be the answer = " << sum << endl;

	return 0;
}

/**
 * 	Functions
 */

int PassValue(int x, int y) {
	return x + y;
}

string PassValue(string x, string y) {
	return x + y;
}

string *Add(vector<string> *inputVec, string word) {
	(*inputVec).push_back(word);
}

void *Display(vector<string> *inputVec) {
	vector<string>::iterator changeIter;
	for (changeIter = (*inputVec).begin(); changeIter < (*inputVec).end(); ++changeIter) {
		cout << *changeIter << endl;
	}
}

float answer(float *x, float *y) {
    return (*x) + (*y);
  }
