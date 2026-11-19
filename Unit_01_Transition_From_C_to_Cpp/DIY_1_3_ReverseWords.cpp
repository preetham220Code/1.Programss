/**
 * Unit 1 - DIY Question 3: Reverse the Words
 * 
 * Problem Statement:
 * Read a sentence like "hello world cpp" and print "cpp world hello"
 * (reverse word order, not individual characters).
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_1_3_ReverseWords.cpp -o DIY_1_3
 *   ./DIY_1_3
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 1 - DIY 3: REVERSE WORD ORDER                \n";
    cout << "====================================================\n";

    cout << "Enter a sentence (or press enter for default 'hello world cpp'): ";
    string s;
    getline(cin, s);

    if (s.empty()) {
        s = "hello world cpp";
        cout << "Using default: \"" << s << "\"\n";
    }

    // Split sentence into words using stringstream
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    cout << "\nOriginal Sentence : " << s << "\n";
    cout << "Reversed Words    : ";
    for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
        cout << words[i] << (i > 0 ? " " : "");
    }
    cout << "\n";

    return 0;
}
