#include <iostream>
using namespace std;

// Base class Vehicle
class Vehicle {
public:
    // Virtual function to display the type of vehicle (to be overridden by derived classes)
    virtual void displayType() const = 0;

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Vehicle() {}
};

// Derived class Car
class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor to initialize the number of doors
    Car(int d) : doors(d) {}

    // Override the displayType function for the Car class
    void displayType() const override {
        cout << "This is a Car with " << doors << " doors." << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle {
private:
    bool hasCarrier;

public:
    // Constructor to initialize whether the bike has a carrier
    Bike(bool carrier) : hasCarrier(carrier) {}

    // Override the displayType function for the Bike class
    void displayType() const override {
        cout << "This is a Bike" << (hasCarrier ? " with a carrier." : " without a carrier.") << endl;
    }
};

int main() {
    // Create objects of Car and Bike
    Car car(4);  // A car with 4 doors
    Bike bike(true);  // A bike with a carrier

    // Call the displayType method for each vehicle
    car.displayType();
    bike.displayType();

    return 0;
}
