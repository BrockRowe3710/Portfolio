#pragma once
#include <string>

using namespace std;

class Card {
public:
	Card(char suit = 'X', string value = "N/A") {
		this->suit = suit;
		this->value = value;
	}

	char GetSuit() const { return suit; }
	string GetValue() const { return value; }

	void SetSuit(char suit);
	void SetValue(string value);
private:
	char suit;
	string value;
};