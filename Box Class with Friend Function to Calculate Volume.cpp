#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor to initialize the box dimensions
    Box(double l = 1, double w = 1, double h = 1) {
        length = l;
        width = w;
        height = h;
    }

    // Friend function to calculate the volume of two boxes
    friend double calculateVolume(Box &box1, Box &box2);

    // Method to display box dimensions
    void display() const {
        cout << "Length: " << length << ", Width: " << width << ", Height: " << height << endl;
    }
};

// Friend function to calculate the volume of two boxes
double calculateVolume(Box &box1, Box &box2) {
    double volume1 = box1.length * box1.width * box1.height;
    double volume2 = box2.length * box2.width * box2.height;

    cout << "Volume of Box 1: " << volume1 << endl;
    cout << "Volume of Box 2: " << volume2 << endl;

    return volume1 + volume2;  // Return the combined volume
}

int main() {
    // Create two Box objects
    Box box1(3.0, 4.0, 5.0);
    Box box2(2.0, 3.0, 6.0);

    // Display the dimensions of both boxes
    cout << "Box 1 dimensions: ";
    box1.display();
    cout << "Box 2 dimensions: ";
    box2.display();

    // Calculate and display the total volume using the friend function
    double totalVolume = calculateVolume(box1, box2);
    cout << "Total Volume of both boxes: " << totalVolume << endl;

    return 0;
}
