#include <iostream>
#include <cstring>

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
    string name[CLASS_CAP][2];
    int id[CLASS_CAP];
    string classification[CLASS_CAP];
    double gpa[CLASS_CAP];

    return 0;
}

int readRoster(string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

int updateRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

char getUserChoiceLASQ()
{
    return 0;
}

char getUserChoiceLIB()
{
    return 0;
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
    return string();
}

void printHeaderRow()
{
}

void printOneRec(int index, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
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
    return 0;
}

void lookUp(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
}

int addStudent(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
    return 0;
}

void showRoster(int cnt, string name[CLASS_CAP][2], int id[CLASS_CAP], string classification[], double GPA[CLASS_CAP])
{
}