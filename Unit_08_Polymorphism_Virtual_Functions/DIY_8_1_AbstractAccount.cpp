/**
 * Unit 8 - DIY Question 1: Abstract Account and Polymorphic Interest
 * 
 * Problem Statement:
 * Pure-virtual calculateInterest(); derive Savings and Current with different
 * rates; process an array of Account*.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_8_1_AbstractAccount.cpp -o DIY_8_1
 *   ./DIY_8_1
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Abstract Base Class
class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string &accNo, double bal) : accountNumber(accNo), balance(bal) {}

    // Pure virtual function makes Account abstract
    virtual double calculateInterest() const = 0;

    // Virtual destructor is vital for polymorphic base classes
    virtual ~Account() {}

    virtual void display() const {
        cout << "Account: " << accountNumber 
             << " | Balance: Rs. " << fixed << setprecision(2) << balance;
    }
};

// Derived Savings Account (4% annual interest)
class SavingsAccount : public Account {
public:
    SavingsAccount(const string &accNo, double bal) : Account(accNo, bal) {}

    double calculateInterest() const override {
        return balance * 0.04; // 4%
    }

    void display() const override {
        cout << "[Savings] ";
        Account::display();
        cout << " | Interest (4%): Rs. " << calculateInterest() << "\n";
    }
};

// Derived Current Account (1.5% interest on balance)
class CurrentAccount : public Account {
public:
    CurrentAccount(const string &accNo, double bal) : Account(accNo, bal) {}

    double calculateInterest() const override {
        return balance * 0.015; // 1.5%
    }

    void display() const override {
        cout << "[Current] ";
        Account::display();
        cout << " | Interest (1.5%): Rs. " << calculateInterest() << "\n";
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 8 - DIY 1: ABSTRACT BASE & RUNTIME DISPATCH  \n";
    cout << "====================================================\n";

    // Polymorphic array of base pointers
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount("SB-10023", 50000.00));
    accounts.push_back(new CurrentAccount("CA-90412", 250000.00));
    accounts.push_back(new SavingsAccount("SB-88310", 12000.00));

    cout << "Processing accounts through base Account* pointer:\n\n";
    for (const auto *acc : accounts) {
        acc->display(); // Dynamic binding resolves to correct derived method
    }

    // Clean up heap memory
    for (auto *acc : accounts) {
        delete acc;
    }

    return 0;
}
