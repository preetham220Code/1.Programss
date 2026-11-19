/**
 * Unit 13 - DIY Question 1: Raw to Smart Pointers (unique_ptr)
 * 
 * Problem Statement:
 * Take any Week-4 program that used new/delete and rewrite it with
 * unique_ptr so no explicit delete remains.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_13_1_RawToSmartUniquePtr.cpp -o DIY_13_1
 *   ./DIY_13_1
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Resource class demonstrating RAII lifecycle
class DeviceBuffer {
private:
    string name;
    unique_ptr<int[]> buffer; // Smart pointer manages heap array automatically
    int size;

public:
    DeviceBuffer(const string &n, int s) : name(n), size(s) {
        buffer = make_unique<int[]>(size); // Heap allocation via smart pointer
        cout << "  [+Construct] DeviceBuffer '" << name << "' created with " << size << " words\n";
    }

    // No explicit delete required in destructor! unique_ptr cleans up buffer automatically
    ~DeviceBuffer() {
        cout << "  [-Destruct ] DeviceBuffer '" << name << "' destroyed safely without explicit delete!\n";
    }

    void set(int idx, int val) {
        if (idx >= 0 && idx < size) buffer[idx] = val;
    }

    int get(int idx) const {
        if (idx >= 0 && idx < size) return buffer[idx];
        return -1;
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 13 - DIY 1: ZERO-LEAK RAII WITH UNIQUE_PTR   \n";
    cout << "====================================================\n";

    {
        cout << "Entering scope with std::unique_ptr:\n";
        // make_unique creates and wraps the object in a unique_ptr
        auto dev = make_unique<DeviceBuffer>("UART_FIFO", 16);
        dev->set(0, 0xAA);
        dev->set(1, 0x55);
        cout << "  Readback: word[0] = 0x" << hex << dev->get(0) 
             << ", word[1] = 0x" << dev->get(1) << dec << "\n";
        cout << "Leaving scope now -> destructor runs automatically:\n";
    }

    cout << "\nScope exited. Memory safely reclaimed with zero manual delete!\n";
    return 0;
}
