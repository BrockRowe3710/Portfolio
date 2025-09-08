//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Cruise Purchase
// Process: The program starts with a series of prompts for the
// user to input how they would like their cruise experience to
// look like. Then, the header of a stylized receipt is printed, 
// relaying some information from the input. Stateroom costs are 
// then displayed, followed by beverage costs, if any beverages 
// were purchased. Port fees and the total cost are displayed
// at the bottom, and the program ends.
// Results: The cost of stateroom, beverages, port fees, the
// total cost, and all costs associated with those
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection:
// This project was much more complex than the last, although it
// still felt manageable the majority of the time. My biggest 
// struggle was feeling like I never had enough variables. I ended
// up with a lot more than I expected to, and I never knew when to
// work with what I had or to make a new one. I reorganized them at
// the end, but I should have done a better job of that during the
// coding process. Other than that, I liked getting comfortable
// with setw(), as well as designing an output that had a better
// style than just plain text.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	// Cruise costs per night
	const double CRUISE_7_NIGHTS = 1109.56;
	const double CRUISE_6_NIGHTS = 987.00;
	const double CRUISE_3_NIGHTS = 235.00;

	// Discounts for each traveler
	const double SINGLE_TRAVELER_DISCOUNT = 0.20;
	const double THIRD_TRAVELER_DISCOUNT = 0.30;
	const double FOURTH_TRAVELER_DISCOUNT = 0.40;

	// Drink package costs (per person per day)
	const double WATER_PACKAGES_COST = 4.00;
	const double FOUNTAIN_PACKAGES_COST = 9.00;
	const double ALCOHOLIC_PACKAGES_COST = 58.00;

	const double FT_CLUB_DISCOUNT = 0.25; // Cruise fare only
	const double PORT_FEES = 0.12; // Applies to ALL costs

	// User inputs
	int userNights;
	int userTravelers;
	int userWaterPackages;
	int userFountainPackages;
	int userAlcoholicPackages;
	int userDiningTime;
	int userFTClub;

	// Variables for calculations
	double travelerCost = 0.00;
	double thirdTravelerCost = 0.00;
	double fourthTravelerCost = 0.00;
	double totalStateroomCost = 0.00;

	double currentPackageCost = 0.00;
	double totalBeverageCost = 0.00;

	double FTDiscountAmount = 0.00;
	double portFeesCost = 0.00;

	double finalCost = 0.00;

	// Take user inputs
	cout << ">>>>>> Welcome to the Blue Horizon Cruises booking application <<<<<<" << endl;
	cout << "1. Select cruise length [1=>3-night, 2=>6-night, 3=>7-night] >>> ";
	cin >> userNights;
	cout << "2. Select number of travelers [1=>single, 2=>two, 3=>three, 4=>four] >>> ";
	cin >> userTravelers;
	cout << "3. How many water packages? >>> ";
	cin >> userWaterPackages;
	cout << "4. How many fountain drink packages? >>> ";
	cin >> userFountainPackages;
	cout << "5. How many alcoholic drink packages? >>> ";
	cin >> userAlcoholicPackages;
	cout << "6. Select dinner seating time [1=>6:00 PM, 2=>8:00 PM] >>> ";
	cin >> userDiningTime;
	cout << "7. Are you a Blue Horizon Cruises FT club member? [1=>Yes, 2=>No] >>> ";
	cin >> userFTClub;

	// Change userNights to the actual amount of nights, set the default cost
	switch (userNights) {
		case 1:
			userNights = 3;
			travelerCost = CRUISE_3_NIGHTS;
			break;
		case 2:
			userNights = 6;
			travelerCost = CRUISE_6_NIGHTS;
			break;
		case 3:
			userNights = 7;
			travelerCost = CRUISE_7_NIGHTS;
			break;
		default:
			cout << endl << "Invalid Amount of Nights" << endl;
			return 0;
	}

	// Make sure userTravelers is valid (1-4)
	if (userTravelers < 1 || userTravelers > 4) {
		cout << endl << "Invalid amount of travelers" << endl;
		return 0;
	}

	// Change userDiningTime to equal the dining hour (PM)
	if (userDiningTime == 1) {
		userDiningTime = 6;
	}
	else if (userDiningTime == 2) {
		userDiningTime = 8;
	}
	else {
		cout << endl << "Invalid Dining Time" << endl;
		return 0;
	}

	// Output the beginning of the receipt
	cout << endl << ">>>>>> Thank you for reserving your Blue Horizon Cruises adventure! <<<<<<" << endl << endl;
	cout << setw(21) << left << "Cruise Length:" << userNights << "-nights" << endl;
	cout << setw(21) << "Stateroom Occupants: " << userTravelers << endl;
	cout << setw(21) << "Dining Seating: " << userDiningTime << ":00 PM" << endl << endl;
	cout << "Stateroom Discounts" << endl;
	cout << string(19, '-') << endl;

	// Find the cost for one traveler or for 2-4 travelers
	if (userTravelers == 1) {
		travelerCost = travelerCost * (1 - SINGLE_TRAVELER_DISCOUNT);
		cout << setw(19) << right << "Single traveler:" << setw(3) << "$" << setw(8) << setprecision(2) << fixed << travelerCost << endl;
		if (userFTClub == 1) {
			FTDiscountAmount = -travelerCost * FT_CLUB_DISCOUNT;
		}
		totalStateroomCost = travelerCost + FTDiscountAmount;
		cout << setw(11) << "FT Club:" << setw(11) << "$" << setw(8) << FTDiscountAmount << endl;
		cout << "Total Stateroom:" << setw(6) << "$" << setw(8) << totalStateroomCost << endl;
	}
	else {
		if (userTravelers >= 3) {
			thirdTravelerCost = travelerCost * (1 - THIRD_TRAVELER_DISCOUNT);
		}
		if (userTravelers == 4) {
			fourthTravelerCost = travelerCost * (1 - FOURTH_TRAVELER_DISCOUNT);
		}

		if (userFTClub == 1) {
			FTDiscountAmount = -(travelerCost + thirdTravelerCost + fourthTravelerCost) * FT_CLUB_DISCOUNT;
		}

		totalStateroomCost = travelerCost + thirdTravelerCost + fourthTravelerCost + FTDiscountAmount;

		cout << setw(20) << right << "1st/2nd traveler:" << setw(2) << "$" << setw(8) << setprecision(2) << fixed << travelerCost << endl;
		cout << setw(16) << "3rd traveler:" << setw(6) << "$" << setw(8) << thirdTravelerCost << endl;
		cout << setw(16) << "4th traveler:" << setw(6) << "$" << setw(8) << fourthTravelerCost << endl;
		cout << setw(20) << "FT Club discount:" << setw(2) << "$" << setw(8) << FTDiscountAmount << endl;
		cout << "Total Stateroom:" << setw(6) << "$" << setw(8) << totalStateroomCost << endl;
	}
	cout << endl;

	// Find the cost of all beverage packages
	if (userWaterPackages != 0 || userFountainPackages != 0 || userAlcoholicPackages != 0) {
		cout << "Beverage Packages" << endl;
		cout << string(17, '-') << endl;

		currentPackageCost = userWaterPackages * WATER_PACKAGES_COST;
		totalBeverageCost += currentPackageCost;
		cout << "   Water Pkg for " << userWaterPackages << " travelers:" << setw(6) << "$" << setw(8) << currentPackageCost << endl;
		currentPackageCost = userFountainPackages * FOUNTAIN_PACKAGES_COST;
		totalBeverageCost += currentPackageCost;
		cout << "   Fountain Pkg for " << userFountainPackages << " travelers:" << setw(3) << "$" << setw(8) << currentPackageCost << endl;
		currentPackageCost = userAlcoholicPackages * ALCOHOLIC_PACKAGES_COST;
		totalBeverageCost += currentPackageCost;
		cout << "   Alcoholic Pkg for " << userAlcoholicPackages << " travelers:" << setw(2) << "$" << setw(8) << currentPackageCost << endl;
		cout << "Total Beverage:" << setw(7) << "$" << setw(8) << totalBeverageCost << endl;
		cout << endl;
	}

	// Calculates port fees for total cost
	portFeesCost = (totalStateroomCost + totalBeverageCost) * (PORT_FEES);
	finalCost = totalStateroomCost + totalBeverageCost + portFeesCost;

	// Output the end of the receipt
	cout << "Taxes, fees, and port expenses:" << setw(4) << "$" << setw(8) << portFeesCost << endl;
	cout << endl;
	cout << string(30, '-') << endl;
	cout << "Total cost:" << setw(11) << "$" << setw(8) << finalCost << endl;
	cout << string(30, '-') << endl;

	return 0;
}