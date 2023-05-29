/*
Week 8
Critter Caretaker
 */

#include <iostream>

using namespace std;

class Critter {                                     //  The class "Critter" is defined
public:                                             //  The "public" definition means exactly that.  All parts of the program can access any function or variable defined here.
    Critter(int hunger = 0, int boredom = 0);       //  Class constructor is defined.  Arguments "hunger" and "boredom" are defined and allow us to interact with "m_hunger" and "m_bordeom".
    void Talk();                                    //  Public void member function "Talk" is declared.
    void Eat(int food = 4);                         //  Public void member function "Eat" is declared.
    void Play(int fun = 4);                         //  Public void member function "Play" is declared.

private:                                            //  The "private" definition means that only variables and function within the class can access these specific variables and functions.
    int m_Hunger;                                   //  Private data member to store "Hunger" level
    int m_Boredom;                                  //  Private data member to store "Boredom" level
                                                    //
    int GetMood() const;                            //  Constant integer member function "GetMood" is declared.
    void PassTime(int time = 1);                    //  Void member function "PassTime" is declared passing an argument of (int time = 1)

};

Critter::Critter(int hunger, int boredom):          //  Class constructor is defined.  Arguments "hunger" and "boredom" are defined and allow us to interact with "m_hunger" and "m_bordeom".
    m_Hunger(hunger),                               //  Private data member "m_hunger" is being sent the value of "hunger".
    m_Boredom(boredom)                              //  Private data member "m_boredom" is being sent the value of "boredom".
{}

inline int Critter::GetMood() const {               //  Inline integer private member function "GetMood" is defined.
    return (m_Hunger + m_Boredom);                  //  The function returns the sum of "m_hunger" and "m_mood" create the mood value for the critter.
}

void Critter::PassTime(int time) {                  //  Void private memeber function "PassTime" is defined with the value of "time" being passed to it.
    m_Hunger += time;                               //  Adds the value of "time" to "m_hunger"
    m_Boredom += time;                              //  Adds the value of "time" to "m_boredom"
}

void Critter::Talk() {                              //  Void public member function "Talk" is defined.
    cout << "I'm a critter and I feel ";            //  "I'm A critter and I feel" is sent to the console.
    int mood = GetMood();                           //  Function variable "mood" is given te value of "GetMood" function.
    /*
    The following is a standard list of "if" state-
    ments.  The response is based upon the value of
    "mood".  Once the operation completes, "PassTime"
    is called.
     */
    if (mood > 15) {
        cout << "mad.\n";
	}
    else if (mood > 10) {
        cout << "frustrated.\n";
	}
    else if (mood > 5) {
        cout << "okay.\n";
	}
    else {
        cout << "happy.\n";
	}

    PassTime();
}

void Critter::Eat(int food) {                       //  Void public member function "Eat" is defined and sent the value of "food"
    cout << "Brruppp.\n";                           //  "Brruppp." is sent to the console.
    m_Hunger -= food;                               //  "m_hunger" has the value of "food" subtracted from it.
    if (m_Hunger < 0) {                             //  A correctional if statement to make sure the value of "m_hunger" doesn't fall below 0.
        m_Hunger = 0;                               //
	}                                               //
                                                    //
    PassTime();                                     //  "PassTime" is called to end the operation.
}

void Critter::Play(int fun) {                       //  Void public member function "Play" is defined and sent the value of "fun"
    cout << "Wheee!\n";                             //  "Wheee!" is sent to the console.
    m_Boredom -= fun;                               //  "m_boredom" has the value of "fun" subtracted from it.
    if (m_Boredom < 0) {                            //  A correctional if statement to make sure the value of "m_boredom" doesn't fall below 0.
        m_Boredom = 0;                              //
	}                                               //
                                                    //
    PassTime();                                     //  "PassTime" is called to end the operation.
}

int main() {
	Critter crit;                                      //  The "Critter" class object is assigned to "crit".
	crit.Talk();                                       //  "crit" refers to the "Critter" class and then "Talk" runs the function from the public section of "Critter".
    
    /*
    The following is the general setup for a basic list
    of commands using a do loop and switch statement to
    create a typical menu to interact with the critter.

    The "do" section creates the list of options to 
    choose from and the "switch" statement calls a 
    function based upon the user selection.
     */
	int choice;                                        
	do {                                       
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch(choice) 
        {
			case 0:	
				cout << "Good-bye.\n";
				break;
			case 1:	
				crit.Talk();
				break;
			case 2:	
				crit.Eat();
				break;
			case 3:	
				crit.Play();
				break;
			default:
				cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
	} while(choice != 0);

    return 0;
}

