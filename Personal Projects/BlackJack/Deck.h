#pragma once
#include "Card.h"
#include <ctime>
#include <vector>

using namespace std;

class Deck {
public:
	void CreateDeck();
	void Shuffle();
	void ResetDeck();
	Card DrawCard();
	void PrintDeck() const;
private:
	vector<Card> cards;
};