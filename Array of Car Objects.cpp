#include <iostream>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;

public:
    // Default constructor
    Car() {
        make = "";
        model = "";
        year = 0;
    }

    // Parameterized constructor
    Car(string m, string mo, int y) {
        make = m;
        model = mo;
        year = y;
    }

    // Method to display car details
    void displayDetails() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
    // Create an array of Car objects
    Car cars[3] = {
        Car("Toyota", "Corolla", 2020),
        Car("Honda", "Civic", 2021),
        Car("Ford", "Focus", 2019)
    };

    cout << "Car Details:\n";
    for (int i = 0; i < 3; i++) {
        cars[i].displayDetails();
    }

    return 0;
}
