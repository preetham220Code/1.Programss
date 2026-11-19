/**
 * Unit 10 - DIY Question 3: Records into Objects and Find Topper
 * 
 * Problem Statement:
 * Store name marks pairs in a file, read them back into an array of
 * Student objects, and print the topper.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_10_3_StudentRecordFile.cpp -o DIY_10_3
 *   ./DIY_10_3
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    double marks;

public:
    Student(const string &n = "", double m = 0.0) : name(n), marks(m) {}

    string getName() const { return name; }
    double getMarks() const { return marks; }

    void display() const {
        cout << "  Student: " << setw(15) << left << name 
             << " | Marks: " << fixed << setprecision(2) << marks << "\n";
    }
};

void createSampleRecords(const string &filename) {
    ofstream file(filename);
    file << "Ananya 94.5\n";
    file << "Vikram 88.0\n";
    file << "Pooja 97.2\n";
    file << "Kiran 91.0\n";
    file << "Suresh 85.5\n";
    cout << "[Setup] Populated student records into '" << filename << "'\n";
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 10 - DIY 3: STUDENT RECORDS FROM FILE        \n";
    cout << "====================================================\n";

    const string filename = "students.txt";
    createSampleRecords(filename);

    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "[Error] Could not open '" << filename << "'\n";
        return 1;
    }

    vector<Student> students;
    string name;
    double marks;

    while (inFile >> name >> marks) {
        students.emplace_back(name, marks);
    }
    inFile.close();

    cout << "\nLoaded " << students.size() << " student records from file:\n";
    for (const auto &s : students) {
        s.display();
    }

    if (students.empty()) {
        cout << "No student records found.\n";
        return 0;
    }

    // Find topper
    const Student *topper = &students[0];
    for (size_t i = 1; i < students.size(); ++i) {
        if (students[i].getMarks() > topper->getMarks()) {
            topper = &students[i];
        }
    }

    cout << "\n🏆 CLASS TOPPER:\n";
    cout << "   Name  : " << topper->getName() << "\n";
    cout << "   Marks : " << topper->getMarks() << " / 100\n";

    return 0;
}
