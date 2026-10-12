#include <iostream>
using namespace std;

class Counter {
    int v;
public:
    Counter(int v = 0) : v(v) {}
    
    // Pre-increment operator (++c)
    Counter& operator++() { 
        ++v; 
        return *this; 
    }
    
    // Post-increment operator (c++)
    Counter operator++(int) { 
        Counter t = *this; 
        ++v; 
        return t; 
    }
    
    int value() const { 
        return v; 
    }
};

class SafeArr {
    int a[5] = {10, 20, 30, 40, 50};
public:
    // Bounds-checked subscript operator ([])
    int& operator[](int i) {
        if (i < 0 || i >= 5) { 
            cout << "out of range!\n"; 
            return a[0]; 
        }
        return a[i];
    }
};

int main() {
    Counter c(5); 
    ++c; 
    c++; // 5 -> 6 -> 7
    cout << "Counter = " << c.value() << endl;
    
    SafeArr s; 
    cout << "s[2] = " << s[2] << endl; // Prints 30
    s[10] = 99; // Triggers bounds check and prints "out of range!"
    
    return 0;
}
