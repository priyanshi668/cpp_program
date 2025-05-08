#include <iostream>
using namespace std;

// Abstract class Vehicle with pure virtual functions
class Vehicle {
public:
    // Pure virtual function for starting the vehicle
    virtual void start() = 0;

    // Pure virtual function for stopping the vehicle
    virtual void stop() = 0;

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Vehicle() {}
};

// Derived class Car
class Car : public Vehicle {
public:
    // Implementing the pure virtual functions for Car
    void start() override {
        cout << "Car is starting..." << endl;
    }

    void stop() override {
        cout << "Car is stopping..." << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle {
public:
    // Implementing the pure virtual functions for Bike
    void start() override {
        cout << "Bike is starting..." << endl;
    }

    void stop() override {
        cout << "Bike is stopping..." << endl;
    }
};

int main() {
    // Creating objects of Car and Bike
    Vehicle* vehicle1 = new Car();  // Creating a Car object
    Vehicle* vehicle2 = new Bike(); // Creating a Bike object

    // Using polymorphism to call start and stop methods
    vehicle1->start();
    vehicle1->stop();

    vehicle2->start();
    vehicle2->stop();

    // Deallocate memory
    delete vehicle1;
    delete vehicle2;

    return 0;
}
