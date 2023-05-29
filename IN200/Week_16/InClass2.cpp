/**
 * Chapter 9 - Adv. Classes and the HEAP
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int* intOnHeap() {
	int* pTemp = new int(20);
	return pTemp;
}

void leak1() {
	int* pTemp = new int(30);		// the new int never gets deleted
}

coid leak2() {
	int* pTemp = new int(50);
	pTemp = new int(100);			// assigns a new int and the old one still remains.
	delete pTemp;
}
int main() {
	cout << "Memory Games\n";

	int* pAge = new int;		// Creating a pointer and a new memoery location
	*pAge = 29;
	cout << "pAge = " << *pAge << "     " << pAge << endl;
	int* pSpeed = intOnHeap();
	cout << "pSpeed = " << *pSpeed << endl;

	cout << "Freeing memory pointed to by pAge\n";
	delete pAge;
	cout << "Freeing memory pointed to by pSpeed.\n";
	delete pSpeed;

	return 0;
}
