#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Constructor to initialize the radius
    Circle(double r = 1) {
        radius = r;
    }

    // Friend function to calculate the area of the circle
    friend double calculateArea(Circle &circle);

    // Method to display the circle's radius
    void display() const {
        cout << "Radius: " << radius << endl;
    }
};

// Friend function to calculate the area of the circle
double calculateArea(Circle &circle) {
    const double PI = 3.14159;
    return PI * circle.radius * circle.radius;
}

int main() {
    // Create a Circle object
    Circle circle(5.0);

    // Display the radius of the circle
    circle.display();

    // Calculate and display the area using the friend function
    double area = calculateArea(circle);
    cout << "Area of the circle: " << area << endl;

    return 0;
}
