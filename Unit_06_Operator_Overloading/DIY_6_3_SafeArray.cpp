/**
 * Unit 6 - DIY Question 3: Safe Array with Bounds Checking
 * 
 * Problem Statement:
 * A class wrapping a dynamic array; overload operator[] to throw / report
 * an error on out-of-range access instead of corrupting memory.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_6_3_SafeArray.cpp -o DIY_6_3
 *   ./DIY_6_3
 */

#include <iostream>
#include <stdexcept>

using namespace std;

class SafeArray {
private:
    int *data;
    int capacity;

public:
    SafeArray(int cap) : capacity(cap) {
        data = new int[capacity]();
    }

    ~SafeArray() {
        delete[] data;
    }

    int size() const { return capacity; }

    // Overload operator[] for non-const objects (read/write)
    int& operator[](int index) {
        if (index < 0 || index >= capacity) {
            throw out_of_range("Index " + to_string(index) + 
                               " is out of bounds! Valid range is [0, " + 
                               to_string(capacity - 1) + "]");
        }
        return data[index];
    }

    // Overload operator[] for const objects (read-only)
    const int& operator[](int index) const {
        if (index < 0 || index >= capacity) {
            throw out_of_range("Index " + to_string(index) + 
                               " is out of bounds! Valid range is [0, " + 
                               to_string(capacity - 1) + "]");
        }
        return data[index];
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 6 - DIY 3: BOUNDS-SAFE ARRAY OPERATOR[]      \n";
    cout << "====================================================\n";

    SafeArray arr(5);

    // Populate elements
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = (i + 1) * 10;
    }

    cout << "SafeArray contents:\n";
    for (int i = 0; i < arr.size(); ++i) {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    // Testing out-of-bounds access
    cout << "\n--- Testing Bounds Protection ---\n";
    try {
        cout << "Attempting to access arr[2] (valid): " << arr[2] << "\n";
        cout << "Attempting to access arr[10] (out of bounds)...\n";
        int val = arr[10]; // Will throw out_of_range exception
        cout << "Value: " << val << "\n";
    } catch (const out_of_range &e) {
        cout << ">> Caught expected exception: " << e.what() << "\n";
    }

    try {
        cout << "Attempting to access arr[-1] (negative index)...\n";
        arr[-1] = 99; // Will throw out_of_range exception
    } catch (const out_of_range &e) {
        cout << ">> Caught expected exception: " << e.what() << "\n";
    }

    cout << "\nMemory integrity was 100% protected against corruption!\n";
    return 0;
}
