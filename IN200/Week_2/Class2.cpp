// In-class work!

#include <iostream>
#include <string>
#include <chrono>  //required for sleep
#include <thread>  //required for sleep
using namespace std ;

int main () {
	cout << "\nThe " ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "to" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "my" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "N" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "I" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "G" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "H" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "T" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "MARE" ; this_thread::sleep_for(chrono::milliseconds(100)) ;
	cout << "45 * 37 = " << 45 * 37 << endl ;
	cout << "45 + 37 = " << 45 + 37 << endl ;
	cout << "45 - 37 = " << 45 - 37 << endl ;
	cout << "45 / 37 = " << 45 / 37 << endl ;
	cout << "45 % 37 = " << 45 % 37 << endl ;
	cout << "The remainder of 47 / 5 = " << 47 % 5 << endl ;
	cout << "Pseudo-random die roll = " << 82107365 % 12 << endl ;

	string playerName = "Link" ;
	string areaInTrouble = "Forest" ;
	cout << "What is your name? :: " ;
	// cin >> playerName ;
	getline(cin, playerName) ;
	cout << "Hey! Listen! " << playerName << ", the " << areaInTrouble << " is in trouble!" << endl ; 
	cout << "We've got to get going!" << endl ; 
	cout << "Where should we go? :: " << endl ; 
	getline(cin, areaInTrouble) ; 
	int zombieCount = 40; 
	int zombieKillCount = 37 ; 
	cout << "There are " << zombieCount << " zombies outside our x-wing!\n" ;
	cout << "[ " << playerName << " kills " << zombieKillCount << " zombies!! ]\n" ;
	zombieCount-= zombieKillCount;
	//zombieCount-- ;		//decrement operator.  Means zombieCount - 1
	cout << "There are now " << zombieCount << " zombies attacking our x-wing!\n" ;
	cout << "While attacking one of the zombies, a CRITICAL HIT +30 was dealt causing the zombie to split into TWO!\n" ; 
	zombieCount++ ;
	cout << "What will you do now when you are being swarmed by " << zombieCount << " remaining zombies?\n" ;

	// Creating a enum list

	enum items {SLINGSHOT = 5, BOOMERANG, SWORD = 10, LIGHTSABER = 40, SHOTGUN = 80} ;
	items heldItem = SWORD ; 
	cout << playerName << " attacks with item for " << heldItem * 10 << " damage!\n" ;
	const int hoursPerDay = 16 ;
	cout << "There are " << hoursPerDay << " one the forest moon of endor.\n" ;
	// hoursPerDay = 24 ; // You cannot change this number.  Ever.

	return 0 ;
}
