/**
 * Unit 4 - DIY Question 3: Lifetime Logger
 * 
 * Problem Statement:
 * Extend Program 4.1 so each Tracer is created with new inside a loop
 * and deleted – observe how forgetting delete leaks (run with g++ -fsanitize=address).
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_4_3_LifetimeLogger.cpp -o DIY_4_3
 *   ./DIY_4_3
 */

#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) {
        cout << "  Construct Tracer #" << id << " at address " << this << "\n";
    }

    ~Tracer() {
        cout << "  Destruct  Tracer #" << id << " at address " << this << "\n";
    }

    void action() const {
        cout << "    [Tracer #" << id << " doing work]\n";
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 4 - DIY 3: LIFETIME LOGGER (HEAP ALLOCATION) \n";
    cout << "====================================================\n";

    cout << "--- Part 1: Correct Heap Allocation with delete ---\n";
    for (int i = 1; i <= 3; ++i) {
        cout << "Iteration " << i << ":\n";
        Tracer *t = new Tracer(i); // Heap allocation
        t->action();
        delete t;                  // Immediate deallocation ensures destructor runs
    }

    cout << "\n--- Part 2: Demonstration of Memory Leak Risk ---\n";
    cout << "If we allocate with 'new' and forget 'delete':\n";
    Tracer *leaked = new Tracer(999);
    leaked->action();
    // Intentionally commented out: // delete leaked;
    cout << "[Notice] Tracer #999 was never deleted. Its destructor was NOT called!\n";
    cout << "In production code or with -fsanitize=address, this reports a heap leak.\n";
    cout << "Cleaning up Tracer #999 now to maintain clean exit:\n";
    delete leaked;

    return 0;
}
