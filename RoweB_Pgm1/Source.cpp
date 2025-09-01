//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Movie Tickets
// Process: The program prints prompts about the name of a movie, how
// many adult tickets were sold, and how many children's tickets were
// sold. After taking the user input from these prompts, the program
// then calculates the gross sales of the movie. It then uses this
// sales number to output the gross ticket sales, as well as the
// theater profit and distributor profit using the constant double
// PERCENT_PROFIT.
// Results: Gross ticket sales, theater profit, and distributor profit
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection:
// I have spent some time working with Python before taking this 
// class, so this project was fairly manageable to me. I felt 
// comfortable declaring variables and taking input, but less
// comfortable with printing output in a way that felt efficient.
// I tested my program by using different numbers and a calculator 
// to make sure that it always gave the correct values. For my 
// next assignment, I think that getting used to using << and >> 
// in my code will make the writing experience more comfortable.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Declare variables and constants
	const double adult_ticket_price = 11.5;
	const double child_ticket_price = 9.5;
	const double PERCENT_PROFIT = 0.82;
	string movie_title;
	int adult_tickets_sold;
	int child_tickets_sold;
	double gross_sales;

	// Output the prompts and take in user inputs
	cout << "Enter the movie title: ";
	cin >> movie_title;
	cout << "How many adult tickets were sold: ";
	cin >> adult_tickets_sold;
	cout << "How many children's tickets were sold: ";
	cin >> child_tickets_sold;
	cout << endl;

	// Calculate gross ticket sales as a variable gross_sales
	gross_sales = (adult_ticket_price * adult_tickets_sold) + (child_ticket_price * child_tickets_sold);

	// Output the movie name and financial gains
	cout << "Gross Ticket Sales for '" << movie_title << "': $" << fixed << setprecision(2) << gross_sales << endl;
	cout << "Theater Net Profit: $" << gross_sales * PERCENT_PROFIT << endl;
	cout << "Amount Paid to Distributor: $" << gross_sales * (1 - PERCENT_PROFIT) << endl;

	// End program
	return 0;
}