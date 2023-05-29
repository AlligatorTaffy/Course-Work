//	Week 7 -- In Class Work
//  Function, Function, what's your Function?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string input = "Beginning C++";

int main() {
	cout << "Let's spell out 'Beginning C++'\n";
	for(int i = 0; i < input.size(); i++) {
		cout << "\t" << input[i] << endl;
	}


	return 0;
}
