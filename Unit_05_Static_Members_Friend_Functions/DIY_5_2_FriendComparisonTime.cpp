/**
 * Unit 5 - DIY Question 2: Friend Comparison for Time
 * 
 * Problem Statement:
 * Write a Time class (hh:mm) and a friend function laterOf(Time, Time)
 * returning the later of two times.
 * 
 * Compilation & Run:
 *   g++ -std=c++17 -Wall DIY_5_2_FriendComparisonTime.cpp -o DIY_5_2
 *   ./DIY_5_2
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        // Normalize time if minutes >= 60
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        hours %= 24;
    }

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":" 
             << setfill('0') << setw(2) << minutes;
    }

    // Friend function declaration: has access to private members 'hours' and 'minutes'
    friend Time laterOf(const Time &t1, const Time &t2);
};

// Friend function definition
Time laterOf(const Time &t1, const Time &t2) {
    int totalMinutes1 = t1.hours * 60 + t1.minutes;
    int totalMinutes2 = t2.hours * 60 + t2.minutes;

    if (totalMinutes1 >= totalMinutes2) {
        return t1;
    } else {
        return t2;
    }
}

int main() {
    cout << "====================================================\n";
    cout << "  UNIT 5 - DIY 2: FRIEND FUNCTION TIME COMPARISON   \n";
    cout << "====================================================\n";

    Time meeting1(9, 45);
    Time meeting2(11, 15);
    Time meeting3(14, 30);
    Time meeting4(14, 10);

    cout << "Time 1: "; meeting1.display(); cout << "\n";
    cout << "Time 2: "; meeting2.display(); cout << "\n";
    cout << ">> Later of Time 1 and Time 2: ";
    laterOf(meeting1, meeting2).display();
    cout << "\n\n";

    cout << "Time 3: "; meeting3.display(); cout << "\n";
    cout << "Time 4: "; meeting4.display(); cout << "\n";
    cout << ">> Later of Time 3 and Time 4: ";
    laterOf(meeting3, meeting4).display();
    cout << "\n";

    return 0;
}
