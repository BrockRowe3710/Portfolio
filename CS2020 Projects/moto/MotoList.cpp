//****************************************************
// Class: MotoList.cpp (Implementation File)         *
// This class maintains a list of node objects.      *
// Programmer: Brock Rowe							 *
// Class: CS 2020, Spring 2026						 *
// Due Date: 4/5/26									 *
// Program 4 Moto									 *
//****************************************************
#include "MotoNode.h" 
#include "MotoList.h"

#include <iostream>
#include <iomanip>
using namespace std;
//****************************************************
// Function: ~MotoList  (Destructor)                 *
// This function destroys the entire list.           *
//****************************************************
MotoList::~MotoList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
MotoList& MotoList::operator=(MotoList& rhs){
	MotoNode* currObj = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currObj != nullptr) {

			PushBack(new MotoNode(currObj->GetName(), currObj->GetModel(),
				currObj->GetStock(), currObj->GetStyle(), currObj->GetPrice(),
				currObj->GetHorsepower()));
			currObj = currObj->GetNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: MotoList(MotoList& rhs)                 *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
MotoList::MotoList(MotoList& rhs){
	MotoNode* currObj = rhs.head;                // Copy List

	while (currObj != nullptr) {
		PushBack(new MotoNode(currObj->GetName(), currObj->GetModel(),
			currObj->GetStock(), currObj->GetStyle(), currObj->GetPrice(),
			currObj->GetHorsepower()));
		currObj = currObj->GetNext();					//Traversal Statement
	}													//Important to point to the next node
}
//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 * 
// NEEDED FOR TWO OF THE BIG THREE!!!!               *
//****************************************************
void MotoList::PushBack(MotoNode* nuNode) {
	if (!head) {
		head = tail = nuNode;
	}
	else {
		tail->SetNext(nuNode);
		tail = nuNode;
	}
}

// AddOneBike: adds to the FRONT of the list
void MotoList::AddOneBike(MotoNode* nuNode) {
	MotoNode* tmpNode = head;
	head = nuNode;
	head->SetNext(tmpNode);
	cout << nuNode->GetStock() << " bike added." << endl;
}

// SellOneBike: removes first bike with equivalent stock
void MotoList::SellOneBike(int stock) {
	MotoNode* currNode = head;
	MotoNode* prevNode = head;

	if (!head) {
		cout << stock << " was not in stock." << endl;
		return;
	}
	else if (head->GetStock() == stock) {
		if (head == tail) {
			tail = nullptr;
		}
		head = head->GetNext();
		currNode->SetNext(nullptr);
		delete currNode;
		cout << stock << " has been sold." << endl;
		return;
	}
	while (currNode && currNode->GetStock() != stock) {
		prevNode = currNode;
		currNode = currNode->GetNext();
	}
	if (currNode) {
		prevNode->SetNext(currNode->GetNext());
		currNode->SetNext(nullptr);
		delete currNode;
		cout << stock << " has been sold." << endl;
		}
	else {
		cout << stock << " was not in stock." << endl;
	}
}

// PrintList: prints all bikes
void MotoList::PrintList() const {
	MotoNode* currObj = head;

	cout << left << fixed << setprecision(2);
	cout << string(80, '=') << endl;
	cout << setw(15) << "Manufacturer"
		<< setw(20) << "Model"
		<< setw(10) << "Stock"
		<< setw(15) << "Style"
		<< setw(15) << "Price"
		<< setw(5) << "HP" << endl;
	cout << setw(15) << string(12, '-')
		<< setw(20) << string(5, '-')
		<< setw(10) << string(5, '-')
		<< setw(15) << string(5, '-')
		<< setw(15) << string(5, '-')
		<< setw(5) << string(2, '-') << endl;

	while (currObj != nullptr) {
		cout << setw(15) << currObj->GetName()
			<< setw(20) << currObj->GetModel()
			<< setw(10) << currObj->GetStock()
			<< setw(15) << currObj->GetStyle()
			<< setw(15) << currObj->GetPrice()
			<< setw(5) << currObj->GetHorsepower() << endl;
		currObj = currObj->GetNext();
	}

	cout << string(80, '=') << endl;
}

// PrintPrice: prints all bikes with <= prices
void MotoList::PrintPrice(double price) {
	MotoNode* currObj = head;

	cout << left << fixed << setprecision(2);
	cout << string(80, '=') << endl;
	cout << "All bikes under: " << price << endl;
	cout << string(80, '=') << endl;
	cout << setw(15) << "Manufacturer"
		<< setw(20) << "Model"
		<< setw(10) << "Stock"
		<< setw(15) << "Style"
		<< setw(15) << "Price"
		<< setw(5) << "HP" << endl;
	cout << setw(15) << string(12, '-')
		<< setw(20) << string(5, '-')
		<< setw(10) << string(5, '-')
		<< setw(15) << string(5, '-')
		<< setw(15) << string(5, '-')
		<< setw(5) << string(2, '-') << endl;

	while (currObj) {
		if (currObj->GetPrice() <= price) {
			cout << setw(15) << currObj->GetName()
				<< setw(20) << currObj->GetModel()
				<< setw(10) << currObj->GetStock()
				<< setw(15) << currObj->GetStyle()
				<< setw(15) << currObj->GetPrice()
				<< setw(5) << currObj->GetHorsepower() << endl;
		}
		currObj = currObj->GetNext();
	}

	cout << string(80, '=') << endl;
}

// PrintStyle: prints all bikes with equivalent style
void MotoList::PrintStyle(string style) {
	MotoNode* currObj = head;

	cout << left << fixed << setprecision(2);
	cout << string(80, '=') << endl;
	cout << "All " << style << " bikes:" << endl;
	cout << string(80, '=') << endl;
	cout << setw(15) << "Manufacturer"
		<< setw(20) << "Model"
		<< setw(10) << "Stock"
		<< setw(15) << "Style"
		<< setw(15) << "Price"
		<< setw(5) << "HP" << endl;
	cout << setw(15) << string(12, '-')
		<< setw(20) << string(5, '-')
		<< setw(10) << string(5, '-')
		<< setw(15) << string(5, '-')
		<< setw(15) << string(5, '-')
		<< setw(5) << string(2, '-') << endl;

	while (currObj) {
		if (currObj->GetStyle() == style) {
			cout << setw(15) << currObj->GetName()
				<< setw(20) << currObj->GetModel()
				<< setw(10) << currObj->GetStock()
				<< setw(15) << currObj->GetStyle()
				<< setw(15) << currObj->GetPrice()
				<< setw(5) << currObj->GetHorsepower() << endl;
		}
		currObj = currObj->GetNext();
	}

	cout << string(80, '=') << endl;
}

