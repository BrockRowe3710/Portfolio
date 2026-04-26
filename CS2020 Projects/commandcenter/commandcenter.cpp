// Program #5 – commandcenter.cpp
// Programmer: Brock Rowe
// Class: CS 2020, Spring 2026
// Due Date: 4/19/26
// Purpose of program: Create a list of
// satellites and vectors from a file

//This file contains a main program to build and display a list
//that utilizes inheritance and polymorphism.
//satellite and rover, which are all derived from
//the same base class spacecraft,  Are stored in a vector used to maintain
//the list of spacecrafts in commission. The vector consists of base class
//pointers to each spacecraft.
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "polycraft.h"

using namespace std;

spacecraft* getspacecraft(int code);				     // prototype: creates a spacecraft
void printList(vector<spacecraft*> missionlist);      // prototype: prints the list of spacecrafts
ifstream infile;									// global file pointer to read data from the input file

int main()
{
        vector<spacecraft*> missionlist;
		spacecraft* SCPtr;
		int code;
		infile.open("missionlist.txt");

		infile >> code; // get a menu code before entering the loop		

		while (code != 3)
		{
			SCPtr = getspacecraft(code);
			missionlist.push_back(SCPtr); //this adds SCPtr to the vector,
										  //the object is dynamically declare
										  //in the heap.
			infile >> code;
		}

		//add a base class object to the end of the list to test your base class functions
		missionlist.push_back(new spacecraft("END", "TEST"));
		//print the list
		printList(missionlist);
		return 0;
}
//-----------------------------------------------------
// Function: getspacecraft
// Inputs data for an spacecraft
// Create a new object based on the type of spacecraft
// and returns a pointer to that spacecraft
//-----------------------------------------------------
spacecraft* getspacecraft(int code)
{
	//Declare the appropriate variables to popluate your object.
	spacecraft* nuSCPtr;
	string callName, country;
	int numDishes, numTires;

	//input those variables to popluate your object.
	infile.ignore();
	getline(infile, callName);
	getline(infile, country);
	//add those variables as arguments to populate your object.
	if (code == 1)
	{
		infile >> numDishes;
		nuSCPtr = new satellite(callName, country, numDishes); // create a satellite with numDishes
	}
	else
	{
		infile >> numTires;
		nuSCPtr = new rover(callName, country, numTires); // create a rover with numTires
	}
	return nuSCPtr;
}
//-----------------------------------------------------
// Function: printList
// Prints the list of spacecraft
//-----------------------------------------------------
void printList(vector<spacecraft*> missionlist)
{
	cout << "The Mission List :" << endl;
	for (int k = 0; k < missionlist.size(); k++)
	{
		cout << "------------------------------------" << endl;
		missionlist[k]->EstimateService();   //missionlist.at(k)->EstimateService()
		missionlist[k]->printObject();		//will also work with vectors
	}
	cout << "------------------------------------" << endl; // add a bottom border to the output
}