//****************************************************
// Program: MotoListClient.cpp						 *
// Client program to use the MotoNode and MotoList   *
// classes											 *   
// Programmer: Brock Rowe							 *
// Class: CS 2020, Spring 2026						 *
// Due Date: 4/5/26									 *
// Purpose: read and manage a list of motorcycles 	 *
//****************************************************
#include "MotoNode.h"
#include "MotoList.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

MotoNode*CreateNuNode(); // prototype: creates a node to be added to the list
ifstream infile;		 // global file pointer to read data from the input file

int main() {

	infile.open("MotoData.txt");	//open data file, mus be in the same folder with your code
									//in other words, in your project folder.

	MotoList MyListOfMoto;			//List of Motorcycle
	double price;					//Use to  bikes under a given price
	int choice, DelStock;			//choice of metdisplayhods, see below
	string Style;					//Use to display bikes under a given price
	MotoNode* NuNode;				//Use to point to the new node

	infile >> choice; // get a menu choice before entering the loop		

	while (choice != 6)
	{
		if (choice == 1) {				//Add a newly created node to the front of the list
			NuNode = CreateNuNode();
			MyListOfMoto.AddOneBike(NuNode);
		}
		else if (choice == 2) {			//Finds and deletes a node based on the integer entered
			infile >> DelStock;
			MyListOfMoto.SellOneBike(DelStock);
		}
		else if (choice == 3) {				  //Display the list
			MyListOfMoto.PrintList();
		}
		else if (choice == 4) {					//Display all bikes for a given price
			infile >> price;
			MyListOfMoto.PrintPrice(price);
		}
		else if (choice == 5){					//Display all bikes for a given style
			getline(infile, Style);
			MyListOfMoto.PrintStyle(Style);
		}
		infile >> choice;
	}

	return 0;
}

//-----------------------------------------------------
// Function: CreateNuNode
// Inputs data for a new bike
// Create a new node and returns a pointer to that node
//-----------------------------------------------------
MotoNode* CreateNuNode()
{
	//Declare the appropriate variables to popluate your node.
	MotoNode* nuNode;
	string manuName;
	string model;
	int stock;
	string style;
	double price;
	int horsepower;

	//input those variables to popluate your node.
	getline(infile, manuName);
	getline(infile, model);
	infile >> stock;
	infile.ignore();
	getline(infile, style);
	infile >> price;
	infile >> horsepower;

	//add those variables as arguments to populate your node.
	nuNode = new MotoNode(manuName, model, stock, style, price, horsepower);

	return nuNode;
}
//--------------------------------------------------------------------
//Make sure you document your additional functions in the classes!!!!!
//--------------------------------------------------------------------
