/**
 * Unit 6 - DIY Question 2: Fraction I/O with Stream Overloading and Auto-Simplification
 * 
 * Problem Statement:
 * A Fraction class; overload << and >> and auto-simplify (divide by GCD)
 * on construction.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_6_2_FractionIO.cpp -o DIY_6_2
 *   ./DIY_6_2
 */

#include <iostream>
#include <numeric> // for std::gcd

using namespace std;

class Fraction {
private:
    int num;
    int den;

    // Simplifies fraction using greatest common divisor
    void simplify() {
        if (den == 0) {
            cout << "[Error] Denominator cannot be zero! Resetting to 1.\n";
            den = 1;
        }
        if (den < 0) { // Keep negative sign in numerator
            num = -num;
            den = -den;
        }
        int g = std::gcd(abs(num), abs(den));
        if (g > 1) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    // Overload stream insertion operator <<
    friend ostream& operator<<(ostream &os, const Fraction &f) {
        if (f.den == 1) {
            os << f.num;
        } else {
            os << f.num << "/" << f.den;
        }
        return os;
    }

    // Overload stream extraction operator >>
    friend istream& operator>>(istream &is, Fraction &f) {
        char slash;
        is >> f.num;
        if (is.peek() == '/') {
            is >> slash >> f.den;
        } else {
            f.den = 1;
        }
        f.simplify();
        return is;
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 6 - DIY 2: FRACTION I/O & AUTO-SIMPLIFICATION\n";
    cout << "====================================================\n";

    Fraction f1(12, 16);
    cout << "Fraction(12, 16) auto-simplified -> " << f1 << " (Expected: 3/4)\n";

    Fraction f2(45, -60);
    cout << "Fraction(45, -60) auto-simplified -> " << f2 << " (Expected: -3/4)\n";

    Fraction f3(14, 7);
    cout << "Fraction(14, 7) auto-simplified  -> " << f3 << " (Expected: 2)\n\n";

    cout << "Testing stream extraction (format 'num/den' or just 'num'):\n";
    cout << "Enter a fraction (or press enter for default test): ";
    
    // Test with sample string or stream
    Fraction inputFrac;
    if (cin >> inputFrac) {
        cout << "Parsed and simplified fraction: " << inputFrac << "\n";
    }

    return 0;
}
