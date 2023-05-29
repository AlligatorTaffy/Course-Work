/*
 AlligatorTaffy
 Program #1
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global Variables
ofstream fout;
ifstream fin;

// Structure Definitions
struct book {
		int book_number;
		string book_title;
		string book_author;
		string book_disc;
		int month_read;
		int year_read;
		int book_rating;
};

// Prototype Functions
void print_books(int slot, book array[]);
void edit_books(int slot, book array[]);
void io_books(int slot, book array[]);


// Main Program
int main() {
	int select;
	int total = 0;
	book books[500];
	cout << "Welcome to the Personal Book Database!" << endl;
	cout << "\n\nChecking for previous database file... " << endl;
	
	// Checking for save file and then importing the data into our structure array
	ifstream fin;
	fin.open("reading_list.txt");
	if (fin.fail()) {
		cout << "NOT FOUND" << endl;
	} else {
		cout << "FOUND" << endl;
		fin >> total;
		for (int i = 0; i < total; i++) {
			fin >> books[i].book_number;
			fin.ignore();
			getline(fin, books[i].book_title);
			getline(fin, books[i].book_author);
			getline(fin, books[i].book_disc);
			fin >> books[i].month_read;
			fin >> books[i].year_read;
			fin >> books[i].book_rating;
		}
	fin.close();
	} 

	// Main Menu using switch cases
	while(select != 6) {
		cout << "\n\nMain Menu:\n\t1.) Print Book List\n\t2.) Create New Book Entry\n\t3.) Modify Book Entry\n\t4.) Print Total Number of Books in Library\n\t5.) Search Books by Rating\n\t6.) Save and Exit\n\nPlease select a number >> ";
		cin >> select;
		switch(select){

			// Printing out the list of all the books in the database
			case 1:
				if(total == 0) {
						cout << "Book database is empty!";
				}
				else { 
					cout << "Printing List of Books\n\n";
					for (int i = 0; i < total; i++) {
						print_books(i, books);
					}
				}
				break;

			// Entering a new book into the database
			case 2:
				cout << "\nEntering a new book\n" << endl;
				books[total].book_number = total + 1;
				cout << "Please enter the following:";
				edit_books(total, books);
				total++;
				cout << "\n\nBook Added!";
				break;

			// Modifying an existing book in the database
			case 3:
				int edit;
				if(total == 0) {
					cout << "Book database is empty!";
					break;
				} 
				else {
					cout << "Total books in database: " << total << endl;
					cout << "Please select a book number to edit (1-" << total << ") >> ";
					cin >> edit;
					if(edit == 0) {
						cout << "Invalid Book Number!!";
						break;
					} else {
						--edit;
					}
				}
				if(edit < total) {
					edit_books(edit, books);
					cout << "Book successfully modified!!";
					break;
				} else {
					cout << "Invalid Book Number!!";
					break;
				}

			// Lists the total amount of books within the database
			case 4:
				if(total == 0) {
					cout << "Book database is empty!";
				} 
				else if(total == 1) {
					cout << "There is " << total << " book in the database!" << endl;
				}
				else {
					cout << "There are " << total << " books in the database!" << endl;
				}				
				break;

			// Searches the database for books based upon a specified rating
			case 5:
				int rating;
				cout << "Please enter a rating (1-10) >> ";
				cin >> rating;
				if(rating >= 1 || rating <= 10) {
					cout << "Displaying Books with Rating of " << rating << endl;
					for (int i = 0; i < total; i++) {
						if(books[i].book_rating == rating) {
							print_books(i, books);
						} else {}
					}
					break;
				} else {
					cout << "Not a valid rating between 1-10!!";
					break;
				}

			// Saving the current database to a file and then exiting the program
			case 6:
				cout << "Now saving book database.  Please wait." << endl;
				fout.open("reading_list.txt");
				fout << total << endl;
				for (int i = 0; i < total; i++) {
						io_books(i, books);
					}
				fout.close();
				cout << "Done. Exiting" << endl;
				break;

			default:
				cout << "Not a valid selection.  Try again" << endl;
				break;
		}
	}

	return 0;
}


// Function Definitions

void print_books(int slot, book array[]) {
	cout << "Book #: " << array[slot].book_number << endl;
	cout << "Title: " << array[slot].book_title << endl;
	cout << "Author: " << array[slot].book_author << endl;
	cout << "Description: " << array[slot].book_disc << endl;
	cout << "Read Date: " << array[slot].month_read << "/" << array[slot].year_read << endl;
	cout << "Rating: " << array[slot].book_rating << endl;
	cout << endl;
};

void edit_books(int slot, book array[]) {
	cout << "\nTitle of Book >> ";
	cin.ignore();
	getline(cin, array[slot].book_title);
	cout << "Author of Book >> ";
	getline(cin, array[slot].book_author);
	cout << "Book Description >> ";
	getline(cin, array[slot].book_disc);
	cout << "Month Read (in MM) >> ";
	cin >> array[slot].month_read;
	cout << "Year Read (in YYYY format) >> ";
	cin >> array[slot].year_read;
	cout << "Rating of book (1-10) >> ";
	cin >> array[slot].book_rating;
};

void io_books(int slot, book array[]) {
		fout << array[slot].book_number << endl;
		fout << array[slot].book_title << endl;
		fout << array[slot].book_author << endl;
		fout << array[slot].book_disc << endl;
		fout << array[slot].month_read << endl;
		fout << array[slot].year_read << endl;
		fout << array[slot].book_rating << endl;
};
