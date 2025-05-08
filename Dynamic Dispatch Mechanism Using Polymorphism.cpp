#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function to be overridden in derived classes
    virtual void draw() const {
        cout << "Drawing a shape\n";
    }

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Shape() {
        cout << "Shape destroyed\n";
    }
};

// Derived class: Circle
class Circle : public Shape {
public:
    // Overriding the draw function
    void draw() const override {
        cout << "Drawing a circle\n";
    }

    ~Circle() {
        cout << "Circle destroyed\n";
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    // Overriding the draw function
    void draw() const override {
        cout << "Drawing a rectangle\n";
    }

    ~Rectangle() {
        cout << "Rectangle destroyed\n";
    }
};

// Main function to demonstrate dynamic dispatch
int main() {
    // Create an array of shape pointers, pointing to different derived types
    Shape* shapes[3];
    shapes[0] = new Shape();      // Base class object
    shapes[1] = new Circle();     // Derived class object
    shapes[2] = new Rectangle();  // Derived class object

    // Demonstrating dynamic dispatch
    for (int i = 0; i < 3; ++i) {
        shapes[i]->draw();  // Calls the appropriate draw function based on the actual object type
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];  // Virtual destructor ensures proper cleanup
    }

    return 0;
}
