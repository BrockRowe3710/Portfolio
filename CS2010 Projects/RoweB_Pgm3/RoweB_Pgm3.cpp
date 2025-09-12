//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Rock Paper Scissors Lizard Spock Player
// Process: The program starts with the user inputting their choice of rock,
// paper, scissors, lizard, or Spock. Then, the computer's choice is made
// randomly. Then, the winner is determined with a series of if and else if
// statements. The total score of the user and computer are also tracked in
// these branches, so when the user decides to end the program, their total
// wins, losses, and ties are all displayed.
// Results: The outcome of the game and the win/loss/tie ratio.
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection:
// I found this program to be easier than the last one, but I think a lot of
// that was also from having to format the output so much. The hardest part
// of this project for me was looking through a lot of code that was all
// structured very similarly. I had to constantly double check the outputs
// for each section, and it led to a much less fluid coding session. I liked
// making it generally though, and I'm excited to use more loops when working
// on other projects in the future especially.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the computer choice RNG
    srand(time(0));

    // Declare Rock, Paper, Scissors, Lizard, Spock
    const char ROCK = 'R';
    const char PAPER = 'P';
    const char SCISSORS = 'S';
    const char LIZARD = 'L';
    const char SPOCK = 'V';

    // Declare choices
    char userChoice = 'Y';
    int computerRandom;
    char computerChoice;

    // Store user wins, losses, ties
    int wins = 0;
    int ties = 0;
    int losses = 0;

    cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock!" << endl << endl;

    while (userChoice != 'n' && userChoice != 'N') {
        // Take in user choice
        cout << "Enter R for Rock, P for Paper, S for Scissors, L for Lizard, or V for Spock: ";
        cin >> userChoice;

        // Choose the computer's choice
        computerRandom = rand() % 5;
        if (computerRandom == 0) {
            computerChoice = ROCK;
            cout << "Computer chose: Rock" << endl;
        }
        else if (computerRandom == 1) {
            computerChoice = PAPER;
            cout << "Computer chose: Paper" << endl;
        }
        else if (computerRandom == 2) {
            computerChoice = SCISSORS;
            cout << "Computer chose: Scissors" << endl;
        }
        else if (computerRandom == 3) {
            computerChoice = LIZARD;
            cout << "Computer chose: Lizard" << endl;
        }
        else {
            computerChoice = SPOCK;
            cout << "Computer chose: Spock" << endl;
        }

        // Determine the winner
        if (userChoice == 'r' || userChoice == 'R') {
            if (computerChoice == ROCK) {
                cout << "It's a tie!";
                ++ties;
            }
            else if (computerChoice == PAPER) {
                cout << "Computer wins this round! (Paper covers Rock)";
                ++losses;
            }
            else if (computerChoice == SCISSORS) {
                cout << "You win this round! (Rock crushes Scissors)";
                ++wins;
            }
            else if (computerChoice == LIZARD) {
                cout << "You win this round! (Rock crushes Lizard)";
                ++wins;
            }
            else if (computerChoice == SPOCK) {
                cout << "Computer wins this round! (Spock vaporizes Rock)";
                ++losses;
            }
        }
        else if (userChoice == 'p' || userChoice == 'P') {
            if (computerChoice == ROCK) {
                cout << "You win this round! (Paper covers Rock)";
                ++wins;
            }
            else if (computerChoice == PAPER) {
                cout << "It's a tie!";
                ++ties;
            }
            else if (computerChoice == SCISSORS) {
                cout << "Computer wins this round! (Scissors cuts Paper)";
                ++losses;
            }
            else if (computerChoice == LIZARD) {
                cout << "Computer wins this round! (Lizard eats Paper)";
                ++losses;
            }
            else if (computerChoice == SPOCK) {
                cout << "You win this round! (Paper disproves Spock)";
                ++wins;
            }
        }
        else if (userChoice == 's' || userChoice == 'S') {
            if (computerChoice == ROCK) {
                cout << "Computer wins this round! (Rock crushes Scissors)";
                ++losses;
            }
            else if (computerChoice == PAPER) {
                cout << "You win this round! (Scissors cuts Paper)";
                ++wins;
            }
            else if (computerChoice == SCISSORS) {
                cout << "It's a tie!";
                ++ties;
            }
            else if (computerChoice == LIZARD) {
                cout << "You win this round! (Scissors kills Lizard)";
                ++wins;
            }
            else if (computerChoice == SPOCK) {
                cout << "Computer wins this round! (Spock smashes Scissors)";
                ++losses;
            }
        }
        else if (userChoice == 'l' || userChoice == 'L') {
            if (computerChoice == ROCK) {
                cout << "Computer wins this round! (Rock crushes Lizard)";
                ++losses;
            }
            else if (computerChoice == PAPER) {
                cout << "You win this round! (Lizard eats Paper)";
                ++wins;
            }
            else if (computerChoice == SCISSORS) {
                cout << "Computer wins this round! (Scissors kills Lizard)";
                ++losses;
            }
            else if (computerChoice == LIZARD) {
                cout << "It's a tie!";
                ++ties;
            }
            else if (computerChoice == SPOCK) {
                cout << "You win this round! (Lizard poisons Spock)";
                ++wins;
            }
        }
        else if (userChoice == 'v' || userChoice == 'V') {
            if (computerChoice == ROCK) {
                cout << "You win this round! (Spock vaporizes Rock)";
                ++wins;
            }
            else if (computerChoice == PAPER) {
                cout << "Computer wins this round! (Paper disproves Spock)";
                ++losses;
            }
            else if (computerChoice == SCISSORS) {
                cout << "You win this round! (Spock smashes Scissors)";
                ++wins;
            }
            else if (computerChoice == LIZARD) {
                cout << "Computer wins this round! (Lizard poisons Spock)";
                ++losses;
            }
            else if (computerChoice == SPOCK) {
                cout << "It's a tie!";
                ++ties;
            }
        }
        else {
            cout << "Invalid input, please try again";
        }

        // Prompt the user to play again
        cout << endl << endl << "Play again? (Y/N): ";
        cin >> userChoice;
        cout << endl;
    }

    // Show final results
    cout << "Final Results:" << endl;
    cout << "User wins: " << wins << endl;
    cout << "Computer wins: " << losses << endl;
    cout << "Ties: " << ties << endl;

    return 0;
}