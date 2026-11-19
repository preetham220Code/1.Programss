/**
 * Unit 11 - DIY Question 2: Generic Queue Class Template
 * 
 * Problem Statement:
 * Implement a class template Queue<T> with enqueue/dequeue/front; test with string.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_11_2_GenericQueue.cpp -o DIY_11_2
 *   ./DIY_11_2
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    vector<T> elements;

public:
    void enqueue(const T &item) {
        elements.push_back(item);
        cout << "  Enqueued: " << item << "\n";
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue Underflow: cannot dequeue from empty queue");
        }
        T frontItem = elements.front();
        elements.erase(elements.begin());
        return frontItem;
    }

    T front() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty: cannot peek front");
        }
        return elements.front();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 11 - DIY 2: GENERIC QUEUE<T> TEMPLATE        \n";
    cout << "====================================================\n";

    cout << "--- Testing Queue<string> ---\n";
    Queue<string> stringQueue;

    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.enqueue("Charlie");
    stringQueue.enqueue("Diana");

    cout << "\nCurrent Front Element: " << stringQueue.front() << "\n";
    cout << "Queue Size           : " << stringQueue.size() << "\n\n";

    cout << "Dequeuing all items:\n";
    while (!stringQueue.isEmpty()) {
        cout << "  Dequeued: " << stringQueue.dequeue() << "\n";
    }

    cout << "\n--- Testing Queue<int> ---\n";
    Queue<int> intQueue;
    intQueue.enqueue(100);
    intQueue.enqueue(200);
    intQueue.enqueue(300);
    cout << "Dequeued from intQueue: " << intQueue.dequeue() << "\n";
    cout << "Front is now          : " << intQueue.front() << "\n";

    return 0;
}
