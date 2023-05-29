//	Week 4
//  The Wordiest of Jumblies NOW WITH COMMENTS!

#include <iostream>		//	Needed for cout and console verbosity
#include <string>		//	Defines the library for defining strings with shorthand
#include <cstdlib>		//	Library needed to seed our random number generator
#include <ctime>		//	I'm assuming it is lettnig us utilize time as the base for our number generator
using namespace std;	//	Allows us to use the shorthand for the standard commands

int main() {											//	The main script for our program
	enum fields {WORD, HINT, NUM_FIELDS};				//	Sets word variables for numbers
	const int NUM_WORDS = 8;							//	This lets us sets the amount of words in the game.  Number cannot be changed due to it being constant
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {		
		{"wall", "Do you feel you're banging your head against something?"},		//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"glasses", "These might help you see the answer."},						//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"labored", "Going slowly, is it?"},										//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"persistent", "Keep at it."},												//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"jumble", "It's what the game is all about."},								//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"nintendo", "It was an 'Entertainment System'."},							//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"sega", "It does what Nintendon't."},										//	Hint strings that assigned in the WORDS and FIELDS arrays
		{"dreamcast", "It's thinking..."},											//	Hint strings that assigned in the WORDS and FIELDS arrays
	};
	srand(static_cast<unsigned int>(time(0)));		//	The seeding of our random number
	int choice = (rand() % NUM_WORDS);				//	creates and sets the choice variable with a random number modulus the NUM_WORDS
	string theWord = WORDS[choice][WORD];			//	theWord string gets populated with a word from the array
	string theHint = WORDS[choice][HINT];			//	theHint string gets populated with the hint phrase associated with the word
	string jumble = theWord;						//	assigns the string 'jumble' with the contents of 'theWord'
	int length = jumble.size();						//	sets the length variable to how many characters the word has

	for(int i = 0; i < length; ++i) {		//	This sets our i counter to repeat the random letter jumble based on the length of the word
		int index1 = (rand() % length);		//	Sets a random number divided by the modulus of the length of the word
		int index2 = (rand() % length);		//	Sets a random number divided by the modulus of the length of the word
		char temp = jumble[index1];			//	A temporary variable to assign the new letter based on the number assigned to index1
		jumble[index1] = jumble[index2];	//	The character number is then assigned to a new random position in index2
		jumble[index2] = temp;				//	The final jumbled word gets assigned to temp again
	}
	cout << "\t\t\tWelcome to Word Jumble!\n\n";			//	prints the title of the program
	cout << "Unscramble the letters to make a word.\n";		//	prints the directions of the game
	cout << "Enter 'hint' for a hint.\n";					//	prints how to get a hint
	cout << "Enter 'quit' to quit the game.\n\n";			//	prints how to exit the game
	cout << "The jumble is: " << jumble;					//	displays the jumbled word


/*		########### Old while loop nonsense ##########


	string guess;
	cout << "\n\nYour Guess: ";
	getline(cin, guess);
	while((guess != theWord) && (guess != "quit")) {
		if(guess == "hint") {
			cout << theHint;
		}
		else {
			cout << "Sorry, that's not it!";
		}
		cout << "\n\nYour Guess: ";
		getline(cin, guess); 
	}
	if(guess == theWord) {
		cout << "\nThat's it!  You guessed it!";
	}
*/	


	string guess;						//	sets our guess variable for user input
	do {								//	start of our do list
		cout << "\n\nYour Guess: ";		//	prints our question to the player to prompt response
		getline(cin, guess);			//	takes input from the user and assigns it to guess
		if(guess == "hint") {			//	first if condition to check if guess = hint
			cout << theHint;			//	prints the hint to the console
		}
		else if(guess == theWord) {							//	second if condition to check if guess == theWord
			cout << "\nThat's it!  You guessed it!";		//	prints you correctly guessed it in the console
		}
		else {												//	default reply of the if statement fails all the previous tests
			cout << "Sorry, that's not it!\n";				//	prints to the console that the guess is incorrect
		}
	}
	while(guess != theWord && guess != "quit");				//	our while condition that loops our do argument unless the stated conditions are met.
	cout << "\nThanks for playing!\n";						//	prints to the console thanking you for playing

	return 0;												//	ends the program
}
