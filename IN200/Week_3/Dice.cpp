// Wednesday Night C++ Fall 2017
// Module 3 - Chapter 2 - Dice Rolling Game

#include <iostream>
#include <string>	//needed for strings
#include <cstdlib>	//for rand()
#include <ctime>	//for rand()
using namespace std ;

int i = 0 ;
int roll = 0 ;
int sixCount = 0 ;

int main() {
    srand(time(NULL)) ;
    cout << "\nLet's Play the Dice Rolling Game!\nWe shall count how many times a '6' is rolled when we roll a 6-sided die 1000 times!\n\n" ;
    while(i < 1000) {
        i++ ;
        cout << "Dice Roll #" << i << ": Result: " ;
        roll = (rand() % 6) + 1 ;
        cout << roll << endl ;
        if(roll == 6) {
            sixCount++ ;
        }
    }
    cout << "\nThe number 6 was rolled " << sixCount << " times out of 1000 rolls!\n\n" ;

    return 0 ;
}
