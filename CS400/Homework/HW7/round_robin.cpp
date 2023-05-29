/**
AlligatorTaffy
Homework #7 - Round Robin
April 14, 2019
**/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#define CPU_TIME 4

// Class Definition
class Process {
public:
	int id;		// Holds Process ID
	int arrival_time;	// Holds the time which the process came in
	int time_needed;	// Holds the time it takes to process
	int finished_time;	// Holds the timestamp when process completed
	Process() {
		id = arrival_time = time_needed = finished_time = 0;	// Default constructor to initialize 0
	}
	Process(int x, int y, int z) {	// Overloaded constructor that takes in ID, Arrival_time, and Time_needed
		id = x;
		arrival_time = y;
		time_needed = z;
	}
};

// Global Variables	
int inputcount = 0;		// Counter for number of lines in file
std::fstream fin;		// Defined fstream variable
std::vector<Process> Input;		// Vector for Read in Process objects from input file
std::queue<Process> Working;	// Working Queue to handle order of processes
std::vector<Process> Finished;	// Vector for holding the sorted Process objects

// Function Declarations
void printVector(std::vector<Process>& vec);	// Function declaration for printing contents of Process class

// Main Program
int main() {
	fin.open("20190408_round_robin.txt");	// Open file
	if (fin.fail()) {		// Condition if file isn't found
		std::cout << "FILE NOT FOUND" << std::endl;
	} else {
		//std::cout << "FOUND" << std::endl;	// Debug Message
		std::string in_string;		// Define empty string to hold line from getline
		int arr[3];		// Create a temporary array to hold parsed values from in_string
		while(std::getline(fin, in_string)) {	// While loop to continue if not at the end of file
			arr[0] = arr[1] = arr[2] = 0;	// Initialize array with 0
			std::stringstream(in_string) >> arr[0] >> arr[1] >> arr[2];		// StringStream to convert string to int
			Input.push_back(Process(arr[0], arr[1], arr[2]));	// Pushing newly created Process object into vector
			inputcount++;	// Increase the file line counter
		}
		fin.close();	// Close the file
	}

	//std::cout << "\tInitial List" << std::endl;
	//printVector(Input);		// Print out the initial order of values from objects

	int time = 0;	// Initialize the timer
	Process Temp;	// Create a temporary Process object
	std::vector<Process>::const_iterator Input_Iter = Input.begin();	// Create a read iterator for Input vector
	Working.push(*Input_Iter);	// Push initial object into the queue
	while(!Working.empty()) {		// While loop to continue while the queue is NOT empty
		if((inputcount - 1) != 0 && time > 0) {		// Condition to check if all the items in the input vector is in the queue
			for(Input_Iter = Input.begin(); Input_Iter != Input.end(); ++Input_Iter) {	// Loop through input vector to see if the time matches to add to queue
				if(Input_Iter->arrival_time == time) {	
					Working.push(*Input_Iter);	// Push object into the queue
					inputcount--;	// Reduce the input count
					//std::cout << "Added!" << std::endl;	// Debug Message
				}
			}
		}

		if(time % CPU_TIME == 0 && time > 0) {	// Condition to decrement process bound by CPU BURST
			Temp = Working.front();		// First in queue is copied into temp Process
			Working.pop();	// First process removed from queue
			Temp.time_needed -= CPU_TIME;	// Subract the CPU time from the process time needed
			if(Temp.time_needed > 0) {	// If there is remaining processing time, push back into queue
				Working.push(Temp);
				//std::cout << "\tP" << Temp.id << std::endl	// Debug Message
			} else {	// If process is done, set time needed to 0, write the current timestamp, then push into completed vector
				Temp.time_needed = 0;
				Temp.finished_time = time;
				Finished.push_back(Temp);
			}
		}
		//std::cout << time++ << std::endl;		// Debug Message
		time++;		// Increment the time
	}


	std::cout << "\n\n\tFinished Order" << std::endl;
	printVector(Finished);		// Print the final vector

	return 0;	// Exit the program
}

void printVector(std::vector<Process>& vec) {
	for(std::vector<Process>::const_iterator readIter = vec.begin(); readIter != vec.end(); ++readIter) {
		std::cout << "ID: " << readIter->id << std::endl;
		std::cout << "Arrival Time: " << readIter->arrival_time << std::endl;
		std::cout << "Time Needed: " << readIter->time_needed << std::endl;
		std::cout << "Finished Time: " << readIter->finished_time << std::endl;
		std::cout << std::endl;
	}
}
