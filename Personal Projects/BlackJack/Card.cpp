#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

void Card::SetSuit(char suit) {
	this->suit = suit;
}

void Card::SetValue(string value) {
	this->value = value;
}
