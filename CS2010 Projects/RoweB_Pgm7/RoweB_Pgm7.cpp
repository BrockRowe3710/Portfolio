#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// FIXME: Working on lookUp, need to finish ID search

using namespace std;

// Global Constants
const int CLASS_CAP = 35;
const string INPUT = "pgm7.txt";
const int COL_WIDTH = 20;

int readRoster(string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

int updateRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

char getUserChoiceLASQ();

char getUserChoiceLIB();

int getID();

string getClassification();

double getGPA();

int checkForDuplicateName(string newFirst, int pos, int cnt, string name[CLASS_CAP][2]);

string formatName(string n);

void printHeaderRow();

void printOneRec(int index, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

void swapRecords(int index, int min, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

void sortByLastName(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

void sortByID(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

int search(string key, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

int search(int key, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

int doAction(char choice, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

void lookUp(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

int addStudent(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

void showRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP]);

int main()
{
    // Name by last, first
    string name[CLASS_CAP][2];
    int id[CLASS_CAP];
    string classification[CLASS_CAP];
    double gpa[CLASS_CAP];

    // Initial student count
    int cnt = 0;

    // Check if a function worked as intended
    int checkValidity;

    // Read the file into name, id, classification, and gpa, returns student count
    cnt = readRoster(name, id, classification, gpa);
    if (cnt == -1) {
        cout << "Error: File open failed.\n";
        return 1;
    }

    cout << name[0][0] << name[0][1] << endl;

    char choice = getUserChoiceLASQ();

    while (choice != 'q') {
        cnt = doAction(choice, cnt, name, id, classification, gpa);

        choice = getUserChoiceLASQ();
    }

    return 0;
}

int readRoster(string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    int index = 0;
    string skipLine;

    ifstream inputFile(INPUT);
    if (!inputFile.is_open()) {
        return -1;
    }

    getline(inputFile, skipLine);

    while (index < CLASS_CAP && !inputFile.eof()) {
        inputFile >> name[index][1] >> name[index][0] >> id[index] >> classification[index] >> GPA[index];
        name[index][1].pop_back();
        ++index;
    }
    
    if (index == CLASS_CAP) {
        cout << "Alert: Class enrollment has reached the cap. You are limited to use\n";
        cout << "L(ook up), S(how) and Q(uit) functions of the system.\n\n";
    }

    inputFile.close();

    return index;
}

int updateRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

char getUserChoiceLASQ()
{
    char inputLASQ;
    
    while (true) {
        cout << "What to do [ L(ook up), A(dd), S(how), Q(uit) ]? ";
        cin >> inputLASQ;
        cout << "\n";

        switch (inputLASQ) {
        case 'l':
        case 'L':
            return 'l';
        case 'a':
        case 'A':
            return 'a';
        case 's':
        case 'S':
            return 's';
        case 'q':
        case 'Q':
            return 'q';
        default:
            cout << "Error: Invalid Input. Try again.\n\n";
        }
    }
}

char getUserChoiceLIB()
{
    char inputLIB;

    while (true) {
        cout << "Select lookup criterion.\n";
        cout << "Type L to look up by last name, type I to look up by ID, type B to go back: ";
        cin >> inputLIB;
        cout << "\n";

        switch (inputLIB) {
        case 'l':
        case 'L':
            return 'l';
        case 'i':
        case 'I':
            return 'i';
        case 'b':
        case 'B':
            return 'b';
        default:
            cout << "Error: Invalid Input. Try again.\n\n";
        }
    }
}

int getID()
{
    return 0;
}

string getClassification()
{
    return string();
}

double getGPA()
{
    return 0.0;
}

int checkForDuplicateName(string newFirst, int pos, int cnt, string name[CLASS_CAP][2])
{
    return 0;
}

string formatName(string n)
{
    n[0] = toupper(n[0]);

    return n;
}

void printHeaderRow()
{
    cout << left << setw(COL_WIDTH) << "Last,First"
        << setw(COL_WIDTH) << "ID"
        << setw(COL_WIDTH) << "Classification"
        << setw(COL_WIDTH) << "GPA"
        << endl;
}

void printOneRec(int index, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    string fullName = name[index][0] + ", " + name[index][1];

    cout << left << setw(COL_WIDTH) << fullName
        << setw(COL_WIDTH) << id[index]
        << setw(COL_WIDTH) << classification[index]
        << setw(COL_WIDTH) << GPA[index]
        << endl;
}

void swapRecords(int index, int min, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
}

void sortByLastName(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
}

void sortByID(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
}

int search(string key, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

int search(int key, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

int doAction(char choice, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    if (choice == 'l') {
        lookUp(cnt, name, id, classification, GPA);
    }
    else if (choice == 'a') {
        cnt = addStudent(cnt, name, id, classification, GPA);
    }
    else if (choice == 's') {
        showRoster(cnt, name, id, classification, GPA);
    }
    else if (choice == 'q') {
        cnt = updateRoster(cnt, name, id, classification, GPA);
    }

    return cnt;
}

void lookUp(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    int studentsFound = 0;

    char choice = getUserChoiceLIB();

    if (choice == 'l') {
        string lastName;
        cout << "Enter the last name: ";
        cin >> lastName;
        cout << endl;

        lastName = formatName(lastName);

        for (int i = 0; i < cnt; ++i) {
            if (name[i][0] == lastName) {
                if (studentsFound == 0) {
                    printHeaderRow();
                }

                printOneRec(i, name, id, classification, GPA);

                ++studentsFound;
            }
        }

        if (studentsFound == 0) {
            cout << "No record has been found.\n\n";
        }
        else {
            cout << studentsFound << " student record(s) were found.\n\n";
        }
    }
}

int addStudent(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

void showRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
}