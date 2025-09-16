//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Book Club Competition
// Process: The program opens a file stored under FILE_NAME and
// takes inputs given with the reader's name and then the total
// number of books that they've read. Then, the program tracks the
// number of readers, total number of books read, and who read the
// most and least amount of books. Finally, these values are output
// at the bottom, underneath the list of users and names.
// Results: Top reader, bottom reader, average books read
//
// Class: CS2010
// Section: 1001
// Term: Fall 2025
// Author: Brock Rowe
//
// Reflection:
// I didn't have many problems with this program, but I definitely
// need more experience working with file I/O. I could understand
// it well enough, but I did not have a good memory with the
// syntax especially. Other than that, I felt pretty comfortable
// running the code at every step and using cout for debugging. I
// went through a couple of slight changes in how I wanted to keep
// everything organized, but I'm glad with how it turned out.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    // Declare arrays and variables
    const int MAX_BOOKS = 25;
    const string FILE_NAME = "Pgm5.txt";

    string readerName[MAX_BOOKS];
    int readerBooks[MAX_BOOKS] = {0};

    // Track total readers and books, and which readers had the most and least books
    int numReaders = 0;
    int numBooks = 0;
    int mostBooksIndex = 0;
    int leastBooksIndex = 0;

    int i = 0;

    // Output header
    cout << "Book Club Reading Competition Results" << endl;
    cout << string(37, '=') << endl << endl;

    // Open the input file
    ifstream inputFile(FILE_NAME);

    if (!inputFile.is_open()) {
        cout << "File 'Pgm5.txt' not found" << endl;
        return 1;
    }

    // Read until end of file
    while (!inputFile.eof()) {
        // Get and store the reader's name and books read
        inputFile >> readerName[i];
        inputFile >> readerBooks[i];

        // Ensure book count is positive
        if (readerBooks[i] < 0) {
            readerBooks[i] *= -1;
        }

        numReaders += 1;
        numBooks += readerBooks[i];

        // Track the readers with the most and least books by their index 
        if (readerBooks[i] > readerBooks[mostBooksIndex]) {
            mostBooksIndex = i;
        }
        if (readerBooks[i] < readerBooks[leastBooksIndex]) {
            leastBooksIndex = i;
        }

        cout << "Reader " << i + 1 << " named " << readerName[i] << " read " << readerBooks[i] << " books" << endl;

        ++i;
    }

    cout << endl;

    // Output top reader, bottom reader, and average books read
    cout << fixed << setprecision(1);
    cout << "The winner is Reader " << mostBooksIndex + 1 << " named " << readerName[mostBooksIndex] << " who read " << readerBooks[mostBooksIndex] << " books." << endl;
    cout << "Reader " << leastBooksIndex + 1 << " named " << readerName[leastBooksIndex] << " read the least number of books: " << readerBooks[leastBooksIndex] << "." << endl;
    cout << "All readers read " << numBooks << " books, an average of " << static_cast<double>(numBooks) / numReaders << " per reader." << endl;

    return 0;
}