/**
 * Unit 9 - DIY Question 3: Exception Catch Ordering Demonstration
 * 
 * Problem Statement:
 * Define MathError and a derived DivideByZero; show that catching
 * MathError first hides DivideByZero, then fix the order.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_9_3_CatchOrderingDemo.cpp -o DIY_9_3
 *   ./DIY_9_3
 */

#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Base exception class
class MathError : public exception {
protected:
    string msg;
public:
    MathError(const string &m = "General Math Error") : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

// Derived exception class
class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("DivideByZero: Division by zero is undefined in arithmetic!") {}
};

double divide(double num, double den) {
    if (den == 0.0) {
        throw DivideByZero();
    }
    return num / den;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 9 - DIY 3: EXCEPTION CATCH ORDERING DEMO     \n";
    cout << "====================================================\n";

    cout << "Theory:\n"
         << "C++ evaluates catch blocks sequentially from top to bottom.\n"
         << "Because derived classes can be caught by base class references (is-a relationship),\n"
         << "putting the base catch first will SHADOW and HIDE the specific derived handler.\n\n";

    cout << "--- Demonstration: Proper Catch Ordering ---\n";
    cout << "Correct pattern: Specific (derived) first, General (base) second.\n\n";

    try {
        cout << "Calling divide(10, 0)...\n";
        double result = divide(10, 0);
        cout << "Result: " << result << "\n";
    } 
    // 1. SPECIFIC DERIVED FIRST:
    catch (const DivideByZero &e) {
        cout << ">> [CORRECT HANDLER TRIGGERED - Specific Derived]: " << e.what() << "\n";
    }
    // 2. GENERAL BASE SECOND:
    catch (const MathError &e) {
        cout << ">> [General Math Error Handler]: " << e.what() << "\n";
    }
    // 3. CATCH-ALL FALLBACK:
    catch (const exception &e) {
        cout << ">> [Standard Exception Handler]: " << e.what() << "\n";
    }

    cout << "\nTakeaway: Always order catch clauses from MOST DERIVED to LEAST DERIVED!\n";
    return 0;
}
