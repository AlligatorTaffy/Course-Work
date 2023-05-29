/*
AlligatorTaffy
Program # 4

Description of the problem:
	The derived class Checking_Account is created with an inherited Account class.
	The Checking_Account adds a transaction fee variable as well as redefining the
	debit function from Account debit so that it'll include the transaction fee if
	the debit is successful.

Pseudo Code:
	Data:
		fee = contains the transaction fee.

	Function:
		Default Constructor - sets the balance and fee to 0
		Constructor - accepts passed value to set bal if the value is greater than
					zero.  If less than zero, bal is set to 0.  It accepts the fee
					value and sets fee.
		Default Destructor - Deletes the class instance

	Accessor Function:
		debit(double x) - calls the original Account::debit function, then checks
						the returned bool to see if the transaction completed, if 
						so, the fee is subtracted from bal	
*/

#ifndef __CHECKING_ACCOUNT_HPP__
#define __CHECKING_ACCOUNT_HPP__

#include <iostream>
#include "account.hpp"
using namespace std;

class Checking_Account : public Account
{
private:
	double fee;
public:
	Checking_Account();
	Checking_Account(double x,double y);
	~Checking_Account();
	void debit(double x);
};

#endif
