/**
 * Unit 8 - DIY Question 3: Prove the Bug - Virtual Destructor Memory Leak
 * 
 * Problem Statement:
 * Build a Base/Derived pair where Derived allocates memory; show the leak
 * when the destructor is not virtual, then fix it (use g++ -fsanitize=address).
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_8_3_VirtualDestructorLeakProof.cpp -o DIY_8_3
 *   ./DIY_8_3
 */

#include <iostream>
using namespace std;

// Base class with VIRTUAL destructor (the fix)
class BaseSafe {
public:
    BaseSafe() { cout << "  BaseSafe constructed\n"; }
    virtual ~BaseSafe() { cout << "  BaseSafe destructed\n"; }
};

// Derived class allocating dynamic memory
class DerivedSafe : public BaseSafe {
private:
    int *largeBuffer;

public:
    DerivedSafe() {
        largeBuffer = new int[1000];
        cout << "  DerivedSafe constructed (allocated 1000 ints)\n";
    }

    ~DerivedSafe() override {
        delete[] largeBuffer;
        cout << "  DerivedSafe destructed (freed 1000 ints safely)\n";
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 8 - DIY 3: VIRTUAL DESTRUCTOR LEAK FIX PROOF \n";
    cout << "====================================================\n";

    cout << "Explanation of the Bug:\n"
         << "When a derived class object is deleted through a pointer to Base,\n"
         << "if ~Base() is NOT marked virtual, the compiler performs static binding\n"
         << "and ONLY executes ~Base(). The ~Derived() destructor NEVER runs, leaking\n"
         << "all resources allocated in Derived!\n\n";

    cout << "Demonstrating the FIX with 'virtual ~BaseSafe()':\n";
    BaseSafe *ptr = new DerivedSafe();

    cout << "\nDeleting Derived object via BaseSafe* pointer:\n";
    delete ptr;

    cout << "\nNotice that BOTH ~DerivedSafe() and ~BaseSafe() executed cleanly!\n"
         << "Rule: Always make base class destructors virtual if classes have virtual methods.\n";

    return 0;
}
