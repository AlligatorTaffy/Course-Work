/**
AlligatorTaffy
Homework #4
March 17, 2019
**/

#include <iostream>
#include <string>
#include <stack>
#include <exception>

// Error Handling Classes
class Div_By_Zero : public std::exception {
public:
    const char *what() const throw() {
        return "Divide by ZERO condition raised";
    }
} Div_By_Zero;

class Invalid_Expression : public std::exception {
public:
    const char *what() const throw() {
        return "Invalid POSTFIX Expression!";
    }
} Invalid_Expression;

// Create an empty STL stack globally
std::stack<int> postfix;

// Function Declarations
void evaluate(std::string x);

// Main Program
int main() {
	// Grab user expression as a string
	std::string input;
	std::cout << "Enter a POSTFIX expression ex. '3 2 + 5 -'" << std::endl;
	std::getline(std::cin, input);

	try {
		evaluate(input);	// Pass string to evaluate postfix string
	}
	catch(class Invalid_Expression &e) {		// Catch condition to catch an Invalid POSTFIX expression
		std::cerr << e.what() << std::endl;
	}
	catch(class Div_By_Zero &e) {		// Catch condition to catch a Divide by Zero condition
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

// Function Definitions
void evaluate(std::string x) {		// Function to evaluation POSTFIX string
	int op1;	// Variable for operand 1
	int op2;	// Variable for operand 2
	int temp;	//	Variable for holding result to pass into stack
	for(int i = 0; i < x.length(); i++) {	// Loop to iterate through char array with length of string
		if(x[i] == ' ') {	// First condition to check if there is a ' ', if space, skip to next i + 1
			continue;
		}
		else if(isdigit(x[i])) {		// Second condition that detects if char is a real digit
			temp = x[i] - '0';			// Convert char number to valid int
			postfix.push(temp);			// Push int into the stack
		}
		else if(x[i] == '+') {				// First condition for + operator
			if(postfix.size() < 2) {		// Expression error check for underflow. stack should have at least 2 values
				throw Invalid_Expression;	// Call Invalid Expression exception
			}
			op2 = postfix.top();	// Assign second operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			op1 = postfix.top();	// Assign first operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			temp = (op1 + op2);		// Perform math operation and assign to temp
			postfix.push(temp);		// Push value of temp to top of stack
		}
		else if(x[i] == '-') {				// First condition for - operator
			if(postfix.size() < 2) {		// Expression error check for underflow. stack should have at least 2 values
				throw Invalid_Expression;	// Call Invalid Expression exception
			}
			op2 = postfix.top();	// Assign second operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			op1 = postfix.top();	// Assign first operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			temp = (op1 - op2);		// Perform math operation and assign to temp
			postfix.push(temp);		// Push value of temp to top of stack
		}
		else if(x[i] == '*') {				// First condition for * operator
			if(postfix.size() < 2) {		// Expression error check for underflow. stack should have at least 2 values
				throw Invalid_Expression;	// Call Invalid Expression exception
			}
			op2 = postfix.top();	// Assign second operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			op1 = postfix.top();	// Assign first operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			temp = (op1 * op2);		// Perform math operation and assign to temp
			postfix.push(temp);		// Push value of temp to top of stack
		}
		else if(x[i] == '/') {				// First condition for / operator
			if(postfix.size() < 2) {		// Expression error check for underflow. stack should have at least 2 values
				throw Invalid_Expression;	// Call Invalid Expression exception
			}
			op2 = postfix.top();	// Assign second operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			op1 = postfix.top();	// Assign first operand with value from top of stack
			postfix.pop();			// Remove top value from stack
			if(op2 == 0) {			// Division by 0 operand check.  Operand2 != zero
				throw Div_By_Zero;	// Call Div By Zero exception
			}
			temp = (op1 / op2);		// Perform math operation and assign to temp
			postfix.push(temp);		// Push value of temp to top of stack
		}
	}
	if(postfix.size() != 1) {		// Expression error check for syntax.  Accurate final result should make postfix.size() = 1
		throw Invalid_Expression;	// Call Invalid Expression exception
	}
	std::cout << postfix.top() << std::endl;	// Print contents of final answer to console
	postfix.pop();		// Pop last value off the stack to make clean
}
