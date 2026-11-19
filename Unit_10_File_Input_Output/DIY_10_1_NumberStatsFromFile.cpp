/**
 * Unit 10 - DIY Question 1: Number Stats from File
 * 
 * Problem Statement:
 * Read an unknown count of integers from nums.txt and print their
 * count, sum, min and max.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_10_1_NumberStatsFromFile.cpp -o DIY_10_1
 *   ./DIY_10_1
 */

#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>

using namespace std;

// Helper to ensure sample nums.txt exists
void createSampleFileIfNotExists(const string &filename) {
    ifstream check(filename);
    if (!check.is_open()) {
        ofstream sample(filename);
        sample << "42 17 88 9 65 3 99 24 51 76\n";
        cout << "[Setup] Created sample '" << filename << "' with numbers: 42 17 88 9 65 3 99 24 51 76\n";
    }
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 10 - DIY 1: FILE NUMBER STATISTICS           \n";
    cout << "====================================================\n";

    const string filename = "nums.txt";
    createSampleFileIfNotExists(filename);

    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "[Error] Could not open file: " << filename << "\n";
        return 1;
    }

    int count = 0;
    long long sum = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int val;

    cout << "Reading integers from '" << filename << "'...\n";
    while (inFile >> val) {
        count++;
        sum += val;
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
    inFile.close();

    if (count == 0) {
        cout << "File was empty. No numbers found.\n";
        return 0;
    }

    double avg = static_cast<double>(sum) / count;

    cout << "\n--- Statistics from File ---\n";
    cout << "Count   : " << count << "\n";
    cout << "Sum     : " << sum << "\n";
    cout << "Average : " << fixed << setprecision(2) << avg << "\n";
    cout << "Minimum : " << minVal << "\n";
    cout << "Maximum : " << maxVal << "\n";

    return 0;
}
