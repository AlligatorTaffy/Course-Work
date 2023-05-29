/*
 AlligatorTaffy
 Program #5 - Converting arrayDb to a template class
 */

#include "arraydb.hpp"
#include <iostream>
using namespace std;


// Templated default constructor
template <class Type>
ArrayDb<Type>::ArrayDb (void)
{
    arr_ptr = NULL;
    size = 0;
}

// Templated overloaded constructor
template <class Type>
ArrayDb<Type>::ArrayDb (unsigned int n, Type val)
{
    arr_ptr = new Type[n];
    if (arr_ptr == NULL)
    {
        cout << "Can't allocate new array";
        exit(0);
    }
    size = n;
    for (unsigned int i = 0; i < size; i++)
        arr_ptr[i] = val;
}

// Templated overloaded constructor given an array
template <class Type>
ArrayDb<Type>::ArrayDb (const Type *pn, unsigned int n)
{
    
    arr_ptr = new Type[n];
    size = n;
    for (unsigned int i = 0; i < size; i++)
        arr_ptr[i] = pn[i];
}

// Templated copy constructor
template <class Type>
ArrayDb<Type>::ArrayDb (const ArrayDb<Type> & a)
{
    size = a.size;
    arr_ptr = new Type[size];
    for (int i = 0; i < size; i ++)
        arr_ptr[i] = a.arr_ptr[i];
}

// Templated destructor
template <class Type>
ArrayDb<Type>::~ArrayDb (void)
{
    if (arr_ptr != NULL)
        delete [] arr_ptr;
}
// Templated overloaded operator[] function
template <class Type>
Type & ArrayDb<Type>::operator[] (unsigned int i)
{
    if (i < 0 || i >= size)
    {
        cerr << "Error in array limits";
        exit (1);
    }
    return arr_ptr[i];
    
}

// Templated overloaded operator[] function
template <class Type>
const Type & ArrayDb<Type>::operator[] (unsigned int i) const
{
    if (i < 0 || i >= size)
    {
        cerr << "Error in array limits";
        exit (1);
    }
    return arr_ptr[i];
}

// Templated overloaded operator= function
template <class Type>
ArrayDb<Type> & ArrayDb<Type>::operator=(const ArrayDb<Type> & a)
{
    if (this == &a)
        return *this;
    
    delete arr_ptr;
    size = a.size;
    arr_ptr = new Type [size];
    for (int i = 0; i < size; i++)
        arr_ptr[i] = a.arr_ptr[i];
    return *this;
    
}

// Templated overloaded operator<< function
template <class Type>
ostream & operator<< (ostream & os, const ArrayDb<Type> &a)
{
    unsigned int i;
    for (i = 0; i < a.size; i++)
    {
        os << a.arr_ptr[i] << " ";
        if (i % 5 == 4)
            os << "\n";
    }
    if (i % 5 != 0)
        os << endl;
    return os;
}
