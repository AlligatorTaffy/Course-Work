/*
AlligatorTaffy
Program # 4
*/

#include <iostream>
#include "account.hpp"
using namespace std;


//	Default Constructor for class Account
Account::Account()
{
	bal = 0;
}

//	Constructor for Account that sets the balance
Account::Account(double x)
{
	if(x <= 0)
	{
		cout << "Initial BALANCE must be greater than or equal to $0." << endl;
		bal = 0;
	} else
	{
		bal = x;
	}
}

//	Default Destructor for Account class
Account::~Account() {}

//	Member function to add credit to the balance of Account
void Account::credit(double x)
{
	if(x < 0)
	{
		cout << "A credit must be greater than $0." << endl;
	} else
	{
		bal += x;
	}
}

//	Member function to remove/debit amount from balance of Account
bool Account::debit(double x)
{	
	if(x > bal)
	{
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	} else
	{
		bal -= x;
		return true;
	}
}

//	Member function to return the balance of Account
double Account::get_balance()
{
	return bal;
}
