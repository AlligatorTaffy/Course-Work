// Wednesday Night C++ Fall 2017
// Module 3 - Chapter 2 - Comments on "Guess My Number"

#include <iostream>		//	needed for console I/O
#include <cstdlib>		//	for rand()
#include <ctime>		//	for rand()
using namespace std ;	//	needed to allow shorthand when typing in commands so you don't have to include "std::" etc.

int main() {			//	this is the main function for our program.  It contains the actual arguments the compiler will read.
	srand(static_cast<unsigned int>(time(0))) ;		//initially creates the random number generator
	int secretNumber = rand() % 100 + 1 ; 		//Creates a stored int of a random number between 1 and 100
	int tries = 0 ;		//creates a stored int for the number of attempts on guessing the secret number
	int guess ;		//creates an int for the user input guess of the secret number

	cout << "\tWelcome to Guess My Number!\n\n" ;		//Displays the title of the program
	do {		//sets the intial loop up for arguments
		cout << "Enter a guess:: " ;		//program asks the user to enter a guess
		cin >> guess ;		//argument that allows the user to input a number
		++tries ;		//increases the 'tries' variable by 1
		if(guess > secretNumber) {		//sets a parameter for what to do if the guess is greater than the secret number  
			cout << "Too high!\n\n" ;		//program telling the player that the number is too high
		}
		else if(guess < secretNumber) {		//sets another parameter for what to do is the guess is less than the secret number
			cout << "Too low!\n\n" ;		//program telling the player that the number is too low
		}
		else {		//the default parameter when none of the previous conditions aren't met
			cout << "\nThat's it! You got it in " << tries << " guesses!\n" ;		//program telling the user they have guessed the secret number and displays the number of attempts to guess it
		}
	} while (guess != secretNumber) ;		//the main definition for the loop.  In this case, the program will loop as long as the guess doesn't equal the secret number.  If the guess does equal the secret number, the loop ends.

	return 0 ;			//	returning 0 tells the process that the program has ended cleanly and successfully
}
