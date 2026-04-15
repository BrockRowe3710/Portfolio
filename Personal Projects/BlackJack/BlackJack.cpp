// BlackJack.cpp

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <cstdlib>
#include <iostream>
#include <Windows.h>

using namespace std;

void PrintState(Hand dealer, Hand player);
void PlayerTurn(Hand dealer, Hand& player, Deck& deck);
void DealerTurn(Hand& dealer, Hand& player, Deck& deck);
void DistributeWinnings(Hand dealer, Hand player, int& chips);
int PlayAgain();

int main()
{
    // Create a Deck class and Hand classes to hold cards
    Deck deck;
    deck.CreateDeck();
    deck.Shuffle();

    // Create player and dealer hands
    Hand playerHand;
    Hand dealerHand;
    dealerHand.SetDealer(true);

    int chips = 10;

    // Loop while chips > 0
    while (chips > 0) {
        system("cls");
        // Distribute original cards on deck
        dealerHand.AddCard(deck.DrawCard());
        playerHand.AddCard(deck.DrawCard());
        playerHand.AddCard(deck.DrawCard());

        PrintState(dealerHand, playerHand);

        // Loop while hand value < 21
        PlayerTurn(dealerHand, playerHand, deck);

        // Play dealer's hand until hand value >= 17
        if (playerHand.GetValue() < 21) DealerTurn(dealerHand, playerHand, deck);

        // Distribute winnings
        DistributeWinnings(dealerHand, playerHand, chips);

        // Prepare next hand
        if (chips <= 0 || PlayAgain() == 1) break;

        playerHand.ResetHand();
        dealerHand.ResetHand();
        deck.ResetDeck();
    }
}

void PrintState(Hand dealer, Hand player) {
    system("cls");

    dealer.PrintHand();
    cout << "Dealer value: " << dealer.GetValue() << "\n\n";
    player.PrintHand();
    cout << "\nHand value: " << player.GetValue() << "\n\n";
}

void PlayerTurn(Hand dealer, Hand& player, Deck& deck) {
    string playerChoice;

    while (player.GetValue() < 21) {
        cout << "Hit or stand? (h or s) ";
        cin >> playerChoice;
        while (playerChoice != "h" && playerChoice != "s") {
            cout << "Enter a valid choice. (h or s) ";
            cin >> playerChoice;
        }

        if (playerChoice == "s") break;

        player.AddCard(deck.DrawCard());

        PrintState(dealer, player);
    }
}

void DealerTurn(Hand& dealer, Hand& player, Deck& deck) {
    do {
        dealer.AddCard(deck.DrawCard());

        PrintState(dealer, player);

        Sleep(750);
    } while (dealer.GetValue() < 17);
}

void DistributeWinnings(Hand dealer, Hand player, int& chips) {
    if (player.GetValue() > 21) {
        --chips;
        cout << "You busted!\n";
    }
    else if (dealer.GetValue() > 21) {
        ++chips;
        cout << "Dealer busted!\n";
    }
    else if (player.GetValue() > dealer.GetValue()) {
        ++chips;
        cout << "You win!\n";
    }
    else if (player.GetValue() < dealer.GetValue()) {
        --chips;
        cout << "Dealer wins!\n";
    }

    cout << "Chips remaining: " << chips << "\n\n";
}

int PlayAgain() {
    string playerChoice;
    
    cout << "Play again? (y or n) ";
    cin >> playerChoice;
    while (playerChoice != "y" && playerChoice != "n") {
        cout << "Enter a valid choice. (y or n) ";
        cin >> playerChoice;
    }
    if (playerChoice == "n") return 1;
}