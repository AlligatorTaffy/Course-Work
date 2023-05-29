/*
 AlligatorTaffy
 Final Project - Media Collection Database
 project.cpp - Main Program

 Description of the Problem:
 User has various quantities of diverse media types (Videos, Music, and Games).
 A program was needed to help create and inventory based upon the most popular 
 media in possesion.  The database helps organize and record what media is actually
 owned.
 
 Pseudo Code:
 I have created a 4 case switch menu to repeat in a while loop until the escape case is selected.
 	Case 1 - View/Search for Media
 			 In this case, you can choose to 'View Media' which prompts the user to display
 			 "All Media", "All Music", "All Video", and "All Games".
 			 "Search Media" allows you to filter the database based upon search criteria.  The 
 			 search parameters are: Genre, Console, Artist, Review, Publisher, and Year Published.
 	Case 2 - Create a New Entry
 			 In this case, the addEntry function is called while nested in the vector push_back function
 			 to make a new entry.  addEntry prompts the user for input data to be stored in a newly 
 			 created media object.
 	Case 3 - Modify/Delete Entry
 			 In this case, you can choose between two options.  "Modify Entry" allows the user to input
 			 the database number (datNum) and then input new information into that media object. The
 			 modEntry function from the 'brice' namespace is used here to search the vector for the 
 			 given datNum and then reassign based upon that iterator
 			 "Delete Entry" is essentially the same function as the "Modify Entry" function by calling
 			 the delEntry function from the 'brice' namespace; however, if the datNum is found by the 
 			 iterator, the vector function .erase(Iter) is called to remove that object from the vector 
 			 and then the ++Iter is called to advance the iterator over the deleted section.
 	Case 9 - Save Database and Exit
 			 In this case, the entire vector is passed to the saveList function which uses fstream to 
 			 write the contents of each media object to "media_database.dat".  The "media_database.dat"
 			 file also keeps track of the total size of the vector so that it can be recalled upon the
 			 start of the program.
 
 Namespace Definitions:
 	brice - This namespace was primarily created to separate my vector functions from my local functions
 			for int main().

 			void printList - Essentailly a for loop is created to iterate through the vector and using 
 							the member function Record::displayItem to cout the contents of each media
 							object in the vector.
 			void modEntry - A function that iterates through the vector looking for the datNum value that
 							matches the user input.  If that value is found, Record::addEntry is called
 							to overwrite the derefenced iterator to change the values of the media object.
 			void delEntry - A function that iterates through the vector looking for the datNum value that
 							matches the user input.  If that value is found, media.erase(Iter) is called
 							to delete the object that Iter is referencing.  Once deleted, the Iter is 
 							incremented over the deleted spot.

 Global Variables:
 	ofstream fout 		-	Created globally so that all functions can access fout so that information can be
 							written to a save file.
 	ifstream fin  		- 	Created globally so that all functions can access fin so that information can be
 							read into the vector upon start.
 	int entries	  		-	Created globally so that all functions can access the total number of entries that
 							are within the vector.  Helps keep a number rather than using .size().
 	int databaseNum 	-	Created globally so that all functions can access the running number to assign a
 							unique number to a value in the database.

 Local Functions:
 	void importList	-	Local function that takes the fin input from the saved "media_database.dat" file and 
 						creates new media objects and pushes them into a vector.
 	void saveList	-	Local functoin that is passed the vector and uses fout to write all of the contents
 						of each media object into a line delimited save file "media_database.dat".
*/

#include "record.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Local Namespace
namespace brice {
	int entries = 0;
	void printList(const vector<Record>& rDisplay, int x) {
		if(x < 0 || x > 3) {
			if(x == 9) {
				cout << "\nReturning to Menu" << endl;
			} else {
				throw "Invalid_Number";
			}
		}
		for(vector<Record>::const_iterator readIter = rDisplay.begin(); readIter != rDisplay.end(); ++readIter) {
			Record temp;
			temp = *readIter;
			if(x == 0) {
				Record::displayItem(temp);
				cout << endl;
			}
			if(Record::getMediaType(temp) == x) {
				Record::displayItem(temp);
				cout << endl;
			}
			
		}
	}
	void modEntry(vector<Record>& rVector, int x) {
		for(vector<Record>::iterator Iter = rVector.begin(); Iter != rVector.end(); ++Iter) {
			Record temp;
			temp = *Iter;
			if(x == Record::getDatNum(temp)) {
				*Iter = Record::addEntry();
			}
			if(x != Record::getDatNum(temp) && Iter == rVector.end()) {
				cout << "Entry Not Found";
			}
		}
	}
	void delEntry(vector<Record>& rVector, int x) {
		for(vector<Record>::iterator Iter = rVector.begin(); Iter != rVector.end();) {
			Record temp;
			temp = *Iter;
			if(x == Record::getDatNum(temp)) {
				Iter = rVector.erase(Iter);
				entries--;
			} else {
				++Iter;
			}
		}
	}
}

// Global Variables
ofstream fout;
ifstream fin;
int entries = 0;
int databaseNum = 0;
vector<Record> media;

// Local Function Declarations
void importList();
void saveList(const vector<Record>& rDisplay);

// Main Program
int main() {
	importList();
	int select = 0;
	int choice = 0;
	int viewNum = 0;
	string search = "NULL";
	int searchVal = 0;
	cout << "\n\n\tWelcome to the Media Database!\n";
	while(select != 9) {
		cout << "\n\nMain Menu:\n\t1.) View/Search Media\n\t2.) Create New Media Entry\n\t3.) Modify/Delete Media Entry\n\t9.) Save and Exit\n\nPlease select a number:: ";
		cin >> select;
		switch(select){
			case 1:
				cout << "\nView Media or Search Media?\n\t1.) View\n\t2.) Search\n\t3.) Back\nMake a Selection:: ";
				cin >> choice;
				if(choice < 1 || choice > 3) {
					cout << "Invalid Number!  Returning to Menu!" << endl;
				}
				if(choice == 1) {
					cout << "\nWhat would you like to view?\n\t0.) All Media\n\t1.) Music List\n\t2.) Video List\n\t3.) Game List\n\t9.) Back\nChoose a number:: ";
					cin >> viewNum;
					cout << endl;
					try {
						brice::printList(media, viewNum);
					}
					catch(char const* error) {
						cout << "\nInvalid Number entered!  Returning to Menu!" << endl;
					}
					cout << endl;
					break;
				}
				if(choice == 2) {
					cout << "\nSelect Filter Criteria\n\t1.) Genre\n\t2.) Console\n\t3.) Artist\n\t4.) Review\n\t5.) Publisher\n\t6.) Year Published\n\t7.) Main Menu\nChoose a Number:: ";
					int searchSel;
					cin >> searchSel;
					if(searchSel == 1) {
						cout << "Filtering by Genre, enter a genre:: ";
						cin.ignore();
						getline(cin, search);
						for(vector<Record>::const_iterator readIter = media.begin(); readIter != media.end(); ++readIter) {
							Record temp;
							temp = *readIter;
							if(Record::getGenre(temp) == search) {
								Record::displayItem(temp);
								cout << endl;
							}
						}
					}
					if(searchSel == 2) {
						cout << "Filtering by Console, enter a console name:: ";
						cin.ignore();
						getline(cin, search);
						for(vector<Record>::const_iterator readIter = media.begin(); readIter != media.end(); ++readIter) {
							Record temp;
							temp = *readIter;
							if(Record::getConsole(temp) == search) {
								Record::displayItem(temp);
								cout << endl;
							}
						}
					}
					if(searchSel == 3) {
						cout << "Filtering by Artist, enter an artist:: ";
						cin.ignore();
						getline(cin, search);
						for(vector<Record>::const_iterator readIter = media.begin(); readIter != media.end(); ++readIter) {
							Record temp;
							temp = *readIter;
							if(Record::getArtist(temp) == search) {
								Record::displayItem(temp);
								cout << endl;
							}
						}
					}
					if(searchSel == 4) {
						cout << "Filtering by Review, enter a review:: ";
						cin.ignore();
						cin >> searchVal;
						for(vector<Record>::const_iterator readIter = media.begin(); readIter != media.end(); ++readIter) {
							Record temp;
							temp = *readIter;
							if(Record::getReview(temp) == searchVal) {
								Record::displayItem(temp);
								cout << endl;
							}
						}
					}
					if(searchSel == 5) {
						cout << "Filtering by Publisher, enter a publisher:: ";
						cin.ignore();
						getline(cin, search);
						for(vector<Record>::const_iterator readIter = media.begin(); readIter != media.end(); ++readIter) {
							Record temp;
							temp = *readIter;
							if(Record::getPublisher(temp) == search) {
								Record::displayItem(temp);
								cout << endl;
							}
						}
					}
					if(searchSel == 6) {
						cout << "Filtering by Year Published, enter a year:: ";
						cin.ignore();
						cin >> searchVal;
						for(vector<Record>::const_iterator readIter = media.begin(); readIter != media.end(); ++readIter) {
							Record temp;
							temp = *readIter;
							if(Record::getYear(temp) == searchVal) {
								Record::displayItem(temp);
								cout << endl;
							}
						}
					}
					if(searchSel == 7) {
						cout << "\n Returning to Main Menu" << endl;
					}
					if(searchSel < 1 || searchSel > 8) {
						cout << "\nInvalid Number entered!  Returning to Menu!" << endl;
					}
				}
				break;
		
			case 2:
				cout << "\nCreating a new entry!" << endl;
				try {
					media.push_back(Record::addEntry());
					entries++;
				}
				catch(char const* error) {
					cout << "\nInvalid Number entered!  Returning to Menu!" << endl;
				}
				break;
			
			case 3:
				cout << "Select Option:\n\t1.) Modify Entry\n\t2.) Delete Entry\n\t9.) Back\nChoose and Option:: ";
				cin >> viewNum;
				if(viewNum == 1) {
					cout << "\nPlease enter a Database Number to be MODIFIED:: ";
					int tempNum;
					cin >> tempNum;
					brice::modEntry(media, tempNum);
				}
				if(viewNum == 2) {
					cout << "\nPlease enter a Database Number to be DELETED:: ";
					int tempNum;
					cin >> tempNum;
					brice::entries = entries;
					brice::delEntry(media, tempNum);
					entries = brice::entries;
				}
				if(viewNum == 9) {
					cout << "\nReturning to Menu" << endl;
				}
				break;

			case 9:
				cout << "\n\tNow Saving..." << endl;
				saveList(media);
				break;

			default:
				cout << "Not a valid selection.  Try again" << endl;
				break;
		}
	}
	return 0;
}

// Local Function Definitions
void importList() {
	fin.open("media_database.dat");
	fin >> entries;
	fin >> databaseNum;
	for(int i = 0; i < entries; i++) {
		int a, h, k, l, m;
		string b, c, d, e, f, g, j;
		fin >> a;
		fin.ignore();
		getline(fin, b);
		getline(fin, c);
		getline(fin, d);
		getline(fin, e);
		getline(fin, f);
		getline(fin, g);
		fin >> h;
		fin.ignore();
		getline(fin, j);
		fin >> k;
		fin >> l;
		fin >> m;
		Record temp(a, b, c, d, e, f, g, h, j, k, l, m);
		media.push_back(temp);
	}
	fin.close();
}
void saveList(const vector<Record>& rDisplay) {
	fout.open("media_database.dat");
	fout << entries << endl;
	fout << databaseNum << endl;
	for(vector<Record>::const_iterator readIter = rDisplay.begin(); readIter != rDisplay.end(); ++readIter) {
		fout << *readIter;
	}
	fout.close();
}