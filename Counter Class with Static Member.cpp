#include <iostream>
using namespace std;

class Counter {
private:
    static int objectCount;  // Static data member

public:
    // Constructor increments the static counter
    Counter() {
        objectCount++;
    }

    // Static method to access the object count
    static int getObjectCount() {
        return objectCount;
    }
};

// Initialize static member
int Counter::objectCount = 0;

int main() {
    // Create objects
    Counter c1;
    Counter c2;
    Counter c3;

    // Display number of objects created
    cout << "Number of Counter objects created: " << Counter::getObjectCount() << endl;

    return 0;
}
