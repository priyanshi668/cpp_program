#include <iostream>
using namespace std;

// Class definition for Box
class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor to initialize the Box dimensions
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Member function to calculate the volume of the Box
    double volume() const {
        return length * width * height;
    }

    // Member function that returns the current object using the 'this' pointer
    Box& setDimensions(double l, double w, double h) {
        // Set the new dimensions of the Box using 'this' pointer
        this->length = l;
        this->width = w;
        this->height = h;
        return *this;  // Return the current object using the 'this' pointer
    }

    // Member function to display the Box details
    void display() const {
        cout << "Length: " << length << ", Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    // Create a Box object
    Box box1(3.0, 4.0, 5.0);

    // Display original Box dimensions and volume
    cout << "Original Box:" << endl;
    box1.display();
    cout << "Volume: " << box1.volume() << endl;

    // Modify Box dimensions using the setDimensions function and return the current object
    box1.setDimensions(6.0, 7.0, 8.0).display();  // Chaining using the returned object
    cout << "Volume after modification: " << box1.volume() << endl;

    return 0;
}
