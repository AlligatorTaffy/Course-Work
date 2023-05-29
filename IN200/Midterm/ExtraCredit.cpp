//	Midterm Extra Credit

#include <iostream>
#include <string>
using namespace std;

//	Global Variables
int glob = 10;

//	Declared Functions
void instructions();
char askYesNo1();
char askYesNo2(string question);
void func();
void access_global();
void hide_global();
void change_global();
int askNumber(int high, int low = 1);
int triple(int number);
string triple(string text);
inline int radiation(int health);
string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);


int main() {

//	Instructions
    instructions();		//	Void function is called to cout the rules to a game

//	Yes or No
    char answer1 = askYesNo1();										//	Calls the function to get user input only for a y/n response
    cout << "Thanks for answering: " << answer1 << "\n\n";			//	Console thanking the user for the input
    char answer2 = askYesNo2("Do you wish to save your game?");		//	Sendings a custom question as a parameter to the AskYesNo function to get a y/n answer
    cout << "Thanks for answering: " << answer2 << "\n";			//	Console thanking the user for the input

//	Scope
    int var = 5;  																// local variable set to 5								
    cout << "In main() var is: " << var << "\n\n";
    func();																		//void function is called to cout the value of var inside the function
    cout << "Back in main() var is: " << var << "\n\n";
    {
        cout << "In main() in a new scope var is: " << var << "\n\n";
        cout << "Creating new var in new scope.\n";
        int var = 10;															// variable in new scope, hides other variable named var
        cout << "In main() in a new scope var is: " << var << "\n\n";
    }
    cout << "At end of main() var created in new scope no longer exists.\n";
    cout << "At end of main() var is: " << var << "\n";

//	Global Reach
    cout << "In main() glob is: " << glob << "\n\n";		//	couts value of glob to the console
    access_global();										//	the void function 'access_global' couts the contents of the global variable
    hide_global();											//	function sets the global variable glob to 0
    cout << "In main() glob is: " << glob << "\n\n";		//	couts value of glob to the console
    change_global();										//	function sets the global variable glob to -10
    cout << "In main() glob is: " << glob << "\n\n";		//	couts value of blog to the console

//	Give me a Number
    int number = askNumber(5);								//	Function 'askNumber' is called and the parameter 5 is sent to the function to ask the user to input a number between 0 - 5
    cout << "Thanks for entering: " << number << "\n\n";	//	couts thanking user for input number
    number = askNumber(10, 5);								//	Function 'askNumber' is called and the parameters 10 and 5 are sent to the function to ask the user to input a number between 5 - 10
    cout << "Thanks for entering: " << number << "\n\n";	//	couts thanking user for input number

//	Triples
    cout << "Tripling 5: " << triple(5) << "\n\n";			//	Function 'triple' is sent the int parameter of 5 to multiply by 3
    cout << "Tripling 'gamer': " << triple("gamer");		//	Function 'triple' is sent the string parameter of gamer to multiply by 3

//	Taking Damage
    int health = 80;															//	int variable 'health' is defined as 80
    cout << "Your health is " << health << "\n\n";								//	couts the value of health
    health = radiation(health);													//	health = Radation function sum that was sent the value of health
    cout << "After radiation exposure your health is " << health << "\n\n";		//	couts the current status of health
    health = radiation(health);													//	health = Radation function sum that was sent the value of health
    cout << "After radiation exposure your health is " << health << "\n\n";		//	couts the current status of health
    health = radiation(health);													//	health = Radation function sum that was sent the value of health
    cout << "After radiation exposure your health is " << health << "\n\n";		//	couts the current status of health

//	Mad-Lib
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";
    string name = askText("Please enter a name: ");								//	variable name being assigned the returned value of 'askText' being sent a question as a parameter
    string noun = askText("Please enter a plural noun: ");						//	variable noun being assigned the returned value of 'askText' being sent a question as a parameter
    int number1 = askNumber("Please enter a number: ");							//	variable number1 being assigned the returned value of 'askNumber' being sent a question as a parameter
    string bodyPart = askText("Please enter a body part: ");					//	variable bodypart being assigned the returned value of 'askText' being sent a question as a parameter
    string verb = askText("Please enter a verb: ");								//	variable verb being assigned the returned value of 'askText' being sent a question as a parameter
    tellStory(name, noun, number1, bodyPart, verb);								//	Function 'tellStory' being called and sent name, noun, number1, bodypart, and verb as parameters

    return 0;
}


void instructions() {														//	void function 'instructions' is defined and couts comments to the console
    cout << "Welcome to the most fun you've ever had with text!\n\n";
    cout << "Here's how to play the game...\n";
}

char askYesNo1() {										//	char function 'askYesNo1' is defined and contains a char variable temporarily holds the user input and only returns 'y' or 'n' values.
    char response1;										//	empty char variable is defined
    do {												//	do loop continues while the input doesnt equal y or n
        cout << "Please enter 'y' or 'n': ";
        cin >> response1;								//	gets user input and assigns it to response1
    } while (response1 != 'y' && response1 != 'n');		//	tests response1 if it contains 'y' or 'n'

    return response1;									//	returns 'y' or 'n'
}

char askYesNo2(string question) {						//	char function 'askYesNo1' is defined and contains a char variable temporarily holds the user input and only returns 'y' or 'n' values.
    char response2;										//	empty char variable is defined
    do {
        cout << question << " (y/n): ";					//	the custom yes or no question being sent into the function as a parameter.
        cin >> response2;								//	gets user input and assigns it to response1
    } while (response2 != 'y' && response2 != 'n');		//	tests response1 if it contains 'y' or 'n'

    return response2;									//	returns 'y' or 'n'
}

void func() {											//	void function 'func' is defined
    int var = -5;  										//	variable defined that only lives in func	
    cout << "In func() var is: " << var << "\n\n";		//	cout the value of var that lives in func
}

void access_global() {												//	void function that couts, and has access to, the global variable 'glob'
    cout << "In access_global() glob is: " << glob << "\n\n";
}

void hide_global() {											//	void function that writes to and couts variable 'glob'
    int glob = 0;  												//	Global variable 'glob' is assigned to 0
    cout << "In hide_global() glob is: " << glob << "\n\n";		
}

void change_global() {											//	void function that writes to and couts variable 'glob'
    glob = -10;  												//	Global variable 'glob' is assigned to -10
    cout << "In change_global() glob is: " << glob << "\n\n";
}

int askNumber(int high, int low) {														//	int function that has two int input parameters
    int num;																			//	temporary int variable is defined
    do {																				//	do/while loop that asks for user input based on a value between the two input parameters
        cout << "Please enter a number" << " (" << low << " - " << high << "): ";
        cin >> num;																		//	assigns user input to num
    } while (num > high || num < low);													//	condition that tests num is between the two input parameters

    return num;																			//	returns the valid user input																
}

int triple(int number) {		//	int function that multiplies the input parameter by 3 (overloaded with a string function of the same name)
    return (number * 3);
}

string triple(string text) {		//	string function that multiplies the input parameter by 3 (overloaded with an int function of the same name)
    return (text + text + text);
}

inline int radiation(int health) {		//	an int function 'radiation' is defined and copied inline into main().  Input parameter is health and is divided by 2 as it is returned
    return (health / 2);
}

string askText(string prompt) {		//	string function 'askText' is defined with the input parameter defined as a string
    string text;					//	temporary string variable that lives inside the function
    cout << prompt;					//	couts the parameter's phrase asking for input
    cin >> text; 					//	user input is assigned to text variable
    return text;					//	text is returned at the end of the function
}

int askNumber(string prompt) {		//	int function 'askNumber' is defined with the input parameter defined as a string
    int num;						//	temporary int variable that lives inside the function
    cout << prompt;					//	couts the parameter's phrase asking for input
    cin >> num;						//	user input is assigned to text variable
    return num;						//	num is returned at the end of the function
}

void tellStory(string name, string noun, int number, string bodyPart, string verb) {	//	void function 'tellStory' is defined and given 5 input parameters to cout in the story block
    cout << "\nHere's your story:\n";
    cout << "The famous explorer ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << noun;
    cout << " when one day, the ";
    cout << noun;														//
    cout << " found the explorer.\n";									//
    cout << "Surrounded by ";											//	Standard cout commands to output the story with variables
    cout << number;														//
    cout << " " << noun;												//
    cout << ", a tear came to ";
    cout << name << "'s ";
    cout << bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << noun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << verb;
    cout << " for.";
}

/*
1.	What's wrong with this prototype? int askNumber(int low=1; int high);
The syntax is incorrect with the first input parameter.  The incoming int that is piped into low and high, low is being forcefully assigned to 1 within the function.
You cannot pass a parameter that way.

2.	// Hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

char AskGuess();
string CheckAnswer(string GuessWord, string Word);

int main()
{
    // set-up
    const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

    vector<string> words;  // collection of possible words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];            // word to guess
    int wrong = 0;                               // number of incorrect guesses
    string soFar(THE_WORD.size(), '-');          // word guessed so far
    string used = "";                            // letters already guessed

    cout << "Welcome to Hangman.  Good luck!\n";


    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        guess = toupper(AskGuess()); 
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            guess = toupper(AskGuess());
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";

            // update soFar to include newly guessed letter
            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
			{
                if (THE_WORD[i] == guess)
				{
                    soFar[i] = guess;
				}
			}
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    // shut down
    if (wrong == MAX_WRONG)
        cout << "\nYou've been hanged!";
    else
        cout << "\nYou guessed it!";
    
    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}


string CheckAnswer(string GuessWord, string Word) {
    if (GuessWord == Word) {
        return "That's the word!";
    } else {
        return "That's not the word!";
    }
}

char AskGuess() {
     char input;
        cout << "\n\nEnter your guess: ";
        cin >> input;
        return input;
}

3.	The basic idea of overloading is as followed.  The directions didn't seem entirely clear
#include <iostream>
#include <string>

using namespace std;

int AskNumber(string question);
string number(string num);
string number(int num);


int main() {
    //  Just asking numbers
    cout << "Type a number:: ";
    string input;
    getline(cin, input);
    cout << AskNumber(input);

    // Overloading the function
    int inte = 3;
    string test = "5";
    number(inte);
    number(test);

    return 0;
}
   
int AskNumber(string question) {
    int num;
    if (question == "") {
        cout << "This is the default question:: ";
    } else {
        cout << question << ":: ";
    }
    cin >> num;

    return num;
}

string number(int num) {
    return num;
}

string number(string num) {
    return num
}

*/
