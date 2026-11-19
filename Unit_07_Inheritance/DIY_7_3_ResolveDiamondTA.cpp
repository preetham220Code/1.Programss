/**
 * Unit 7 - DIY Question 3: Resolve Diamond Inheritance with Virtual Base
 * 
 * Problem Statement:
 * Build Person -> Student, Person -> Employee, then TA (teaching assistant)
 * inheriting both; use a virtual base so Person appears once.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_7_3_ResolveDiamondTA.cpp -o DIY_7_3
 *   ./DIY_7_3
 */

#include <iostream>
#include <string>

using namespace std;

// Base Person
class Person {
protected:
    string name;
    int age;

public:
    Person(const string &n, int a) : name(n), age(a) {
        cout << "  [Person Constructor] Initialized: " << name << ", Age: " << age << "\n";
    }

    virtual ~Person() {}

    void printPerson() const {
        cout << "Name: " << name << " | Age: " << age;
    }
};

// Virtual inheritance prevents duplication of Person subobject
class Student : virtual public Person {
protected:
    string usn;

public:
    Student(const string &n, int a, const string &u) 
        : Person(n, a), usn(u) {
        cout << "  [Student Constructor] USN: " << usn << "\n";
    }
};

// Virtual inheritance prevents duplication of Person subobject
class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(const string &n, int a, int id) 
        : Person(n, a), empId(id) {
        cout << "  [Employee Constructor] EmpId: " << empId << "\n";
    }
};

// Most derived class TA: directly initializes the virtual base Person
class TA : public Student, public Employee {
private:
    string course;

public:
    TA(const string &n, int a, const string &u, int id, const string &c)
        : Person(n, a), Student(n, a, u), Employee(n, a, id), course(c) {
        cout << "  [TA Constructor] Assigned Course: " << course << "\n";
    }

    void displayTA() const {
        cout << "\n--- Teaching Assistant Details ---\n";
        printPerson(); // No ambiguity! Only one Person subobject exists.
        cout << "\nUSN             : " << usn 
             << "\nEmployee ID     : " << empId 
             << "\nAssigned Course : " << course << "\n";
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 7 - DIY 3: RESOLVING DIAMOND INHERITANCE     \n";
    cout << "====================================================\n";

    cout << "Creating TA object:\n";
    TA ta("Aditi Roy", 23, "1RV24EC001", 9021, "ECE121 - C++ OOP Lab");

    ta.displayTA();

    cout << "\nSuccess: Person was initialized exactly ONCE without duplicate state or ambiguity!\n";
    return 0;
}
