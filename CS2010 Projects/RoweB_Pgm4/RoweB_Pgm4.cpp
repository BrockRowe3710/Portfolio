//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: YoY Inflation Rate Calculator
// Process: The program reads from a file that has three columns in it, one
// for the month of the year, one for the Core PCE of the first year, and one
// for the Core PCE of the second year. Then, it calculates the YoY inflation
// rate and determines the highest and lowest months of YoY inflation. the
// highest and lowest months are output to the console, and a table with the
// formatted data is written in an output file.
// Results: YoY inflation rates, highest and lowest YoY inflation months
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection:
// I found this program to be relatively easy, as I have worked on all of the
// other ones before this. Accessing files still isn't always intuitive to me, 
// but I find myself remembering the syntax a lot better than before. I also
// notice that I can usually know what libraries I'll need for a project
// before I start it, rather than adding them as I go along. Other than that,
// the project went by fairly quickly, and I liked practicing input and output
// to a file again.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const string INPUT_FILE = "pgm4.txt";
    const string OUTPUT_FILE = "output.txt";

    const int MONTH_WIDTH = 15;
    const int DATA_WIDTH = 10;

    string month = "";
    string highestMonth = "";
    string lowestMonth = "";

    double PCEYear1 = 0.0;
    double PCEYear2 = 0.0;
    double inflationRate = 0.0;
    double highestInflation = 0.0;
    double lowestInflation = 0.0;

    // Attempt to open files
    ifstream dataFile(INPUT_FILE);
    if (!dataFile.is_open()) {
        cout << "Failed to open " << INPUT_FILE << " file\n";
        return 1;
    }

    ofstream outputFile(OUTPUT_FILE);
    if (!outputFile.is_open()) {
        cout << "Failed to create " << OUTPUT_FILE << " file\n";
        return 1;
    }

    // Process each line in the input file
    while (!dataFile.eof()) {
        // Get month and PCE data from the input file
        dataFile >> month >> PCEYear1 >> PCEYear2;

        outputFile << fixed << setprecision(3) << left;
        outputFile << setw(MONTH_WIDTH) << month << setw(DATA_WIDTH) << PCEYear1 << setw(DATA_WIDTH) << PCEYear2;

        // Give a different output for the header
        if (month == "Month") {
            outputFile << "YoY Inflation Rate" << endl;
            continue;
        }

        // Calculate YoY Inflation Rate
        inflationRate = ((PCEYear2 - PCEYear1) / PCEYear1) * 100;

        // Set highest and lowest inflation rate on first line
        if (highestMonth == "") {
            highestMonth = month;
            highestInflation = inflationRate;
            lowestMonth = month;
            lowestInflation = inflationRate;
        }

        // Check for higher inflation rate
        if (highestInflation < inflationRate) {
            highestInflation = inflationRate;
            highestMonth = month;
        }

        // Check for lower inflation rate
        if (lowestInflation > inflationRate) {
            lowestInflation = inflationRate;
            lowestMonth = month;
        }

        outputFile << setprecision(2) << inflationRate << "%";

        // Avoid extra end line
        if (!dataFile.eof()) {
            outputFile << endl;
        }
    }

    dataFile.close();
    outputFile.close();

    // Output highest and lowest inflation rate months
    cout << setprecision(3) << "In 2024, " << highestMonth << " recorded the highest YoY inflation rate at " << highestInflation
        << "%, while " << lowestMonth << " recorded the lowest at " << lowestInflation << "%.\n";
    cout << "The YoY annual inflation rates are listed in " << OUTPUT_FILE << ".\n";

    return 0;
}