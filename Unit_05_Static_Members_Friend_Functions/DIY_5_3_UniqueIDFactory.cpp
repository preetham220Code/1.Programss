/**
 * Unit 5 - DIY Question 3: Unique ID Factory
 * 
 * Problem Statement:
 * Use a static member so every new Order object automatically receives
 * the next ID (1001, 1002, . . . ) in its constructor.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_5_3_UniqueIDFactory.cpp -o DIY_5_3
 *   ./DIY_5_3
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Order {
private:
    static int nextId;     // Shared across all instances to generate auto-increment IDs
    const int orderId;     // Immutable unique ID assigned upon creation
    string itemName;
    double price;

public:
    // Member initializer list assigns orderId from static nextId
    Order(const string &item, double cost) 
        : orderId(nextId++), itemName(item), price(cost) {}

    void display() const {
        cout << "  Order #" << orderId 
             << " | Item: " << setw(18) << left << itemName 
             << " | Price: Rs. " << fixed << setprecision(2) << price << "\n";
    }

    int getId() const { return orderId; }
};

// Start ID sequence at 1001
int Order::nextId = 1001;

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 5 - DIY 3: UNIQUE AUTO-INCREMENT ID FACTORY  \n";
    cout << "====================================================\n";

    cout << "Creating customer orders:\n\n";

    Order o1("Wireless Mouse", 599.00);
    Order o2("Mechanical Keyboard", 2499.50);
    Order o3("USB-C Hub", 1250.00);
    Order o4("27-inch 4K Monitor", 22000.00);
    Order o5("Noise Canceling Headset", 4500.00);

    o1.display();
    o2.display();
    o3.display();
    o4.display();
    o5.display();

    cout << "\nEvery object received a strictly sequential, unique ID without manual entry!\n";
    return 0;
}
