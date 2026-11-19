/**
 * Unit 3 - DIY Question 2: Counter Array
 * 
 * Problem Statement:
 * A Counter class with increment(), reset() and get(); create an array
 * of 3 counters and exercise them.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_3_2_CounterArray.cpp -o DIY_3_2
 *   ./DIY_3_2
 */

#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int initial = 0) : count(initial) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 3 - DIY 2: ARRAY OF COUNTER OBJECTS          \n";
    cout << "====================================================\n";

    const int NUM_COUNTERS = 3;
    Counter counters[NUM_COUNTERS]; // Array of 3 Counter objects

    // Exercise counter 0: increment 5 times
    for (int i = 0; i < 5; ++i) counters[0].increment();

    // Exercise counter 1: increment 12 times
    for (int i = 0; i < 12; ++i) counters[1].increment();

    // Exercise counter 2: increment 8 times, then reset, then increment 2 times
    for (int i = 0; i < 8; ++i) counters[2].increment();
    counters[2].reset();
    counters[2].increment();
    counters[2].increment();

    // Display state of all counters
    cout << "State of all counters after exercising:\n";
    for (int i = 0; i < NUM_COUNTERS; ++i) {
        cout << "Counter [" << i << "] value = " << counters[i].get() << "\n";
    }

    return 0;
}
