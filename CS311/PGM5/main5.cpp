/*
 AlligatorTaffy
 Program #5 - Converting arrayDb to a template class
 
 Description of the Problem:
 Testing if the templated arrayDb class can handle the 9 basic types:
 int, short int, long int, long long int, double, long double, float, char,
 & bool.
 
 Pseudo Code:
 There are 9 different test cases.  Each case tests each of the 9 basic types
 identified above.  The start of the program will ask for the size the user
 desires for ALL arrays during this test.  The case will tell the user what
 type of array has been created and then ask for said value of the corresponding
 type.  It will then display the contents of the array class once all user input
 has been received.
 
 Each test proves the following functions:
 - Creates an array class by the given type using an overloaded constructor
 - Displays the contents of the given array by using overloaded operator<<
 
 These test cases should be sufficient to prove that the specific type of
 array class has been created and can store the given parameter type.  Value in
 and value out without giving an error demonstrates this.
*/

#include <iostream>
#include "arraydb.cpp"
using namespace std;


 int main()
 {
     int size;
     cout << "Enter how large you want ALL the arrays?";
     cin >> size;
 
     // Create a double type array of that size
     ArrayDb<double> arrayDBL(size);
     cout << "This array is a 'double'!" << endl;
     cout << "Enter a double number::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayDBL[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayDBL;
     
     // Create a int type array of that size
     ArrayDb<int> arrayINT(size);
     cout << "\nThis array is a 'int'!" << endl;
     cout << "Enter a int number::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayINT[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayINT;
     
     // Create a float type array of that size
     ArrayDb<float> arrayFLT(size);
     cout << "\nThis array is a 'float'!" << endl;
     cout << "Enter a float number::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayFLT[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayFLT;
     
     // Create a char type array of that size
     ArrayDb<char> arrayCHAR(size);
     cout << "\nThis array is a 'char'!" << endl;
     cout << "Enter a char::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayCHAR[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayCHAR;
     
     // Create a bool type array of that size
     ArrayDb<bool> arrayBOOL(size);
     cout << "\nThis array is a 'bool'!" << endl;
     cout << "Enter a bool value (TRUE=1,FALSE=0)::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayBOOL[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayBOOL;
     
     // Create a short int type array of that size
     ArrayDb<short int> arraySINT(size);
     cout << "\nThis array is a 'short int'!" << endl;
     cout << "Enter a short int::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arraySINT[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arraySINT;
     
     // Create a long int type array of that size
     ArrayDb<long int> arrayLINT(size);
     cout << "\nThis array is a 'long int'!" << endl;
     cout << "Enter a long int::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayLINT[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayLINT;
     
     // Create a long long int type array of that size
     ArrayDb<long long int> arrayLLINT(size);
     cout << "\nThis array is a 'long long int'!" << endl;
     cout << "Enter a long long int::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayLLINT[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayLLINT;
     
     // Create a long double type array of that size
     ArrayDb<long double> arrayLDBL(size);
     cout << "\nThis array is a 'long double'!" << endl;
     cout << "Enter a long double::" << endl;
     for(int i = 0; i < size; i++)
     {
         cout << "Slot " << (i+1) << ":  ";
         cin >> arrayLDBL[i];
     }
     cout << "Here are the contents of the array" << endl;
     cout << arrayLDBL;
 
 return 0;
 }
