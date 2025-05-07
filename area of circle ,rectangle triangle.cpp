#include <iostream>
#include <cmath>  // for M_PI
using namespace std;

// Overloaded function for circle area
double area(double radius) {
    return M_PI * radius * radius;
}

// Overloaded function for rectangle area
double area(double length, double width) {
    return length * width;
}

// Overloaded function for triangle area
double area(double base, double height, char type) {
    return 0.5 * base * height;
}

int main() {
    double radius = 5.0;
    double length = 10.0, width = 4.0;
    double base = 6.0, height = 3.0;

    cout << "Area of circle: " << area(radius) << endl;
    cout << "Area of rectangle: " << area(length, width) << endl;
    cout << "Area of triangle: " << area(base, height, 't') << endl;

    return 0;
}
