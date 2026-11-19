/**
 * Unit 2 - DIY Question 1: Overloaded Volume
 * 
 * Problem Statement:
 * Write three overloads computing the volume of:
 * 1. Cube (1 arg: side)
 * 2. Cuboid (3 args: length, width, height)
 * 3. Cylinder (2 args: radius, height)
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_2_1_OverloadedVolume.cpp -o DIY_2_1
 *   ./DIY_2_1
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

// 1. Cube: volume = side^3
double volume(double side) {
    return side * side * side;
}

// 2. Cuboid: volume = length * width * height
double volume(double length, double width, double height) {
    return length * width * height;
}

// 3. Cylinder: volume = pi * r^2 * height
double volume(double radius, double height) {
    return PI * radius * radius * height;
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 2 - DIY 1: OVERLOADED VOLUME FUNCTIONS       \n";
    cout << "====================================================\n";
    cout << fixed << setprecision(3);

    // Cube
    double side = 4.0;
    cout << "1. Cube with side = " << side 
         << " -> Volume = " << volume(side) << "\n";

    // Cuboid
    double l = 5.0, w = 3.0, h = 6.0;
    cout << "2. Cuboid with L=" << l << ", W=" << w << ", H=" << h
         << " -> Volume = " << volume(l, w, h) << "\n";

    // Cylinder
    double r = 3.5, cylH = 10.0;
    cout << "3. Cylinder with radius=" << r << ", height=" << cylH
         << " -> Volume = " << volume(r, cylH) << "\n";

    return 0;
}
