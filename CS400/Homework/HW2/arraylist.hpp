/**
AlligatorTaffy
Homework #2
February 22, 2019


Class ArrayList

Private:
	data_type arr[30];	--	Container array for Car classes
	int count;	--	Keeps size of the ArrayList and protects out of bounds

Public:
	typedef Car data_type;	--	Defines 'Car' as the data_type
	ArrayList();	--	Default Constructor for ArrayList
	void add(data_type obj);	--	Adds new 'Car' object to the end of ArrayList
	int search(int id);		--	Search Car objects in ArrayList for ID
	int search(std::string str, int sel, int index);	--	Search Car objects in ArrayList for Make/Category
	data_type get(int index);	--	Returns Car object given the index of ArrayList
	void del(int index);	--	Removes Car object from ArrayList given the index.  Shifts all objects to the left by 1
	int size();		--	Returns the current count of ArrayList
	void sort();	--	Sorts ArrayList using bubblesort by Car object 'ID'

**/

#include <iostream>
#include "car.hpp"

#ifndef __ARRAYLIST_HPP__
#define __ARRAYLIST_APP__

class ArrayList {
public:
	typedef Car data_type;
	ArrayList() {count = 0;}	// Default Constructor that sets index to 0
	void add(data_type obj) {
		if(count <= 30) {		// Checks the count to make sure the ArrayList isn't full
			arr[count++] = obj;		// Inserts Car object into the index = count then increments the count by 1
		}
		else {
			std::cout << "Add failed. No space in ArrayList." << std::endl;		// Display error message that ArrayList is full
		}
	}
	int search(int id) {
		for(int i = 0; i < count; i++) {	// Start loop at index 0 to count - 1. Iterates through ArrayList
			if(id == arr[i].getId()) {		// Condition to check if the passed ID value matches the returned ID field of Car object
				return i;		// if ID matches, return index of said object
			}
		}
		return -1;	// If value isn't found, return error
	}
	int search(std::string str, int sel, int index) {	// Overloaded search. Accepts the search parameter, a flag for Make/Category, and index
		if(sel == 1) {		// Flag for searching for Make
			if(str == arr[index].getMake()) {	// Condition to check if the passed MAKE value matches the returned MAKE field of Car object
				return index;		// If MAKE matches, return index of said object
			}
		}
		if(sel == 2) {		// Flag for searching for Category
			if(str == arr[index].getCategory()) {	// Condition to check if the passed Category value matches the returned Categry field of Car object
				return index;		// If Category matches, return index of said object
			}
		}
		return -1;	// If value isn't found, return error
	}
	data_type get(int index) {	// Returns Car object given index of ArrayList
		return arr[index];
	}
	void del(int index) {
		if(index >= 0 && index < count) {	// Index boundary orrer checking to make sure passed value is within operating range
			for(int i = index; i < count - 1; i++) {	// Loop to shift objects to the left from passed index
				arr[i] = arr[i + 1];	// Assigns object to the right of index into the index
			}
			count--;	// Decrements the count by 1
		}
		else {
			std::cout << "Invalid index." << std::endl;		// If index it out of bounds, return error message
		}
	}
	int size() {	// Returns the count which is the size of the ArrayList
		return count;
	}
	void sort() {	// Bubblesort function to sort by ID field of Car object.  
		for(int i = 0; i < (count - 1); i++) {	// Sets loop parameters to travese the ArrayList
			for(int j = 0; j < (count - 1 - i); j++) {	//	Sets loop to check value and move to the right
				if(arr[j].getId() > arr[j + 1].getId()) {	// Condition if object on the left is larger than on the right
					Car temp = arr[j];	// Object on the left assigned to temp object
					arr[j] = arr[j + 1];	// Object on the right overwrites object on the left
					arr[j + 1] = temp;	// Object on the right is assigned the value of left object from temp
				}
			}
		}
	}
private:
	data_type arr[30];	// ArrayList capacity of 30 is defined
	int count;	// Size of the ArrayList
};
#endif