/**
AlligatorTaffy
Homework #5 - Palindrome
March 29, 2019
**/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

// Create an empty STL stack globally
std::stack<char> reverser;

// Function Declarations
void isPalindrome(std::string x);

// Main Program
int main() {
	// Grab user expression as a string
	std::string input;
	std::cout << "Enter a string:: ";
	std::getline(std::cin, input);
	// Convert string casing to all UPPER case
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	isPalindrome(input);

	return 0;
}

void isPalindrome(std::string x) {
	// Defining my forward and reverse strings to compare
	std::string forward = "";
	std::string reverse = "";

	for(int i = 0; i < x.length(); i++) {	// Loop to iterate through char array with length of string and removes common punctuation
		if(x[i] == ' ' || x[i] == ',' || x[i] == '.' || x[i] == '?' || x[i] == '!' || x[i] == '"' || x[i] == '\'') {	
			// std::cout << "skip" << std::endl; // Debug message
			continue;
		}
		else {
			forward += x[i];	// Add character to forward string
			reverser.push(x[i]);	// push character to stack
			// std::cout << "push" << std::endl;	// Debug message
		}
	}
	int size = reverser.size();	// Create size variable based on size of stack
	for(int i = 0; i < size; i++) {		// loop function based on size of the stack
		reverse += reverser.top();	// Add character from top of the stack to the reverse string
		reverser.pop();	// pop character off the stack
	}
	// std::cout << forward << std::endl;	// Debug Message
	// std::cout << reverse << std::endl;	// Debug Message
	if(forward == reverse) {	// Compares forward and reverse string to see if they match
		std::cout << "Yes! It is a Palindrome." << std::endl;	// Print phrase if it is a palindrome
	}
	else {
		std::cout << "No! It is NOT a Palindrome." << std::endl;	// Print phrase if is not a palindrome
	}

}