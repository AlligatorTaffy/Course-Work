// Wednesday Night C++ Fall 2017
// In Class Work
// Chapter 1 Review

#include <iostream>
#include <string>	//needed for strings
#include <chrono>	//needed for sleep()
#include <thread>	//needed for sleep()
#include <cstdlib>	//for rand()
#include <ctime>	//for rand()
using namespace std ; 

string playerName = "null" ;
int healthCount = 0 ; 

int main () {

/*
	cout << "Hello\n" ;

// Reviewing the following topics:
	cout << "\nLet's do the Modulus shuffle\n" << "It's the remainder of a number like 100/37 = " << 100 % 37 << endl ;
	cout << "Now let's add a 1 into our variable\n" << healthCount ;
	healthCount++ ;
	cout << " is now " << healthCount << "!\n" ;
	cout << healthCount-- ;
	cout << "\nInsert Name :: " ;
	getline(cin, playerName) ;
	cout << playerName ;
	enum cars {Sentra = 0, Pinto, Chevelle = 20} ;
	cars myCar = Chevelle ;
	cout << myCar ;
*/
/*
// start of chapter 2
	// if, else if, and else
	// less than or equal to, greater than or equal to, test if equal to
	int playerAge ;
	cout << "\n\nHello! How old are you? | " ;
	cin >> playerAge ;
	if (playerAge >= 21 && playerAge != 28) {
		cout << "You're old enough to consume alcohol according to US law.\n" ;
	}
	else if (playerAge <= 17) {
		cout << "You've got a whole lot of extra laws attached to you as a minor in the US.\n" ;
	}
	else if (playerAge == 28) {
		cout << "Hey, you are the same age as Prof Foster! You probably have some things in common.\n" ;
	}
	else {
		cout << "Be irresponsible.  Prison builds character.\n" ;
	}
*/
/*
// 3. Switch, while, do-while
	enum movies {THEMATRIX = 1, STARWARS, LOTR, EVERAFTER} ;
	int playerChoice ;
	do {	
		cout << "\nI can do impressions! What movie would you like to hear a line from?\n" ;
		cout << "1 - The Matrix\n2. - Star Wars\n3. - Lord of the Rings\n4. - Ever After\n" ;
		cout << "You can also enter a '0' to quit this nonsense.\n" ;
		cin >> playerChoice ;
		switch(playerChoice) {
			case THEMATRIX:	cout << "\n\t'We've done it Trinity, we've found him.'\n" ; break ;
			case STARWARS:	cout << "\n\t'I thought they smelled bad on the outside!'\n" ; break ;
			case LOTR:		cout << "\n\t'It's a dangerout business, Frodo, going out your door.'\n" ; break ;
			case EVERAFTER:	cout << "\n\t'You cannot leave everything to fate, boy.  She's got a lot to do.'\n" ; break ;
			case 0:			cout << "\n\tThanks for listening!\n" ; break ;
			default:		cout << "\n\tThat wasn't one of the options! Enter a number 1 through 4.\n" ;
		}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000)) ;
	}
	while(playerChoice != 0);
*/
	int i = 0 ;
	int roll = 0 ;
	srand(time(NULL));
	while(i <10) {
		std::this_thread::sleep_for(std::chrono::milliseconds(250)) ;
		i++ ;
		if(i == 5) {
			cout << "The 5th roll is skipped!\n" ;
			continue ;
		}
	cout << i << ", Rolling Dice: " ;
	roll = (rand() % 12) + 1 ;
	cout << roll << endl ;
	}

	return 0 ;
}




/*
2 part assignment 

Programming problem
out of 1000 rolls of a dice, how many times does 6 come up on a 6-sided die.

chapter 2 guess my number program.  Type up.  Comment every line with what it is doing.
