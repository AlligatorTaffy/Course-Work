//  Array Passer


#include <iostream>     //  We are using the basic commands from the console I/O kit.

using namespace std;    //  Declaring that we can use the standard namespace shorthand.

void increase(int* const array, const int NUM_ELEMENTS);            //  Declaring a void function that the accepted input is assigned to a pointer aimed at a constant int array with the number of array slots to process.
void display(const int* const array, const int NUM_ELEMENTS);       //  Declaring a void function that creates a constant pointer aimed at a constant int array with the number of array slots to process.

int main() {
    cout << "Creating an array of high scores.\n\n";
    const int NUM_SCORES = 3;                           //  a constant int is defined for the total number of scores possible
    int highScores[NUM_SCORES] = {5000, 3500, 2700};    //  the array gets values assigned via the initializer list
    
    cout << "Displaying scores using array name as a constant pointer.\n";
    cout << *highScores << endl;                    //  array 'highScores' is dereferenced to display the first score
    cout << *(highScores + 1) << endl;              //  array 'highScores' is dereferenced to display the second score
    cout << *(highScores + 2) << "\n\n";            //  array 'highScores' is dereferenced to display the third score
    
    cout << "Increasing scores by passing array as a constant pointer.\n\n";
    increase(highScores, NUM_SCORES);
    
    cout << "Displaying scores by passing array as a constant pointer to a constant.\n";
    display(highScores, NUM_SCORES);
   
    return 0;
}

void increase(int* const array, const int NUM_ELEMENTS) {           //  Defining a void function that the accepted input is assigned to a pointer aimed at a constant int array with the number of array slots to process.
    for (int i = 0; i < NUM_ELEMENTS; ++i) {                        //  The array is sent to this function and a pointer is created to point at the constant array.  So now the pointer 'array' points to the same location that 'highscores' is.
        array[i] += 500;                                            //  
	}
}

void display(const int* const array, const int NUM_ELEMENTS) {      //  Defining a void function that creates a constant pointer aimed at a constant int array with the number of array slots to process.
    for (int i = 0; i < NUM_ELEMENTS; ++i) {                        //  The array is sent to this function and a constant pointer is created to point to the constant array.  So now the pointer 'array' points to the same location that 'highscores' is.
        cout << array[i] << endl;                                   //  The contents of the array cannot be changed by definition.
	}
}

