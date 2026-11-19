
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Parameterized constructor with default arguments
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Takes an object BY CONST REFERENCE, RETURNS a new object BY VALUE
    Point add(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    // 'this' points to the calling object; returning *this enables method chaining
    Point& setX(int v) {
        this->x = v;
        return *this;
    }

    Point& setY(int v) {
        this->y = v;
        return *this;
    }

    void show() const {
        cout << "(" << x << ", " << y << ")\n";
    }
};

// Pass-by-reference: modifies the original caller object
void shift(Point &p) {
    p.setX(99);
}

// Pass-by-value: works on a copy; original object remains untouched
void tryShift(Point p) {
    p.setX(-1);
}

int main() {
    cout << "============================================================\n";
    cout << "  EXPERIMENT 3.3: PASSING & RETURNING OBJECTS; 'this' POINTER\n";
    cout << "============================================================\n";

    Point a(1, 2), b(3, 4);
    cout << "Initial Point a : "; a.show();
    cout << "Initial Point b : "; b.show();

    // 1. Returning an object
    Point c = a.add(b);
    cout << "\n1. Result of c = a.add(b) : ";
    c.show(); // Expected: (4, 6)

    // 2. Method chaining through 'this' pointer
    Point d;
    d.setX(7).setY(8);
    cout << "2. Chaining d.setX(7).setY(8) : ";
    d.show(); // Expected: (7, 8)

    // 3. Passing by reference (modifies original)
    shift(a);
    cout << "3. After shift(a) [Pass-by-Reference] -> a = ";
    a.show(); // Expected: (99, 2) - original changed

    // 4. Passing by value (leaves original unchanged)
    tryShift(b);
    cout << "4. After tryShift(b) [Pass-by-Value] -> b = ";
    b.show(); // Expected: (3, 4) - original unchanged

    return 0;
}
