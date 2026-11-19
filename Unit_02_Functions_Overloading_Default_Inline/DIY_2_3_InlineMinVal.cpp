/**
 * Unit 2 - DIY Question 3: Inline Min
 * 
 * Problem Statement:
 * Write an inline overloaded minVal returning the smaller of two ints
 * and, via a second overload, the smallest of three ints.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_2_3_InlineMinVal.cpp -o DIY_2_3
 *   ./DIY_2_3
 */

#include <iostream>
using namespace std;

// Inline overload for 2 integers: eliminates function call overhead
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Inline overload for 3 integers: reuses the 2-parameter overload
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 2 - DIY 3: INLINE OVERLOADED MINVAL          \n";
    cout << "====================================================\n";

    int x = 45, y = 18, z = 32;

    cout << "Values: x = " << x << ", y = " << y << ", z = " << z << "\n\n";

    // Overload 1 (2 arguments)
    cout << "1. minVal(x, y)       -> " << minVal(x, y) << "\n";

    // Overload 2 (3 arguments)
    cout << "2. minVal(x, y, z)    -> " << minVal(x, y, z) << "\n";

    // Additional test cases
    cout << "3. minVal(100, 200)   -> " << minVal(100, 200) << "\n";
    cout << "4. minVal(99, 12, -5) -> " << minVal(99, 12, -5) << "\n";

    return 0;
}
