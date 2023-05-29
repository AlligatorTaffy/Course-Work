/**
AlligatorTaffy
Homework #2
February 22, 2019


Class Car

Private:
	int id;		--	Stores ID of car
	std::string make;	--	Store the MAKE of car
	std::string model;	--	Store the MODEL of car
	std::string category;	--	Store the CATEGORY of car

Public:
	Car();	--	Default Constructor to set default values (unused)
	Car(int id_in, std::string make_in, std::string model_in, std::string category_in); -- Creates Car with passed ID, MAKE, MODEL, & CATEGORY values
	int getId();	--	Returns ID of object
	std::string getMake() -- Returns MAKE of object
	std::string getModel()	--	Returns MODEL of object
	std::string getCategory()	--	Returns CATEGORY of object

**/

#include <iostream>
#include <string>

#ifndef __CAR_HPP__
#define __CAR_APP__

class Car {
private:
	int id;		// Store ID of car
	std::string make;	// Store MAKE of car
	std::string model;	// Store MODEL of car
	std::string category;	// Store CATEGORY of car
public:
	Car() {		// Default Constructor 
		id = 0;		// ID is set to 0
		make = "NULL";	// MAKE is set to NULL
		model = "NULL";	// MODEL is set to NULL
		category = "compact";	// CATEGORY is set to NULL
	}
	Car(int id_in, std::string make_in, std::string model_in, std::string category_in) {	// Overloaded Constructor
		id = id_in;		// ID is set to passed id_in
		make = make_in;		// MAKE is set to passed make_in
		model = model_in;	// MODEL is set to passed model_in
		category = category_in;	// CATEGORY is set to passed category_in
	}
	int getId() {return id;}	// Getter function to return ID
	std::string getMake() {return make;}	// Getter function to return MAKE
	std::string getModel() {return model;}	// Getter function to return MODEL
	std::string getCategory() {return category;}	// Getter function to return CATEGORY
};
#endif