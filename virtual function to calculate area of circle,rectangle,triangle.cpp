#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual void input() = 0;           // Pure virtual function for input
    virtual double area() const = 0;    // Pure virtual function for area
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    void input() override {
        cout << "Enter radius of the circle: ";
        cin >> radius;
    }

    double area() const override {
        return M_PI * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    void input() override {
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
    }

    double area() const override {
        return length * width;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base, height;
public:
    void input() override {
        cout << "Enter base and height of the triangle: ";
        cin >> base >> height;
    }

    double area() const override {
        return 0.5 * base * height;
    }
};

// Example usage
int main() {
    Shape* shape;

    // Circle
    shape = new Circle();
    shape->input();
    cout << "Area of Circle: " << shape->area() << "\n";
    delete shape;

    // Rectangle
    shape = new Rectangle();
    shape->input();
    cout << "Area of Rectangle: " << shape->area() << "\n";
    delete shape;

    // Triangle
    shape = new Triangle();
    shape->input();
    cout << "Area of Triangle: " << shape->area() << "\n";
    delete shape;

    return 0;
}
