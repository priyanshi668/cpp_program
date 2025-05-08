#include <iostream>
#include <string>
using namespace std;

// Base class
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

// Intermediate class inherits from Base
class Intermediate : public Base {
protected:
    string intermediateMessage;

public:
    // Constructor to initialize both Base and Intermediate messages
    Intermediate(string baseMsg, string interMsg) 
        : Base(baseMsg), intermediateMessage(interMsg) {}

    // Method to display intermediate message
    void displayIntermediateMessage() const {
        cout << "Intermediate Message: " << intermediateMessage << endl;
    }
};

// Derived class inherits from Intermediate
class Derived : public Intermediate {
private:
    string derivedMessage;

public:
    // Constructor to initialize Base, Intermediate, and Derived messages
    Derived(string baseMsg, string interMsg, string derivMsg)
        : Intermediate(baseMsg, interMsg), derivedMessage(derivMsg) {}

    // Method to display derived message
    void displayDerivedMessage() const {
        cout << "Derived Message: " << derivedMessage << endl;
    }
};

int main() {
    // Create an object of the Derived class
    Derived derivedObject("Base message", "Intermediate message", "Derived message");

    // Display all the messages from Base, Intermediate, and Derived
    derivedObject.displayBaseMessage();
    derivedObject.displayIntermediateMessage();
    derivedObject.displayDerivedMessage();

    return 0;
}
