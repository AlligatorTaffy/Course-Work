/*
  AlligatorTaffy
  Program Number: 3

     Description of the Problem:
          We have created a basic fraction calculator to add, subtract, 
          multiply, divide, calculate the decimal value, and reduce the
          fraction.  A switch case is used for each type of operator.

          Pseudo Code:
          A cout menu is made within a while loop and a switch statement
          
          Addition case - The user is asked for two different fractions 
               that are passed to c1 and c2 respectively.  Those two 
               classes are then added together and then the result is
               cout to the console.
          
          Subtraction case - The user is asked for two different fractions 
               that are passed to c1 and c2 respectively.  Those two 
               classes are then subtracted and then the result is
               cout to the console.
               
          Multiplication case - The user is asked for two different fractions 
               that are passed to c1 and c2 respectively.  Those two 
               classes are then multiplied together and then the result is
               cout to the console.
               
          Division case - The user is asked for two different fractions 
               that are passed to c1 and c2 respectively.  Those two 
               classes are then divided and then the result is
               cout to the console.
               
          Reduce case - The user is asked for a fraction that is passed
               to c3.  The member function c3.reduce() is called that
               reduces the fraction that is cout to the console.
               
          Decimal case - The user is asked for a function that is passed
               to c3.  The member function c3.deceq() is called to 
               calculate the decimal value of the numerator and denominator
               of c3.  The member function c3.getdec() is called to return
               the value of c3.dec to the console.
               
          Exit case - break is called and the program ends.
*/

#include <iostream>
#include "fraction.hpp"
using namespace std;

int main()
{
     int select = 0;
     Fraction c1, c2, c3;
     while(select != 7)
     {
          cout << "Main Menu:" << endl;
          cout << "\t1.) Add Fractions" << endl;
          cout << "\t2.) Subtract Fractions" << endl;
          cout << "\t3.) Multiply Fractions" << endl;
          cout << "\t4.) Divide Fractions" << endl;
          cout << "\t5.) Reduce Fraction" << endl;
          cout << "\t6.) Show Decimal Value of Fraction" << endl;
          cout << "\t7.) Exit" << endl;
          cout << "Please Enter a Selection:: ";
          cin >> select;
          cout << endl;
          switch(select)
          {
               case 1:
               {
                    cout << "Add Fractions" << endl;
                    cout << "Enter first fraction (example 1 2) ";
                    cin >> c1;
                    cout << "Enter second fraction (example 1 2) ";
                    cin >> c2;
                    c3 = c1 + c2;
                    cout << "The Sum is " << c3 << endl;
                    break;
               }
               case 2:
               {
                    cout << "Subtract Fractions" << endl;
                    cout << "Enter first fraction (example 1 2) ";
                    cin >> c1;
                    cout << "Enter second fraction (example 1 2) ";
                    cin >> c2;
                    c3 = c1 - c2;
                    cout << "The Difference is " << c3 << endl;
                    break;
               }
               case 3:
               {
                    cout << "Multiply Fractions" << endl;
                    cout << "Enter first fraction (example 1 2) ";
                    cin >> c1;
                    cout << "Enter second fraction (example 1 2) ";
                    cin >> c2;
                    c3 = c1 * c2;
                    cout << "The Product is " << c3 << endl;
                    break;
               }
               case 4:
               {
                    cout << "Divide Fractions" << endl;
                    cout << "Enter first fraction (example 1 2) ";
                    cin >> c1;
                    cout << "Enter second fraction (example 1 2) ";
                    cin >> c2;
                    c3 = c1 / c2;
                    cout << "The Quotient is " << c3 << endl;
                    break;
               }
               case 5:
               {
                    cout << "Reduce Fraction" << endl;
                    cout << "Enter fraction (example 1 2) ";
                    cin >> c3;
                    cout << "The Fraction reduces to " << c3.reduce() << endl;
                    break;
               }
               case 6:
               {
                    cout << "Show Decimal of Fraction" << endl;
                    cout << "Enter fraction (example 1 2) ";
                    cin >> c3;
                    c3.deceq();
                    cout << "The Decimal Value is " << c3.getdec() << endl;
                    break;
               }
               case 7:
               {
                    cout << "Exiting..." << endl;
                    break;
               }
               default:
               {
                    cout << "That is not a valid option." << endl;
                    break;
               }

          }

     }
     return 0;
}
