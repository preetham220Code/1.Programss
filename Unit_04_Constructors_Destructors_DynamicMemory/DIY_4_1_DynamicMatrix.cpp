/**
 * Unit 4 - DIY Question 1: Dynamic Matrix with Deep Copy
 * 
 * Problem Statement:
 * A Matrix class that allocates an m x n grid with new, provides a deep
 * copy constructor, and frees it in the destructor.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_4_1_DynamicMatrix.cpp -o DIY_4_1
 *   ./DIY_4_1
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **data;

    void allocate() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols](); // zero-initialized
        }
    }

    void deallocate() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
        allocate();
        cout << "[Constructor] Allocated " << rows << "x" << cols << " matrix\n";
    }

    // Deep Copy Constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(nullptr) {
        allocate();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        cout << "[Deep Copy Constructor] Copied " << rows << "x" << cols << " matrix\n";
    }

    // Destructor
    ~Matrix() {
        deallocate();
        cout << "[Destructor] Deallocated matrix memory\n";
    }

    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }

    int get(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }
        return 0;
    }

    void display(const string &title = "Matrix") const {
        cout << title << " (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            cout << "  [ ";
            for (int j = 0; j < cols; ++j) {
                cout << setw(3) << data[i][j] << " ";
            }
            cout << "]\n";
        }
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 4 - DIY 1: DYNAMIC MATRIX WITH DEEP COPY     \n";
    cout << "====================================================\n";

    {
        Matrix m1(2, 3);
        m1.set(0, 0, 10); m1.set(0, 1, 20); m1.set(0, 2, 30);
        m1.set(1, 0, 40); m1.set(1, 1, 50); m1.set(1, 2, 60);
        m1.display("Original Matrix m1");

        // Deep copy
        Matrix m2 = m1;
        m2.display("Copied Matrix m2");

        // Modify m2 to prove it does not affect m1
        cout << "\nModifying m2[0][0] = 999...\n";
        m2.set(0, 0, 999);

        m1.display("Original Matrix m1 (remains 10 at [0][0])");
        m2.display("Copied Matrix m2   (has 999 at [0][0])");
        cout << "\nExiting inner block -> destructors will be invoked...\n";
    }

    cout << "Returned safely to main. No double-free crash!\n";
    return 0;
}
