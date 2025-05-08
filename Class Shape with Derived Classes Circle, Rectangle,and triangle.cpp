#include <iostream>
#include <cmath> // For M_PI
using namespace std;

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area (to be overridden by derived classes)
    virtual double area() const = 0;

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Override the area function to calculate the area of the circle
    double area() const override {
        return M_PI * radius * radius;  // Area of a circle: π * r^2
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the area function to calculate the area of the rectangle
    double area() const override {
        return length * width;  // Area of a rectangle: length * width
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    // Constructor to initialize base and height
    Triangle(double b, double h) : base(b), height(h) {}

    // Override the area function to calculate the area of the triangle
    double area() const override {
        return 0.5 * base * height;  // Area of a triangle: 0.5 * base * height
    }
};

int main() {
    // Create objects of each derived class
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0);

    // Calculate and display the areas of the shapes
    cout << "Area of Circle: " << circle.area() << endl;
    cout << "Area of Rectangle: " << rectangle.area() << endl;
    cout << "Area of Triangle: " << triangle.area() << endl;

    return 0;
}
