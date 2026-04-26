//****************************************************
// Class: MotoNode.h (Header File)                   *
// A class for motorcyles acting as nodes for a list *
// Programmer: Brock Rowe							 *
// Class: CS 2020, Spring 2026						 *
// Due Date: 4/5/26									 *
// Program 4 Moto									 *
//****************************************************

#pragma once
#include <iostream>
#include <string>

using namespace std;

// A node of motorcycles, with their manufacturer's name, model, stock, style, price, horsepower
class MotoNode {
public:
	MotoNode(string manuName, string model, int stock,
		string style, double price, int horsepower);
	~MotoNode(); // Terminates list if next is not set to nullptr

	// Returns respective data member
	string GetName() const;
	string GetModel() const;
	int GetStock() const;
	string GetStyle() const;
	double GetPrice() const;
	int GetHorsepower() const;
	MotoNode* GetNext() const;

	// Sets the respective data members;
	void SetName(string name);
	void SetModel(string model);
	void SetStock(int stock);
	void SetStyle(string style);
	void SetPrice(double price);
	void SetHorsepower(int horsepower);
	void SetNext(MotoNode* nuNode); // Set "next" pointer to another MotoNode
private:
	string manuName;
	string model;
	int stock;
	string style;
	double price;
	int horsepower;
	MotoNode* next;
};