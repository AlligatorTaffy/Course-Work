/*
 AlligatorTaffy
 Program #6 - Add Out_Of_Bounds exception class to handle index out of range
            error.
 
 Description of the Problem:
 Testing if the templated arrayDb class can handle an array out of bounds
 execption without causing the program to crash.  
 
 Pseudo Code:
 I have created two different test cases.  A case to test the exception for
 the overloaded operator[] and the overloaded const operator[].  Each case
 will create each specific array and then give the user the option to cause
 the exception error.
 
 Each test proves the following functions:
 - Creates an array class by the given type using an overloaded constructor
 - Displays the contents of the given array by using overloaded operator<<
 - Tests the 'try' and 'catch' blocks by causing an out of range exception
 
 These test cases should be sufficient to prove that the specific type of
 array class has been created and can throw the Out_of_Bounds exception
 given the user input.
 */

#include <iostream>
#include "arraydb.cpp"
using namespace std;


int main()
{
    // Test case to check for Out of Bounds exception by accessing an index
    // outside the size of the array
    cout << "Initiating Out of Bounds Test on standard array" << endl;
    cout << "The array size is 3" << endl;
    ArrayDb<int> test1(3,1);
    for(int i = 0; i < 3; i++)
    {
        cout << "Index #" << i << ": " << test1[i] << endl;
    }
    int index;
        cout << "Enter an index (a value >2 will cause exception::";
        cin >> index;
    try {
        cout << test1[index] << endl;
    }
    catch(Out_Of_Bounds &e) {
        cout << e.what() << endl;
    }
    
    // Test case to check for Out of Bounds exception by accessing an index
    // outside the size of the const array
    cout << "\n\n\n\nInitiating Out of Bounds Test on const array" << endl;
    cout << "The array size is 3" << endl;
    const ArrayDb<int> test2(3,3);
    for(int i = 0; i < 3; i++)
    {
        cout << "Index #" << i << ": " << test2[i] << endl;
    }
    cout << "Enter an index (a value >2 will cause exception::";
    cin >> index;
    try {
        cout << test2[index] << endl;
    }
    catch(Out_Of_Bounds &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
