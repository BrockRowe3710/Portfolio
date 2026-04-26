// Program #1 – Insurance Program
// Programmer: Brock Rowe
// Class: CS 2020, Spring 2026
// Due Date: 2/1/26
// Purpose of program: Show, compare, and find insurance clients

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 50;
const string INPUT = "insur.txt";

void FillVectors(int& numClients, vector<string>& clientNames, vector<string>& policy, vector<int>& yrs, vector<int>& premium);

void PrintVectors(int numClients, vector<string> clientNames, vector<string> policy, vector<int> yrs, vector<int> premium);

void SelSort(int numClients, vector<string>& clientNames, vector<string>& policy, vector<int>& yrs, vector<int>& premium);

void LoyalClient(int numClients, vector<string> clientNames, vector<int> yrs);

void ShowBoats(int numClients, vector<string> clientNames, vector<string> policy, vector<int> premium);

int HighestPremium(int numClients, vector<int> premium);

int FindClient(int numClients, vector<string> clientNames);

int BinarySearch(int numClients, vector<string> clientNames, string targetName);

int main()
{
    // Client info vectors
    vector<string> clientNames(SIZE);
    vector<string> policy(SIZE);
    vector<int> yrs(SIZE);
    vector<int> premium(SIZE);

    int numClients = 0;
    int highPremIndex;
    int targetIndex;

    string targetName;

    FillVectors(numClients, clientNames, policy, yrs, premium);

    PrintVectors(numClients, clientNames, policy, yrs, premium);

    SelSort(numClients, clientNames, policy, yrs, premium);

    PrintVectors(numClients, clientNames, policy, yrs, premium);

    LoyalClient(numClients, clientNames, yrs);

    ShowBoats(numClients, clientNames, policy, premium);

    highPremIndex = HighestPremium(numClients, premium);
    cout << string(60, '*') << endl;
    cout << clientNames.at(highPremIndex) << " has the highest premium of $" << premium.at(highPremIndex) << endl;
    cout << string(60, '*') << endl;

    targetIndex = FindClient(numClients, clientNames);
    if (targetIndex == -1) { // End program if FindClient fails
        cout << "Client not found." << endl;
        exit(0);
    }
    
    // Output the target client if found
    cout << left << setw(10) << "Client:" << clientNames.at(targetIndex) << endl
        << setw(10) << "Policy:" << policy.at(targetIndex) << endl
        << setw(10) << "Years:" << yrs.at(targetIndex) << endl
        << setw(10) << "Premium:" << premium.at(targetIndex) << endl;

    return 0;
}

// Read all client info into respective vectors from INPUT
void FillVectors(int& numClients, vector<string>& clientNames, vector<string>& policy, vector<int>& yrs, vector<int>& premium) {
    ifstream inputFile(INPUT);
    if (!inputFile.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }

    while (!inputFile.eof() && numClients < SIZE) {
        getline(inputFile, clientNames.at(numClients));
        getline(inputFile, policy.at(numClients));
        inputFile >> yrs.at(numClients);
        inputFile >> premium.at(numClients);
        inputFile.ignore();

        ++numClients;
    }

    inputFile.close();
}

// Print all clients, with their information in rows
void PrintVectors(int numClients, vector<string> clientNames, vector<string> policy, vector<int> yrs, vector<int> premium) {
    int i = 0;
    
    cout << string(60, '*') << endl;
    cout << left << setw(20) << "Names"
        << setw(15) << "Policy"
        << setw(15) << "Yrs"
        << setw(10) << "Prem" << endl;
    cout << left << setw(20) << "-----"
        << setw(15) << "------"
        << setw(15) << "---"
        << setw(10) << "----" << endl;

    for (i = 0; i < numClients; ++i) {
        cout << left << setw(20) << clientNames.at(i)
            << setw(15) << policy.at(i)
            << setw(15) << yrs.at(i)
            << setw(10) << premium.at(i) << endl;
    }
    cout << string(60, '*') << endl;
}

// Selection sort by client's first and last names
void SelSort(int numClients, vector<string>& clientNames, vector<string>& policy, vector<int>& yrs, vector<int>& premium) {
    int i, j, tempInt, minIndex;
    string tempStr;

    for (i = 0; i < numClients - 1; ++i) {
        minIndex = i;
        for (j = i + 1; j < numClients; ++j) {
            if (clientNames.at(j) < clientNames.at(minIndex)) {
                minIndex = j;
            }
        }

        tempStr = clientNames.at(i);
        clientNames.at(i) = clientNames.at(minIndex);
        clientNames.at(minIndex) = tempStr;

        tempStr = policy.at(i);
        policy.at(i) = policy.at(minIndex);
        policy.at(minIndex) = tempStr;

        tempInt = yrs.at(i);
        yrs.at(i) = yrs.at(minIndex);
        yrs.at(minIndex) = tempInt;

        tempInt = premium.at(i);
        premium.at(i) = premium.at(minIndex);
        premium.at(minIndex) = tempInt;
    }
}

// Output all loyal clients and their years as a client in rows
void LoyalClient(int numClients, vector<string> clientNames, vector<int> yrs) {
    int i;

    cout << "Loyal Client List:" << endl;
    cout << string(60, '-') << endl;

    for (i = 0; i < numClients; ++i) {
        if (yrs.at(i) >= 10) {
            cout << setw(20) << left << clientNames.at(i)
                << yrs.at(i) << endl;
        }
    }

    cout << string(60, '*') << endl;
}

// Output all clients with boat insurance and a high enough premium
void ShowBoats(int numClients, vector<string> clientNames, vector<string> policy, vector<int> premium) {
    int i;

    cout << "Show Boat List:" << endl;
    cout << string(60, '-') << endl;

    for (i = 0; i < numClients; ++i) {
        if (policy.at(i) == "Boat" && premium.at(i) >= 4800) {
            cout << setw(20) << left << clientNames.at(i)
                << setw(10) << policy.at(i)
                << premium.at(i) << endl;
        }
    }

    cout << string(60, '*') << endl;
}

// Return the index of the client with the highest premium
int HighestPremium(int numClients, vector<int> premium) {
    int i;
    int hpIndex = 0;

    for (i = 0; i < numClients; ++i) {
        if (premium.at(i) > premium.at(hpIndex)) {
            hpIndex = i;
        }
    }

    return hpIndex;
}

// Return index of a client's name gotten by input
int FindClient(int numClients, vector<string> clientNames) {
    string targetName;
    
    cout << "Enter the client's name: ";
    getline(cin, targetName);
    return BinarySearch(numClients, clientNames, targetName);
}

// Find a target client in the list of stored vectors
int BinarySearch(int numClients, vector<string> clientNames, string targetName) {
    int low = 0;
    int high = numClients - 1;
    int mid;
    int notFound = -1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (clientNames.at(mid) < targetName) {
            low = mid + 1;
        }
        else if (clientNames.at(mid) > targetName) {
            high = mid - 1;
        }
        else { return mid; }
    }

    return notFound;
}