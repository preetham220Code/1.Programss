/**
 * Unit 1 - DIY Question 1: Vowel & Consonant Counter
 * 
 * Problem Statement:
 * Read a sentence with getline(cin, s) and print how many vowels and
 * consonants it contains.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_1_1_VowelConsonantCounter.cpp -o DIY_1_1
 *   ./DIY_1_1
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 1 - DIY 1: VOWEL & CONSONANT COUNTER         \n";
    cout << "====================================================\n";

    cout << "Enter a sentence (or press enter for default test): ";
    string s;
    getline(cin, s);

    if (s.empty()) {
        s = "Object-Oriented Programming in C++ with Lab!";
        cout << "Using default sentence: \"" << s << "\"\n";
    }

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int others = 0;

    for (char ch : s) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char lower = tolower(static_cast<unsigned char>(ch));
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(static_cast<unsigned char>(ch))) {
            digits++;
        } else if (isspace(static_cast<unsigned char>(ch))) {
            spaces++;
        } else {
            others++;
        }
    }

    cout << "\n--- Analysis Results ---\n";
    cout << "Total Characters : " << s.length() << "\n";
    cout << "Vowels           : " << vowels << "\n";
    cout << "Consonants       : " << consonants << "\n";
    cout << "Digits           : " << digits << "\n";
    cout << "Spaces           : " << spaces << "\n";
    cout << "Punctuation/Other: " << others << "\n";

    return 0;
}
