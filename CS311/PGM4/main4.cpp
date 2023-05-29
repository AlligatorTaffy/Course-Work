/*
AlligatorTaffy
Program # 4

Description of the Problem:
	Create an inheritance hierarchy that a bank might use to represent customers’
	bank accounts. All customers at this bank can deposit (i.e., credit) money into
	their accounts and withdraw it (i.e. debit) money from their accounts. More
	specific types of accounts also exist. Savings accounts, for instance, can earn
	interest on the money they hold. Checking accounts, on the other hand, charge a
	fee per transaction (i.e, credit or debit).

Pseudo Code:
	There are 3 different test cases (Account, Savings, and Checking Account) and
	each test case uses the Default Constructor and the Initialized Constructor.

	Each test proves the following functions:
		- tests the creation of the class
		- uses member function get_balance() to display bal variable
		- uses member function credit(double x) to add values to bal
		- uses member function debit(double x) to subtract values from bal
		- error checking debit(double x) so that the account is not overdrawn

	Savings Class Test includes the additional:
		- tests calculate_interest(double x) to calculate the given interest based
		on the given rate and then adds that to bal

	Checking Class Test includes the additional:
		- tests the redefined debit(double x) function so that it will subtract the
		fee associated with each successful debit from bal using debit(double x)
*/

#include <iostream>
#include "account.hpp"
#include "checking_account.hpp"
#include "savings_account.hpp"
using namespace std;

int main()
{
	// Creating a base Account using Account class with default as initial
	Account account1;
	cout << "Account with BALANCE of $0.00 has been created." << endl;
	// Calling get_balance to display balance in the Account class
	cout << "Account Balance = $" << account1.get_balance() << endl;
	// Calling credit to add $10.00 to the Account class
	account1.credit(10.00);
	cout << "Account Balance after $10.00 credit = $" << account1.get_balance() << endl;
	// Calling debit to subtract $10.00 from the Account class
	account1.debit(5.00);
	cout << "Account Balance after $5.00 debit = $" << account1.get_balance() << endl;
	// Proving overdraw by debiting more than the account, $100
	account1.debit(100.00);
	cout << "Account Balance after $100.00 debit failure = $" << account1.get_balance() << endl;


	// Creating a base Account using Account class with $15.00 as initial
	Account account2(15.00);
	cout << "\n\nAccount with BALANCE of $15.00 has been created." << endl;
	// Calling get_balance to display balance in the Account class
	cout << "Account Balance = $" << account2.get_balance() << endl;
	// Calling credit to add $10.00 to the Account class
	account2.credit(10.00);
	cout << "Account Balance after $10.00 credit = $" << account2.get_balance() << endl;
	//Calling debit to subtract $5.00 from the Account class
	account2.debit(5.00);
	cout << "Account Balance after $5.00 debit = $" << account2.get_balance() << endl;
	// Proving overdraw by debiting more than the account, $100
	account2.debit(100.00);
	cout << "Account Balance after $100.00 debit failure = $" << account2.get_balance() << endl;





	// Creating a Savings Account using inherited Account class with default as initial balance
	// and initial interest rate of default
	Savings_Account account3;
	cout << "\n\nSavings Account with BALANCE of $0.00 has been created with 0% " << "interest rate" << endl;
	// Calling get_balance to display balance
	cout << "Savings Account Balance = $" << account3.get_balance() << endl;
	// Generating interest by calling the calculate_interest member function
	account3.calculate_interest();
	// Calling get_balance to display balance with calculated interest
	cout << "Savings Account Balance (with interest) = $" << account3.get_balance() << endl;
	// Calling credit to add $10.00 to the Savings Account class
	account3.credit(10.00);
	cout << "Savings Account Balance after $10.00 credit = $" << account3.get_balance() << endl;
	//Calling debit to subtract $5.00 from the Savings Account class
	account3.debit(5.00);
	cout << "Savings Account Balance after $5.00 debit = $" << account3.get_balance() << endl;
	// Proving overdraw by debiting more than the account, $100
	account3.debit(100.00);
	cout << "Savings Account Balance after $100.00 debit failure = $" << account3.get_balance() << endl;


	// Creating a Savings Account using inherited Account class with $15.00 as initial balance
	// and initial interest rate of 1.75%
	Savings_Account account4(15.00, 1.75);
	cout << "\n\nSavings Account with BALANCE of $15.00 has been created with 1.75% " << "interest rate" << endl;
	// Calling get_balance to display balance
	cout << "Savings Account Balance = $" << account4.get_balance() << endl;
	// Generating interest by calling the calculate_interest member function
	account4.calculate_interest();
	// Calling get_balance to display balance with calculated interest
	cout << "Savings Account Balance (with interest) = $" << account4.get_balance() << endl;
	// Calling credit to add $10.00 to the Savings Account class
	account4.credit(10.00);
	cout << "Savings Account Balance after $10.00 credit = $" << account4.get_balance() << endl;
	//Calling debit to subtract $5.00 from the Savings Account class
	account4.debit(5.00);
	cout << "Savings Account Balance after $5.00 debit = $" << account4.get_balance() << endl;
	// Proving overdraw by debiting more than the account, $100
	account4.debit(100.00);
	cout << "Savings Account Balance after $100.00 debit failure = $" << account4.get_balance() << endl;





	// Creating a Checking Account using inherited Account class with default as initial balance
	// and initial transaction fee of default
	Checking_Account account5;
	cout << "\n\nChecking Account with BALANCE of $0.00 has been created with a $0.00 transaction fee" << endl;
	// Calling get_balance to display balance
	cout << "Checking Account Balance = $" << account5.get_balance() << endl;
	// Calling credit to add $10.00 to the Checking Account class
	account5.credit(10.00);
	cout << "Checking Account Balance after $10.00 credit and $0.50 fee = $" << account5.get_balance() << endl;
	//Calling debit to subtract $5.00 from the Checking Account class
	account5.debit(5.00);
	cout << "Checking Account Balance after $5.00 debit and $0.50 fee = $" << account5.get_balance() << endl;
	// Proving overdraw by debiting more than the account, $100
	account5.debit(100.00);
	cout << "Checking Account Balance after $100.00 debit failure = $" << account5.get_balance() << endl;


	// Creating a Checking Account using inherited Account class with $15.00 as initial balance
	// and initial transaction fee of $0.50
	Checking_Account account6(15.00, 0.50);
	cout << "\n\nChecking Account with BALANCE of $15.00 has been created with $0.50 transaction fee" << endl;
	// Calling get_balance to display balance
	cout << "Checking Account Balance = $" << account6.get_balance() << endl;
	// Calling credit to add $10.00 to the Checking Account class
	account6.credit(10.00);
	cout << "Checking Account Balance after $10.00 credit and $0.50 fee = $" << account6.get_balance() << endl;
	//Calling debit to subtract $5.00 from the Checking Account class
	account6.debit(5.00);
	cout << "Checking Account Balance after $5.00 debit and $0.50 fee = $" << account6.get_balance() << endl;
	// Proving overdraw by debiting more than the account, $100
	account6.debit(100.00);
	cout << "Checking Account Balance after $100.00 debit failure = $" << account6.get_balance() << endl;

	return 0;
}
