/**
 * Unit 10 - DIY Question 2: Line-Numbered File Copy
 * 
 * Problem Statement:
 * Read in.txt and write out.txt with each line prefixed by its line number.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_10_2_LineNumberedCopy.cpp -o DIY_10_2
 *   ./DIY_10_2
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Helper to ensure in.txt exists
void createSampleInputFile(const string &filename) {
    ifstream check(filename);
    if (!check.is_open()) {
        ofstream sample(filename);
        sample << "Object-Oriented Programming in C++\n"
               << "Electronics and Communication Engineering\n"
               << "Lab manual DIY code generation\n"
               << "Ready for VS Code direct execution\n";
        cout << "[Setup] Created sample input file: '" << filename << "'\n";
    }
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 10 - DIY 2: LINE-NUMBERED FILE COPY          \n";
    cout << "====================================================\n";

    const string inFilename = "in.txt";
    const string outFilename = "out.txt";

    createSampleInputFile(inFilename);

    ifstream inFile(inFilename);
    if (!inFile.is_open()) {
        cerr << "[Error] Could not open '" << inFilename << "' for reading!\n";
        return 1;
    }

    ofstream outFile(outFilename);
    if (!outFile.is_open()) {
        cerr << "[Error] Could not open '" << outFilename << "' for writing!\n";
        inFile.close();
        return 1;
    }

    string line;
    int lineNum = 1;

    cout << "Copying lines from '" << inFilename << "' to '" << outFilename << "'...\n";
    while (getline(inFile, line)) {
        outFile << lineNum << ": " << line << "\n";
        lineNum++;
    }

    inFile.close();
    outFile.close();

    cout << "Copied " << (lineNum - 1) << " lines successfully!\n\n";

    // Read back out.txt to display on console
    cout << "--- Contents of '" << outFilename << "' ---\n";
    ifstream checkOut(outFilename);
    string resultLine;
    while (getline(checkOut, resultLine)) {
        cout << resultLine << "\n";
    }
    checkOut.close();

    return 0;
}
