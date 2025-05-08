#include <iostream>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;

public:
    // Constructor
    Car(string m, string mo, int y) {
        make = m;
        model = mo;
        year = y;
    }

    // Method to display car details
    void displayDetails() {
        cout << "Car Details:" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create an object of Car
    Car myCar("Toyota", "Camry", 2022);

    // Display the car details
    myCar.displayDetails();

    return 0;
}
