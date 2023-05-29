/**
AlligatorTaffy
Extra Credit #1
March 4, 2019
**/

#include <iostream>

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

typedef Node* NodeP;	// Create shortcut to make Node pointers

// Function Declarations
void add_head(NodeP& head, int num);
void printList(NodeP& head);
void insertSort(NodeP* head_ref);
void insertMove(NodeP* head_ref, NodeP new_node);
void reverseList(NodeP& head);


int main() {
	NodeP head = NULL;		// Create the linked list and point it to null

	// Call add_head to add 10 integers in random sequence to the head
	add_head(head, 7);
	add_head(head, 10);
	add_head(head, 1);
	add_head(head, 2);
	add_head(head, 9);
	add_head(head, 3);
	add_head(head, 5);
	add_head(head, 6);
	add_head(head, 4);
	add_head(head, 8);

	// Test to display the UNSORTED Linked List
	std::cout << "This is an UNSORTED Linked List:" << std::endl;
	printList(head);
	std::cout << std::endl;

	// Test to display the SORTED Linked list
	std::cout << "This is a SORTED Linked List via Insertion Sort:" << std::endl;
	insertSort(&head);
	printList(head);
	std::cout << std::endl;

	// Test to display the REVERSE SORTED Linked List
	std::cout << "This is a REVERSE SORTED Linked List:" << std::endl;
	reverseList(head);
	printList(head);
	std::cout << std::endl;

	return 0;
}


void add_head(NodeP& head, int num) {	// Function to add a new node to the head of the Linked List
	NodeP temp = head;		// Make copy of the head
	head = new Node(num);	// Create new node and assign to head
	head->next = temp;		// Assigns the previous head address to the new node next address
}

void printList(NodeP& head) {		// Function to print the values of the final summation
	NodeP temp = head;		// Create a temp pointer of the passed head
	while(temp != NULL) {	// Do the following while temp isn't NULL
		std::cout << temp->data << " ";	// Print value from object to console
		temp = temp->next;	// Increment temp pointer to the next object
	}
}

void insertSort(NodeP* head) {		// Function to use insertion sort on a passed linked list by passed dereferenced head
	NodeP curr = *head;		// Create pointer to address of head
    NodeP sorted = NULL;	// Create pointer for sorted
    NodeP next = NULL;		// Create pointer for next
    while(curr != NULL) {	// Iterate through the linked list
        next = curr->next;	// Assign next location with the address in current object's next address
        insertMove(&sorted, curr);	// Pass reference to sorted list and current object pointer to insertMode
        curr = next;	// Increment current object pointer to next object
    }
    *head = sorted;		// Assign the sorted list address to head
} 

void insertMove(NodeP* head, NodeP node) {		// Function to compare adjacent objects data value and move then based on size
    NodeP curr = NULL;		// Create a current location pointer set to NULL		
    if(*head == NULL || (*head)->data >= node->data) {	// If the address of head equals NULL OR the dereferenced value of head is greater than the passed node
        node->next = *head;	// Move address of head into the passed node's next address (moves head object to the right)
        *head = node;	// Passed node is now the new head
    }
    else {
        curr = *head;	// Current pointer is assigned head address
        while(curr->next != NULL && curr->next->data < node->data) {	// While next address isn't NULL and the value of data in the next object is less than the passed object
        	curr = curr->next; // Shift left by moving next address to current address
        }
        node->next = curr->next;	// move address of passed node next to the next address of current object
        curr->next = node;		// move address of the next object from current to the passed node
    }
}

void reverseList(NodeP& head) {		// Function to reverse addresses of a singly linked list
	NodeP curr = head;		// Create temporary curr pointer assigned address of head
	NodeP prev = NULL;		// Create temporary prev pointer and set it to NULL
	NodeP next = NULL;		// Create temporary next pointer and set it to NULL
	while(curr != NULL) {	// Iterate through list while curr doesn't equal NULL
		next = curr->next;	// Current object places its next address in next pointer
		curr->next = prev;	// Current object assigned its next address with contents of prev
		prev = curr;	// Prev pointer holds address of current object
		curr = next;	// Current object is assigned the address of next
	}
	head = prev;	// Address of prev is assigned to head of linked list
}