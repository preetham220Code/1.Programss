/**
 * Unit 13 - DIY Question 3: Prove the Race Condition vs Thread Mutex
 * 
 * Problem Statement:
 * Run Program 13.3 without the lock_guard, observe the wrong total
 * over several runs, then restore the lock and confirm 200000.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -pthread -Wall DIY_13_3_ThreadRaceMutexProof.cpp -o DIY_13_3
 *   ./DIY_13_3
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

long unsafeCounter = 0;
long safeCounter = 0;
mutex mtx;

const int ITERATIONS = 100000;

// Unsafe increment: unprotected critical section causes race condition
void addUnsafe() {
    for (int i = 0; i < ITERATIONS; ++i) {
        ++unsafeCounter; // Data race! Read-modify-write is not atomic.
    }
}

// Safe increment: protected with std::lock_guard
void addSafe() {
    for (int i = 0; i < ITERATIONS; ++i) {
        lock_guard<mutex> lock(mtx); // RAII lock guarantees mutual exclusion
        ++safeCounter;
    }
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 13 - DIY 3: RACE CONDITION VS MUTEX PROOF    \n";
    cout << "====================================================\n";

    cout << "Starting 2 threads with 100,000 iterations each (Expected total: 200,000).\n\n";

    // 1. Without lock: Race Condition Demo
    cout << "--- 1. Running WITHOUT Lock (Data Race) ---\n";
    unsafeCounter = 0;
    thread t1(addUnsafe);
    thread t2(addUnsafe);
    t1.join();
    t2.join();
    cout << "Unsafe Counter = " << unsafeCounter 
         << " (Expected: 200000 | Difference/Lost updates: " 
         << (200000 - unsafeCounter) << ")\n";

    // 2. With lock: Thread-safe Mutex Demo
    cout << "\n--- 2. Running WITH lock_guard (Thread-Safe) ---\n";
    safeCounter = 0;
    thread t3(addSafe);
    thread t4(addSafe);
    t3.join();
    t4.join();
    cout << "Safe Counter   = " << safeCounter << " (Guaranteed exact 200000!)\n";

    cout << "\nConclusion: lock_guard prevents data races and ensures correct synchronization.\n";
    return 0;
}
