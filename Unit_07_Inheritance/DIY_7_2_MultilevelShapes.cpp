/**
 * Unit 7 - DIY Question 2: Multilevel Shapes Construction & Destruction Order
 * 
 * Problem Statement:
 * Shape -> Polygon -> Rectangle; each level adds one field; demonstrate
 * the constructor and destructor call order with print statements.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_7_2_MultilevelShapes.cpp -o DIY_7_2
 *   ./DIY_7_2
 */

#include <iostream>
#include <string>

using namespace std;

// Level 1: Base Shape
class Shape {
protected:
    string color;

public:
    Shape(const string &c) : color(c) {
        cout << "  [1. Shape Constructor    ] Color: " << color << "\n";
    }

    virtual ~Shape() {
        cout << "  [1. Shape Destructor     ] Destroyed Shape\n";
    }
};

// Level 2: Derived Polygon
class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(const string &c, int sides) : Shape(c), numSides(sides) {
        cout << "  [2. Polygon Constructor  ] Sides: " << numSides << "\n";
    }

    ~Polygon() override {
        cout << "  [2. Polygon Destructor   ] Destroyed Polygon\n";
    }
};

// Level 3: Derived Rectangle
class Rectangle : public Polygon {
private:
    double length;
    double width;

public:
    Rectangle(const string &c, double l, double w) 
        : Polygon(c, 4), length(l), width(w) {
        cout << "  [3. Rectangle Constructor] Length=" << length << ", Width=" << width << "\n";
    }

    ~Rectangle() override {
        cout << "  [3. Rectangle Destructor ] Destroyed Rectangle\n";
    }

    double area() const { return length * width; }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 7 - DIY 2: MULTILEVEL INHERITANCE ORDER      \n";
    cout << "====================================================\n";

    cout << "--- Constructing Rectangle in local scope ---\n";
    {
        Rectangle rect("Blue", 12.0, 5.0);
        cout << "\nRectangle created successfully. Area = " << rect.area() << "\n\n";
        cout << "--- Leaving local scope -> observe destruction order ---\n";
    }

    cout << "\nNotice:\n"
         << "1. Construction runs Base -> Intermediate -> Derived\n"
         << "2. Destruction runs in exact reverse: Derived -> Intermediate -> Base (LIFO)\n";

    return 0;
}
