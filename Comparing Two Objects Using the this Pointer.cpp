#include <iostream>
using namespace std;

// Class definition for Counter
class Counter {
private:
    int count;

public:
    // Constructor to initialize the counter value
    Counter(int c) : count(c) {}

    // Member function to compare two Counter objects using the 'this' pointer
    bool isEqualTo(const Counter& other) const {
        // Compare the current object with the 'other' object
        return this->count == other.count;  // 'this' pointer is implicitly used here
    }

    // Method to display the count
    void displayCount() const {
        cout << "Count: " << count << endl;
    }
};

int main() {
    // Create two Counter objects with different values
    Counter counter1(10);
    Counter counter2(20);
    Counter counter3(10);

    // Display count values
    counter1.displayCount();
    counter2.displayCount();
    counter3.displayCount();

    // Compare counter1 with counter2 using the isEqualTo member function
    if (counter1.isEqualTo(counter2)) {
        cout << "counter1 and counter2 have the same count." << endl;
    } else {
        cout << "counter1 and counter2 have different counts." << endl;
    }

    // Compare counter1 with counter3 using the isEqualTo member function
    if (counter1.isEqualTo(counter3)) {
        cout << "counter1 and counter3 have the same count." << endl;
    } else {
        cout << "counter1 and counter3 have different counts." << endl;
    }

    return 0;
}
