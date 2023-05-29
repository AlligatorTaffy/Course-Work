/*
 AlligatorTaffy
 Program #3
 */

#include <iostream>
#include "fraction.hpp"
using namespace std;

//   Default Constructor
Fraction::Fraction(): numerator(1), denominator(1)
{
     deceq();
}

//   Constructor with passed values
Fraction::Fraction(double num, double den): numerator(num), denominator(den)
{
     deceq();
}

//   Function to calculate decimal value
void Fraction::deceq()
{
     dec = numerator / denominator;
}

//   Fraction Function to reduce function by internal values
Fraction Fraction::reduce()
{
     Fraction result;
     int x = 0;
     int leastNum = (int)numerator;
     int leastDen = (int)denominator;
     while (leastDen != 0)
     {
          x = leastDen;
          leastDen = leastNum%leastDen;
          leastNum = x;
     }
     result.numerator = numerator / leastNum;
     result.denominator = denominator / leastNum;
     result.deceq();
     return result;
}

//   Member Function to display the decimal value variable
double Fraction::getdec()
{
     return dec;
}

//   Overloaded << operator to display contents of Fraction class
ostream &operator<<(ostream &os, const Fraction &frac)
{
     if(frac.numerator == 0)
     {
          os << 0;
     } else
     {
          os << frac.numerator;
          os << '/';
          os << frac.denominator;
     }
     return os;
}

//   Overloaded >> operator to write contents of Fraction class
istream & operator>>(istream &in, Fraction &frac) 
{    
     in >> frac.numerator >> frac.denominator;
     return in; 
}

//   Overloaded + operator to add two Fraction classes
Fraction Fraction::operator+(Fraction const &frac)
{ 
     Fraction result;
     if(denominator == frac.denominator)
     {
          result.numerator = numerator + frac.numerator;
          result.denominator = denominator;
     } else
     {
          result.denominator = denominator * frac.denominator;
          result.numerator = (numerator * frac.denominator) + (denominator * frac.numerator);
     }
     result.deceq();
     return result.reduce();
}

//   Overloaded - operator to subtract two Fraction classes
Fraction Fraction::operator-(Fraction const &frac)
{ 
     Fraction result;
     if(denominator == frac.denominator)
     {
          result.numerator = numerator - frac.numerator;
          result.denominator = denominator;
     } else
     {
          result.denominator = denominator * frac.denominator;
          result.numerator = (numerator * frac.denominator) - (denominator * frac.numerator);
     }
     result.deceq();
     return result.reduce();
}

//   Overloaded * operator to multiply two Fraction classes
Fraction Fraction::operator*(Fraction const &frac)
{ 
     Fraction result; 
     result.numerator = numerator * frac.numerator; 
     result.denominator = denominator * frac.denominator;
     result.deceq();
     return result.reduce();
}

//   Overloaded / operator to divide two Fraction classes
Fraction Fraction::operator/(Fraction const &frac)
{ 
     Fraction result; 
     if(denominator == 0 || frac.denominator == 0)
     {
          cout << "Cannot Divide by 0! Result is invalid" << endl;
          result.numerator = 0;
          result.denominator = 0;
          
     } else
     {
          result.numerator = numerator * frac.denominator; 
          result.denominator = denominator * frac.numerator;
          result.deceq();
     }
     return result.reduce();
     
}
