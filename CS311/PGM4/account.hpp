/*
AlligatorTaffy
Program # 4

Description of the problem:
	The base class of Account is created so that it can be inherited to derived 
	classes that can utilize the variable and member functions.

Pseudo Code:
	Data:
		bal = contains the balance of the Account

	Function:
		Default Constructor - sets the balance to 0
		Constructor - accepts passed value to set bal if the value is greater than
					zero.  If less than zero, bal is set to 0
		Default Destructor - Deletes the class instance

	Accessor Function:
		credit(double x) - credits the balance with the passed value if the value
						is greater than zero
		debit(double x) - debits the balance with the passed values, if the value
						is greater than the balance, it fails
		get_balance - returns the value of variable bal		
*/

#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>
using namespace std;

class Account
{
protected:
	double bal;
public:
	Account();
	Account(double x);
	~Account();
	void credit(double x);
	bool debit(double x);
	double get_balance();
};

#endif
