//	In Class assignment #4

#include <iostream> 
#include <string>
using namespace std ;

int main () {
	int iter = 0 ;
	while (iter < 10) {
		cout << ++iter << endl ;
	}
	// for(initialization; test; action)
	cout << "New loop incoming!\n" ;
	for(int i = 0; i < 10; i++) {
		cout << i ;
	}
	cout << endl ;
	for(int i = 0; i < 50; i += 5) {
		cout << i << " ";
	}
	for(int num = 100; num < 0; num -= 5) {
		cout << num << " ";
	}
	cout << endl ;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 3; j++) {
			cout << i << "." << j << "  " ;
		}
		cout << endl; 
	}

	cout << "End of loops lesson.\n" ;
	cout << "Let's talk strings. \n" ;

	string first = "Game" ;
	string last = "Over" ;
	string excited(3, '!') ;

	string phrase = first + " " + last + excited;		//concatenator is +
	cout << "The phrase is " << phrase << endl ;

	cout << "the phrase has " << phrase.size() << " characters in it.\n" ;
	cout << "Changing the fourth character >> \n" ;
	phrase[3] = '3' ;
	cout << "the phrase is " << phrase << endl ;
	cout << "Changing the eighth character >> \n" ;
	phrase[7] = '3' ;
	cout << "the phrase is " << phrase << endl ;
	for(int i = 0; i < phrase.size(); i++) {
		cout << "phrase[" << i << "] = " << phrase[i] << endl;
	}

	cout << "enough about strings, here are arrays!\n" ;
	string inv[10];
	int numItems = 0 ;
	inv[numItems++] = "Master Sword" ;
	inv[numItems++] = "Boomerang" ;
	inv[numItems++] = "Deku Shield" ;

	cout << "The first item in my inventory is the " << inv[0] << endl; 
	for(int i = 0; i < numItems; i++) {
		cout << i + 1 << ". " << inv[i] << endl ;
	}
	// add another item, then change item
	cout << "\nWe picked up the Blue Tunic!\n" ;
	inv[numItems++] = "Blue Tunic" ;
	for(int i = 0; i < numItems; i++) {
		cout << i + 1 << ". " << inv[i] << endl ;
	}
	cout << endl ;

	cout << "You caught a Fairy in a Bottle!\n" ;
	inv[1] = "Fairy" ;
	for(int i = 0; i < numItems; i++) {
		cout << i + 1 << ". " << inv[i] << endl ;
	}

	cout << "\nTesting Scope™\n" ;
	int myScore = 10;
	{
		int myScore = 10000 ;
		cout << "my score = " << myScore << endl;
	}
	cout << "my score = " << myScore << endl;

	return 0 ;
}


/*
Do word jumble from chapter 3

change the while loop to a do-while
do 8 words instead of 3

/*
