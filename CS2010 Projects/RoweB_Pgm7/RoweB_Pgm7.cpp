//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Program 7, RoweB_Pgm7.cpp, 12/07/2025
// Take a roster of students from a file and let the user look up, 
// add, and show students. The input file is updated after quitting.
// Process: Takes in a file with student information and saves it into arrays.
// Then, the user can edit the roster or find students in the roster by their
// last name or ID, add them with new information, or show the roster, all in
// a loop that updates when quit.
// Results: The input file is updated with new students and reformatted.
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection: I liked this program a lot, mostly because I felt like I was
// developing a deeper understanding of the code because it was more complex
// than the other program. I liked making search and sort functions, as I
// hadn't really done that on my own time. I also liked working with so many
// functions and realizing that I had already created the tools that I needed
// to solve a problem. The hardest part was making sure that everything fit
// into the constraints of the assignment, but I liked that it made me think
// about how I could approach problems differently.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Global Constants
const int CLASS_CAP = 35;
const string INPUT = "pgm7.txt";
const int COL_WIDTH = 20;

// All function declarations
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
    // Name by last, then first
    string name[CLASS_CAP][2];
    int id[CLASS_CAP];
    string classification[CLASS_CAP];
    double gpa[CLASS_CAP];

    // Initial student count
    int cnt = 0;

    // Read the file into name, id, classification, and gpa, returns student count
    cnt = readRoster(name, id, classification, gpa);
    if (cnt == -1) {
        cout << "Error: File open failed.\n";
        return 1;
    }

    char choice = getUserChoiceLASQ();

    // Main menu loop
    while (choice != 'q') {
        cnt = doAction(choice, cnt, name, id, classification, gpa);

        choice = getUserChoiceLASQ();
    }

    // Updates the input file with the new student information
    cnt = updateRoster(cnt, name, id, classification, gpa);
    if (cnt == -1) {
        cout << "Error: File open failed.\n";
        return 1;
    }

    cout << "Roster updated to " << INPUT << endl;

    return 0;
}

// Reads INPUT to get student information
int readRoster(string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    int index = 0;
    string skipLine;

    ifstream inputFile(INPUT);
    if (!inputFile.is_open()) {
        return -1;
    }

    getline(inputFile, skipLine);

    // Store student information
    while (index < CLASS_CAP && !inputFile.eof()) {
        inputFile >> name[index][0] >> name[index][1] >> id[index] >> classification[index] >> GPA[index];
        getline(inputFile, skipLine);
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

// Update INPUT with new information and formatting
int updateRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    string fullName;

    ofstream outputFile(INPUT);
    if (!outputFile.is_open()) {
        return -1;
    }

    // Write the header to the file
    outputFile << "   " << left << fixed << setprecision(2) 
        << setw(COL_WIDTH) << "Last, First" << setw(COL_WIDTH) << "ID"
        << setw(COL_WIDTH) << "Classification" << setw(COL_WIDTH) << "GPA";

    // Write each student by line
    sortByLastName(cnt, name, id, classification, GPA);

    for (int i = 0; i < cnt; ++i) {
        fullName = name[i][0] + ", " + name[i][1];

        outputFile << endl << setw(3) << i + 1
            << setw(COL_WIDTH) << fullName
            << setw(COL_WIDTH) << id[i]
            << setw(COL_WIDTH) << classification[i]
            << setw(COL_WIDTH) << GPA[i];
    }

    outputFile.close();

    return cnt;
}

// Let the user look up, add, or show students, then goes to doAction()
char getUserChoiceLASQ()
{
    char inputLASQ;
    
	// Case insensitive input validation loop
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

// Lets user search by last name or ID, used in lookUp()
char getUserChoiceLIB()
{
    char inputLIB;

	// Case insensitive input validation loop
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

// Validates an added student's ID
int getID()
{
    int newID;

    while (true) {
        cout << "Enter the student's 6-digit ID or enter -1 to return to the main menu: ";
        cin >> newID;

        if (newID == -1 || (newID >= 100000 && newID <= 999999)) {
            return newID;
        }
        else {
            cout << "Invalid Student ID. Try again.\n\n";
        }
    }
}

// Validates an added student's classification
string getClassification()
{
    int newClassification;

    while (true) {
        cout << "Enter the student's classification. Type 1 for freshman, 2 for sophomore, 3 for junior, "
            << "4 for senior, or -1 to return to the main menu: ";
        cin >> newClassification;

        switch (newClassification) {
        case -1:
            return "-1";
        case 1:
            return "Freshman";
        case 2:
            return "Sophomore";
        case 3:
            return "Junior";
        case 4:
            return "Senior";
        default:
            cout << "Error: Invalid Classification. Try again.\n\n";
        }
    }
}

// Validates an added student's GPA
double getGPA()
{
    double newGPA;

    while (true) {
        cout << "Enter the student's GPA or -1 to return to the main menu: ";
        cin >> newGPA;

        if (newGPA == -1.0) {
            return newGPA;
        }
        if (newGPA >= 0.0 && newGPA <= 4.0) {
            return newGPA;
        }
        else {
            cout << "Error: Invalid GPA. Try again.\n\n";
        }
    }
}

// Check if a student is in the roster based on sharing the same last name at index pos
int checkForDuplicateName(string newFirst, int pos, int cnt, string name[CLASS_CAP][2])
{
    if (newFirst == name[pos][1]) {
        return pos;
    }
    else if (pos < cnt - 1 && newFirst == name[pos + 1][1]) {
        return pos + 1;
    }
    else {
        return -1;
    }
}

// Uppercases the first letter of names
string formatName(string n)
{
    n[0] = toupper(n[0]);

    return n;
}

// Prints the top row to show columns of student information
void printHeaderRow()
{
    cout << left << setprecision(2)
        << setw(COL_WIDTH) << "Last, First"
        << setw(COL_WIDTH) << "ID"
        << setw(COL_WIDTH) << "Classification"
        << setw(COL_WIDTH) << "GPA"
        << endl;
}

// Prints the record of one student in colums of COL_WIDTH width
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

// Switch two records in the arrays with temporary variables
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
            else if (name[j][0] == name[min][0]) {
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
    int high = cnt - 1;
    int mid;

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
    int high = cnt - 1;
    int mid;

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

// Does the action chosen from getUserChoiceLASQ()
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
        return cnt;
    }

    return cnt;
}

// Find a student with search() by using either their last name or id
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

        sortByLastName(cnt, name, id, classification, GPA);
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

        sortByID(cnt, name, id, classification, GPA);
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

// Add a student to the roster, ensures that the student is unique
int addStudent(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    string newLastName;
    string newFirstName;
    int newID;
    string newClassification;
    double newGPA;

    if (cnt == CLASS_CAP) {
        cout << "Error: Class enrollment has reached the cap.\n\n";
        return cnt;
    }

    cout << "Enter the student's last name or type ! to return to the main menu: ";
    cin >> newLastName;
    if (newLastName == "!") {
        cout << endl;
        return cnt;
    }
    newLastName = formatName(newLastName);

    cout << "Enter the student's first name or type ! to return to the main menu: ";
    cin >> newFirstName;
    if (newFirstName == "!") {
        cout << endl;
        return cnt;
    }
    newFirstName = formatName(newFirstName);

	// Check for duplicate names by searching last names, then first names that match
    int dupeCheck = -1;
    int index = search(newLastName, cnt, name, id, classification, GPA);
    if (index != -1) {
        dupeCheck = checkForDuplicateName(newFirstName, index, cnt, name);
    }

    if (dupeCheck != -1) {
        cout << endl << newLastName << ", " << newFirstName << " is already enrolled.\n";
        printOneRec(dupeCheck, name, id, classification, GPA);
        cout << endl;
        return cnt;
    }

    newID = getID();
    if (newID == -1) {
        cout << endl;
        return cnt;
    }

    newClassification = getClassification();
    if (newClassification == "-1") {
        cout << endl;
        return cnt;
    }

    newGPA = getGPA();
    if (newGPA == -1.0) {
        cout << endl;
        return cnt;
    }

    name[cnt][0] = newLastName;
    name[cnt][1] = newFirstName;
    id[cnt] = newID;
    classification[cnt] = newClassification;
    GPA[cnt] = newGPA;

    cout << endl << "Student added successfully.\n\n";

    return cnt + 1;
}

// Prints the roster to the user by last name
void showRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    sortByLastName(cnt, name, id, classification, GPA);

    cout << "   ";
    printHeaderRow();

    for (int i = 0; i < cnt; ++i) {
        cout << setw(3) << left << i + 1;
        printOneRec(i, name, id, classification, GPA);
    }

    cout << endl;
}