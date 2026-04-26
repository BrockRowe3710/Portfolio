//****************************************************
// Class: MotoNode.cpp (Implementation File)         *
// A class for motorcyles acting as nodes for a list *
// Programmer: Brock Rowe							 *
// Class: CS 2020, Spring 2026						 *
// Due Date: 4/5/26									 *
// Program 4 Moto									 *
//****************************************************

#include <iostream>
#include <string>
#include "MotoNode.h"

using namespace std;

// Constructor: create a new MotoNode with a motorcycle's information
MotoNode::MotoNode(string manuName, string model, int stock,
	string style, double price, int horsepower) {
	this->manuName = manuName;
	this->model = model;
	this->stock = stock;
	this->style = style;
	this->price = price;
	this->horsepower = horsepower;
	this->next = next;
}

// Destructor: deletes node, deletes ALL nodes in list if next != nullptr when called
MotoNode::~MotoNode() {
	cout << stock << " bike removed." << endl;
	delete next;
	next = nullptr;
}

// GetName: return manufacturer's name
string MotoNode::GetName() const {
	return this->manuName;
}

// GetModel: return model
string MotoNode::GetModel() const {
	return this->model;
}

// GetStock: return stock
int MotoNode::GetStock() const {
	return this->stock;
}

// GetStyle: return style
string MotoNode::GetStyle() const {
	return this->style;
}

// GetPrice: return price
double MotoNode::GetPrice() const {
	return this->price;
}

// GetHorsepower: return horsepower
int MotoNode::GetHorsepower() const {
	return this->horsepower;
}

// GetNext: return pointer to next node
MotoNode* MotoNode::GetNext() const {
	return this->next;
}

// SetName: set new manuName
void MotoNode::SetName(string name) {
	this->manuName = name;
}

// SetModel: set new model
void MotoNode::SetModel(string model) {
	this->model = model;
}

// SetStock: set new stock
void MotoNode::SetStock(int stock) {
	this->stock = stock;
}

// SetStyle: set new style
void MotoNode::SetStyle(string style) {
	this->style = style;
}

// SetPrice: set new price
void MotoNode::SetPrice(double price) {
	this->price = price;
}

// SetHorsepower: set new horsepower
void MotoNode::SetHorsepower(int horsepower) {
	this->horsepower = horsepower;
}

// SetNext: set "next" pointer to another MotoNode
void MotoNode::SetNext(MotoNode* nuNode) {
	this->next = nuNode;
}