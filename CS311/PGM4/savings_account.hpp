/*
AlligatorTaffy
Program # 4

Description of the problem:
    The derived class Savings_Account is created with an inherited Account class.
    The Savings_Account adds a interest rate variable as well as a new member 
    function that will calculate and add the interest to bal.

Pseudo Code:
    Data:
        i_rate = contains the balance of the Account

    Function:
        Default Constructor - sets the balance and fee to 0
        Constructor - accepts passed value to set bal if the value is greater than
                    zero.  If less than zero, bal is set to 0.  It accepts the rate
                    value and sets i_rate.
        Default Destructor - Deletes the class instance

    Accessor Function:
        calculate_interest() - calculates the new balance based on the base balance
                            and the given interest rate.
*/

#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__

#include <iostream>
#include "account.hpp"
using namespace std;

class Savings_Account : public Account
{
private:
	double i_rate;
public:
	Savings_Account();
	Savings_Account(double x, double y);
	~Savings_Account();

	double calculate_interest();

};

#endif
