/**
 * Unit 11 - DIY Question 1: Generic Utilities (swapVals & findMax)
 * 
 * Problem Statement:
 * Write template functions swapVals(T&,T&) and findMax(T arr[], int n)
 * and test with int and double.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_11_1_GenericUtilities.cpp -o DIY_11_1
 *   ./DIY_11_1
 */

#include <iostream>
#include <string>

using namespace std;

// Function template to swap two values of any type
template <typename T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Function template to find maximum element in an array
template <typename T>
T findMax(const T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 11 - DIY 1: GENERIC TEMPLATE UTILITIES       \n";
    cout << "====================================================\n";

    // Test with integers
    int i1 = 25, i2 = 80;
    cout << "--- Integer Tests ---\n";
    cout << "Before swap: i1 = " << i1 << ", i2 = " << i2 << "\n";
    swapVals(i1, i2);
    cout << "After swap : i1 = " << i1 << ", i2 = " << i2 << "\n";

    int intArr[] = {14, 82, 33, 99, 45};
    cout << "Max in intArr: " << findMax(intArr, 5) << " (Expected: 99)\n\n";

    // Test with doubles
    double d1 = 3.1415, d2 = 2.7182;
    cout << "--- Double Tests ---\n";
    cout << "Before swap: d1 = " << d1 << ", d2 = " << d2 << "\n";
    swapVals(d1, d2);
    cout << "After swap : d1 = " << d1 << ", d2 = " << d2 << "\n";

    double dblArr[] = {1.25, 9.81, 3.14, 7.62, 5.56};
    cout << "Max in dblArr: " << findMax(dblArr, 5) << " (Expected: 9.81)\n\n";

    // Test with strings
    string s1 = "Alpha", s2 = "Omega";
    cout << "--- String Tests ---\n";
    swapVals(s1, s2);
    cout << "Swapped strings: s1 = " << s1 << ", s2 = " << s2 << "\n";

    string strArr[] = {"Apple", "Zebra", "Mango", "Banana"};
    cout << "Max in strArr (lexicographical): " << findMax(strArr, 4) << " (Expected: Zebra)\n";

    return 0;
}
