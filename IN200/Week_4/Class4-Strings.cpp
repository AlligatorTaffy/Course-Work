//	In Class assignment #4

#include <iostream> 
#include <string>
using namespace std ;

int main () {
	string userName ;
	cout << "Why hell there player!  What is your name?\n" ;
	getline (cin, userName) ;
	if (userName == "Brice") {
		cout << "Hey that's my name!\n" ;
	}
	else if (userName == "Darth Vader") {
		cout << "I'll be your best friend!\n" ;
	}
	else {
		cout << "Now that's a cool name!\n" ;
	}

	return 0 ;
}
