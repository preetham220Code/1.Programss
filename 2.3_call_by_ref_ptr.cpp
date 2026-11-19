
#include <iostream>
using namespace std;

// Call-by-reference: outputs min and max via references
// Clean, no pointer syntax, cannot be null, syntactically transparent
void minMax(const int a[], int n, int &mn, int &mx) {
    mn = mx = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
}

// Call-by-pointer: outputs min and max via explicit pointers
// Requires dereferencing (*mn, *mx) and passing addresses (&lo, &hi)
void minMaxPtr(const int a[], int n, int *mn, int *mx) {
    if (!mn || !mx) return; // defensive null check
    *mn = *mx = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < *mn) *mn = a[i];
        if (a[i] > *mx) *mx = a[i];
    }
}

int main() {
    int data[] = {7, 2, 9, 4, 1};
    int n = sizeof(data) / sizeof(data[0]);
    int lo = 0, hi = 0;

    cout << "============================================================\n";
    cout << "  EXPERIMENT 2.3: CALL-BY-REFERENCE VS CALL-BY-POINTER      \n";
    cout << "============================================================\n";
    cout << "Input Array: [ ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << (i < n - 1 ? ", " : " ");
    }
    cout << "]\n\n";

    // 1. Using Call-by-reference
    minMax(data, n, lo, hi);
    cout << "1. Call-by-Reference result: min = " << lo << ", max = " << hi << "\n";

    // Reset values to demonstrate pointer version
    lo = hi = 0;

    // 2. Using Call-by-pointer
    minMaxPtr(data, n, &lo, &hi);
    cout << "2. Call-by-Pointer   result: min = " << lo << ", max = " << hi << "\n";

    cout << "\nConclusion: Both techniques allow returning multiple values,\n"
         << "but C++ references provide cleaner syntax and avoid null-pointer risks.\n";

    return 0;
}
