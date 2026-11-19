/**
 * Unit 3 - DIY Question 1: Rectangle Class with Validation
 * 
 * Problem Statement:
 * Private length and width, public setters with validation (reject negatives),
 * and area()/perimeter() getters.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_3_1_RectangleClass.cpp -o DIY_3_1
 *   ./DIY_3_1
 */

#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor ensuring valid invariants
    Rectangle(double l = 1.0, double w = 1.0) {
        setLength(l);
        setWidth(w);
    }

    // Setters with validation
    bool setLength(double l) {
        if (l > 0.0) {
            length = l;
            return true;
        }
        cout << "[Warning] Invalid length: " << l << " (must be positive). Value unchanged.\n";
        return false;
    }

    bool setWidth(double w) {
        if (w > 0.0) {
            width = w;
            return true;
        }
        cout << "[Warning] Invalid width: " << w << " (must be positive). Value unchanged.\n";
        return false;
    }

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2.0 * (length + width);
    }

    void display() const {
        cout << "Rectangle [ Length = " << length 
             << ", Width = " << width 
             << " | Area = " << area() 
             << ", Perimeter = " << perimeter() << " ]\n";
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 3 - DIY 1: RECTANGLE WITH VALIDATION         \n";
    cout << "====================================================\n";

    Rectangle rect(10.5, 4.0);
    cout << "Initial valid rectangle:\n";
    rect.display();

    cout << "\nAttempting to set invalid negative length (-7.5)...\n";
    rect.setLength(-7.5);
    rect.display();

    cout << "\nAttempting to set valid dimensions (8.0, 5.0)...\n";
    rect.setLength(8.0);
    rect.setWidth(5.0);
    rect.display();

    return 0;
}
