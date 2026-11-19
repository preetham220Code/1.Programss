/**
 * Unit 9 - DIY Question 1: Safe Withdrawal with Custom Exception
 * 
 * Problem Statement:
 * Extend the Week-3 BankAccount to throw a custom InsufficientFunds
 * exception instead of returning false.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_9_1_SafeWithdrawalException.cpp -o DIY_9_1
 *   ./DIY_9_1
 */

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

using namespace std;

// Custom exception class derived from std::exception
class InsufficientFundsException : public exception {
private:
    string errorMsg;
    double requested;
    double currentBalance;

public:
    InsufficientFundsException(double req, double bal) 
        : requested(req), currentBalance(bal) {
        errorMsg = "Insufficient Funds: Attempted to withdraw Rs. " + 
                   to_string(req) + ", but available balance is only Rs. " + 
                   to_string(bal) + "!";
    }

    const char* what() const noexcept override {
        return errorMsg.c_str();
    }

    double getRequested() const { return requested; }
    double getBalance() const { return currentBalance; }
};

// Safe Bank Account class
class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(const string &name, double initialBal) 
        : owner(name), balance(initialBal > 0 ? initialBal : 0) {}

    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }

    // Throws InsufficientFundsException if withdrawal exceeds balance
    void withdraw(double amt) {
        if (amt <= 0) {
            cout << "[Warning] Invalid withdrawal amount.\n";
            return;
        }
        if (amt > balance) {
            throw InsufficientFundsException(amt, balance);
        }
        balance -= amt;
        cout << "[Success] Withdrew Rs. " << fixed << setprecision(2) << amt 
             << ". Remaining Balance: Rs. " << balance << "\n";
    }

    double getBalance() const { return balance; }
    string getOwner() const { return owner; }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 9 - DIY 1: CUSTOM EXCEPTION SAFE WITHDRAWAL  \n";
    cout << "====================================================\n";

    BankAccount acc("Preetham", 15000.00);
    cout << "Account Owner: " << acc.getOwner() << " | Balance: Rs. " << acc.getBalance() << "\n\n";

    // 1. Normal valid withdrawal
    try {
        cout << "Attempting withdrawal of Rs. 5000.00...\n";
        acc.withdraw(5000.00);
    } catch (const InsufficientFundsException &e) {
        cout << ">> Exception caught: " << e.what() << "\n";
    }

    // 2. Overdraft withdrawal triggering custom exception
    try {
        cout << "\nAttempting withdrawal of Rs. 18000.00 (Exceeds Balance)...\n";
        acc.withdraw(18000.00); // Throws InsufficientFundsException
    } catch (const InsufficientFundsException &e) {
        cout << ">> [CAUGHT EXCEPTION] " << e.what() << "\n";
        cout << "   Requested : Rs. " << e.getRequested() << "\n";
        cout << "   Available : Rs. " << e.getBalance() << "\n";
    }

    cout << "\nCurrent balance after operations: Rs. " << acc.getBalance() << "\n";
    return 0;
}
