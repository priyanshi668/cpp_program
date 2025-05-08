#include <iostream>
#include <string>
using namespace std;

// Base class Appliance
class Appliance {
public:
    // Virtual function to display appliance functionality
    virtual void displayFunctionality() const {
        cout << "This is a general appliance." << endl;
    }

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Appliance() {}
};

// Derived class WashingMachine
class WashingMachine : public Appliance {
public:
    // Overridden function to display the functionality of a washing machine
    void displayFunctionality() const override {
        cout << "This is a Washing Machine. It washes clothes." << endl;
    }
};

// Derived class Refrigerator
class Refrigerator : public Appliance {
public:
    // Overridden function to display the functionality of a refrigerator
    void displayFunctionality() const override {
        cout << "This is a Refrigerator. It keeps food and drinks cold." << endl;
    }
};

// Derived class Microwave
class Microwave : public Appliance {
public:
    // Overridden function to display the functionality of a microwave
    void displayFunctionality() const override {
        cout << "This is a Microwave. It heats and cooks food quickly." << endl;
    }
};

int main() {
    // Creating base class pointers to derived class objects
    Appliance* appliance1 = new WashingMachine();
    Appliance* appliance2 = new Refrigerator();
    Appliance* appliance3 = new Microwave();

    // Demonstrating polymorphism by calling the overridden displayFunctionality function
    appliance1->displayFunctionality();  // Will call WashingMachine's displayFunctionality()
    appliance2->displayFunctionality();  // Will call Refrigerator's displayFunctionality()
    appliance3->displayFunctionality();  // Will call Microwave's displayFunctionality()

    // Deallocate memory
    delete appliance1;
    delete appliance2;
    delete appliance3;

    return 0;
}
