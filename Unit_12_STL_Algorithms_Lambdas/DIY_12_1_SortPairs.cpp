/**
 * Unit 12 - DIY Question 1: Sort Vector of Pairs by Second Field
 * 
 * Problem Statement:
 * Given a vector<pair<string,int>>, sort by the integer (second) field
 * ascending, then print.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_12_1_SortPairs.cpp -o DIY_12_1
 *   ./DIY_12_1
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 12 - DIY 1: SORT PAIRS WITH LAMBDA           \n";
    cout << "====================================================\n";

    vector<pair<string, int>> studentScores = {
        {"Rohit", 85},
        {"Sneha", 96},
        {"Amit", 72},
        {"Divya", 91},
        {"Varun", 68},
        {"Kavya", 89}
    };

    cout << "--- Original List ---\n";
    for (const auto &p : studentScores) {
        cout << "  " << setw(10) << left << p.first << " : " << p.second << "\n";
    }

    // Sort using std::sort with a lambda comparing the .second field
    sort(studentScores.begin(), studentScores.end(), 
         [](const pair<string, int> &a, const pair<string, int> &b) {
             return a.second < b.second; // Ascending by second field
         });

    cout << "\n--- Sorted by Score (Ascending) ---\n";
    for (const auto &p : studentScores) {
        cout << "  " << setw(10) << left << p.first << " : " << p.second << "\n";
    }

    return 0;
}
