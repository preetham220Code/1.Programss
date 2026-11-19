/**
 * Unit 8 - DIY Question 2: Polymorphic Logger
 * 
 * Problem Statement:
 * Abstract Logger with write(string); derive ConsoleLogger and FileLogger;
 * switch at run time.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_8_2_PolymorphicLogger.cpp -o DIY_8_2
 *   ./DIY_8_2
 */

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

// Abstract Logger interface
class Logger {
public:
    virtual void write(const string &msg) = 0;
    virtual ~Logger() {}
};

// Concrete ConsoleLogger
class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override {
        cout << "[CONSOLE LOG] " << msg << "\n";
    }
};

// Concrete FileLogger
class FileLogger : public Logger {
private:
    string filename;

public:
    FileLogger(const string &file) : filename(file) {}

    void write(const string &msg) override {
        ofstream out(filename, ios::app);
        if (out.is_open()) {
            out << "[FILE LOG] " << msg << "\n";
            cout << "[LOGGED TO FILE: " << filename << "] " << msg << "\n";
        }
    }
};

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 8 - DIY 2: POLYMORPHIC RUNTIME LOGGER SWITCH \n";
    cout << "====================================================\n";

    ConsoleLogger consoleLog;
    FileLogger fileLog("app_log.txt");

    Logger *activeLogger = nullptr;

    // Switch to Console Logger
    cout << "1. Selecting Console Logger at runtime:\n";
    activeLogger = &consoleLog;
    activeLogger->write("System initialization started.");
    activeLogger->write("Connecting to database: OK");

    // Switch to File Logger dynamically
    cout << "\n2. Switching to File Logger dynamically at runtime:\n";
    activeLogger = &fileLog;
    activeLogger->write("Transaction #10294 processed successfully.");
    activeLogger->write("System shutdown initiated.");

    cout << "\nSuccessfully demonstrated runtime polymorphism without changing caller code!\n";
    return 0;
}
