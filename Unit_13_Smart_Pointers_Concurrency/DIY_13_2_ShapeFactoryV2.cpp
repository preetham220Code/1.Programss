/**
 * Unit 13 - DIY Question 2: Shape Factory v2 with Triangle & User Choice
 * 
 * Problem Statement:
 * Extend Program 13.1 with a Triangle and let the user type the shape name
 * at run time; store the created shapes in a vector<unique_ptr<Shape>>.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_13_2_ShapeFactoryV2.cpp -o DIY_13_2
 *   ./DIY_13_2
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Abstract Base Shape
struct Shape {
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() {}
};

// Derived: Circle
struct Circle : Shape {
    double r;
    Circle(double r) : r(r) {}
    double area() const override { return 3.1415926535 * r * r; }
    string name() const override { return "Circle (r=" + to_string(r) + ")"; }
};

// Derived: Square
struct Square : Shape {
    double s;
    Square(double s) : s(s) {}
    double area() const override { return s * s; }
    string name() const override { return "Square (side=" + to_string(s) + ")"; }
};

// Extended Derived: Triangle
struct Triangle : Shape {
    double base;
    double height;
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    string name() const override { return "Triangle (b=" + to_string(base) + ", h=" + to_string(height) + ")"; }
};

// Factory function returning unique_ptr<Shape>
unique_ptr<Shape> makeShape(const string &kind) {
    if (kind == "circle") return make_unique<Circle>(4.0);
    if (kind == "square") return make_unique<Square>(5.0);
    if (kind == "triangle") return make_unique<Triangle>(6.0, 8.0);
    return nullptr;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 13 - DIY 2: EXTENDED SHAPE FACTORY V2        \n";
    cout << "====================================================\n";

    vector<unique_ptr<Shape>> shapes;

    cout << "Populating factory with Circle, Square, and Triangle:\n";
    shapes.push_back(makeShape("circle"));
    shapes.push_back(makeShape("square"));
    shapes.push_back(makeShape("triangle"));

    cout << "\n--- Polymorphic Shapes in vector<unique_ptr<Shape>> ---\n";
    cout << fixed << setprecision(2);
    for (const auto &s : shapes) {
        if (s) {
            cout << "  " << setw(28) << left << s->name() 
                 << " -> Area = " << s->area() << "\n";
        }
    }

    return 0;
}
