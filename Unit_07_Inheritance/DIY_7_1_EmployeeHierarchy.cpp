/**
 * Unit 7 - DIY Question 1: Employee Hierarchy
 * 
 * Problem Statement:
 * Base Employee (name, id); derive Manager (adds team size) and Engineer
 * (adds skill); print details of each.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_7_1_EmployeeHierarchy.cpp -o DIY_7_1
 *   ./DIY_7_1
 */

#include <iostream>
#include <string>

using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &empName, int empId) : name(empName), id(empId) {}

    void display() const {
        cout << "ID: " << id << " | Name: " << name;
    }
};

// Derived class: Manager
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string &name, int id, int size) 
        : Employee(name, id), teamSize(size) {}

    void display() const {
        cout << "[Manager ] ";
        Employee::display();
        cout << " | Team Size: " << teamSize << " members\n";
    }
};

// Derived class: Engineer
class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(const string &name, int id, const string &domainSkill) 
        : Employee(name, id), skill(domainSkill) {}

    void display() const {
        cout << "[Engineer] ";
        Employee::display();
        cout << " | Domain Skill: " << skill << "\n";
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 7 - DIY 1: EMPLOYEE INHERITANCE HIERARCHY   \n";
    cout << "====================================================\n";

    Manager m("Ramesh Sharma", 101, 15);
    Engineer e1("Priya Nair", 204, "C++ & SystemVerilog UVM");
    Engineer e2("Arjun Mehta", 205, "Embedded Linux & RTOS");

    m.display();
    e1.display();
    e2.display();

    return 0;
}
