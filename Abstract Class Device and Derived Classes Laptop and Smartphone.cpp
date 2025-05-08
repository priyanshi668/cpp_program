#include <iostream>
#include <string>
using namespace std;

// Abstract base class Device
class Device {
public:
    // Pure virtual function to turn on the device
    virtual void turnOn() const = 0;

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Device() {}
};

// Derived class Laptop
class Laptop : public Device {
private:
    string brand;
    string model;

public:
    // Constructor to initialize Laptop details
    Laptop(string br, string mo) : brand(br), model(mo) {}

    // Implement the turnOn function for Laptop
    void turnOn() const override {
        cout << "Turning on the Laptop..." << endl;
        cout << "Brand: " << brand << ", Model: " << model << endl;
        cout << "Laptop is now ON." << endl;
    }
};

// Derived class Smartphone
class Smartphone : public Device {
private:
    string brand;
    string model;

public:
    // Constructor to initialize Smartphone details
    Smartphone(string br, string mo) : brand(br), model(mo) {}

    // Implement the turnOn function for Smartphone
    void turnOn() const override {
        cout << "Turning on the Smartphone..." << endl;
        cout << "Brand: " << brand << ", Model: " << model << endl;
        cout << "Smartphone is now ON." << endl;
    }
};

int main() {
    // Create objects of Laptop and Smartphone
    Device* laptop = new Laptop("Dell", "XPS 13");
    Device* smartphone = new Smartphone("Apple", "iPhone 13");

    // Turn on the devices
    laptop->turnOn();  // Calls Laptop's turnOn function
    cout << endl;
    smartphone->turnOn();  // Calls Smartphone's turnOn function

    // Deallocate memory
    delete laptop;
    delete smartphone;

    return 0;
}
