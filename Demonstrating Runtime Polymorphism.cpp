#include <iostream>
#include <cmath>
using namespace std;

// Base class Shape with a virtual function
class Shape {
public:
    // Virtual function to calculate the area of the shape
    virtual double area() const = 0;  // Pure virtual function (making Shape an abstract class)

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius of the circle
    Circle(double r) : radius(r) {}

    // Override the area function for Circle
    double area() const override {
        return M_PI * radius * radius;  // Area of a circle: πr²
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;

public:
    // Constructor to initialize side of the square
    Square(double s) : side(s) {}

    // Override the area function for Square
    double area() const override {
        return side * side;  // Area of a square: side²
    }
};

int main() {
    // Creating pointers to base class Shape
    Shape* shape1 = new Circle(5.0);  // Circle object with radius 5
    Shape* shape2 = new Square(4.0);  // Square object with side 4

    // Using polymorphism to calculate and display areas
    cout << "Area of Circle: " << shape1->area() << endl;  // Runtime polymorphism
    cout << "Area of Square: " << shape2->area() << endl;  // Runtime polymorphism

    // Deallocate memory
    delete shape1;
    delete shape2;

    return 0;
}
