#include <iostream>
using namespace std;

// Base class Animal
class Animal {
public:
    // Virtual function to make sound (to be overridden by derived classes)
    virtual void makeSound() const = 0;

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal {
public:
    // Override the makeSound function for the Dog class
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Override the makeSound function for the Cat class
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
};

// Derived class Bird
class Bird : public Animal {
public:
    // Override the makeSound function for the Bird class
    void makeSound() const override {
        cout << "Chirp! Chirp!" << endl;
    }
};

int main() {
    // Create objects of each derived class
    Dog dog;
    Cat cat;
    Bird bird;

    // Call the makeSound method for each animal
    cout << "Dog sound: ";
    dog.makeSound();

    cout << "Cat sound: ";
    cat.makeSound();

    cout << "Bird sound: ";
    bird.makeSound();

    return 0;
}
