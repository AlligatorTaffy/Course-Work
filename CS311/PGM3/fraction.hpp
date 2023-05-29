/*
  AlligatorTaffy
  Program Number: 3
 
   Description of the problem:
     This is a Fraction class that will create a fraction given user input
     of a combined numerator and denominator.  It will then calculate the
     decimal representation.

     Pseudo Code:
          Data:
                    numerator - contains the numerator of fraction
                    denominator - contains the denominator of fraction
                    dec - contains the calculated decimal

          Function:
                    Default Constructor - sets numerator and denominator
                    to 1 and then calls deceq() to set decimal
                    Constuctor - accepts user input numerator and denominator
                    then calls deceq() to set the decimal
                    
                    Accessor functions:
                    deceq() - calculates the decimal from numerator /
								denominator
					reduce() - reduces the fraction by finding the least
								common multiple and then dividing the
								numerator and denominator by it
					getdec - returns the decimal variable from fraction
					operator+ - overloaded + to handle numerator and denominator
					operator- - overloaded + to handle numerator and denominator
					operator* - overloaded + to handle numerator and denominator
					operator/ - overloaded + to handle numerator and denominator
					
					Friend Functions:
					friend istream &operator>>(istream &in, Fraction &frac);
					friend ostream &operator<<(ostream &os, const Fraction &frac);
*/

#include <iostream>
using namespace std;

class Fraction
{
private:
     double numerator, denominator, dec;
public:
     Fraction();
     Fraction(double num, double den);
     void deceq();
     Fraction reduce();
     double getdec();
     Fraction operator+(Fraction const &frac);
     Fraction operator-(Fraction const &frac);
     Fraction operator*(Fraction const &frac);
     Fraction operator/(Fraction const &frac);
     friend istream &operator>>(istream &in, Fraction &frac);
     friend ostream &operator<<(ostream &os, const Fraction &frac);
};
