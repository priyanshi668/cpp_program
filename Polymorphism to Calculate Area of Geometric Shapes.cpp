#include <iostream>
#include <cmath>  // For M_PI (π constant)
using namespace std;

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area (to be overridden in derived classes)
    virtual double area() const {
        return 0.0;  // Default implementation returns 0
    }

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Overridden area function for Circle
    double area() const override {
        return M_PI * radius * radius;  // Area of a circle = π * r^2
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overridden area function for Rectangle
    double area() const override {
        return length * width;  // Area of a rectangle = length * width
    }
};

int main() {
    // Create base class pointers to derived class objects
    Shape* shape1 = new Circle(5.0);  // Circle with radius 5
    Shape* shape2 = new Rectangle(4.0, 6.0);  // Rectangle with length 4 and width 6

    // Demonstrate polymorphism: calling the overridden area() function
    cout << "Area of Circle: " << shape1->area() << endl;  // Calls Circle's area
    cout << "Area of Rectangle: " << shape2->area() << endl;  // Calls Rectangle's area

    // Deallocate memory
    delete shape1;
    delete shape2;

    return 0;
}
