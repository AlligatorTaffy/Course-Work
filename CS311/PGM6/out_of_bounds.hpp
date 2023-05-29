/*
 AlligatorTaffy
 Program #6 - Add Out_Of_Bounds exception class to handle index out of range
 error.
 
 Description of the problem:
 Testing if the templated arrayDb class can handle an array out of bounds
 execption without causing the program to crash.
 
 Pseudo Code:
 Data:
 
 Constructors:
 Default Constructor - Inherits the exception class
 
 Accessor Function:
 Redefinition of what to return a message indicating an Index Out of Bounds
 Exception
 
 */

#ifndef __out_of_bounds_hpp__
#define __out_of_bounds_hpp__

#include <iostream>
#include <exception>
using namespace std;


class Out_Of_Bounds : public exception
{
public:
    const char *what() const throw() {
        return "Index Out of Bounds Exception!";
    }
};
#endif
