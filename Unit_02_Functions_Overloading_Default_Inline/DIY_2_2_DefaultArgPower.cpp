/**
 * Unit 2 - DIY Question 2: Default-Argument Calculator
 * 
 * Problem Statement:
 * Write power(int base, int exp = 2) so power(5) gives 25
 * and power(2, 10) gives 1024.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_2_2_DefaultArgPower.cpp -o DIY_2_2
 *   ./DIY_2_2
 */

#include <iostream>
using namespace std;

// exp defaults to 2; only the base is mandatory
long long power(int base, int exp = 2) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 2 - DIY 2: DEFAULT ARGUMENT POWER CALCULATOR \n";
    cout << "====================================================\n";

    // Test default argument (exp defaults to 2)
    cout << "Calling power(5)       [exp defaults to 2] -> " << power(5) << " (Expected: 25)\n";

    // Test explicit argument
    cout << "Calling power(2, 10)   [exp specified as 10] -> " << power(2, 10) << " (Expected: 1024)\n";

    // Additional tests
    cout << "Calling power(3, 4)    [3^4]               -> " << power(3, 4) << " (Expected: 81)\n";
    cout << "Calling power(10)      [10^2 default]      -> " << power(10) << " (Expected: 100)\n";

    return 0;
}
