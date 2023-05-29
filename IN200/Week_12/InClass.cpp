// In Class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Greeting() {
	cout << "Welcome to Pointers!\n";
}

void BadSwap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void GoodSwap(int *const x, int *const y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

string *ChosenWord(vector<string> *givenVec, string givenWord) {
	for(int i = 0; i < (*givenVec).size(); i++) {
		if((*givenVec)[i] == givenWord) {
			return &(*givenVec)[i];
		}
	}
	(*givenVec).push_back("Couldn't find that word.\n");
	//	string asdf = "asdf";		// this will be erased at the end of the function.
	//	return &asdf;		//dangling pointer.  He's a bad hombre
	return &(*givenVec)[(*givenVec).size() - 1];
}

void Super(string * givenArray) {
	for(int i = 0; i < 5; i++) {
		givenArray[i] = "SUPER " + givenArray[i];
	}
}

void Display(string *givenArray) {
	for(int i = 0; i < 5; i++) {
		cout << *(givenArray + i) << endl;
	}
}

int main() {
	Greeting();

	int myAge = 29;
	int* pAge = &myAge;
	cout << "The Value that pAge is pointing to is: " << *pAge << endl;
	cout << "The Addres of myAge = " << &myAge << endl;
	cout << "The Address that pAge is pointing to is: " << pAge << endl;

	string butt = "Mr. PoopyButthole";
	string* pbutt = &butt;
	cout << pbutt << endl;
	cout << *pbutt << endl;

	string* pName = 0;		// creating a null pointer.  It's safer because we know it's not pointing to anything
	string myName = "Brice";
	pName = &myName;
	cout << "*pName = " << *pName << endl;

	cout << "We're going adventuring!\n";
	int distance = 500;
	int* pNum1 = &distance;
	int * pNum2;
	int *asdf;
	int *num3, *num4, num5;

	cout << "We have " << *pNum1 << " meters left until the next castle.\n";
	cout << "After some time...\n";
	*pNum1 -= 300;
	cout << "we only have " << *pNum1 << " meters left.\n";

	cout << "While on the road - we are attacked!!!\n";
	int health = 74;
	pNum1 = &health;

	cout << "Our health is now " << *pNum1 << endl;

	cout << "Ridiculous amounts of constants incoming!\n";
	cout << "Here's a Constant Pointer.\n";
	string profname = "Professor Foster";
	string *const pProfname = &profname;
	cout << "A constant pointer can't be reassigned to anouther variable.\n";
	// pProfname = &myName;
	cout << "Here's a pointer to a constant\n";
	string food = "Pizza", otherFood = "Broccoli";
	const string *favFood = &food;
	cout << "My fav food = " << *favFood << endl;
	cout << "You can't change the value of a pointer to a constant.\n";
	// *favFood = "Chicken";  (read only)
	cout << "Here's a constant Pointer to a Constant\n";
	cout << "It's read-only and you can't change what it points to.\n";
	const string *const pLockDown = &otherFood;
	cout << "*pLockDown = " << *pLockDown << endl;

	cout << "First break is O V E R ! ! ! !\n";
	cout << "The score storyline in the book SUPER LAME.\n";
	int playerHealth = 15;
	int enemyHealth = 95;
	cout << "I'm a fight you! playerHealth = " << playerHealth << " and enemyHealth = " << enemyHealth << ".\n";
	cout << "I'm a vampire!! Swapping your health with mine... via biting.\n";
	BadSwap(playerHealth, enemyHealth);
	cout << "Behold! playerHealth = " << playerHealth << " and enemyHealth = " << enemyHealth << ".\n";
	cout << "Cough cough... what's this?  my health is still poor?!?!?!?!?\n";
	cout << "[biting intensifies]\n";
	GoodSwap(&playerHealth, &enemyHealth);
	cout << "Behold! playerHealth = " << playerHealth << " and enemyHealth = " << enemyHealth << ".\n";

	cout << "BEWARE THE DANGLING POINTER!!!\n";
	cout << "BEWARE....\n";
	// build a vector of string holding 5 food words.

	vector<string> foods;
	foods.push_back("Domino's");
	foods.push_back("Popeye's");
	foods.push_back("Chipotle");
	foods.push_back("Spangle's");
	foods.push_back("BK Spicy Nugs");
	string input = "bun";
	cout << *ChosenWord(&foods, input) << endl;

	cout << "Building a pointer to an int and a pointer to a string\n";
	int number = 4;
	string number5 = "Is alive";
	int *pNumber = &number;
	string *pNumber5 = &number5;

	cout << "Here be dragons!\n";
	cout << "1. The name of an array is a pointer to the first item in an array.\n";
	cout << "2. Arrays are stored in a continuous blocks of memory.\n";
	string names[5] = {"Gandalf", "Tom", "Bilbo", "Pippen", "Treebeard"};
	cout << "The first name in names is " << *names << ".\n";
	cout << "The second name in names is " << *(names + 1) << ".\n";

	cout << "16-bit is here!\n";
	Super(names);
	Display(names);

	return 0;
}