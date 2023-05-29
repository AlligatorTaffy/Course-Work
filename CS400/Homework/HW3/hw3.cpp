/**
AlligatorTaffy
Homework #3
March 3, 2019
**/

#include <iostream>
#include <fstream>

// Constant Definitions
#define NUM_INTS 100
#define DIGIT_SIZE 50
#define FIRST_LENGTH 10

// Class Definition
class Node {
public:
	int data;		// Variable to hold a digit of the sum in a linked object
	Node *next;		// Variable to hold the address of the next object in the linked list
	Node() {		// Default constructor settings values to 0 / NULL
		data = 0;
		next= NULL;
	}
	Node(int x) {	// Overloaded constructor to set value of data on creation
		data = x;
		next = NULL;
	}
};

// Global Variables
typedef Node* NodeP;
std::ifstream fin;

// Function Declarations
void add_tail(NodeP& head, int num);
void add_head(NodeP& head, int num);
void del(NodeP& head, int target);		// Unused for scope of assignment
void traverse(NodeP& head);				// Unused except for debug
void set(NodeP& head, int target, int replace);	// Unused for scope of assignment
NodeP search(NodeP& head, int target);	// Unused for the scopt of assignment
void addNum(NodeP list, std::string input);
void printList(NodeP list);

// Main Program
int main(){
	NodeP final = NULL;		// Null pointer pointing to the Final answer Linked List
	NodeP head = NULL;		// Null pointer pointing to the reversed summation Linked List
	for(int i = 0; i < DIGIT_SIZE; i++) {	// Initializes the initial Reversed Linked List to size of integers
		add_head(head, 0);	// Adds a 0 to the value of each data member of the linked list
	}

	std::string temp;	// Declares a temporary string to grab each integer from the file as a string	
	fin.open("nums.txt");	// Open 'nums.txt' file
	if (fin.fail()) {	// Check to see if file exists
		std::cout << "NUM LIST 'nums.txt' FILE NOT FOUND\n" << std::endl;	// Error message if file doesn't exist
	} 
	else {
		for(int i = 0; i < NUM_INTS; i++) {	// Loops through each line of the nums.txt file.  Bound by integer per line
			std::getline(fin, temp);	// Getline is used to grab the entire line of the file
			addNum(head, temp);		// Add the passed string to the passed head pointer of the reversed sum linked list
		}
		fin.close();	// Cleanly close the nums.txt file
	}

	NodeP flip = head;		// Create temporary pointer pointing to the head of the reversed sum linked list
	while(flip != NULL) {		// Condition for when the pointer isn't NULL, do the following
		add_head(final, flip->data);	// Call add_head function to create new nodes at the head of the final answer linked list
		flip = flip->next;	// Increment the temporary pointer to the next object
	}

	//traverse(head);		// Debug traverse function (head to tail) to output each value of every node in the reversed sum linked list
	//traverse(final);		// Debug traverse function (head to tail) to output each value of every node in the final answer linked list

	printList(final);		// Function to print out the final full sum and truncated first 10 digits of final sum

	return 0;
}

void add_tail(NodeP& head, int num) {	// Function that will add a new node to the tail of passed head of linked list
	if(head == NULL) {		// If the head of pointer is NULL
		head = new Node(num);	// Creates new node to the linked list given the passed value
	}
	else {
		NodeP temp = head;	// If head isn't NULL, make a temp pointer and give it the address of head
		while(temp->next != NULL) {		// this loop will stop at the last node
			temp = temp->next;	// Increments the address of the pointer as it moves along the list
		}
	temp->next = new Node(num);		// Creates a new object at the end of linked list
	}
}
void add_head(NodeP& head, int num) {	// Function to add a new node to the head of the Linked List
	NodeP temp = head;		// Make copy of the head
	head = new Node(num);	// Create new node and assign to head
	head->next = temp;		// Assigns the previous head address to the new node next address
}

void del(NodeP& head, int target) {		// Deletes a node from the linked list given the target matches a data member
	if(head == NULL) {
		return;			// If the linked list is empty, do nothing.
	}
	if(head && head->data == target) {	// If head isn't NULL and the data member matches the passed target value
		NodeP temp = head;		// If the head has the target value, make temporary pointer for head
		head = head->next;		// Assign the next object in the list to the NEW head
		delete temp;		// Deletes the previous head object now pointed at temp
	}
	NodeP prev = NULL;		// Assigns temporary pointer to previous node
	NodeP curr = head;		// Assigns temporary pointer to current node

	while(curr != NULL && curr->data != target) {	// Checks to make sure curr isn't NULL and that the curr data object doesn't match the target
		prev = curr;	// prev pointer is updated to curr
		curr = curr->next;	// curr pointer is updated to next
	}
	if(curr == NULL) {  // If the target isn't found, do nothing
		return;
	}
	prev->next = curr->next;	// If the target is found, the prev node is given the address of curr next
	delete curr;	// Curr object gets deleted
}

void traverse(NodeP& head) {	// Function that traverses and prints the values of the linked list
    NodeP temp = head;		// Make a temp pointer that copies the value of head
	while(temp != NULL) {	// While temp point isn't NULL
		std::cout << temp->let << " " << temp->frequency << std::endl;	// Print data value of temp pointer object and makes new line
		temp = temp->next;	// Increment temp pointer to the next object
	}
}

void set(NodeP& head, int target, int replace) {	// Replaces data value if found in linked list
	NodeP temp = head;		// Creates a temp pointer assigned from head
	while(temp != NULL && temp->data != target) {	// If temp isn't NULL and the target isn't in the data object
		temp = temp->next;	// Increment the temp pointer to thenext object
	}
	if(temp != NULL) {
		temp->data = replace;	// Replace value of object if it is found
	}
}

NodeP search(NodeP& head, int target) {	// Searches list for target and returns address of object
	NodeP temp = head;		// Creates a temp pointer assigned from head
	while(temp != NULL && temp->data != target) {	// If temp isn't NULL and the target isn't in the data object
		temp = temp->next;	// Increment the temp pointer to thenext object
	}
	return temp;	// Returns address of object if found or NULL if it isn't found
}

void addNum(NodeP list, std::string input) {	// Function to add passed string to the reverse sum linked list
	int sum = 0;		// Temporary variable to hold the sum for each object
	int digit = 0;		// Temporary variable to hold the converted string digit as an int
	int carry = 0;		// Temporary variable to hold the carry from the summation
	NodeP slot = list;	// Temporary pointer that copies the value of the head of passed Linked List
	for(int i = DIGIT_SIZE - 1; i >= 0; i--) {	// Loop given the number of digits of the input integer (In REVERSE)
		digit = input[i] - '0';		// Converts the char value of string into an int
		sum = digit + slot->data + carry;	// Adds the digit from file, current value in object, and carry value into sum
		carry = 0;	// Set carry bit to zero
		if(sum >= 10) {		// If sum exceeds a single digit
			sum -= 10;		// Subtract 10 from value 
			carry = 1;		// Add 1 to the carry
		}
		slot->data = sum;	// Assign the new sum to the data member of the object
		slot = slot->next;	// Move the pointer to the next object
	}
	while(carry == 1) {		// If there is a carry after the complete summation do one of the following
		if(slot != NULL) {		// If the pointer isn't NULL
			slot->data = slot->data + carry;	// Add the carry digit to the value of the object
			if(slot->data >= 10) {		// if the new value is greater than 10
				slot->data = slot->data - 10;	// Subtract 10 from the object
			}
			else {
				carry = 0;	// if the object value doesn't exceed 10, set carry back to 0
			}
			slot = slot->next;	// Increment the point to the next object
		}
		else {
			add_tail(list, carry);	// Since the pointer is NULL, call add_tail to create a new object with the vaue of carry
			carry = 0;		// Set carry back to 0
		}
	}
}

void printList(NodeP list) {		// Function to print the values of the final summation
	NodeP temp = list;		// Create a temp pointer of the passed head
	std::cout << "Full sum of all numbers:: ";
	while(temp != NULL) {	// Do the following while temp isn't NULL
		std::cout << temp->data;	// Print value from object to console
		temp = temp->next;	// Increment temp pointer to the next object
	}
	temp = list;	// Reset temp pointer back to head
	std::cout << "\nFirst " << FIRST_LENGTH << " digits of sum:: ";
	for(int i = 0; i < FIRST_LENGTH; i++) {	// Condition to print only the first 10 objects
		std::cout << temp->data;	// Print value from object to the console
		temp = temp->next;	// Increment temp pointer to the next object
	}
	std::cout << std::endl;
}
