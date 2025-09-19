//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Turns a txt file with grades into a readable report txt file
// Process: The program first takes the user input file and output file of
// the scores and the report, respectively. Then the program loads the scores
// from the input file and saves them as integers. It then computes useful
// stats about the grades, like the lowest and highest scores, average score,
// and how many of each letter grade there are. Finally, the results are
// created in a new file that has a readable version of all the information,
// as well as a histogram at the bottom.
// Results: Min & max scores, average, and letter grade count
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection:
// I felt a lot more comfortable working with ifstream and ofstream than I
// did in the last program. While the syntax will still take a bit of getting
// used to, I found that I better understood how to use the I/O in a useful
// way. I'm very excited to work with functions, as I think that a lot of
// future programs that I write will become easier and cleaner with them.
// Overall, the only issues I had with this program was getting some small
// details with functions to work properly, but after sorting them out I
// found that the rest of the logic came to me fairly naturally.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Store the scores from the input file into the scores[] array
int LoadScores(ifstream& in, int scores[], const int MAX_SCORES) {
    int n = 0;
    int score;
    for (int i = 0; i < MAX_SCORES; ++i) {
        in >> score;
        if (in.eof() != true) {
            scores[i] = score;
            ++n;
        }
        else {
            break;
        }
    }
    return n;
}

// Calculate information regarding the scores
void ComputeStats(const int scores[], int n, int& minScore, int& maxScore, double& avg, int& aCnt, int& bCnt, int& cCnt, int& dCnt, int& fCnt) {
    int i;
    int sum = 0;
    minScore = scores[0];
    maxScore = scores[0];
    // Find min and max scores, calculate average, and count each letter grade
    for (i = 0; i < n; ++i) {
        if (scores[i] < minScore) {
            minScore = scores[i];
        }
        else if (scores[i] > maxScore) {
            maxScore = scores[i];
        }

        sum += scores[i];

        if (scores[i] >= 90) {
            ++aCnt;
        }
        else if (scores[i] >= 80) {
            ++bCnt;
        }
        else if (scores[i] >= 70) {
            ++cCnt;
        }
        else if (scores[i] >= 60) {
            ++dCnt;
        }
        else {
            ++fCnt;
        }
    }

    avg = static_cast<double>(sum) / n;
}

// Write a readable grade summary to an output file
void WriteReport(ofstream& out, const int scores[], int n, int& minScore, int& maxScore, double& avg, int& aCnt, int& bCnt, int& cCnt, int& dCnt, int& fCnt) {
    out << fixed << left << setprecision(2);
    out << "CS2010 Grade Report" << endl;
    out << string(19, '=') << endl;

    out << setw(13) << "Count" << ": " << n << endl;
    out << setw(13) << "Minimum" << ": " << minScore << endl;
    out << setw(13) << "Maximum" << ": " << maxScore << endl;
    out << setw(13) << "Average" << ": " << avg << endl;
    out << endl;

    out << "Letter Grades" << endl;
    out << "A (90-100): " << aCnt << endl;
    out << "B (80-89) : " << bCnt << endl;
    out << "C (70-79) : " << cCnt << endl;
    out << "D (60-69) : " << dCnt << endl;
    out << "F (<60)   : " << fCnt << endl;
    out << endl;

    out << "Histogram (each * = 1 student)" << endl;
    out << "A: " << string(aCnt, '*') << endl;
    out << "B: " << string(bCnt, '*') << endl;
    out << "C: " << string(cCnt, '*') << endl;
    out << "D: " << string(dCnt, '*') << endl;
    out << "F: " << string(fCnt, '*') << endl;
    out << endl;
}

int main()
{
    // Variables to read and store scores
    const int MAX_SCORES = 100;

    string inputFile;
    string outputFile;

    int scores[MAX_SCORES];
    int scoresRead;

    // Variables for stats and for each letter grade
    int minScore = 0; // Updated before use
    int maxScore = 0; // Updated before use
    double avg = 0;
    int aCnt = 0;
    int bCnt = 0;
    int cCnt = 0;
    int dCnt = 0;
    int fCnt = 0;

    // Get the input/output files from console
    cout << "Enter input filename: ";
    cin >> inputFile; // scores.txt
    cout << "Enter output filename: ";
    cin >> outputFile; // report.txt

    // Open the scores file and store all values
    ifstream in(inputFile);

    // Validate input file opened
    if (in.is_open() != true) {
        cout << "Failed to find " << inputFile << endl;
        return 1;
    }

    scoresRead = LoadScores(in, scores, MAX_SCORES);

    in.close();

    ComputeStats(scores, scoresRead, minScore, maxScore, avg, aCnt, bCnt, cCnt, dCnt, fCnt);

    // Open the output file and print a readable report
    ofstream out(outputFile);

    // Validate output file opened
    if (out.is_open() != true) {
        cout << "Failed to find " << outputFile << endl;
        return 1;
    }

    WriteReport(out, scores, scoresRead, minScore, maxScore, avg, aCnt, bCnt, cCnt, dCnt, fCnt);

    out.close();

    cout << "Read " << scoresRead << " score(s). Report written to '" << outputFile << "'." << endl;

    return 0;
}