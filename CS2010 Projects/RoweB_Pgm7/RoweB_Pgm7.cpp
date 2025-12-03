#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// FIXME: Implement adding students

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

    char choice = getUserChoiceLASQ();

    while (choice != 'q') {
        cnt = doAction(choice, cnt, name, id, classification, gpa);

        choice = getUserChoiceLASQ();
    }

    updateRoster(cnt, name, id, classification, gpa);

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
        inputFile >> name[index][0] >> name[index][1] >> id[index] >> classification[index] >> GPA[index];
        name[index][0].pop_back();
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

        switch (inputLIB) {
        case 'l':
        case 'L':
            return 'l';
        case 'i':
        case 'I':
            return 'i';
        case 'b':
        case 'B':
            cout << endl;
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
    cout << left << setprecision(2)
        << setw(COL_WIDTH) << "Last,First"
        << setw(COL_WIDTH) << "ID"
        << setw(COL_WIDTH) << "Classification"
        << setw(COL_WIDTH) << "GPA"
        << endl;
}

void printOneRec(int index, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    string fullName = name[index][0] + ", " + name[index][1];

    cout << left << fixed << setprecision(2) 
        << setw(COL_WIDTH) << fullName
        << setw(COL_WIDTH) << id[index]
        << setw(COL_WIDTH) << classification[index]
        << setw(COL_WIDTH) << GPA[index]
        << endl;
}

void swapRecords(int index, int min, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    string tempName[1][2];
    tempName[0][0] = name[index][0];
    tempName[0][1] = name[index][1];
    int tempID = id[index];
    string tempClass = classification[index];
    double tempGPA = GPA[index];

    name[index][0] = name[min][0];
    name[index][1] = name[min][1];
    id[index] = id[min];
    classification[index] = classification[min];
    GPA[index] = GPA[min];

    name[min][0] = tempName[0][0];
    name[min][1] = tempName[0][1];
    id[min] = tempID;
    classification[min] = tempClass;
    GPA[min] = tempGPA;
}

// Modified selection sort to sort by last name, then first name
void sortByLastName(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    int min;

    for (int i = 0; i < cnt; ++i) {
        min = i;
        for (int j = i; j < cnt; ++j) {
            if (name[j][0] < name[min][0]) {
                min = j;
            }
            if (name[j][0] == name[min][0]) {
                if (name[j][1] < name[min][1]) {
                    min = j;
                }
            }
        }
        swapRecords(i, min, name, id, classification, GPA);
    }
}

// Insertion sort to sort by ID
void sortByID(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    for (int i = 1; i < cnt; ++i) {
        for (int j = i; j > 0; --j) {
            if (id[j] < id[j - 1]) {
                swapRecords(j, j - 1, name, id, classification, GPA);
            }
            else {
                break;
            }
        }
    }
}

// Binary search by last name key
int search(string key, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    int low = 0;
    int high = cnt;
    int mid;

    sortByLastName(cnt, name, id, classification, GPA);

    while (high >= low) {
        mid = low + (high - low) / 2;
        if (name[mid][0] == key) {
            return mid;
        }
        else if (name[mid][0] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

// Binary search by ID using 6-digit key
int search(int key, int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    int low = 0;
    int high = cnt;
    int mid;

    sortByID(cnt, name, id, classification, GPA);

    while (high >= low) {
        mid = low + (high - low) / 2;
        if (id[mid] == key) {
            if (mid != 0 && id[mid] == id[mid - 1]) {
                return mid - 1;
            }
            return mid;
        }
        else if (id[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
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
    int index = -1;

    char choice = getUserChoiceLIB();

    if (choice == 'b') {
        return;
    }
    else if (choice == 'l') {
        string key;
        cout << "Enter the last name: ";
        cin >> key;
        cout << endl;

        key = formatName(key);

        index = search(key, cnt, name, id, classification, GPA);

        if (index == -1) {
            cout << "No record has been found.\n\n";
        }
        else {
            printHeaderRow();
            printOneRec(index, name, id, classification, GPA);
            if (index != cnt && name[index][0] == name[index + 1][0]) {
                printOneRec(index + 1, name, id, classification, GPA);
                cout << "2 student record(s) were found.\n\n";
            }
            else {
                cout << "1 student record(s) were found.\n\n";
            }
        }
    }
    else if (choice == 'i') {
        int key;
        cout << "Enter the student's 6-digit ID or enter -1 to return to the main menu: ";
        cin >> key;
        cout << endl;

        if (key == -1) {
            return;
        }

        index = search(key, cnt, name, id, classification, GPA);

        if (index == -1) {
            cout << "No record has been found.\n\n";
        }
        else {
            printHeaderRow();
            printOneRec(index, name, id, classification, GPA);
            cout << "1 student record(s) were found.\n\n";
        }
    }
}

int addStudent(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

void showRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    sortByLastName(cnt, name, id, classification, GPA);

    for (int i = 0; i < cnt; ++i) {
        printOneRec(i, name, id, classification, GPA);
    }

    cout << endl;
}

/* TEMP PRINT ALL VALUES
for (int i = 0; i < cnt; ++i) {
    printOneRec(i, name, id, classification, gpa);
}
*/