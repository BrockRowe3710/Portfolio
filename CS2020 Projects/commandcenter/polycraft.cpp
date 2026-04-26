// Program #5 – polycraft.cpp
// Programmer: Brock Rowe
// Class: CS 2020, Spring 2026
// Due Date: 4/19/26
// Purpose of program: Store functions
// for spacecraft, satellite, and rover
// classes, including constructors

#include <iomanip>
#include <iostream>
#include <string>
#include "polycraft.h"

using namespace std;
//=====================spacecraft class member functions======================
//-----------------------spacecraft Constructor-----------------------------

spacecraft::spacecraft(string ccallName, string ccountry) {
	callName = ccallName;
	country = ccountry;
	estCost = 0.0;
}

//-----------------------spacecraft EstimateService-----------------------------

void spacecraft::EstimateService() {
	estCost = 0.0;
}

//-----------------------spacecraft printObject-----------------------------

void spacecraft::printObject() {
	cout << left;
	cout << setw(18) << "Call Name" << ":" << callName << endl;
	cout << setw(18) << "Country" << ":" << country << endl;
	cout << setw(18) << "Estimated Cost" << ":" << estCost << endl;
}

//=========================satellite class member functions=========================
//-----------------------satellite Constructor-----------------------------

satellite::satellite(string ccallName, string ccountry, int cnumdishes) : spacecraft(ccallName, ccountry) {
	numdishes = cnumdishes;
}

//-----------------------satellite EstimateService-----------------------------

// $40,000 if <= 4 dishes, numdishes * $7,000 otherwise
void satellite::EstimateService() {
	if (numdishes <= 4) {
		estCost = 40000;
	}
	else {
		estCost = numdishes * 7000;
	}
}

//-----------------------satellite printObject-----------------------------

void satellite::printObject() {
	cout << "[Satellite]" << endl;
	this->spacecraft::printObject();
	cout << setw(18) << "Number of Dishes" << ":" << numdishes << endl;
}

//====================rover class member functions=========================
//-----------------------rover Constructor-----------------------------

rover::rover(string ccallName, string ccountry, int cnumwheels) : spacecraft(ccallName, ccountry) {
	numwheels = cnumwheels;
}

//-----------------------rover EstimateService-----------------------------

// $10,000 if <= 8 wheels, numwheels * $2,000 otherwise
void rover::EstimateService() {
	if (numwheels <= 8) {
		estCost = 10000;
	}
	else {
		estCost = numwheels * 2000;
	}
}

//-----------------------rover printObject-----------------------------

void rover::printObject() {
	cout << "[Rover]" << endl;
	this->spacecraft::printObject();
	cout << setw(18) << "Number of Wheels" << ":" << numwheels << endl;
}