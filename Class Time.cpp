#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

    // Normalize time (e.g., 75 minutes => 1 hour 15 minutes)
    void normalize() {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        } else if (minutes < 0) {
            int h = (abs(minutes) + 59) / 60;
            hours -= h;
            minutes += h * 60;
        }

        if (hours < 0) {
            hours = 0;
            minutes = 0;
        }
    }

public:
    // Constructors
    Time() : hours(0), minutes(0) {}
    Time(int h, int m) : hours(h), minutes(m) {
        normalize();
    }

    // Display time
    void display() const {
        cout << hours << " hr " << minutes << " min" << endl;
    }

    // Add time
    Time add(const Time& t) const {
        Time result;
        result.hours = hours + t.hours;
        result.minutes = minutes + t.minutes;
        result.normalize();
        return result;
    }

    // Subtract time
    Time subtract(const Time& t) const {
        int total1 = hours * 60 + minutes;
        int total2 = t.hours * 60 + t.minutes;
        int diff = total1 - total2;
        return Time(diff / 60, diff % 60);
    }

    // Compare time (returns 1 if this > t, -1 if this < t, 0 if equal)
    int compare(const Time& t) const {
        if (hours > t.hours || (hours == t.hours && minutes > t.minutes)) {
            return 1;
        } else if (hours < t.hours || (hours == t.hours && minutes < t.minutes)) {
            return -1;
        } else {
            return 0;
        }
    }
};

// Driver code
int main() {
    Time t1(2, 50);
    Time t2(1, 30);

    cout << "Time 1: ";
    t1.display();

    cout << "Time 2: ";
    t2.display();

    Time t3 = t1.add(t2);
    cout << "\nAddition: ";
    t3.display();

    Time t4 = t1.subtract(t2);
    cout << "Subtraction: ";
    t4.display();

    cout << "Comparison: ";
    int cmp = t1.compare(t2);
    if (cmp == 1)
        cout << "Time 1 is greater than Time 2" << endl;
    else if (cmp == -1)
        cout << "Time 1 is less than Time 2" << endl;
    else
        cout << "Time 1 is equal to Time 2" << endl;

    return 0;
}
