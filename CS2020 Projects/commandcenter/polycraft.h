// Program #5 – polycraft.h
// Programmer: Brock Rowe
// Class: CS 2020, Spring 2026
// Due Date: 4/19/26
// Purpose of program: Create the base class
// spacecraft, use inheritance to create
// satellite and rover classes

#include <iostream>
#include <string>

using namespace std;
//=========================spacecraft class definition=========================
//-----------------------------------------------------------------------

class spacecraft { // base class for both satellite and rover classes
public:
	spacecraft(string ccallName, string ccountry); // sets estCost to 0

	string GetName() const { return callName; }
	string GetCountry() const { return country; }
	double GetEstCost() const { return estCost; }

	void SetName(string ccallName) { callName = ccallName; }
	void SetCountry(string ccountry) { country = ccountry; }

	virtual void EstimateService(); // defaults estCost to 0
	virtual void printObject(); // prints callName, country, and estCost

protected:
	string callName;
	string country;
	double estCost;
};

//-----------------------------------------------------------------------
//=========================satellite class definition=========================
//-----------------------------------------------------------------------

class satellite : public spacecraft { // satellite class inheriting spacecraft class
public:
	satellite(string ccallName, string ccountry, int cnumdishes);

	// unique to satellite objects
	int GetNumDishes() const { return numdishes; }
	void SetNumDishes(int cnumdishes) { numdishes = cnumdishes; }
	// --------------------

	void EstimateService() override;
	void printObject() override;

private:
	int numdishes; // unique to satellite objects
};

//-----------------------------------------------------------------------
//=========================rover class definition=========================
//-----------------------------------------------------------------------

class rover : public spacecraft { // rover class inheriting spacecraft class
public:
	rover(string ccallName, string ccountry, int numwheels);

	// unique to rover objects
	int GetNumWheels() const { return numwheels; }
	void SetNumWheels(int cnumwheels) { numwheels = cnumwheels; }
	// ---------------------

	void EstimateService() override;
	void printObject() override;

private:
	int numwheels; // unique to rover objects
};

//-----------------------------------------------------------------------
