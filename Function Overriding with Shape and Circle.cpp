#include <iostream>
#include <cmath>  // For M_PI
using namespace std;

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area (this will be overridden)
    virtual double area() const {
        cout << "Area of shape is not defined." << endl;
        return 0.0;
    }

    // Virtual function to calculate perimeter (this will be overridden)
    virtual double perimeter() const {
        cout << "Perimeter of shape is not defined." << endl;
        return 0.0;
    }

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class Circle that overrides base class methods
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize the radius of the circle
    Circle(double r) : radius(r) {}

    // Override area function for Circle
    double area() const override {
        return M_PI * radius * radius;  // Area of circle = πr²
    }

    // Override perimeter function for Circle
    double perimeter() const override {
        return 2 * M_PI * radius;  // Perimeter of circle = 2πr
    }
};

int main() {
    // Create a Shape pointer to hold the Circle object
    Shape* shapePtr;

    // Create a Circle object
    Circle circle(5.0);

    // Point the Shape pointer to the Circle object
    shapePtr = &circle;

    // Call overridden functions using base class pointer
    cout << "Area of Circle: " << shapePtr->area() << endl;
    cout << "Perimeter of Circle: " << shapePtr->perimeter() << endl;

    return 0;
}
