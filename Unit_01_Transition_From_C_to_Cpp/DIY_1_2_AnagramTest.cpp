/**
 * Unit 1 - DIY Question 2: Anagram Test
 * 
 * Problem Statement:
 * Read two words and decide whether one is an anagram of the other
 * (hint: count character frequencies, or sort both).
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_1_2_AnagramTest.cpp -o DIY_1_2
 *   ./DIY_1_2
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

// Function to clean string: lowercase only alphabets
string cleanString(const string &s) {
    string cleaned = "";
    for (char c : s) {
        if (isalpha(static_cast<unsigned char>(c))) {
            cleaned += tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

// Method 1: Using Sorting
bool isAnagramSort(string s1, string s2) {
    s1 = cleanString(s1);
    s2 = cleanString(s2);
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// Method 2: Frequency Count (O(N) time)
bool isAnagramFreq(const string &s1, const string &s2) {
    string c1 = cleanString(s1);
    string c2 = cleanString(s2);
    if (c1.length() != c2.length()) return false;

    vector<int> freq(26, 0);
    for (char c : c1) freq[c - 'a']++;
    for (char c : c2) freq[c - 'a']--;

    for (int count : freq) {
        if (count != 0) return false;
    }
    return true;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 1 - DIY 2: ANAGRAM TEST                      \n";
    cout << "====================================================\n";

    string w1, w2;
    cout << "Enter first word  (or press enter for default 'listen'): ";
    getline(cin, w1);
    if (w1.empty()) w1 = "listen";

    cout << "Enter second word (or press enter for default 'silent'): ";
    getline(cin, w2);
    if (w2.empty()) w2 = "silent";

    cout << "\nComparing: \"" << w1 << "\" and \"" << w2 << "\"\n";

    bool result = isAnagramFreq(w1, w2);
    if (result) {
        cout << ">> RESULT: YES! They ARE anagrams of each other.\n";
    } else {
        cout << ">> RESULT: NO! They are NOT anagrams.\n";
    }

    return 0;
}
