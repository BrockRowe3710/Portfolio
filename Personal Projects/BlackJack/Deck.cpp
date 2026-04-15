#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

void Deck::CreateDeck() {
	Card currCard;

	for (char suit : { 'H', 'D', 'C', 'S' }) {
		for (string value : {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}) {
			currCard.SetSuit(suit);
			currCard.SetValue(value);
			cards.push_back(currCard);
		}
	}
}

void Deck::Shuffle() {
	random_device rd;
	mt19937 g(rd());
	shuffle(cards.begin(), cards.end(), g);
}

void Deck::ResetDeck() {
	cards.clear();
	this->CreateDeck();
	this->Shuffle();
}

Card Deck::DrawCard() {
	Card drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
}

void Deck::PrintDeck() const {
	for (Card card : cards) {
		cout << card.GetValue() << " " << card.GetSuit() << endl;
	}
}