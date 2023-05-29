/**
AlligatorTaffy
Homework #8 - Huffman Coding
April 24, 2019
**/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


// Class Definitions
class Node {
public:
	char let;
	int frequency;
	Node *next, *left, *right;
	Node() {
		let = '*';
		frequency = 0;
		next = left = right = NULL;
	}
	Node(char w, int x) {
		let = w;
		frequency = x;
		next = NULL;
		left = NULL;
		right = NULL;
	}
};


// Typedefs
typedef Node* NodeP;


// Declared Functions
NodeP sortedListToBST(NodeP& head, int n);
void preOrder(NodeP node);
void inOrder(NodeP node);
void postOrder(NodeP node);
void sortList(NodeP& head);
void traverse(NodeP& head);
void add_tail(NodeP& head, char x, int y);
void processFreq(std::string x);


// Global Variables
std::fstream fin;
int freq[26];
char letter[26];
NodeP head = NULL;
NodeP root = NULL;


// Main Program
int main() {
	for(int i = 0; i < 26; i++) {	// Loop to intialize the letters array
		letter[i] = 'A' + i;
	}
	fin.open("20190417_doc.txt");	// Open file
	if (fin.fail()) {		// Condition if file isn't found
		std::cout << "FILE NOT FOUND" << std::endl;
	} else {
		//std::cout << "FOUND" << std::endl;	// Debug Message
		std::string in_string;		// Define empty string to hold line from getline
		while(std::getline(fin, in_string)) {	// While loop to continue if not at the end of file
			transform(in_string.begin(), in_string.end(), in_string.begin(), ::toupper);	// Convert all letters to capital
			processFreq(in_string);
		}
		fin.close();	// Close the file
	}

	for(int i = 0; i < 26; i++) {	// Loop to combine Letter and Frequency arrays into a linked list
		add_tail(head, letter[i], freq[i]);
	}

	sortList(head);	// Sorts the linked list from least to greatest
	std::cout << "This is the sorted Linked List created by the input file with the LETTER and FREQUENCY:" << std::endl;
	traverse(head);	// Traverses and prints the linked list
	root = sortedListToBST(head, 26);	// Converts the linked list into a Binary Tree

	std::cout << "This is the PreOrder list from the Balanced Binary Tree:" << std::endl;
	preOrder(root);	// Prints the Binary Tree in preOrder
	std::cout << std::endl;

	std::cout << "This is the InOrder list from the Balanced Binary Tree:" << std::endl;
	inOrder(root);	// Prints the Binary Tree in Order
	std::cout << std::endl;

	std::cout << "This is the PostOrder list from the Balanced Binary Tree:" << std::endl;
	postOrder(root);	// Prints the Binary Tree in postOrder
	std::cout << std::endl;

	return 0;
}


// Function Definitions
NodeP sortedListToBST(NodeP& head, int n) {  
    /* Base Case */
    if (n <= 0) {
    	return NULL;
    }
    NodeP left = sortedListToBST(head, n/2);	// Construct the left side of tree
    NodeP root = new Node(head->let, head->frequency);	// Create a temp root to move left 
    root->left = left;
    head = head->next;	// Increment head pointer to next node
    root->right = sortedListToBST(head, n - n / 2 - 1);	// Move right and repeat building to the left recursively
  
    return root;
}

void preOrder(NodeP node) {	// Function to print the contents of Binary tree from farthest left node to farthest right
    if (node == NULL) {
    	return;
    }
    std::cout << "(" << node->let << " " << node->frequency << ") ";  
    preOrder(node->left);  
    preOrder(node->right);  
}

void inOrder(NodeP node) {	// Function to print the contents of the Binary Tree in order by frequency
    if (node == NULL) {
    	return;
    }
    inOrder(node->left);
    std::cout << "(" << node->let << " " << node->frequency << ") ";
    inOrder(node->right); 
} 

void postOrder(NodeP node) {	// Function to print the contents of Binary tree from farthest right node to farthest left
    if (node == NULL) {
    	return;
    }
    postOrder(node->left); 
    postOrder(node->right); 
    std::cout << "(" << node->let << " " << node->frequency << ") ";
} 

void sortList(NodeP& head) {	// Function used to sort the linked list by frequency
    if(head == NULL || head->next == NULL) {
       return;
    }
    NodeP t1 = head->next;
    while(t1 != NULL) {
    	char sec_let = t1->let;
        int sec_freq = t1->frequency;
        int found = 0;
        NodeP t2 = head;
        while(t2 != t1) {
            if(t2->frequency > t1->frequency && found == 0) {
            	sec_let = t2->let;
                sec_freq = t2->frequency;
                t2->let = t1->let;
                t2->frequency = t1->frequency;
                found = 1;
                t2 = t2->next;
            } else {
                if(found == 1) {
                	char temp_let = sec_let;
                    int temp = sec_freq;
                    sec_let = t2->let;
                    sec_freq = t2->frequency;
                    t2->frequency = temp;
                    t2->let = temp_let;
                }
                t2 = t2->next;
            }
       }
       t2->let = sec_let;
       t2->frequency = sec_freq;
       t1 = t1->next;
    }
}

void traverse(NodeP& head) {	// Function that traverses and prints the values of the linked list
    NodeP temp = head;		// Make a temp pointer that copies the value of head
	while(temp != NULL) {	// While temp point isn't NULL
		std::cout << temp->let << " " << temp->frequency << std::endl;	// Print data value of temp pointer object and makes new line
		temp = temp->next;	// Increment temp pointer to the next object
	}
}

void add_tail(NodeP& head, char x, int y) {	// Function that will add a new node to the tail of passed head of linked list
	if(head == NULL) {		// If the head of pointer is NULL
		head = new Node(x, y);	// Creates new node to the linked list given the passed value
	}
	else {
		NodeP temp = head;	// If head isn't NULL, make a temp pointer and give it the address of head
		while(temp->next != NULL) {		// this loop will stop at the last node
			temp = temp->next;	// Increments the address of the pointer as it moves along the list
		}
	temp->next = new Node(x, y);		// Creates a new object at the end of linked list
	}
}

void processFreq(std::string x) {
	for(unsigned int i = 0; i < x.length(); i++) {	// Loop to iterate through char array with length of string and removes common punctuation
		if(x[i] == ' ' || x[i] == ',' || x[i] == '.' || x[i] == '?' || x[i] == '!' || x[i] == '"' || x[i] == '\'') {
			continue;
		}
		else {
			if(x[i] == 'A') {
				freq[0] += 1;
			}
			else if(x[i] == 'B') {
				freq[1] += 1;
			}
			else if(x[i] == 'C') {
				freq[2] += 1;
			}
			else if(x[i] == 'D') {
				freq[3] += 1;
			}
			else if(x[i] == 'E') {
				freq[4] += 1;
			}
			else if(x[i] == 'F') {
				freq[5] += 1;
			}
			else if(x[i] == 'G') {
				freq[6] += 1;
			}
			else if(x[i] == 'H') {
				freq[7] += 1;
			}
			else if(x[i] == 'I') {
				freq[8] += 1;
			}
			else if(x[i] == 'J') {
				freq[9] += 1;
			}
			else if(x[i] == 'K') {
				freq[10] += 1;
			}
			else if(x[i] == 'L') {
				freq[11] += 1;
			}
			else if(x[i] == 'M') {
				freq[12] += 1;
			}
			else if(x[i] == 'N') {
				freq[13] += 1;
			}
			else if(x[i] == 'O') {
				freq[14] += 1;
			}
			else if(x[i] == 'P') {
				freq[15] += 1;
			}
			else if(x[i] == 'Q') {
				freq[16] += 1;
			}
			else if(x[i] == 'R') {
				freq[17] += 1;
			}
			else if(x[i] == 'S') {
				freq[18] += 1;
			}
			else if(x[i] == 'T') {
				freq[19] += 1;
			}
			else if(x[i] == 'U') {
				freq[20] += 1;
			}
			else if(x[i] == 'V') {
				freq[21] += 1;
			}
			else if(x[i] == 'W') {
				freq[22] += 1;
			}
			else if(x[i] == 'X') {
				freq[23] += 1;
			}
			else if(x[i] == 'Y') {
				freq[24] += 1;
			}
			else if(x[i] == 'Z') {
				freq[25] += 1;
			}
		}
	}
}