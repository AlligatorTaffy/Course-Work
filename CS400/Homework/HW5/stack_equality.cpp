/**
AlligatorTaffy
Homework #5 - Stack Equality
March 29, 2019
**/

#include <iostream>
#include <string>
#include <stack>

// Function Declarations
template <typename T>
void isEqual(std::stack<T> &Stack1, std::stack<T> &Stack2);

// Main Program
int main() {
	// Testing using DOUBLEs on the stack. (Stacks are the same size and values)
	std::stack<double> Stack1, Stack2;
	Stack1.push(1.34);
	Stack1.push(2.23);
	Stack1.push(3.987);
	Stack1.push(4.1234);
	Stack1.push(5.7);

	Stack2.push(1.34);
	Stack2.push(2.23);
	Stack2.push(3.987);
	Stack2.push(4.1234);
	Stack2.push(5.7);

	std::cout << "Testing using DOUBLEs on the stack. (Stacks are the same size and values)" << std::endl;
	std::cout << "\t1.34\t1.34\n\t2.23\t2.23\n\t3.987\t3.987\n\t4.1234\t4.1234\n\t5.7\t5.7" << std::endl; 

	isEqual(Stack1, Stack2);

	// Testing using INTs on the stack. (Stacks are the same size but NOT values)
	std::stack<int> Stack3, Stack4;
	Stack3.push(1);
	Stack3.push(8);
	Stack3.push(3);
	Stack3.push(4);
	Stack3.push(5);

	Stack4.push(1);
	Stack4.push(2);
	Stack4.push(3);
	Stack4.push(4);
	Stack4.push(5);

	std::cout << "Testing using INTs on the stack. (Stacks are the same size but NOT values)" << std::endl;
	std::cout << "\t1\t1\n\t8\t2\n\t3\t3\n\t4\t4\n\t5\t5" << std::endl;
	
	isEqual(Stack3, Stack4);

	// Testing using CHARs on the stack. (Stacks are NOT the same size)
	std::stack<char> Stack5, Stack6;
	Stack5.push('A');
	Stack5.push('B');
	Stack5.push('C');
	Stack5.push('D');
	Stack5.push('E');

	Stack6.push('B');
	Stack6.push('C');
	Stack6.push('D');
	Stack6.push('E');

	std::cout << "Testing using CHARs on the stack. (Stacks are NOT the same size)" << std::endl;
	std::cout << "\tA\n\tB\tB\n\tC\tC\n\tD\tD\n\tE\tE" << std::endl;
	
	isEqual(Stack3, Stack4);

	return 0;
}

template <typename T>	// Set templated variable as T
void isEqual(std::stack<T> &Stack1, std::stack<T> &Stack2) {	// Templated function based on T that accepts two different stacks
	std::stack<T> TempStack;	// Temporary templated stack to hold values that are equal
	bool fault = 0;	// boolean flag that checks to make sure there isn't a fault
	if(Stack1.size() != Stack2.size()) {	// First condition that checks if the two stacks are equal in size.
		fault = 1;	// if they aren't equal, set the fault flag to 1.
	}
	while(!Stack1.empty() && !Stack2.empty() && !fault) {	// While loop that proceeds as long as The two stacks are not empty and if there are no faults
		if(Stack1.top() == Stack2.top()) {	// Condition that checks if the two top of the stacks are equal
			TempStack.push(Stack1.top());	// if equal, push value onto temporary stack
			Stack1.pop();	// Pop value from stack
			Stack2.pop();	// Pop value from stack
			// std::cout << "SAME" << std::endl;	// Debug Message
		} else {
			fault = 1;	// If they aren't equal, set the fault flag to 1.
			// std::cout << "NOT SAME" << std::endl;	// Debug Message
		}
	}

	// While loop that restores that rebuilds the original stacks
	while(!TempStack.empty()) {		// Condition to continue while TempStack isn't empty
		Stack1.push(TempStack.top());	// Push top value from TempStack
		Stack2.push(TempStack.top());	// Push top value from TempStack
		TempStack.pop();	// Pop value off the stack
	}
	if(fault) {		// Display result if there was a fault
		std::cout << "Stacks are not equal!" << std::endl;
	} else {		// Display result if there is no fault
		std::cout << "Stacks are equal!" << std::endl;
	}
  
}