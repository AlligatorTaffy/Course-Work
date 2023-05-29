/*
AlligatorTaffy
Program # 4
*/

#include <iostream>
#include "checking_account.hpp"
using namespace std;


//	Default Constructor with inherited Account Constructor
Checking_Account::Checking_Account()
{
	bal = 0;
	fee = 0;
}

//	Constructor for Checking_Account to initialize the balance and fee with inherited Account
Checking_Account::Checking_Account(double x, double y)
{
	bal = x;
	fee = y;
}

//	Default Destructor for Checking_Account with inherited Account Destructor
Checking_Account::~Checking_Account()
{}

//	Redefined Account::debit function for use with Checking_Account
//	Checks to make sure a transaction completes then subtracts the fee
void Checking_Account::debit(double x)
{	
	bool y;
	y = Account::debit(x);
	if(y == true)
	{
		bal -= fee;
	}
}
