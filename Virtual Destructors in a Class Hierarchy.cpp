#include <iostream>
using namespace std;

// Base class with virtual destructor
class Base {
public:
    Base() {
        cout << "Base constructor called\n";
    }

    virtual ~Base() {  // Virtual destructor
        cout << "Base destructor called\n";
    }
};

// Derived class
class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5];  // Dynamic memory allocation
        cout << "Derived constructor called\n";
    }

    ~Derived() {
        delete[] data;  // Proper cleanup
        cout << "Derived destructor called\n";
    }
};

// Main function
int main() {
    Base* obj = new Derived();  // Upcasting
    cout << "\nDeleting object through base class pointer...\n";
    delete obj;  // Virtual destructor ensures Derived's destructor is called

    return 0;
}
