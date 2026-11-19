/**
 * Unit 11 - DIY Question 3: Frequency Counter with unordered_map
 * 
 * Problem Statement:
 * Read words from input and use an unordered_map<string,int> to print
 * each word with its count; then print the most frequent word.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_11_3_WordFrequencyCounter.cpp -o DIY_11_3
 *   ./DIY_11_3
 */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <iomanip>

using namespace std;

string cleanWord(const string &w) {
    string cleaned = "";
    for (char c : w) {
        if (isalnum(static_cast<unsigned char>(c))) {
            cleaned += tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 11 - DIY 3: WORD FREQUENCY COUNTER (HASHMAP) \n";
    cout << "====================================================\n";

    cout << "Enter a paragraph (or press enter for default test):\n";
    string text;
    getline(cin, text);

    if (text.empty()) {
        text = "C++ is fast. C++ is powerful and C++ supports object oriented programming. "
               "OOP in C++ makes code reusable and structured.";
        cout << "Using default text:\n\"" << text << "\"\n\n";
    }

    stringstream ss(text);
    string token;
    unordered_map<string, int> freqMap;

    while (ss >> token) {
        string cleaned = cleanWord(token);
        if (!cleaned.empty()) {
            freqMap[cleaned]++;
        }
    }

    cout << "--- Word Frequency Table ---\n";
    string mostFreqWord = "";
    int maxFreq = 0;

    for (const auto &pair : freqMap) {
        cout << "  " << setw(15) << left << pair.first << " : " << pair.second << "\n";
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFreqWord = pair.first;
        }
    }

    cout << "\n🔥 MOST FREQUENT WORD:\n";
    cout << "   Word  : \"" << mostFreqWord << "\"\n";
    cout << "   Count : " << maxFreq << " times\n";

    return 0;
}
