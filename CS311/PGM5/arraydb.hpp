/*
 AlligatorTaffy
 Program #5 - Converting arrayDb to a template class
 
 Description of the problem:
 Convert ArrayDb into a templated class to accept the 9 basic types
 
 Pseudo Code:
 Data:
 size = unsigned integer to define the size of array
 Type *arr_ptr = creates a new pointer for each instance
 
 Constructors:
 Default Constructor - sets the array size to 0
 Constructor - accepts passed value to set size of the array and values
 Constructor - accepts another array and creates a copy of it
 Copy Contructor - Creates a copy of instance
 Default Destructor - Deletes the class instance
 
 Accessor Function:
 get_ary_size() = returns the size of array
 Template Reference to operator[] = Sets the array index to arr_ptr
 Friend overloaded operator<< = Displays the contents of created array
 
 */

#ifndef __ARRAYDB_HPP__
#define __ARRAYDB_HPP__

#include <iostream>
using namespace std;

template <class Type>
class ArrayDb
{
    unsigned int size;
protected:
    Type *arr_ptr;
    
public:
    ArrayDb();
    ArrayDb(unsigned int n, Type val = 0.0);
    ArrayDb(const Type *pn, unsigned int n);
    ArrayDb(const ArrayDb &a);
    ~ArrayDb();
    
    unsigned int get_ary_size() const {return size;}
    Type &operator[](unsigned int i);
    const Type &operator[](unsigned int i) const;
    ArrayDb<Type> &operator=(const ArrayDb<Type> &a);
    template <class Ntype>
    friend ostream &operator<<(ostream & os, const ArrayDb<Ntype> &a);
};
#endif
