/**
 * Unit 5 - DIY Question 1: Static Object Counter
 * 
 * Problem Statement:
 * Add a static member to your Week-3 Counter class that reports how many
 * Counter objects have ever been created and how many are currently alive.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_5_1_ObjectCounter.cpp -o DIY_5_1
 *   ./DIY_5_1
 */

#include <iostream>
using namespace std;

class Counter {
private:
    int value;
    static int totalCreated;   // Tracks all objects ever instantiated
    static int currentlyAlive; // Tracks active objects currently in memory

public:
    Counter(int val = 0) : value(val) {
        totalCreated++;
        currentlyAlive++;
        cout << "  [+Construct] Counter instance created (Alive: " 
             << currentlyAlive << ", Total: " << totalCreated << ")\n";
    }

    ~Counter() {
        currentlyAlive--;
        cout << "  [-Destruct ] Counter instance destroyed (Alive: " 
             << currentlyAlive << ", Total: " << totalCreated << ")\n";
    }

    void increment() { value++; }
    int get() const { return value; }

    // Static member functions to inspect static members
    static int getTotalCreated() { return totalCreated; }
    static int getCurrentlyAlive() { return currentlyAlive; }
};

// Define and initialize static members outside class definition
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 5 - DIY 1: STATIC OBJECT LIFECYCLE COUNTER   \n";
    cout << "====================================================\n";

    cout << "Initial Status -> Alive: " << Counter::getCurrentlyAlive()
         << ", Total Created: " << Counter::getTotalCreated() << "\n\n";

    Counter c1(10);
    Counter c2(20);

    cout << "\nStatus in outer scope:\n";
    cout << "  Currently Alive: " << Counter::getCurrentlyAlive() << "\n";
    cout << "  Total Created  : " << Counter::getTotalCreated() << "\n\n";

    {
        cout << "Entering nested block scope:\n";
        Counter c3(30);
        Counter c4(40);
        cout << "  Inside block -> Alive: " << Counter::getCurrentlyAlive() 
             << ", Total: " << Counter::getTotalCreated() << "\n";
        cout << "Leaving nested block scope:\n";
    }

    cout << "\nStatus after nested block exits:\n";
    cout << "  Currently Alive: " << Counter::getCurrentlyAlive() << " (Expected: 2)\n";
    cout << "  Total Created  : " << Counter::getTotalCreated() << " (Expected: 4)\n";

    return 0;
}
