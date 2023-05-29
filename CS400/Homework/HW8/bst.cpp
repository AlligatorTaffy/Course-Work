/**
AlligatorTaffy
Homework #8 - BST
April 24, 2019
**/

#include <iostream>

// Struct Definition
struct Node {
	int num;
	Node* left;
	Node* right;
	Node(int num) :num(num), left(NULL), right(NULL){}
};


// Global Variables	


// Function Declarations
bool search(Node* obj, int num);
Node* add(Node* obj, int num);
Node* del(Node* obj, int num);
int largestLeft(Node* obj);
void in_order(Node* obj);


// Main Program
int main() {
	Node* root = NULL;	// Initialize the BST
	int arr[12] = { 11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 31, 18 };	// Used number array from class example
	for(int i = 0; i < 12; i++) {	// Loop to insert values into the tree
		root = add(root, arr[i]);
	}


	// Test the Search function
	std::cout << "\n\nTesting the Search function" << std::endl;
	in_order(root);
	std::cout << std::endl;
	std::cout << "Is 7 in the BST? = " << search(root, 7) << std::endl;


	// Test the Add function
	std::cout << "\n\nTesting the Add function by inserting 7" << std::endl;
	in_order(root);
	std::cout << std::endl;
	add(root, 7);
	in_order(root);
	std::cout << std::endl;


	// Test the Del function
	std::cout << "\n\nTesting the Del function by removing 7" << std::endl;
	in_order(root);
	std::cout << std::endl;
	del(root, 7);
	in_order(root);
	std::cout << std::endl;


	return 0;	// Exit the program
}

// Function Definitions

bool search(Node* obj, int num) {
	Node* temp = obj; 	// assigns pointer to a temporary node
	while(temp) {	// While the temp node isn't NULL
		if(num == temp->num) {	// Check that the node's value matches the searched number
			return true;
		}
		if(num < temp->num) {	// Condition to check if the number is less than node number
			temp = temp->left;	// Assigns pointer to the left to the temp node
		}
		else{
			temp = temp->right;	// Condition that assigns right pointer to temp if num is greater
		}
	}
	return false; 
}

Node* add(Node* obj, int num) {
	if(!obj) {	// If the node doesnt exist
		Node* node = new Node(num);	// Create new node with number
		return node; 	// return address of the node
	}
	if(num == obj->num) {	// Condition to check if the number matches the node's number
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

Node* del(Node* obj, int num) {
	if(!obj) {	// Condition check to see if there is a isn't a matching node
		std::cout << "Target not found" << std::endl;
		return NULL; 
	}

	if(num < obj->num) {	// Condition if number is less than the node number
		obj->left = del(obj->left, num);	// Assign result of delete function to pointer of object left
	}
	else if(num > obj->num) {	// Condition if number is greater than the node number
		obj->right = del(obj->right, num);	// Assign result of delete function to pointer of object right
	}
	else {	// Condition that does operations on the target node
		if(obj->left == NULL && obj->right == NULL) {	// Condition for a leaf node
			delete obj;
			return NULL; 
		}
		else if(obj->left == NULL) {	// Condition if there is only a right child node
			Node *temp = obj->right;	// Create a temporary node pointer to hold address of right child node
			delete obj;
			return temp; 
		}
		else if(obj->right == NULL) {	// Condition when there is only a left child node
			Node *temp = obj->left;		// Create a temporary node pointer to hold address of left child node
			delete obj;
			return temp;
		}
		else {	// Condition when there are left and right child nodes
			obj->num = largestLeft(obj->left);	// Call function to find the largest number stored in the left child node
			obj->left = del(obj->left, obj->num);	// Assign result pointer from delete function to node left pointer
		}
	}
	return obj;
}

int largestLeft(Node *obj) {	// Function to check number all down the left side of tree
	int number; 
	while(obj) {
		number = obj->num;
		obj = obj->right; 
	}
	return number; 
}

void in_order(Node* obj) {	// Function from class notes to check the numbers in the tree
	if(obj) {
		in_order(obj->left);
		std::cout << obj->num << " ";
		in_order(obj->right);
	}
}