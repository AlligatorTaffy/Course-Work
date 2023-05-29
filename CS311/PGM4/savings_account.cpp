/*
AlligatorTaffy
Program # 4
*/

#include <iostream>
#include <math.h>
#include "savings_account.hpp"
using namespace std;


// Default Constructor that also inherits Account Constructor
Savings_Account::Savings_Account()
{
	i_rate = 0;
}

// Overloaded Initializing Constructor with inherited Account
Savings_Account::Savings_Account(double x, double y)
{
	i_rate = (y / 100);
	bal = x;
}

// Default Destructor for Savings_Account with inherited Account Destructor
Savings_Account::~Savings_Account()
{}

// Member function for class Savings_Account to calculate and add the interest to balance
double Savings_Account::calculate_interest()
{
	bal += (bal * i_rate);
	bal = roundf(bal * 100) / 100;
	return bal;
}
