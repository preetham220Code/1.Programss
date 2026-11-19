/**
 * Unit 12 - DIY Question 2: Top-3 with Heap (priority_queue)
 * 
 * Problem Statement:
 * Read N numbers and print the three largest using a priority_queue
 * (do not sort the whole array).
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_12_2_Top3HeapPriorityQueue.cpp -o DIY_12_2
 *   ./DIY_12_2
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 12 - DIY 2: TOP-3 LARGEST USING MIN-HEAP     \n";
    cout << "====================================================\n";

    // Dataset of N numbers
    vector<int> numbers = {45, 12, 89, 3, 76, 24, 90, 5, 61, 38, 98, 17, 83};
    const int K = 3;

    cout << "Input Array of " << numbers.size() << " numbers: [ ";
    for (int n : numbers) cout << n << " ";
    cout << "]\n\n";

    // Min-heap of size K: O(N log K) time complexity
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : numbers) {
        minHeap.push(x);
        if (static_cast<int>(minHeap.size()) > K) {
            minHeap.pop(); // Discard the smallest among the (K+1) elements
        }
    }

    // Extract top K elements from heap
    vector<int> top3;
    while (!minHeap.empty()) {
        top3.push_back(minHeap.top());
        minHeap.pop();
    }

    // Reverse to display descending order
    reverse(top3.begin(), top3.end());

    cout << "--- Top " << K << " Largest Elements ---\n";
    for (size_t i = 0; i < top3.size(); ++i) {
        cout << "  Rank " << (i + 1) << " : " << top3[i] << "\n";
    }

    cout << "\nEfficiency Note: Computed in O(N log 3) without sorting the full array!\n";
    return 0;
}
