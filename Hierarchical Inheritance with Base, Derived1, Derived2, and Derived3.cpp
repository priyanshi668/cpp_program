#include <iostream>
#include <string>
using namespace std;

// Base class Base
class Base {
protected:
    string baseMessage;

public:
    // Constructor to initialize the base message
    Base(string msg) : baseMessage(msg) {}

    // Method to display the base message
    void displayBaseMessage() const {
        cout << "Base Message: " << baseMessage << endl;
    }
};

// Derived class Derived1 inherits from Base
class Derived1 : public Base {
public:
    // Constructor to initialize Base class through constructor initializer list
    Derived1(string msg) : Base(msg) {}

    // Method to display a specific message for Derived1
    void displayDerived1Message() const {
        cout << "Derived1 specific message." << endl;
    }
};

// Derived class Derived2 inherits from Base
class Derived2 : public Base {
public:
    // Constructor to initialize Base class through constructor initializer list
    Derived2(string msg) : Base(msg) {}

    // Method to display a specific message for Derived2
    void displayDerived2Message() const {
        cout << "Derived2 specific message." << endl;
    }
};

// Derived class Derived3 inherits from Base
class Derived3 : public Base {
public:
    // Constructor to initialize Base class through constructor initializer list
    Derived3(string msg) : Base(msg) {}

    // Method to display a specific message for Derived3
    void displayDerived3Message() const {
        cout << "Derived3 specific message." << endl;
    }
};

int main() {
    // Create objects of the derived classes
    Derived1 derived1("Base message for Derived1");
    Derived2 derived2("Base message for Derived2");
    Derived3 derived3("Base message for Derived3");

    // Display messages for each object
    derived1.displayBaseMessage();
    derived1.displayDerived1Message();

    derived2.displayBaseMessage();
    derived2.displayDerived2Message();

    derived3.displayBaseMessage();
    derived3.displayDerived3Message();

    return 0;
}
