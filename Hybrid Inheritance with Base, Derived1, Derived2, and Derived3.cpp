#include <iostream>
#include <string>
using namespace std;

// Base class
class Base {
protected:
    string baseMessage;

public:
    // Constructor to initialize base message
    Base(string msg) : baseMessage(msg) {}

    // Method to display base message
    void displayBaseMessage() const {
        cout << "Base Message: " << baseMessage << endl;
    }
};

// Derived class Derived1 inherits from Base
class Derived1 : public Base {
protected:
    string derived1Message;

public:
    // Constructor to initialize both Base and Derived1 messages
    Derived1(string baseMsg, string msg1) : Base(baseMsg), derived1Message(msg1) {}

    // Method to display Derived1 specific message
    void displayDerived1Message() const {
        cout << "Derived1 Message: " << derived1Message << endl;
    }
};

// Derived class Derived2 inherits from Base
class Derived2 : public Base {
protected:
    string derived2Message;

public:
    // Constructor to initialize both Base and Derived2 messages
    Derived2(string baseMsg, string msg2) : Base(baseMsg), derived2Message(msg2) {}

    // Method to display Derived2 specific message
    void displayDerived2Message() const {
        cout << "Derived2 Message: " << derived2Message << endl;
    }
};

// Derived class Derived3 inherits from Derived1 and Derived2
class Derived3 : public Derived1, public Derived2 {
private:
    string derived3Message;

public:
    // Constructor to initialize all classes: Base, Derived1, and Derived2
    Derived3(string baseMsg, string msg1, string msg2, string msg3)
        : Base(baseMsg), Derived1(baseMsg, msg1), Derived2(baseMsg, msg2), derived3Message(msg3) {}

    // Method to display all messages from Base, Derived1, Derived2, and Derived3
    void displayAllMessages() const {
        displayBaseMessage();             // From Base
        displayDerived1Message();         // From Derived1
        displayDerived2Message();         // From Derived2
        cout << "Derived3 Message: " << derived3Message << endl;
    }
};

int main() {
    // Create an object of Derived3 class
    Derived3 derived3Object("Base message", "Derived1 message", "Derived2 message", "Derived3 message");

    // Display all messages from all classes
    derived3Object.displayAllMessages();

    return 0;
}
