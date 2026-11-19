/**
 * Unit 9 - DIY Question 2: Stack with Custom Overflow and Underflow Exceptions
 * 
 * Problem Statement:
 * Give your Week-4 Stack custom Overflow and Underflow exceptions
 * and handle them in main.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_9_2_StackExceptions.cpp -o DIY_9_2
 *   ./DIY_9_2
 */

#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Custom Stack Overflow Exception
class StackOverflowException : public exception {
    string msg;
public:
    StackOverflowException(int val, int cap) {
        msg = "StackOverflowException: Cannot push " + to_string(val) + 
              "; capacity of " + to_string(cap) + " elements exceeded!";
    }
    const char* what() const noexcept override { return msg.c_str(); }
};

// Custom Stack Underflow Exception
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: Cannot pop or peek from an empty stack!";
    }
};

class Stack {
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    Stack(int cap = 3) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (topIndex == capacity - 1) {
            throw StackOverflowException(val, capacity);
        }
        arr[++topIndex] = val;
        cout << "  Pushed: " << val << "\n";
    }

    int pop() {
        if (topIndex == -1) {
            throw StackUnderflowException();
        }
        return arr[topIndex--];
    }

    int peek() const {
        if (topIndex == -1) {
            throw StackUnderflowException();
        }
        return arr[topIndex];
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 9 - DIY 2: STACK OVERFLOW & UNDERFLOW        \n";
    cout << "====================================================\n";

    Stack s(3); // Small capacity of 3 to demonstrate exceptions easily

    // Demonstration 1: Causing and catching Overflow
    try {
        cout << "Pushing elements into stack of capacity 3:\n";
        s.push(10);
        s.push(20);
        s.push(30);
        cout << "Attempting to push 4th element (should throw overflow):\n";
        s.push(40); // Will throw StackOverflowException
    } catch (const StackOverflowException &e) {
        cout << ">> [Handled] " << e.what() << "\n\n";
    }

    // Demonstration 2: Emptying stack and causing Underflow
    try {
        cout << "Popping elements:\n";
        cout << "  Popped: " << s.pop() << "\n";
        cout << "  Popped: " << s.pop() << "\n";
        cout << "  Popped: " << s.pop() << "\n";
        cout << "Attempting to pop from now-empty stack:\n";
        s.pop(); // Will throw StackUnderflowException
    } catch (const StackUnderflowException &e) {
        cout << ">> [Handled] " << e.what() << "\n";
    }

    return 0;
}
