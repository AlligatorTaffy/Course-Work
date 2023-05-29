//	IN200 In-Class Week 10

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//	Passing by Value
void badSwap(int givenNum1, int givenNum2) {
	int temp = givenNum1;
	givenNum1 = givenNum2;
	givenNum2 = temp;
}
//	Passing by Reference
void goodSwap(int& rGivenNum1, int& rGivenNum2){
	int temp = rGivenNum1;
	rGivenNum1 = rGivenNum2;
	rGivenNum2 = temp;
}

/*
What is passing a value?
Passing a value is sending a copy of the contents to a function.  A = 5 then a copy X = 5, X dies in the functions

What is passing by reference?
Passing by reference is creating a symbolic link to a variable.  Instead of sending the value of A we literally send A.

How do I create a reference and what value do I give it? 
You create a reference by tossing an ampersand to the definition.  string steve = "perry";  string& rSteve = steve;

*/

void display(const vector<string>& rVec) {
	cout << "Your list:\n";
	for(vector<string>::const_iterator readIter = rVec.begin(); readIter != rVec.end(); ++readIter) {
		cout << *readIter << endl;
	}
}

int main() {
/*
	int myScore = 4500;
	int yourScore = 1500;
	cout << "Mine = " << myScore << " and Yours = " << yourScore << endl;
	badSwap(myScore, yourScore);
	cout << "Mine = " << myScore << " and Yours = " << yourScore << endl;
	goodSwap(myScore, yourScore);
	cout << "Mine = " << myScore << " and Yours = " << yourScore << endl;



	cout << "In the middle of the niiiiiiight!\n";

	string lyric = "We can dance if we want to.\n";
	string& rLyric = lyric;
//	references cannot be changed once defined.  They cannot be not initialized string& rLyric; rLyric acts identically as a variable
	cout << rLyric;
	int score = 9000;
	int& rPlayerScore = score;
	cout << rPlayerScore << endl;
*/
	vector<string> Poops;
	Poops.push_back("Standard");
	Poops.push_back("Watery");
	Poops.push_back("Mush");
	Poops.push_back("Green");
	vector<string>& rPoops = Poops;

	display(Poops);
	return 0;
}
