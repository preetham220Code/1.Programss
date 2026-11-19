/**
 * Unit 4 - DIY Question 2: Stack with Destructor
 * 
 * Problem Statement:
 * An integer Stack backed by a dynamic array; push/pop plus a destructor
 * that releases the buffer.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_4_2_StackWithDestructor.cpp -o DIY_4_2
 *   ./DIY_4_2
 */

#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    // Constructor allocating dynamic buffer
    Stack(int cap = 5) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
        cout << "[Stack] Created stack with capacity " << capacity << "\n";
    }

    // Destructor releasing dynamic buffer
    ~Stack() {
        delete[] arr;
        cout << "[Stack] Destructor executed: dynamic buffer released safely\n";
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "[Error] Stack Overflow! Cannot push " << val << "\n";
            return;
        }
        arr[++topIndex] = val;
        cout << "Pushed: " << val << "\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "[Error] Stack Underflow! Returning -1\n";
            return -1;
        }
        int val = arr[topIndex--];
        cout << "Popped: " << val << "\n";
        return val;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "[Notice] Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 4 - DIY 2: DYNAMIC STACK WITH DESTRUCTOR     \n";
    cout << "====================================================\n";

    {
        Stack s(4);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50); // triggers overflow

        cout << "Top element is: " << s.peek() << "\n";

        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop(); // triggers underflow

        cout << "\nLeaving scope...\n";
    }

    cout << "Stack destroyed cleanly without leaks.\n";
    return 0;
}
