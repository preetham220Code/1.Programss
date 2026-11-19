/**
 * Unit 12 - DIY Question 3: Custom Aggregate with std::accumulate and Lambdas
 * 
 * Problem Statement:
 * Use accumulate with a lambda to compute the product of all elements,
 * or the sum of only the even ones.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_12_3_CustomAggregateLambda.cpp -o DIY_12_3
 *   ./DIY_12_3
 */

#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

using namespace std;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 12 - DIY 3: ACCUMULATE WITH LAMBDAS          \n";
    cout << "====================================================\n";

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "Numbers: [ ";
    for (int x : nums) cout << x << " ";
    cout << "]\n\n";

    // 1. Compute product of all elements using accumulate with a lambda
    long long product = accumulate(nums.begin(), nums.end(), 1LL, 
        [](long long total, int val) {
            return total * val;
        });

    cout << "1. Product of all elements: " << product 
         << " (Expected: 1*2*3*4*5*6*7*8 = 40320)\n";

    // 2. Compute sum of ONLY even elements using accumulate with a lambda
    int sumOfEvens = accumulate(nums.begin(), nums.end(), 0, 
        [](int sum, int val) {
            return (val % 2 == 0) ? (sum + val) : sum;
        });

    cout << "2. Sum of only even numbers (2 + 4 + 6 + 8): " 
         << sumOfEvens << " (Expected: 20)\n";

    return 0;
}
