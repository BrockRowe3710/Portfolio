
/* Start your documentation here*/
// Program #3 – Wall Program
// Programmer: Brock Rowe
// Class: CS 2020, Spring 2026
// Due Date: 3/15/26
// Purpose of program: Create two climbers
// and race them to the top of a wall

#include "wall.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>  //use to generate a random number
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include<windows.h> //used to pause a windows display

using namespace std;
const int TOP_OF_WALL = 20;
int main()
{
	wall player1("Player 001"), player2("Player 456");
	int player1turn, player2turn;//use to decide if the player should climb or drop
	bool winner = false;		// use to terminate the loop once a player reaches 
	// the top of the wall

	unsigned seed = time(0);	//use top get a different set of ramdom numbers
	srand(seed);				// part of the random number process

	while (!winner)				//while there is not a winner the loop iterates
	{
		system("CLS");			//clears the screen (stdlib needed)

		cout << "==================== Top of the World!! =======================\n";
		player1turn = (rand() % 2);	//randomly generates a number from 0 to 1
		player2turn = (rand() % 2);	// 1 means the player will climb, 0 means player drops

		//write the code to make player 1 climb or drop
		// based of the value of turn

//add code here for player 1
		if (player1turn == 1) { // 1 = climb, 0 = drop
			player1.climb();
		}
		else { player1.drop(); }


		//write the code to make player 2 climb or drop
		// based of the value of turn

//add code here for player2
		if (player2turn == 1) { // 1 = climb, 0 = drop
			player2.climb();
		}
		else { player2.drop(); }


		//My test to make sure the a player does go below the ground.
		if (player1.getposition() < 0 || player2.getposition() < 0)
		{
			cout << "ERROR IN CODE" << endl;
			exit(1);
		}
		//animated wall with player labels
		cout << "---------------------------------------------------------------\n";
		for (int k = TOP_OF_WALL; k >= 0; k--)
		{
			if (k == 0 || k == 19)
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << setw(5) << k;
			if (player1.getposition() == k || (k == TOP_OF_WALL && player1.getposition() >= TOP_OF_WALL))
				cout << setw(15) << player1.getname();
			else
				cout << setw(15) << " ";

			if (player2.getposition() == k || (k == TOP_OF_WALL && player2.getposition() >= TOP_OF_WALL))
				cout << setw(15) << player2.getname();
			cout << endl;

		}
		cout << "---------------------------------------------------------------\n";
		Sleep(400); // pauses
		//Determine if there is a winner. Display the winner and set the condition
		//to exit the loop. If there is a tie, player 1 wins.

		//add code
		// if player 1 wins or tie
		if (player1.getposition() >= 20) {
			winner = true;
			cout << string(60, '=') << endl;
			cout << player1.getname() << " is the winner." << endl;
			cout << string(60, '=') << endl;
			cout << player2.getname() << " has been eliminated." << endl;
			cout << string(60, '=') << endl;
		}
		// if player 2 wins
		else if (player2.getposition() >= 20) {
			winner = true;
			cout << string(60, '=') << endl;
			cout << player2.getname() << " is the winner." << endl;
			cout << string(60, '=') << endl;
			cout << player1.getname() << " has been eliminated." << endl;
			cout << string(60, '=') << endl;
		}

	}
	return 0;
}
//end of code