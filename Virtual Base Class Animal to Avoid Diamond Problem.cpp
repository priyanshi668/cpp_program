#include <iostream>
#include <string>
using namespace std;

// Virtual base class Animal
class Animal {
public:
    virtual void sound() const = 0; // Pure virtual function to make a sound
    virtual ~Animal() {} // Virtual destructor
};

// Derived class Mammal
class Mammal : virtual public Animal {
public:
    void sound() const override {
        cout << "Mammal sound" << endl;
    }
};

// Derived class Bird
class Bird : virtual public Animal {
public:
    void sound() const override {
        cout << "Bird sound" << endl;
    }
};

// Derived class Bat which inherits from both Mammal and Bird
class Bat : public Mammal, public Bird {
public:
    void sound() const override {
        cout << "Bat sound" << endl;
    }
};

int main() {
    // Create a Bat object
    Bat bat;

    // Calling the overridden sound function from Bat
    cout << "Bat Sound: ";
    bat.sound();

    return 0;
}
