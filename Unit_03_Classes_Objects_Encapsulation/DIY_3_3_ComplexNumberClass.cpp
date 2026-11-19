/**
 * Unit 3 - DIY Question 3: Complex Number Class
 * 
 * Problem Statement:
 * Store real and imag, provide setData() and display(); print a small
 * array of complex numbers. (You will overload + for this class in Week 6.)
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_3_3_ComplexNumberClass.cpp -o DIY_3_3
 *   ./DIY_3_3
 */

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i\n";
        } else {
            cout << real << " - " << -imag << "i\n";
        }
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 3 - DIY 3: COMPLEX NUMBER CLASS & ARRAY      \n";
    cout << "====================================================\n";

    const int SIZE = 4;
    Complex numbers[SIZE];

    // Initialize array of complex numbers using setData()
    numbers[0].setData(3.5, 4.2);
    numbers[1].setData(-2.0, 7.8);
    numbers[2].setData(5.0, -6.3);
    numbers[3].setData(0.0, -1.5);

    cout << "Displaying Array of Complex Numbers:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Number " << (i + 1) << " : ";
        numbers[i].display();
    }

    return 0;
}
