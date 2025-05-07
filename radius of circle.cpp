#include <iostream>
#include <cmath> // for M_PI constant
using namespace std;

// Function prototype
double calculateArea(double radius);

int main() {
    double radius;

    // Input the radius of the circle
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Call the function to calculate and display the area
    double area = calculateArea(radius);
    cout << "The area of the circle with radius " << radius << " is: " << area << endl;

    return 0;
}

// Function definition
double calculateArea(double radius) {
    return M_PI * radius * radius; // Formula: Area = π * r^2
}
