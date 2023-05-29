/**
AlligatorTaffy
Homework #6 - Permutations
April 7, 2019
**/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

// Global Variables
int count = 0;	// Counter for the permutations

// Function Declarations
void enumerate(int[], int, int);
void printPermutation(int a[]);
bool isConsistent(int a[], int k, int size);

// Main Program
int main() {
	int list[] = {1, 2, 3, 4, 5};	// Initialize array of ints
	enumerate(list, 0, 6);	// Pass array, index, and size + 1 to enumerate function

	return 0;	// Exit the program
}

// Function Definitions
void enumerate(int a[], int k, int size) {	// Enumerate function that accepts an int array, int index (k), and int size of array
	if(k == size) {		// Condition which checks if the index has hit the end of the array
		printPermutation(a);	// Pass array to printPermutation function to print contents of array
	} else {
		for(int i = 1; i <= size; i++) {	// Loop that inserts value into index spot of array
			a[k] = i;	// Index location being assigned value of i
			if(isConsistent(a, k, size)) {	// Condition that checks if the current numerical arrangement does not have repeating numbers
				enumerate(a, k+1, size);	// If no numbers repeat, recursively call the function increasing the index by 1
			}
		}
	}
}

void printPermutation(int a[]) {	// Function that prints all slots of the array
	std::cout << "P#" << ++count << ":  " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;
}

bool isConsistent(int a[], int k, int size) {	// Consistency check function to detect whether numbers repeat
	int dupes = 0;	// Counter for duplicate numbers 
	for(int i = 0; i < size; i++) {		// Loop that iterates through the array
		if(a[i] == a[k]) {	// Comparison of the index value k matches the value based on iter i
			dupes++;	// If equal, increment the counter
		}
	}
	if(dupes == 1) {	// Condition to make sure only one value exists
		//std::cout << "true" << std::endl;		// Debug Message
		return true;
	} else {
		//std::cout << "false" << std::endl;	// Debug Message
		return false;
	}
}
