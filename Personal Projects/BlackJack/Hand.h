#pragma once
#include "Card.h"
#include <iostream>
#include <vector>

class Hand {
public:
	void ResetHand();
	void AddCard(Card newCard);
	int GetValue();
	void UpdateValue(Card currCard);
	void SetDealer(bool dealTF) { dealer = dealTF; }
	void PrintHand();
private:
	int value = 0;
	int softCount = 0;
	vector<Card> cardsInHand;
	bool dealer = false;
};

