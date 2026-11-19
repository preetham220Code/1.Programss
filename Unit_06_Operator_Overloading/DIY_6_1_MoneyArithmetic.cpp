/**
 * Unit 6 - DIY Question 1: Money Arithmetic
 * 
 * Problem Statement:
 * A Money class (rupees, paise); overload + and - with correct carry/borrow
 * of paise into rupees.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_6_1_MoneyArithmetic.cpp -o DIY_6_1
 *   ./DIY_6_1
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Money {
private:
    long rupees;
    int paise;

    // Normalizes paise into range [0, 99], handling carry and borrow
    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            long borrow = (-paise + 99) / 100;
            rupees -= borrow;
            paise += borrow * 100;
        }
        if (rupees < 0 && paise > 0) {
            rupees += 1;
            paise -= 100;
        }
    }

public:
    Money(long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    // Overload + operator
    Money operator+(const Money &other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    // Overload - operator
    Money operator-(const Money &other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    // Overload << operator for elegant formatting
    friend ostream& operator<<(ostream &os, const Money &m) {
        os << "Rs. " << m.rupees << "." 
           << setfill('0') << setw(2) << m.paise;
        return os;
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 6 - DIY 1: MONEY ARITHMETIC (+ and -)        \n";
    cout << "====================================================\n";

    Money m1(15, 75); // Rs 15.75
    Money m2(10, 50); // Rs 10.50
    Money m3(4, 80);  // Rs 4.80

    cout << "m1 = " << m1 << "\n";
    cout << "m2 = " << m2 << "\n";
    cout << "m3 = " << m3 << "\n\n";

    // Addition with carry
    Money sum = m1 + m2;
    cout << "m1 + m2 = " << sum << " (Expected: Rs. 26.25)\n";

    // Subtraction with borrow
    Money diff1 = m1 - m3;
    cout << "m1 - m3 = " << diff1 << " (Expected: Rs. 10.95)\n";

    // Subtraction requiring borrow from rupees
    Money m4(5, 20);
    Money m5(2, 60);
    Money diff2 = m4 - m5;
    cout << "m4 (Rs. 5.20) - m5 (Rs. 2.60) = " << diff2 << " (Expected: Rs. 2.60)\n";

    return 0;
}
