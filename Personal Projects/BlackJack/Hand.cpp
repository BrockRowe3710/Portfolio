#include "Hand.h"
#include "Card.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Hand::ResetHand() {
	cardsInHand.clear();
	value = 0;
	softCount = 0;
}

void Hand::AddCard(Card newCard) {
	cardsInHand.push_back(newCard);
	this->UpdateValue(newCard);
}

int Hand::GetValue() {
	return value;
}

void Hand::UpdateValue(Card currCard) {
	if (currCard.GetValue() == "A") {
		softCount += 1;
		value += 11;
	}
	else if (currCard.GetValue() == "K" || currCard.GetValue() == "Q" || currCard.GetValue() == "J") {
		value += 10;
	}
	else {
		value += stoi(currCard.GetValue());
	}

	while (softCount && value > 21) {
		value -= 10;
		--softCount;
	}
}

void Hand::PrintHand() {
	int i, j;
	bool isBlank = false;

	if (cardsInHand.size() == 1) { // add blank card while player is playing
		Card blankCard(' ', " ");
		cardsInHand.push_back(blankCard);
		isBlank = true;
	}

	for (i = 0; i < 7; ++i) {
		for (Card currCard : cardsInHand) {
			switch (i) {
			case 0:
			case 6:
				cout << "+-----+ ";
				break;
			case 2:
			case 4:
			case 5:
				cout << "|     | ";
				break;
			case 1:
				cout << "|" << setw(2) << currCard.GetValue() << "   | ";
				break;
			case 3:
				cout << "|  " << currCard.GetSuit() << "  | ";
			}
		}
		cout << endl;
	}

	if (isBlank) cardsInHand.pop_back();
}