//  Tic-Tac-Toe with comments

#include <iostream>				//
#include <string>				//	Inclusion of external libraries
#include <vector>				//
#include <algorithm>			//

using namespace std;			//	Flag to enable iostream shorthand


const char X = 'X';				//	Constant that marks an X in the space
const char O = 'O';				//	Constant that marks an O in the space
const char EMPTY = ' ';			//  Constant that marks a blank in the space
const char TIE = 'T';			//	Constant that is used to send the "tie" condition to be called
const char NO_ONE = 'N';		//	Constant that is used to send the "game is not complete" condition


void instructions();												//
char askYesNo(string question);										//
int askNumber(string question, int high, int low = 0);				//
char humanPiece();													//
char opponent(char piece);											//
void displayBoard(const vector<char>& board);						//	Declarations of functions defined below int main()
char winner(const vector<char>& board);								//
bool isLegal(const vector<char>& board, int move);					//
int humanMove(const vector<char>& board, char human);				//
int computerMove(vector<char> board, char computer);				//
void announceWinner(char winner, char computer, char human);		//


int main() {											//	Begin main program
    int move;											//	Defines the 'move' variable as an integer
    const int NUM_SQUARES = 9;							//	Defines the total number of squares allowed in the game (constant)
    vector<char> board(NUM_SQUARES, EMPTY);				//	Creats a vector that has 9 positions (from NUM_SQUARES) and assigns "EMPTY" into each indicating a blank space

    instructions();										//	Calls the "Instructions" function
    char human = humanPiece();							//	Assigns either an X or O as the human player
    char computer = opponent(human);					//	Assigns either an X or O as the computer player but sending the human selection to the "Opponent" function
    char turn = X;										//	The variable "turn" is initially defined as X because X always goes first
    displayBoard(board);								//	Calls the "displayboard" function to cout the current status of the game board

    while (winner(board) == NO_ONE) {					//	The while loop will continue until a T, Win, Lose condition is made
        if (turn == human) {							//	If the turn is equal to the human's assigned piece (X/O) then the player moves
            move = humanMove(board, human);				//	Variable 'move' is set the the "humanMove" function getting user input for the location
            board[move] = human;						//	Vector 'board' is assigned either X/O in the location the player has selected
        }
        else {
            move = computerMove(board, computer);		//	Variable 'move' is set the the "computerMove" function using a number generator to choose location
            board[move] = computer;						//	Vector 'board' is assigned either X/O in the location the computer has selected
        }
        displayBoard(board);							//	Calls the "displayboard" function to cout the current status of the game board
        turn = opponent(turn);							//	Variable 'turn' is assigned by the "opponent" function.  (Function acts as an inverter)
    }

    announceWinner(winner(board), computer, human);		//	Function "announceWinnder" is called and determines the condition based upon what variable is contained in a winning row or if EMPTY = 0

    return 0;											//	Program closes
}




void instructions() {																//	Defines a void function of "instructions"
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";			//
    cout << "--where human brain is pit against silicon processor\n\n";				//
    																				//
    cout << "Make your move known by entering a number, 0 - 8.  The number\n";		//
    cout << "corresponds to the desired board position, as illustrated:\n\n";		//
    																				//	
    cout << "       0 | 1 | 2\n";													//	couts the greeting, instructions, and warning for the game
    cout << "       ---------\n";													//
    cout << "       3 | 4 | 5\n";													//
    cout << "       ---------\n";													//
    cout << "       6 | 7 | 8\n\n";													//
    																				//
    cout << "Prepare yourself, human.  The battle is about to begin.\n\n";			//
}

char askYesNo(string question) {											//	Defines a standard "Yes/No" function with custom question
    char response;															//	Internal char variable in the function
    do {																	//	Start of a Do/While loop
        cout << question << " (y/n): ";										//	cout of the custom question with additional (y/n) instruction
        cin >> response;													//	Gets user input and assigns it to response
    } while (response != 'y' && response != 'n');							//	Loop will continue to run until a 'y' or 'n' is received

    return response;														//	the y/n response is turned from the function
}

int askNumber(string question, int high, int low) {							//	Defines "askNumber" function to prompt the player to pick a number
    int number;																//	temporarily defines a variable for number
    do {																	
        cout << question << " (" << low << " - " << high << "): ";			//	Asks a custom question asking for a number between the lowest and highest number in the size of the board
        cin >> number;														//	Gets player input for the number
    } while (number > high || number < low);								//	Makes sure the value selected is within the number range

    return number;															//	returns the chosen number
}

char humanPiece() {																//	HumanPiece function is created
    char go_first = askYesNo("Do you require the first move?");					//	Variable "go_first" is definted and assigned input from the askYesNo function
    if (go_first == 'y') {														//	If go_first is equal to 'y' then do the operations
        cout << "\nThen take the first move.  You will need it.\n";				//	Tell the user they are going first
        return X;																//	Assigns the human player as X
    } else {
        cout << "\nYour bravery will be your undoing... I will go first.\n";	//	Tell the user that the computer is going first
        return O;																//	Assigns the human player as O
    }
}

char opponent(char piece) {		//	Defines the "opponent" function (basically acts as an interter)
    if (piece == X) {			
        return O;				//	Returns O if X was received
	} else {
        return X;				//	Returns X if O was received
	}
}

void displayBoard(const vector<char>& board) {									//	Defines the "displayBoard" function
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];		//
    cout << "\n\t" << "---------";												//
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];		//	couts multiple lines to create a grid displaying the contents of each vector location
    cout << "\n\t" << "---------";												//
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];		//
    cout << "\n\n";																//
}

char winner(const vector<char>& board) {											//	Defines the "winner" function to test for winning conditions
    const int WINNING_ROWS[8][3] = { {0, 1, 2},										//
                                     {3, 4, 5},										//
                                     {6, 7, 8},										//
                                     {0, 3, 6},										//	an integer 8x3 array is created and populated with the winning combinations
                                     {1, 4, 7},										//
                                     {2, 5, 8},										//
                                     {0, 4, 8},										//
                                     {2, 4, 6} };									//
    const int TOTAL_ROWS = 8;														//	Total number of rows is defined and is set to 8

    for(int row = 0; row < TOTAL_ROWS; ++row) {									//	for loop is created to check the conditions of each of the 3 rows
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&			
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&	//	Conditions for how the row is tested.  It check for each of the following 8 rows to see if the same character is in each position or if there are still EMPTY spaces
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )		//
        {
            return board[WINNING_ROWS[row][0]];									//	If the condition passes, return the winning row
        }
    }

    if (count(board.begin(), board.end(), EMPTY) == 0)					//	if condition that determines if there are any EMPTY spaces left.
        return TIE;														//	if there are no EMPTY spaces left and no winning row, return TIE condition

    return NO_ONE;														//	Returns game is still in progress condition
}

inline bool isLegal(int move, const vector<char>& board) {				//	Defines the 'islegal' function to determine if the space of the number chosen is = EMPTY
    return (board[move] == EMPTY);										//	Returns the vector space being EMPTY
}

int humanMove(const vector<char>& board, char human) {						//	Defines the 'humanMove' function
    int move = askNumber("Where will you move?", (board.size() - 1));		//	defines a variable 'move' and using the function "askNumber" to get user input for the space number
    while (!isLegal(move, board)) {											//	Checks to see if that space is assigned EMPTY or not, if not, it couts for you to try again
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Fine...\n";													//	Computer reluctantly tells you it'll assign the space

    return move;															//	returns the number where the player has chosen to move
}

int computerMove(vector<char> board, char computer) { 						//	Defines the "computerMove" function
    unsigned int move = 0;													//	Defines internal int "move"
    bool found = false;														//	sets a boolean condition variable "found" to false

    //if computer can win on next move, that’s the move to make
    while (!found && move < board.size()) {				//	While loop to run while the condition is true and the moves are less than the spaces on the board
        if (isLegal(move, board)) {						//	if the function of "isLegal" is true, then try the move
            board[move] = computer;						//	board location slot is filled with the computer's X/O
            found = winner(board) == computer;   		//	found gets assigned to the contents of the winning rows from "winner" function and tests for computer's X/O
            board[move] = EMPTY;						//	If not the winning condition, set space back to EMPTY
        } if (!found) {
            ++move;										//	Adds 1 to check the next space
        }
    }
  
    //otherwise, if opponent can win on next move, that's the move to make
    if (!found) {									//	sets if condition while bool is equal to true
        move = 0;									//	sets move variable to 0
        char human = opponent(computer);			//	human variable gets defined and set to the opposite of the computer variable using "opponent" function

        while (!found && move < board.size()) {		//	While loop to run while the condition is true and the moves are less than the spaces on the board
            if (isLegal(move, board)) {
				board[move] = human;  				//	board location slot is filled with the human's X/O
                found = winner(board) == human;     //	found gets assigned to the contents of the winning rows from "winner" function and tests for human's X/O
				board[move] = EMPTY;        		//	If not the winning condition, set space back to EMPTY
            } if (!found) {
                ++move;								//	Adds 1 to check the next space
            }
        }
    }

    //otherwise, moving to the best open square is the move to make
    if (!found) {													//	sets if condition while bool is equal to true
        move = 0;													//	sets move variable to 0
        unsigned int i = 0;											//	defines a temporary i and sets it to 0

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};		//	creates an array for the "best moves" and populates that list
        while (!found && i <  board.size()) {						//	While loop to run while the condition is true and i is less than the spaces on the board
            move = BEST_MOVES[i];									//	sets move to a specified slot in BEST_MOVES for whatever i currently is.
            if (isLegal(move, board)) {								//	checks to see if that is a legal move
                found = true;										//	if true, sets found as true breaking while loop
            }

            ++i;													//	adds 1 to i
        }
    }

    cout << "I shall take square number " << move << endl;			//	Computer makes it known where he wasnt to go
	return move;													//	returns the space number where the move is to be placed
}

void announceWinner(char winner, char computer, char human) {						//	Function "announceWinner" function is defined
	if (winner == computer) {														//	Displays Computer gloating of winning if winner = computer
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    } else if (winner == human) {													//	Displays Computer disdain of losing if winner = human
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n";
    } else {																		//	Displays neutral tie text if no condition is set to winner
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}
