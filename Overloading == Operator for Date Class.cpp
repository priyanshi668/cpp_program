#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor to initialize the date
    Date(int d = 1, int m = 1, int y = 2000) {
        day = d;
        month = m;
        year = y;
    }

    // Overloading the "==" operator to compare two dates
    bool operator==(const Date &other) {
        return (day == other.day && month == other.month && year == other.year);
    }

    // Method to display the date
    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    // Creating two Date objects
    Date date1(15, 5, 2023);
    Date date2(15, 5, 2023);
    Date date3(16, 5, 2023);

    // Comparing dates using overloaded "==" operator
    if (date1 == date2) {
        cout << "date1 and date2 are the same." << endl;
    } else {
        cout << "date1 and date2 are different." << endl;
    }

    if (date1 == date3) {
        cout << "date1 and date3 are the same." << endl;
    } else {
        cout << "date1 and date3 are different." << endl;
    }

    return 0;
}
