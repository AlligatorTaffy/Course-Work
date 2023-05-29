/**
AlligatorTaffy
Homework #9 - Hashtable
May 5, 2019
**/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <chrono>

// Struct Definition
struct Node {
	int num;
	int count;
	Node* left;
	Node* right;
	Node(int num) :num(num), count(1), left(NULL), right(NULL){}
};

// Global Definitions
std::vector<int> Vec1;
std::vector<int> Vec2;
std::unordered_multimap<int, int> Hash_Table;
int summary = 0;

// Function Declarations
void search(Node* obj, int num);
Node* add(Node* obj, int num);


int main() {
	srand(time(NULL));	// Seed the random number generator
	// Create 100000 random numbers between 0 - 100000 into Vector 1
	for(int i = 0; i < 100000; i++) {
		Vec1.push_back(rand() % 100000);
	}

	// Create Vector 2 of 10000 numbers with 5000 from Vector 1 and 100000 newly generated
	for(int i = 0; i < 5000; i++) {
		Vec2.push_back(Vec1[rand() % 100000]);
		Vec2.push_back(rand() % 100000);
	}

	// Create Hashtable of 100000 numbers given Vector 1
	for(std::vector<int>::const_iterator Iter1 = Vec1.begin(); Iter1 != Vec1.end(); ++Iter1) {
		Hash_Table.insert(Hash_Table.begin(), std::pair<int, int>(*Iter1, *Iter1));
	}

	// Linear search of integers from Vector 2 inside Vector 1
	std::cout << "Linear Searching Vector 1 with values from Vector 2" << std::endl;
	summary = 0;	// Set Summary count to 0
	auto time_start = std::chrono::high_resolution_clock::now();	// Start initial timestamp
	for(std::vector<int>::const_iterator Iter2 = Vec2.begin(); Iter2 != Vec2.end(); ++Iter2){	// Loop through Vec2 with search digit
		int key = *Iter2;
		for(std::vector<int>::const_iterator Iter1 = Vec1.begin(); Iter1 != Vec1.end(); ++Iter1) {	// Search through Vec1 with Vec2 digit
			if(key == *Iter1) {	// If found condition
				summary++;	// Add one to the summary
			}
		}
	}
	auto time_end = std::chrono::high_resolution_clock::now();	// Record the end timestamp
	auto elapsed = time_end - time_start;	// Find elapsed difference in time
	std::cout << "Found " << summary << " matching integers in " << elapsed.count() << " milliseconds." << std::endl;

	// Linear search of integers from Vector 2 inside Hashtable
	std::cout << "\nLinear Searching HashTable with values from Vector 2" << std::endl;
	summary = 0;	// Set Summary count to 0
	time_start = std::chrono::high_resolution_clock::now();	// Start initial timestamp
	for(std::vector<int>::const_iterator Iter2 = Vec2.begin(); Iter2 != Vec2.end(); ++Iter2){
		summary += Hash_Table.count(*Iter2);	// Add count to the summary
	}
	time_end = std::chrono::high_resolution_clock::now();	// Record the end timestamp
	elapsed = time_end - time_start;	// Find elapsed difference in time
	std::cout << "Found " << summary << " matching integers in " << elapsed.count() << " milliseconds." << std::endl;

	// EXTRA CREDIT - Linear search of integers in BST given values of Vector 2
	Node* root = NULL;	// Create the root of tree
	for(std::vector<int>::const_iterator Iter1 = Vec1.begin(); Iter1 != Vec1.end(); ++Iter1) {	// Loop to build BST given Vec1
		root = add(root, *Iter1);
	}
	std::cout << "\nLinear Searching BST with values from Vector 2" << std::endl;
	summary = 0;	// Set Summary count to 0
	time_start = std::chrono::high_resolution_clock::now();	// Start initial timestamp
	for(std::vector<int>::const_iterator Iter2 = Vec2.begin(); Iter2 != Vec2.end(); ++Iter2){
		search(root, *Iter2);
	}
	time_end = std::chrono::high_resolution_clock::now();	// Record the end timestamp
	elapsed = time_end - time_start;	// Find elapsed difference in time
	std::cout << "Found " << summary << " matching integers in " << elapsed.count() << " milliseconds." << std::endl;

	return 0;
}

// Function Definitions
void search(Node* obj, int num) {
	Node* temp = obj; 	// assigns pointer to a temporary node
	while(temp) {	// While the temp node isn't NULL
		if(num == temp->num) {	// Check that the node's value matches the searched number
			summary += temp->count;
		}
		if(num < temp->num) {	// Condition to check if the number is less than node number
			temp = temp->left;	// Assigns pointer to the left to the temp node
		}
		else{
			temp = temp->right;	// Condition that assigns right pointer to temp if num is greater
		}
	} 
}

Node* add(Node* obj, int num) {
	if(!obj) {	// If the node doesnt exist
		Node* node = new Node(num);	// Create new node with number
		return node; 	// return address of the node
	}
	if(num == obj->num) {	// Condition to check if the number matches the node's number
		obj->count = obj->count + 1;	// Add 1 to count
		return obj;	// return node pointer of matching value
	}
	if(num < obj->num) {	// Condition to check if the number is less than the node number
		obj->left = add(obj->left, num);	// Add result of add function to the left pointer of node
	}
	else {
		obj->right = add(obj->right, num);	// Add result of add function to the right pointer of node
	}
	return obj;
}

/*
know insert and delete from binary search tree

know functions for hashtable

binary search tree

leafs per height 2^height
total leaves 2^(height+1) - 1

tree traversal

binary search tree
inster and deletion done recursively.  3 conditions, 1 child, no child, 2 child

*/