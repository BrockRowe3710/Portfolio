// A simple calculator with +, -, *, /.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Declare Variables
	int first_number;
	char user_operation;
	int second_number;
	double final_number = 0.0;

	// Prompt user for inputs
	cout << "Enter first number: ";
	cin >> first_number;
	cout << "Enter operator (+,-,*,/): ";
	cin >> user_operation;
	cout << "Enter second number: ";
	cin >> second_number;
	cout << endl;

	// Calculate final number
	if (user_operation == '+') {
		final_number = first_number + second_number;
	} else if (user_operation == '-') {
		final_number = first_number - second_number;
	} else if (user_operation == '*') {
		final_number = first_number * second_number;
	} else if (user_operation == '/') {
		cout << fixed << setprecision(4);
		final_number = static_cast<double>(first_number) / second_number;
	}

	// Print result
	cout << "The result is " << final_number << endl;

	// End program
	return 0;
}