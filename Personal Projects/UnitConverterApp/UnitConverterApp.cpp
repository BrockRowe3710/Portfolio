// A simple length unit converter
// Meters, Kilometers, Feet, Inches included
// Switch case practice

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Declare variables and conversion rates
	int unit_1;
	double unit_1_value;
	int unit_2;
	double unit_2_value;
	const int KILOMETERS_TO_METERS = 1000;
	const int FEET_TO_INCHES = 12;
	const double METERS_TO_FEET = 3.2808399;
	const double KILOMETERS_TO_FEET = 3280.399;
	string unit_1_name;
	string unit_2_name;

	// Get user inputs
	cout << "Choose a unit to convert from:" << endl;
	cout << "1. Inches" << endl;
	cout << "2. Feet" << endl;
	cout << "3. Meters" << endl;
	cout << "4. Kilometers" << endl << endl;
	cout << "Enter corresponding number: ";
	cin >> unit_1;
	cout << endl;

	cout << "How many are you converting: ";
	cin >> unit_1_value;
	cout << endl;

	cout << "Choose a unit to convert to:" << endl;
	cout << "1. Inches" << endl;
	cout << "2. Feet" << endl;
	cout << "3. Meters" << endl;
	cout << "4. Kilometers" << endl << endl;
	cout << "Enter corresponding number: ";
	cin >> unit_2;
	cout << endl;

	// Calculate the conversions
	switch (unit_1) {
	case 1:
		switch (unit_2) {
		case 1:
			unit_2_value = unit_1_value;
			break;
		case 2:
			unit_2_value = unit_1_value / FEET_TO_INCHES;
			break;
		case 3:
			unit_2_value = unit_1_value / FEET_TO_INCHES / METERS_TO_FEET;
			break;
		case 4:
			unit_2_value = unit_1_value / FEET_TO_INCHES / KILOMETERS_TO_FEET;
			break;
		default:
			return 0;
		}
		break;
	case 2:
		switch (unit_2) {
		case 1:
			unit_2_value = unit_1_value * FEET_TO_INCHES;
			break;
		case 2:
			unit_2_value = unit_1_value;
			break;
		case 3:
			unit_2_value = unit_1_value / METERS_TO_FEET;
			break;
		case 4:
			unit_2_value = unit_1_value / KILOMETERS_TO_FEET;
			break;
		default:
			return 0;
		}
		break;
	case 3:
		switch (unit_2) {
		case 1:
			unit_2_value = unit_1_value * METERS_TO_FEET * FEET_TO_INCHES;
			break;
		case 2:
			unit_2_value = unit_1_value * METERS_TO_FEET;
			break;
		case 3:
			unit_2_value = unit_1_value;
			break;
		case 4:
			unit_2_value = unit_1_value / KILOMETERS_TO_METERS;
			break;
		default:
			return 0;
		}
		break;
	case 4:
		switch (unit_2) {
		case 1:
			unit_2_value = unit_1_value * KILOMETERS_TO_FEET * FEET_TO_INCHES;
			break;
		case 2:
			unit_2_value = unit_1_value * KILOMETERS_TO_FEET;
			break;
		case 3:
			unit_2_value = unit_1_value * KILOMETERS_TO_METERS;
			break;
		case 4:
			unit_2_value = unit_1_value;
			break;
		default:
			return 0;
		}
		break;
	}

	// Give the values their unit names
	switch (unit_1) {
	case 1:
		unit_1_name = "inches";
		break;
	case 2:
		unit_1_name = "feet";
		break;
	case 3:
		unit_1_name = "meters";
		break;
	case 4:
		unit_1_name = "kilometers";
		break;
	default:
		cout << "Invalid Input\n";
		return 0;
	}

	switch (unit_2) {
	case 1:
		unit_2_name = "inches";
		break;
	case 2:
		unit_2_name = "feet";
		break;
	case 3:
		unit_2_name = "meters";
		break;
	case 4:
		unit_2_name = "kilometers";
		break;
	default:
		cout << "Invalid Input\n";
		return 0;
	}

	// Print the output
	cout << fixed << setprecision(3);
	cout << unit_1_value << " " << unit_1_name << " is equivalent to " << unit_2_value << " " << unit_2_name << "." << endl;

	// End program
	return 0;
}