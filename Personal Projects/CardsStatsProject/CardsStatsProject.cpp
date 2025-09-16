// Lay out 10 cards 1-10, check how many have the same position as their value
// Quick solution to a discrete mathematics assignment

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main() {
    // Seed the shuffle RNG
    default_random_engine rng(time(0));

    // Create array for deck
    int deck[10];
    int position;

    int success = 0;
    int failure = 0;
    bool program_succeeded;

    // Input for how many times to run it
    int userTimesToRun;
    
    cout << "How many times to run the program? ";
    cin >> userTimesToRun;
    cout << endl;

    for (int i = 0; i < userTimesToRun; ++i) {
        for (int j = 0; j < 10; ++j) {
            deck[j] = j + 1;
        }
        
        shuffle(deck, deck + 10, rng);

        program_succeeded = true;

        for (position = 1; position <= 10; ++position) {
            // cout << setw(3) << left << position;
            // cout << deck[position - 1] << endl;
            if (position == deck[position - 1]) {
                // cout << "Same position and value!" << endl;
                program_succeeded = false;
                break;
            }
        }

        if (program_succeeded == true) {
            ++success;
        }
        else {
            ++failure;
        }

        // cout << endl;
    }

    cout << "Successes: " << success << endl;
    cout << "Failures: " << failure << endl;
    cout << "Percent of successes: " << setprecision(2) << fixed << 100 * static_cast<double>(success) / userTimesToRun << "%" << endl;
}
