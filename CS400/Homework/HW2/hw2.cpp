/**
AlligatorTaffy
Homework #2
February 22, 2019
**/

#include <iostream>
#include <fstream>
#include <ctime>
#include "arraylist.hpp"

// Function Declarations
void addCar();
void printCar(Car obj);
int searchId(int x);
void searchMC(std::string x, int y);
void readData();
void writeData();

// Global Variables
ArrayList Inventory;
Car TempCar;
std::ifstream fin;
std::ofstream fout;

int main(){
	srand(time(NULL));		// Seed the random number generator
	int select = 0;
	int searchSelect = 0;
	int id = 0;
	std::string input = "NULL";
	readData();		// Call readData function to read cars.data into the ArrayList
	std::cout << "Welcome to the Vehicle Inventory!" << std::endl;
	while(select != 4) {
		std::cout << "\nMain Menu:\n\t0) Search Car Inventory\n\t1) Add New Car to Inventory\n\t2) Delete Existing Car by ID\n\t3) List All Cars in Inventory\n\t4) Exit the Program\nMake a Numerical Selection::";
		std::cin >> select;
		switch(select) {
			case 0:		// Search option of Menu
					std::cout << "\n\tSearch Menu:\n\t\t0) ID\n\t\t1) Make\n\t\t2) Category\nMake a Numerical Selection::";
					std::cin.ignore();
					std::cin >> searchSelect;  // Grab user input to select subcategory
					switch(searchSelect) {
						case 0:		// Subcategory to search by ID
								std::cout << "Enter ID:: ";
								std::cin.ignore();
								std::cin >> id;
								searchId(id);
								break;
						case 1:		// Subcategory to search by MAKE
								std::cout << "Enter Make:: ";
								std::cin.ignore();
								std::getline(std::cin, input);
								searchMC(input, 1);
								break;
						case 2:		// Subcategory to search by CATEGORY
								std::cout << "Enter Category:: ";
								std::cin.ignore();
								std::getline(std::cin, input);
								searchMC(input, 2);
								break;
						default:	// Default case to return error message
								std::cout << "Invalid Selection!" << std::endl;
								break;
					}
					break;
			case 1:		// Add Car to Inventory option of Menu
					addCar();	// Call addCar function to add Car object to end of ArrayList
					break;
			case 2:		// Delete Car from Inventory option of Menu
					std::cout << "Enter ID of car to be DELETED:: ";
					std::cin.ignore();
					std::cin >> id;
					Inventory.del(Inventory.search(id));
					break;
			case 3:		// List cars in Inventory option of Menu
					if(Inventory.size() == 0) {  // Condition to check of Inventory is 0
						std::cout << "Inventory List is Empty!" << std::endl;
					}
					else {	// Option to sort the Inventory before printing
						std::cout << "Want to sort Inventory by ID before Listing?\nPress 'y' to sort, 'Enter' to continue::";
						std::cin.ignore();
						std::getline(std::cin, input);
						if(input == "y") {
							Inventory.sort();  // Function called to sort ArrayList by Car ID
							for(int i = 0; i < Inventory.size(); i++) {		// Loop to traverse ArrayList
								printCar(Inventory.get(i));		// printCar function is passed the return index of ArrayList get function
								std::cout << std::endl;
							}
						}
						else {
							for(int i = 0; i < Inventory.size(); i++) {		// Loop to traverse ArrayList
								printCar(Inventory.get(i));		// printCar function is passed the return index of ArrayList get function
								std::cout << std::endl;
							}
						}
					}
					break;
			case 4:		// Save and Quit option of Menu
					writeData();	// writeData function is called to write contents of ArrayList to 'cars.data'
					break;
			default:
					std::cout << "Invalid Selection!" << std::endl;  // Error message if select doesnt match case
					break;
		}
	}
	return 0;
}

void addCar() {
	std::string make;
	std::string model;
	std::string category;
	std::cout << "Adding a new car" << std::endl;
	std::cin.ignore();
	std::cout << "What is the Make?:: ";
	std::getline(std::cin, make);
	std::cout << "What is the Model?:: ";
	std::getline(std::cin, model);
	std::cout << "What is the Category?:: ";
	std::getline(std::cin, category);

	// Condition that only allows certain CATEGORY values (compact, mid-size, full-size, c-suv, m-suv, f-suv, mini-van, truck)
	if(category == "compact" || category == "mid-size" || category == "full-size" || category == "c-suv" || category == "m-suv" || category == "f-suv" || category == "mini-van" || category == "truck") {
		int tempNum = ((static_cast<double>(rand())/RAND_MAX) * 1000) + 1;	// Random number between 1-1000 is generate for ID
		for(int i = 0; i < Inventory.size(); i++) {		// Loop created to traverse ArrayList
			TempCar = Inventory.get(i);		// Each object in the loop is assigned to TempCar object
			if(TempCar.getId() == tempNum) {	// Condition that checks if there is a repeated ID number
				tempNum = ((static_cast<double>(rand())/RAND_MAX) * 1000) + 1;	// If duplicate ID exists, generate new ID number
				i = 0;	// Reset loop to the beginning
			}
		}
		TempCar = Car(tempNum, make, model, category);	// TempCar object is overwritted with newly created Car object given the user received varables
		Inventory.add(TempCar);		// TempCar object is added to the end of ArrayList via Add function
	}
	else {
		std::cout << "Invalid Category!  Must be 'compact, mid-size, full-size, c-suv, m-suv, f-suv, mini-van, truck'" << std::endl;
	}
}

void printCar(Car obj) {	// Function that prints contents to the console
	std::cout << "ID: " << obj.getId() << std::endl;	// Returned ID is written to console
	std::cout << "Make: " << obj.getMake() << std::endl;	// Returned MAKE is written to console
	std::cout << "Model: " << obj.getModel() << std::endl;	// Returned MODEL is written to console
	std::cout << "Category: " << obj.getCategory() << std::endl;	// Returned CATEGORY is written to console
}
int searchId(int x) {	// Search function that search ID given the search parameter
	if(Inventory.search(x) == -1) {		// If the search parameter is NOT found, print error message
		std::cout << "ID Not Found!" << std::endl;
	}
	else {
		printCar(Inventory.get(Inventory.search(x)));	// printCar function is called to print found object
	}
	return -1;
}
void searchMC(std::string x, int y) {	// Search function that searches MAKE and CATEGORY given search parameter, menu option, and index
	for(int i = 0; i < Inventory.size(); i++) {
		if(Inventory.search(x, y, i) != -1) {	// If the search parameter is found, return the index of object
			printCar(Inventory.get(Inventory.search(x, y, i)));		// printCar function is called to print found object
			std::cout << std::endl;
		}
	}
}
void readData() {
	int total;
	int w;
	std::string x;
	std::string y;
	std::string z;
	fin.open("cars.data");	// Open 'cars.data' file
	if (fin.fail()) {	// Check to see if file exists
		std::cout << "DATABASE 'cars.data' FILE NOT FOUND\n" << std::endl;
	} 
	else {
		fin >> total;	// Reads first line of file to determine size of ArrayList
		for(int i = 0; i < total; i++) {	// Loop condition to traverse the size of imported array size
			fin >> w;	// Read ID into 'w' variable
			fin.ignore();	
			std::getline(fin, x);	// Read MAKE into 'x' variable
			std::getline(fin, y);	// Read MODEL into 'y' variable
			std::getline(fin, z);	// Read CATEGORY into 'z' variable
			TempCar = Car(w, x, y, z);	// Create temporary Car object from overloaded constructor
			Inventory.add(TempCar);		// Add function of ArrayList is called and passed temporary Car object
		}
	fin.close();
	}
}
void writeData() {
	std::cout << "Now Saving Car Database.  Please wait." << std::endl;
	fout.open("cars.data");		// Open 'cars.data' file
	fout << Inventory.size() << std::endl;		// Write size of ArrayList to file
	for(int i = 0; i < Inventory.size(); i++) {		// Loop through each object of the ArrayList
		TempCar = Inventory.get(i);		// Returned object is assigned to temporary Car object
		fout << TempCar.getId() << std::endl;	// Write returned value of getId to line of file
		fout << TempCar.getMake() << std::endl;		// Write returned value of getMake to line of file
		fout << TempCar.getModel() << std::endl;	// Write returned value of getModel to line of file
		fout << TempCar.getCategory() << std::endl;	// Write returned value of getCategory to line of file
	}
	fout.close();	// Close 'cars.data' file
	std::cout << "Done. Exiting" << std::endl;
	
}
