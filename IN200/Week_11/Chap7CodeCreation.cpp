//	IN200 W 7pm -- Chapter 7 Code Creation
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int PassIntValue(int num1);
string PassStringValue(string words);
void PassStringRef(string& rwords);
void AddVectorRef(vector<string>& rVector, string& rInput);
void display(const vector<string>& rDisplay);
float Add(float& num1, float& num2);

int main() {
//	Passing by Values
	int intput;
	string words;
	cout << "Multiplying a number by 3!\nChoose a Number::";
	cin >> intput;
	cout << PassIntValue(intput) << endl;
	cout << "What would you like the the computer to shout?::";
	cin.ignore();
	getline(cin, words);
	cout << PassStringValue(words) << endl;
//	Passing by Reference
	string someString;
	cout << "Now we are passing by reference, What would you like to say?::" << endl;
	getline(cin, someString);
	cout << "So you want to say '" << someString << "'?" << endl;
	PassStringRef(someString);
	cout << someString;
	vector<string> vectorMan;
	vectorMan.push_back("Insert");
	vectorMan.push_back("More");
	vectorMan.push_back("Words");
	string vectorInput;
	cout << "Let's add something to the vector::";
	getline(cin, vectorInput);
	cout << "\nDisplaying the initial list:\n";
	display(vectorMan);
	AddVectorRef(vectorMan, vectorInput);
	cout << "\nDisplaying the final list:\n";
//	Constant reference to a vector
	const vector<string>& rList = vectorMan;
	display(rList);
//	Returning a constant to a float
	float num1;
	float num2;
	float answer;
	cout << "Let's add some floats!\nWhat is the first number?::";
	cin >> num1;
	cout << "And the second number?::";
	cin >> num2;
	answer = Add(num1, num2);
	cout << "This should be the answer = " << answer << endl;

	return 0;
}

int PassIntValue(int num1) {
	cout << "We are now multiplying " << num1 << " by 3!  The result = ";

	return num1 * 3;
}

string PassStringValue(string words) {
	string scream = "!!!!!!!!!!!!!!!";

	return words + scream;
}

void PassStringRef(string& rwords) {
	string first = "Listen to this guy wanting to say '";
	string last = "'. What a maroon.\n";
	string temp = rwords;
	rwords = first + temp + last;
}

void AddVectorRef(vector<string>& rVector, string& rInput) {
	rVector.push_back(rInput);
}

void display(const vector<string>& rDisplay) {
	for(vector<string>::const_iterator readIter = rDisplay.begin(); readIter != rDisplay.end(); ++readIter) {
		cout << *readIter << endl;
	}
}

float Add(float& num1, float& num2) {
	return num1 + num2;
}
