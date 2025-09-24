// Create a readable schedule of classes from user's input
// Author's Note: Wanted to make a passion project based on what I had
// learned from the first month in CS, took around 6 hours to finish
// split between two days, and it was a fun project that taught me
// more about functions and how to apply them
// Known bugs:
// Times ending in :0X do not output correctly

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

// Put part of the input string into their respective array
void AssignArrayWithSubstr(string& tempStr, string array[], int& pos, int i) {
    pos = tempStr.find(',');
    array[i] = tempStr.substr(0, pos);
    tempStr = tempStr.erase(0, pos + 2);
}

// Turn the time string into minutes and hours
void SplitHoursAndMinutes(string timeString, int hours[], int minutes[], int i) {
    if (timeString.size() == 4) { // For X:XX times
        hours[i] = stoi(timeString.substr(0, 1));
        minutes[i] = stoi(timeString.substr(2, 2));
    }
    else { // For XX:XX times
        hours[i] = stoi(timeString.substr(0, 2));
        minutes[i] = stoi(timeString.substr(3, 2));
    }
}

// Store days as integers for easier use later
void DaysToInts(int days[], string allDays, int i) {
    for (int j = 0; j < allDays.size(); ++j) {
        switch (allDays[j]) {
        case 'm':
        case 'M':
            days[(i * 10)] = 1;
            break;
        case 't':
        case 'T':
            days[(i * 10) + 1] = 1;
            break;
        case 'w':
        case 'W':
            days[(i * 10) + 2] = 1;
            break;
        case 'r':
        case 'R':
            days[(i * 10) + 3] = 1;
            break;
        case 'f':
        case 'F':
            days[(i * 10) + 4] = 1;
            break;
        default:
            cout << "Enter Valid Dates" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

// Find the start and end of the calendar
void StartAndEndTimes(int sHours[], int fHours[], int fMins[], int size, int& sTime, int& fTime) {
    for (int i = 0; i < size; ++i) {
        if (sHours[i] < sTime) {
            sTime = sHours[i];
        }
        if (fHours[i] >= fTime) {
            if (fMins[i] > 0) {
                fTime = fHours[i] + 1;
            }
            else {
                fTime = fHours[i];
            }
        }
    }
    --sTime;
    ++fTime;
}

// Print a line of the calendar, will also print the "time" line after locations
void PrintLine(int sHours[], int sMinutes[], int fHours[], int fMinutes[], int currHour, int days[], string currArray[], bool outTime) {
    int classesDone = 0;

    for (int j = 0; j < 5; ++j) {
        classesDone = 0;
        for (int i = 0; i < 10; ++i) {
            if (sHours[i] == currHour && (days[i * 10 + j]) == 1) {
                cout << setw(11) << left << currArray[i] << "|";
                ++classesDone;
                break;
            }
            else if (fHours[i] == currHour && fMinutes[i] > 0 && (days[i * 10 + j]) == 1) {
                cout << setw(11) << left << currArray[i] << "|";
                ++classesDone;
                break;
            }
        }
        if (classesDone == 0) {
            cout << "           |";
        }
    }
    cout << endl;

    // See if time should be output after the previous line
    if (outTime == true) {
        cout << "|       |";
        for (int j = 0; j < 5; ++j) {
            classesDone = 0;
            for (int i = 0; i < 10; ++i) {
                if (sHours[i] == currHour && (days[i * 10 + j]) == 1) {
                    cout << setw(2) << right << sHours[i] << ":" << sMinutes[i] << "-" << setw(2) << fHours[i] << ":" << fMinutes[i] << "|";
                    days[i * 10 + j] = 0;
                    ++classesDone;
                    break;
                }
                else if (fHours[i] == currHour && fMinutes[i] > 0 && (days[i * 10 + j]) == 1) {
                    cout << setw(2) << right << sHours[i] << ":" << sMinutes[i] << "-" << setw(2) << fHours[i] << ":" << fMinutes[i] << "|";
                    days[i * 10 + j] = 0;
                    ++classesDone;
                    break;
                }
            }
            if (classesDone == 0) {
                cout << "           |";
            }
        }
        cout << endl;
    }
}

void CallPrintLine(int maxClass, int sHours[], int sMinutes[], int fHours[], int fMinutes[], int currHour, int days[], string classes[], string locations[]) {
    for (int i = 0; i < maxClass; ++i) {
        bool printTime = false;
        PrintLine(sHours, sMinutes, fHours, fMinutes, currHour, days, classes, printTime);
        cout << "|       |";
        printTime = true;
        PrintLine(sHours, sMinutes, fHours, fMinutes, currHour, days, locations, printTime);
        if (i != maxClass - 1) {
            cout << "|       |           |           |           |           |           |" << endl << "|       |";
        }
    }
    cout << "+-------+-----------+-----------+-----------+-----------+-----------+" << endl;
}

void PrintEntireRow(string classes[], string locations[], int days[], int currHour, int sHours[], int sMinutes[], int fHours[], int fMinutes[]) {
    // Iterate through each row (Time of day)
    // Count how many classes in the given row
    // Print out each line with PrintLine()

    int maxClassesInRow = 0;
    int classesInBox = 0;
    for (int j = 0; j < 5; ++j) {
        classesInBox = 0;
        for (int i = 0; i < 10; ++i) {
            if (sHours[i] == currHour && (days[i * 10] + j) == 1) {
                ++classesInBox;
            }
        }
        if (classesInBox > maxClassesInRow) {
            maxClassesInRow = classesInBox;
        }
    }

    // Print each line based on the amount of classes held
    bool printTime = false;
    if (maxClassesInRow == 0) {
        cout << "| " << setw(2) << right << currHour << ":00 |           |           |           |           |           |" << endl;
        cout << "+-------+-----------+-----------+-----------+-----------+-----------+" << endl;
    }
    else {
        cout << "| " << setw(2) << right << currHour << ":00 |";
        CallPrintLine(maxClassesInRow, sHours, sMinutes, fHours, fMinutes, currHour, days, classes, locations);
    }
}

void ReadTimesAndDates(int days[], 
    int sHours[], int sMinutes[], int fHours[], int fMinutes[],
    string classes[], string locations[], int& numClass) {

    string classCheck;
    string tempString;
    string timeString;
    string allDays;
    int i = 0;
    int pos = 0;
    int j;

    // Take input for up to 10 classes
    for (i; i < 10; ++i) {
        cout << "Enter your class: ";
        getline(cin, tempString);
        if (tempString == "-1") {
            break;
        }
        
        // Assigns classes[] and locations[] with strings from input
        AssignArrayWithSubstr(tempString, classes, pos, i);
        AssignArrayWithSubstr(tempString, locations, pos, i);

        // Find the days of the week
        pos = tempString.find(' ');
        allDays = tempString.substr(0, pos);
        DaysToInts(days, allDays, i);
        tempString = tempString.erase(0, pos + 1);

        // Store the start and finishing times
        pos = tempString.find('-');
        timeString = tempString.substr(0, pos);
        SplitHoursAndMinutes(timeString, sHours, sMinutes, i);
        timeString = tempString.erase(0, pos + 1);
        SplitHoursAndMinutes(timeString, fHours, fMinutes, i);

        numClass += 1;
    }
}

void DrawReadableSchedule(int days[], int sHours[], int sMinutes[], int fHours[],
    int fMinutes[], string classes[], string locations[], int numClass) {

    int startTime = sHours[0];
    int finalTime = fHours[0];

    // Draw the top of the schedule
    cout << "+-------+-----------+-----------+-----------+-----------+-----------+" << endl;
    cout << "|       |           |           |           |           |           |" << endl;
    cout << "| Time: |  Monday   |  Tuesday  | Wednesday | Thursday  |  Friday   |" << endl;
    cout << "|       |           |           |           |           |           |" << endl;
    cout << "+-------+-----------+-----------+-----------+-----------+-----------+" << endl;

    // Find amount of rows with hours
    StartAndEndTimes(sHours, fHours, fMinutes, numClass, startTime, finalTime);
    
    // Find the amount of lines for each row (1 for 0 classes, 5 for 1, 9 for 2)
    for (int i = startTime; i < finalTime; ++i) {
        PrintEntireRow(classes, locations, days, i, sHours, sMinutes, fHours, fMinutes);
    }
}

int main()
{
    // Variables to store all the class information
    string classes[10];
    string locations[10];
    int days[100] = { 0 };
    int sHours[10];
    int sMinutes[10];
    int fHours[10];
    int fMinutes[10];
    int numOfClasses = 0;

    // Explain the program to the user
    cout << "Welcome to the Schedule Maker!" << endl;
    cout << "* Enter your classes in this format:" << endl;
    cout << "'CS 2010, Hayes 107, MWF 8:30-9:20' (use 24-hour time)" << endl;
    cout << "* Ensure all entries except for time are 11 characters or less" << endl;

    // Function to take in class times and dates
    ReadTimesAndDates(days, sHours, sMinutes, fHours, fMinutes, classes, locations, numOfClasses);

    // Function to print out each row on schedule
    DrawReadableSchedule(days, sHours, sMinutes, fHours, fMinutes, classes, locations, numOfClasses);

    return 0;
}
