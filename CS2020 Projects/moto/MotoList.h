//****************************************************
// Header: MotoList.h (Header File)				     *
// This class maintains a list of node objects.      *
// Programmer: Brock Rowe							 *
// Class: CS 2020, Spring 2026						 *
// Due Date: 4/5/26									 *
// Program 4 Moto									 *
//****************************************************

#pragma once
#include <string>
#include "MotoNode.h"

using namespace std;

// A list of MotoNodes
class MotoList {
public:
	MotoList() {}
	~MotoList(); // deletes list through recursive node destruction
	MotoList& operator=(MotoList& rhs);
	MotoList(MotoList& rhs);
	void PushBack(MotoNode* nuNode); // adds to the END of list
	void AddOneBike(MotoNode* nuNode); // adds to FRONT of list
	void SellOneBike(int stock); // removes first bike with equivalent stock
	void PrintList() const; // prints all bikes
	void PrintPrice(double price); // prints all bikes with <= prices
	void PrintStyle(string style); // prints all bikes with equivalent style
private:
	MotoNode* head = nullptr; // ptr to first node
	MotoNode* tail = nullptr; // ptr to last node
};