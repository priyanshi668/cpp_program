#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Default constructor (sets x and y to 0)
    Point() {
        x = 0;
        y = 0;
    }

    // Parameterized constructor (initializes x and y with given values)
    Point(int a, int b) {
        x = a;
        y = b;
    }

    // Copy constructor (creates a copy of another Point object)
    Point(const Point &p) {
        x = p.x;
        y = p.y;
    }

    // Method to display point coordinates
    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Using default constructor
    Point p1;
    cout << "Default constructor: ";
    p1.display();

    // Using parameterized constructor
    Point p2(3, 4);
    cout << "Parameterized constructor: ";
    p2.display();

    // Using copy constructor
    Point p3 = p2;
    cout << "Copy constructor: ";
    p3.display();

    return 0;
}
