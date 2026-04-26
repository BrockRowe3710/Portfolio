// Program #2 – Shareholder Program
// Programmer: Brock Rowe
// Class: CS 2020, Spring 2026
// Due Date: 2/22/26
// Purpose of program: Read a list of shareholders and
// calculate the values that they bring to a company

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Stores client information when read from a file
struct Shareholder {
    string name;
    string category;
    int shares = 0;
};

void FillVector(vector<Shareholder>& ClientList);
void PrintVectors(vector<Shareholder> ClientList);
void FindCategory(vector<Shareholder> ClientList);
void Breakdown(vector<Shareholder> ClientList);

int main() {
    vector<Shareholder> ClientList;

    FillVector(ClientList); // Read the shareholders from the input file

    PrintVectors(ClientList); // Print shareholders and their information

    FindCategory(ClientList); // Print only shareholders from one category

    Breakdown(ClientList); // Print total shareholder value by category, then total
}

// Fill the ClientList with Shareholder objects with information from the input file
void FillVector(vector<Shareholder>& ClientList) {
    ifstream inFile;
    inFile.open("shares.txt");
    
    if (!inFile.is_open()) {
        cout << "File failed to open" << endl;
        exit(1);
    }

    Shareholder tempShareholder;

    while (!inFile.eof()) {
        getline(inFile, tempShareholder.name);
        getline(inFile, tempShareholder.category);
        inFile >> tempShareholder.shares;
        inFile.ignore();

        ClientList.push_back(tempShareholder);
    }

    inFile.close();
}

// Print all shareholder's names, categories, and shares
void PrintVectors(vector<Shareholder> ClientList) {
    int i = 0;

    cout << string(50, '=') << endl;
    cout << left << setw(5) << "#"
        << setw(20) << "Name"
        << setw(15) << "Category"
        << setw(10) << "Shares" << endl;
    cout << string(50, '-') << endl;

    for (Shareholder currClient : ClientList) {
        cout << setw(5) << i
            << setw(20) << currClient.name
            << setw(15) << currClient.category
            << setw(10) << currClient.shares << endl;
        ++i;
    }

    cout << endl;
}

// Get input category, then display all names and shares in category
void FindCategory(vector<Shareholder> ClientList) {
    string chosenCat;
    int catValue = 0;
    int catClients = 0;

    cout << string(20, '=') << " FindCat. " << string(20, '=') << endl << endl;

    cout << "Enter the Category (Gold, Silver, or Bronze): ";
    cin >> chosenCat;

    if (chosenCat != "Gold" && chosenCat != "Silver" && chosenCat != "Bronze") {
        cout << "Invalid category, exiting program." << endl;
        exit(1);
    }

    cout << endl << string(30, '=') << endl;
    cout << "The " << chosenCat << " clients." << endl;
    cout << string(30, '=') << endl;

    for (Shareholder currClient : ClientList) { // Display all clients of chosenCat
        if (currClient.category == chosenCat) {
            cout << setw(25) << currClient.name
                << setw(5) << currClient.shares << endl;
            catValue += currClient.shares;
            ++catClients;
        }
    }

    // Display average shares owned by members of chosenCat
    cout << string(30, '-') << endl;
    cout << "The average " << chosenCat << " shares: " << catValue / catClients << endl;
    cout << string(30, '-') << endl << endl;
}

// Print the value of each category of shares and the total value of all shares
void Breakdown(vector<Shareholder> ClientList) {
    double goldVal = 0.0;
    double silverVal = 0.0;
    double bronzeVal = 0.0;
    double totalVal = 0.0;

    cout << string(24, '=') << " FindAssets " << string(24, '=') << endl;
    cout << string(60, '*') << endl;

    for (Shareholder currClient : ClientList) { // Gold = 8.95, Silver = 4.95, Bronze = 1.95
        if (currClient.category == "Gold") {
            goldVal += currClient.shares * 8.95;
        }
        else if (currClient.category == "Silver") {
            silverVal += currClient.shares * 4.95;
        }
        else if (currClient.category == "Bronze") {
            bronzeVal += currClient.shares * 1.95;
        }
    }
    totalVal = goldVal + silverVal + bronzeVal;

    // Output all category values and total value
    cout << fixed << setprecision(2);
    cout << left << setw(49) << "The value of the Gold Shareholders is:" << "$" << setw(10) << right << goldVal << endl;
    cout << left << setw(49) << "The value of the Silver Shareholders is:" << "$" << setw(10) << right << silverVal << endl;
    cout << left << setw(49) << "The value of the Bronze Shareholders is:" << "$" << setw(10) << right << bronzeVal << endl;
    cout << left << setw(49) << "The Total value of the Shareholders is:" << "$" << setw(10) << right << totalVal << endl;
}